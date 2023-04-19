#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <arpa/inet.h>

int connfd0 = -1, connfd1 = -1;

void str_0()
{
    int n = 1;
    int bufsize = 1024;
    char *buffer = malloc(bufsize);

    do
    {
        while ((n = recv(connfd0, buffer, bufsize, 0)) > 0)
            send(connfd1, buffer, n, 0);
    } while (n > 0);

}
void str_1()
{
    int n = 1;
    int bufsize = 1024;
    char *buffer = malloc(bufsize);

    do
    {
        while ((n = recv(connfd1, buffer, bufsize, 0)) > 0)
            send(connfd0, buffer, n, 0);
    } while (n > 0);

}


int main()
{
    int listenfd, addrlen, addrlen0, addrlen1, pid0, pid1;
    struct sockaddr_in address, address0, address1;

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
    
    connfd0 = accept(listenfd, (struct sockaddr *)&address0, &addrlen0); //waits for a client to accept
    connfd1 = accept(listenfd, (struct sockaddr *)&address1, &addrlen1); //waits for the other client to be accepted

        printf("The Client0 %s is Connected...on port%d\n",inet_ntoa(address0.sin_addr),htons(address0.sin_port));
    printf("The Client1 %s is Connected...on port%d\n",inet_ntoa(address1.sin_addr),htons(address1.sin_port));
        
        if ((pid0 = fork()) == 0)
        {
            close(listenfd);
            str_0(); //sending function from client0 to client1
            exit(0);
        }
    if ((pid1 = fork()) == 0)
        {
            close(listenfd);
            str_1(); //sending function from client1 to client0
            exit(0);
        }
    }

    close(connfd1);
    close(connfd0);
    return 0;
}
