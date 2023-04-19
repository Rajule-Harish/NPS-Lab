#include <unistd.h>                //
#include <fcntl.h>              //
#include <stdio.h>              // input-output
#include <stdlib.h>             // malloc()

#include <sys/types.h>        //
#include <sys/stat.h>           //
#include <sys/socket.h>       // socket(),listen(), send()

#include <netinet/in.h>         // AF_INET
#include <arpa/inet.h>          // inet_pton()


void str_echo(int connfd)
{
    int n = 1;
    int bufsize = 1024;
    char *buffer = malloc(bufsize);

    do
    {
        while ((n = recv(connfd, buffer, bufsize, 0)) > 0)
            send(connfd, buffer, n, 0);
    } while (n > 0);

}


int main()
{
    int listenfd, connfd, addrlen;
    struct sockaddr_in address;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) > 0)
        printf("The socket was created\n");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(15001);


    if (bind(listenfd, (struct sockaddr *)&address, sizeof(address)) == 0)
        printf("Binding Socket\n");

    listen(listenfd, 3);

    printf("server is listening\n");


    for (;;)
    {
       addrlen = sizeof(struct sockaddr);

        connfd = accept(listenfd, (struct sockaddr *)&address, &addrlen);

        printf("The Client %s is Connected...on port%d\n",inet_ntoa(address.sin_addr),htons(address.sin_port));

        str_echo(connfd);
        close(listenfd);
    }

    return close(connfd);
}
