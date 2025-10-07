#include <stdio.h>

int main() {
    int n = 4;
    int matriz[4][4] = {
        {4, 2, 7, 1},
        {5, 9, 7, 3},
        {8, 6, 7, 0},
        {1, 4, 2, 7}
    };

    int num, i, j;
    int encontrado = 0;

    printf("Matriz 4x4:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nIngrese el número a buscar: ");
    scanf("%d", &num);

    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] == num) {
                printf("Número encontrado en fila %d, columna %d\n", i, j);
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("El número %d no se encuentra en la matriz.\n", num);
    }

    return 0;
}
