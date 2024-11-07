#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // Added for exit() and wait()
#include <sys/wait.h> // Added for wait()
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

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(p[0]); // Close the reading end in the parent process
        write(p[1], msg1, SIZE);
        write(p[1], msg2, SIZE);
        write(p[1], msg3, SIZE);
        close(p[1]); // Close the writing end after writing
        wait(NULL); // Wait for child process to finish
    } else { // Child process
        close(p[1]); // Close the writing end in the child process
        while (read(p[0], inbuf, SIZE) > 0) {
            printf("%s\n", inbuf); // Print the received message
        }
        close(p[0]); // Close the reading end after reading
        printf("Finished reading\n");
    }

    return 0;
}
