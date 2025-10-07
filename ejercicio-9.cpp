#include <stdio.h>

int main() {
    int m = 2, n = 3, p = 2; // Dimensiones fijas como en el ejemplo
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int B[3][2] = {
        {1, 4},
        {2, 5},
        {3, 6}
    };
    int C[2][2] = {0}; // Resultado

    // Multiplicación de matrices: C[i][j] = suma(A[i][k] * B[k][j])
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Mostrar A
    printf("Matriz A (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

    // Mostrar B
    printf("\nMatriz B (%dx%d):\n", n, p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%4d", B[i][j]);
        }
        printf("\n");
    }

    // Mostrar C
    printf("\nMatriz C = A x B (%dx%d):\n", m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
