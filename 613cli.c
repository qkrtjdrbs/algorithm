#include <unistd.h>     /* unix standard library */
#include <arpa/inet.h>  /* IP addresses manipulation utilities */
#include <netinet/in.h> /* sockaddr_in structure definition */
#include <sys/socket.h> /* berkley socket library */
#include <stdio.h>      /* standard I/O library */
#include <string.h>     /* include to have memset*/
#include <stdlib.h>     /* include to have exit*/
#include <sys/select.h>
#define MAXLINE 4096

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
    int maxfdp1, stdineof;
    fd_set rset;
    char buf[MAXLINE];
    int n;

    stdineof = 0;
    FD_ZERO(&rset);
    for (;;)
    {
        if (stdineof == 0)
            FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdp1 = max(fileno(fp), sockfd) + 1;
        select(maxfdp1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &rset))
        { /* socket is readable */
            if ((n = read(sockfd, buf, MAXLINE)) == 0)
            {
                if (stdineof == 1)
                    return; /* normal termination */
                else
                    perror("str_cli: server terminated prematurely");
            }

            writen(fileno(stdout), buf, n);
        }

        if (FD_ISSET(fileno(fp), &rset))
        { /* input is readable */
            if ((n = read(fileno(fp), buf, MAXLINE)) == 0)
            {
                stdineof = 1;
                shutdown(sockfd, SHUT_WR); /* send FIN */
                FD_CLR(fileno(fp), &rset);
                continue;
            }

            writen(sockfd, buf, n);
        }
    }
}
