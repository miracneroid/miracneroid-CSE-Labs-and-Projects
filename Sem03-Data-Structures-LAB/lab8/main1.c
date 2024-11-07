/*
1)Find the sum of two sparse matrice
*/

#include <stdio.h>
#include <stdlib.h>

struct SparseMatrix {
    int row, col, value;
};

int main() {
    int i, j, k;
    int m, n, p, q;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of non-zero elements in the first matrix: ");
    scanf("%d", &k);

    struct SparseMatrix mat1[k];

    printf("Enter the non-zero elements of the first matrix (row, column, value):\n");
    for (i = 0; i < k; i++) {
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &p, &q);

    if (m != p || n != q) {
        printf("Matrix addition is not possible. Matrices must have the same dimensions.\n");
        return 1;
    }

    printf("Enter the number of non-zero elements in the second matrix: ");
    scanf("%d", &k);

    struct SparseMatrix mat2[k];

    printf("Enter the non-zero elements of the second matrix (row, column, value):\n");
    for (i = 0; i < k; i++) {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    int result[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < k; i++) {
        result[mat1[i].row][mat1[i].col] += mat1[i].value;
        result[mat2[i].row][mat2[i].col] += mat2[i].value;
    }

    printf("Resulting matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
