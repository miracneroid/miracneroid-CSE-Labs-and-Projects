/*
u have given an unsorted array from range 1 to N and a numbers is missing init find the missing numbers,

ask for the range from the user, sort the array, and find the missing number, 


do it using XOR
*/

#include <stdio.h>

int main(){
    int n;
    printf("Enter the range of the array: ");
    scanf("%d", &n);
    int arr[n-1];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n-1; i++){
        scanf("%d", &arr[i]);
    }
    int xor = 0;
    for(int i = 0; i < n-1; i++){
        xor = xor ^ arr[i];
    }
    for(int i = 1; i <= n; i++){
        xor = xor ^ i;
    }
    printf("The missing number is %d\n", xor);
    return 0;
}