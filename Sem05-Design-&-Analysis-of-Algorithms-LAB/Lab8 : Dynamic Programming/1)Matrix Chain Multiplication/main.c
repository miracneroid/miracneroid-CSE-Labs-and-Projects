#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void matrix_chain_order(int p[], int n, int** M, int** S) {
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int** S, int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        print_optimal_parens(S, i, S[i][j]);
        print_optimal_parens(S, S[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    
    int p[n + 1];
    for (int i = 0; i < n; i++) {
        int rows, cols;
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &rows, &cols);
        if (i == 0) {
            p[i] = rows;
        }
        p[i + 1] = cols;
    }

    for (int i = 0; i < n - 1; i++) {
        if (p[i + 1] != p[i + 2]) {
            printf("Error: Matrix dimensions are not compatible for multiplication.\n");
            return 0;
        }
    }

    int** M = (int**)malloc(n * sizeof(int*));
    int** S = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        M[i] = (int*)malloc(n * sizeof(int));
        S[i] = (int*)malloc(n * sizeof(int));
    }

    matrix_chain_order(p, n, M, S);

    printf("\nM Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    print_optimal_parens(S, 0, n - 1);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", M[0][n - 1]);

    for (int i = 0; i < n; i++) {
        free(M[i]);
        free(S[i]);
    }
    free(M);
    free(S);

    return 0;
}
