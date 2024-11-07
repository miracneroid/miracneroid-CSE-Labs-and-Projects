#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    if (fork()==0)
    {
        printf("I am the child my id is: %d\n",getpid());
    }
    else
        printf("I am thge parent, my id is: %d\n", getpid());
    return 0;
}