/*
2)Find the product of two sparse matrices taking input from user
*/

#include <stdio.h>

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

    if (n != p) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    printf("Enter the number of non-zero elements in the second matrix: ");
    scanf("%d", &k);

    struct SparseMatrix mat2[k];

    printf("Enter the non-zero elements of the second matrix (row, column, value):\n");
    for (i = 0; i < k; i++) {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    int result[m][q];

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            for (k = 0; k < n; k++) {
                int val1 = 0;
                int val2 = 0;
                for (int x = 0; x < n; x++) {
                    if (mat1[x].row == i && mat1[x].col == k) {
                        val1 = mat1[x].value;
                        break;
                    }
                }
                for (int x = 0; x < q; x++) {
                    if (mat2[x].row == k && mat2[x].col == j) {
                        val2 = mat2[x].value;
                        break;
                    }
                }
                result[i][j] += val1 * val2;
            }
        }
    }

    printf("Resulting matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
