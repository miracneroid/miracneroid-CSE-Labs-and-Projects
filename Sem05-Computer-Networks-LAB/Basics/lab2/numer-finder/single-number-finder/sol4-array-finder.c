/*
u have given an unsorted array from range 1 to N and a numbers is missing init find the missing numbers,

ask for the range from the user, sort the array, and find the missing number, 

solve using hashmaps
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
    int hash[n];
    for(int i = 0; i < n; i++){
        hash[i] = 0;
    }
    for(int i = 0; i < n-1; i++){
        hash[arr[i]] = 1;
    }
    for(int i = 1; i < n; i++){
        if(hash[i] == 0){
            printf("The missing number is %d\n", i);
            break;
        }
    }
    return 0;
}