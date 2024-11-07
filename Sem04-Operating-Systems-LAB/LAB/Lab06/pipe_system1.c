#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // Added for exit()
#define SIZE 16

char* msg1 = "Hello World! #1";
char* msg2 = "Hello World! #2";
char* msg3 = "Hello World! #3";

int main() {
    char inbuf[SIZE];
    int p[2], i;
    
    if (pipe(p) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    /* continued write pipe */
    write(p[1], msg1, SIZE);
    write(p[1], msg2, SIZE);
    write(p[1], msg3, SIZE);

    for (i = 0; i < 3; i++) {
        /* read from pipe */
        read(p[0], inbuf, SIZE);
        inbuf[SIZE - 1] = '\0'; // Null-terminate the received message
        printf("%s\n", inbuf);
    }

    return 0;
}
