#include <stdio.h>

int main() {
    int n = 4;
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int i, j;
    int sumaPrincipal = 0, sumaSecundaria = 0;

    printf("Matriz 4x4:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nDiagonal principal: ");
    for (i = 0; i < n; i++) {
        printf("%d ", matriz[i][i]);
        sumaPrincipal += matriz[i][i];
    }

    printf("\nSuma diagonal principal: %d\n", sumaPrincipal);

    printf("\nDiagonal secundaria: ");
    for (i = 0; i < n; i++) {
        printf("%d ", matriz[i][n - 1 - i]);
        sumaSecundaria += matriz[i][n - 1 - i];
    }

    printf("\nSuma diagonal secundaria: %d\n", sumaSecundaria);

    return 0;
}
