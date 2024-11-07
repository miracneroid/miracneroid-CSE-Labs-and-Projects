/*
u have given an unsorted array from range 1 to N and a numbers is missing init find the missing numbers,

ask for the range from the user, sort the array, and find the missing number, 
*/

#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Enter the range of the array: ");
    scanf("%d", &n);
    int arr[n-1];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n-1; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n-1; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < n-1; i++){
        printf("%d ", arr[i]);
    }
    // Bubble sort
    for(int i = 0; i < n-1; i++){
        if(arr[i] != i+1){
            printf("The missing number is %d\n", i+1);
            break;
        }
    }
    return 0;
}