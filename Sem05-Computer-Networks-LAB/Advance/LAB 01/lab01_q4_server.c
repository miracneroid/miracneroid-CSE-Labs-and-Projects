// Will practice again

#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <unistd.h> // close function
#define PORT 5000
#define MAXLINE 1000

int main()
{
    char buffer[100];
    int servsockfd, len, n;
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));

    // Create a UDP Socket
    servsockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;

    // bind server address to socket descriptor
    bind(servsockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    //receive the datagram
    len = sizeof(cliaddr);
    n = recvfrom(servsockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Request: \n");
    puts(buffer);
    //Echoing back to the client

    time_t t; // not a primitive datatype
    time(&t);

    sendto(servsockfd, ctime(&t), n, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    getchar();

    // close the descriptor
    close(servsockfd);
}
