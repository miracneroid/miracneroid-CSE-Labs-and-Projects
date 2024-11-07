/*
u have given an unsorted array from range 1 to N and a numbers is missing init find the missing numbers,

ask for the range from the user, sort the array, and find the missing number, 

do it by the addition of the sum of all the value of the array, divide it in half and subtract the sum of the array from the sum of the range
 
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
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        sum += arr[i];
    }
    int total = n*(n+1)/2;
    printf("The missing number is %d\n", total - sum);
    return 0;
}