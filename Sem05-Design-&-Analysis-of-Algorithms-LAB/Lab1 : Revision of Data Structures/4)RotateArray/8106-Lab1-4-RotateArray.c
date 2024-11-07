/*
1.4 Aim of the program: Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2
elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &
q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.
Input:
Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
Call the function ROTATE_RIGHT(A, 5)
Output:
Before ROTATE: 11 22 33 44 55 66 77 88 99
After ROTATE: 55 11 22 33 44 66 77 88 99
*/

#include <stdio.h>
#include <stdlib.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    if (p2 <= 1) return;
    int i;
    for (i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main() {
    FILE *file;
    int size, i, p2 = 5;
    int *array;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fscanf(file, "%d", &size);

    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    printf("Data read from the file:\n");
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
        printf("%d ", array[i]);
    }
    printf("\n");

    fclose(file);

    printf("Before ROTATE:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    ROTATE_RIGHT(array, p2);

    printf("After ROTATE:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}