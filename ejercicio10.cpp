#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int A[ROWS][COLS];
    int AT[COLS][ROWS];

    // Ingresar valores para A
    printf("Ingrese los valores para la matriz A (3x4):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Calcular la transpuesta AT[j][i] = A[i][j]
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            AT[j][i] = A[i][j];
        }
    }

    // Mostrar A
    printf("\nMatriz A (3x4):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

    // Mostrar AT
    printf("\nMatriz Transpuesta AT (4x3):\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%4d", AT[i][j]);
        }
        printf("\n");
    }

    return 0;
}
