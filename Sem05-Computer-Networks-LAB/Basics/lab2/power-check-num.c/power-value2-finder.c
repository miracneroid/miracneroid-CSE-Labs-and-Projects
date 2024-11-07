/*
write a prgram to check whether a number is power of 2 or not
*/

#include <stdio.h>

int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    if(num & (num-1)){
        printf("%d is not a power of 2\n", num);
    }else{
        printf("%d is a power of 2\n", num);
    }
    return 0;  
}
