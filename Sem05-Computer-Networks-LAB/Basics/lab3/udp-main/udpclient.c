#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int i, sockfd, length;
    char buf[100], buf1[100];
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1"); // loopback IP address
    sa.sin_port = htons(6025);

    while (1) {
        printf("\nEnter a message: ");
        fgets(buf, sizeof(buf), stdin); // Use fgets instead of gets

        // Remove newline character if present
        buf[strcspn(buf, "\n")] = '\0';

        sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&sa, sizeof(sa)); //data inside buffer1 and we need to send buffer1

        // Check if the client wants to exit
        if (strcmp(buf, "exit") == 0) {
            printf("Client is exiting...\n");
            break;
        }

        length = sizeof(sa);
        int k = recvfrom(sockfd, buf1, 100, 0, (struct sockaddr *)&sa, &length);
        buf1[k] = '\0';
        printf("\nReceived: %s\n", buf1);

        // Check if the server wants to exit
        if (strcmp(buf1, "exit") == 0) {
            printf("Server requested to exit. Client shutting down...\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}
