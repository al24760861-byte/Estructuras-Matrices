#include <stdio.h>

#define SIZE 4

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int i, j;

    // Ingresar valores para la matriz A
    printf("Ingrese los valores para la matriz A (4x4):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Ingresar valores para la matriz B
    printf("\nIngrese los valores para la matriz B (4x4):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Calcular la matriz C = A - B
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    // Mostrar matriz A
    printf("\nMatriz A:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

    // Mostrar matriz B
    printf("\nMatriz B:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%4d", B[i][j]);
        }
        printf("\n");
    }

    // Mostrar matriz C = A - B
    printf("\nMatriz C (A - B):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
