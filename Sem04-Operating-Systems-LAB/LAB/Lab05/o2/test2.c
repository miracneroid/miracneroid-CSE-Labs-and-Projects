#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // make two process which run same program after this instruction
  if(fork()==0)
    printf("I am a child and my id is %d \n",getpid());
  else{
    printf("I am a Parent  and my id is %d \n",getpid());
    printf("I am a Parent  and my id is %d \n",getppid());
  }
  fork();
  return 0;
}