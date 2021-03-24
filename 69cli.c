#include <unistd.h>     /* unix standard library */
#include <arpa/inet.h>  /* IP addresses manipulation utilities */
#include <netinet/in.h> /* sockaddr_in structure definition */
#include <sys/socket.h> /* berkley socket library */
#include <stdio.h>      /* standard I/O library */
#include <string.h>     /* include to have memset*/
#include <stdlib.h>     /* include to have exit*/
#include <sys/select.h>
#define MAXLINE 4096

static int read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];
static ssize_t
my_read(int fd, char *ptr)
{
    if (read_cnt <= 0)
    {
    again:
        if ((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0)
        {
            if (errno == EINTR)
                goto again;
            return (-1);
        }
        else if (read_cnt == 0)
            return (0);
        read_ptr = read_buf;
    }
    read_cnt--;
    *ptr = *read_ptr++;
    return (1);
}
ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
    ssize_t n, rc;
    char c, *ptr;
    ptr = vptr;
    for (n = 1; n < maxlen; n++)
    {
        if ((rc = my_read(fd, &c)) == 1)
        {
            *ptr++ = c;
            if (c == '\n')
                break; /* newline is stored, like fgets() */
        }
        else if (rc == 0)
        {
            *ptr = 0;
            return (n - 1); /* EOF, n - 1 bytes were read */
        }
        else
            return (-1); /* error, errno set by read() */
    }
    *ptr = 0; /* null terminate like fgets() */
    return (n);
}
ssize_t
readlinebuf(void **vptrptr)
{
    if (read_cnt)
        *vptrptr = read_ptr;
    return (read_cnt);
}

ssize_t /* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
    size_t nleft;
    ssize_t nwritten;
    const char *ptr;
    ptr = vptr;
    nleft = n;
    while (nleft > 0)
    {
        if ((nwritten = write(fd, ptr, nleft)) <= 0)
        {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0; /* and call write() again */
            else
                return (-1); /* error */
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return (n);
}

void str_cli(FILE *fp, int sockfd)
{
    int maxfdp1;
    fd_set rset;
    char sendline[MAXLINE], recvline[MAXLINE];

    FD_ZERO(&rset);
    for (;;)
    {
        FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdp1 = max(fileno(fp), sockfd) + 1;
        select(maxfdp1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &rset))
        { /* socket is readable */
            if (readline(sockfd, recvline, MAXLINE) == 0)
                perror("str_cli: server terminated prematurely");
            fputs(recvline, stdout);
        }

        if (FD_ISSET(fileno(fp), &rset))
        { /* input is readable */
            if (fgets(sendline, MAXLINE, fp) == NULL)
                return; /* all done */
            writen(sockfd, sendline, strlen(sendline));
        }
    }
}