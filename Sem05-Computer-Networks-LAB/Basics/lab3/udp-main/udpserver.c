#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>d

int main()
{
    int sockfd, fd1, length, i;
    char buf[100], buf1[100];
    struct sockaddr_in sa, ca;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(6025);

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    printf("test %d%d\n", sockfd, i);

    while (1) {
        length = sizeof(sa);
        int k = recvfrom(sockfd, buf, 100, 0, (struct sockaddr *)&ca, &length);
        buf[k] = '\0';
        printf("\nReceived: %s\n", buf);

        // Check if the received message is "exit"
        if (strcmp(buf, "exit") == 0) {
            printf("Client requested to exit. Server shutting down...\n");
            break;
        }

        printf("Enter a message for client: ");
        fgets(buf1, sizeof(buf1), stdin); // Use fgets instead of gets

        // Remove newline character if present
        buf1[strcspn(buf1, "\n")] = '\0';

        sendto(sockfd, buf1, strlen(buf1), 0, (struct sockaddr *)&ca, sizeof(ca));

        // Check if the server wants to exit
        if (strcmp(buf1, "exit") == 0) {
            printf("Server is exiting...\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}
