#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void createProcessTree(int depth) {
    if (depth > 0) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Child process (PID: %d) created at depth %d\n", getpid(), depth);
            createProcessTree(depth - 1);
        } else if (pid > 0) {
            int status;
            pid_t childPid = wait(&status);
            printf("Parent process (PID: %d) waited for child process (PID: %d) to complete\n", getpid(), childPid);
            createProcessTree(depth - 1);
        } else {
            printf("Fork failed\n");
        }
    }
}

int main() {
    int depth = 3;
    printf("Creating process tree of depth %d...\n", depth);
    createProcessTree(depth);
    return 0;
}