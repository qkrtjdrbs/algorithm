#include <unistd.h>     /* unix standard library */
#include <arpa/inet.h>  /* IP addresses manipulation utilities */
#include <netinet/in.h> /* sockaddr_in structure definition */
#include <sys/socket.h> /* berkley socket library */
#include <stdio.h>      /* standard I/O library */
#include <string.h>     /* include to have memset*/
#include <stdlib.h>     /* include to have exit*/
#include <sys/select.h>
#define MAXLINE 4096
#define LISTENQ 1024
#define FD_SETSIZE 10

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

int main(int argc, char **argv)
{
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char buf[MAXLINE];
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);

    maxfd = listenfd; /* initialize */
    maxi = -1;        /* index into client[] array */
    for (i = 0; i < FD_SETSIZE; i++)
        client[i] = -1; /* -1 indicates available entry */
    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);
    /* end fig01 */

    /* include fig02 */
    for (;;)
    {
        rset = allset; /* structure assignment */
        nready = Select(maxfd + 1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(listenfd, &rset))
        { /* new client connection */
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
#ifdef NOTDEF
            printf("new client: %s, port %d\n",
                   Inet_ntop(AF_INET, &cliaddr.sin_addr, 4, NULL),
                   ntohs(cliaddr.sin_port));
#endif

            for (i = 0; i < FD_SETSIZE; i++)
                if (client[i] < 0)
                {
                    client[i] = connfd; /* save descriptor */
                    break;
                }
            if (i == FD_SETSIZE)
                err_quit("too many clients");

            FD_SET(connfd, &allset); /* add new descriptor to set */
            if (connfd > maxfd)
                maxfd = connfd; /* for select */
            if (i > maxi)
                maxi = i; /* max index in client[] array */

            if (--nready <= 0)
                continue; /* no more readable descriptors */
        }

        for (i = 0; i <= maxi; i++)
        { /* check all clients for data */
            if ((sockfd = client[i]) < 0)
                continue;
            if (FD_ISSET(sockfd, &rset))
            {
                if ((n = read(sockfd, buf, MAXLINE)) == 0)
                {
                    /*4connection closed by client */
                    close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                }
                else
                    writen(sockfd, buf, n);

                if (--nready <= 0)
                    break; /* no more readable descriptors */
            }
        }
    }
}