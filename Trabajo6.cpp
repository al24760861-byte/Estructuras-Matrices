#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Prototipos
void inicializar_matriz(int filas, int columnas, int matriz[][COLS]);
void llenar_matriz_aleatoria(int filas, int columnas, int matriz[][COLS]);
void imprimir_matriz_con_sumas(int filas, int columnas, int matriz[][COLS], int sum_filas[]);
void sumar_filas_y_columnas(int filas, int columnas, int matriz[][COLS],
                            int sum_filas[], int sum_columnas[]);
void imprimir_sumas_columnas(int sum_columnas[]);

int main(void) {
    // Semilla para números aleatorios
    srand((unsigned int)time(NULL));

    int M[FILAS][COLS];
    int sum_filas[FILAS];
    int sum_columnas[COLS];

    inicializar_matriz(FILAS, COLS, M);
    llenar_matriz_aleatoria(FILAS, COLS, M);

    // Calcular sumas
    sumar_filas_y_columnas(FILAS, COLS, M, sum_filas, sum_columnas);

    // Imprimir matriz y sumas de filas
    printf("Matriz:\n");
    imprimir_matriz_con_sumas(FILAS, COLS, M, sum_filas);
    printf("---\n");
    printf("Suma columnas: ");
    imprimir_sumas_columnas(sum_columnas);
    printf("\n");

    return 0;
}

// Inicializa la matriz a cero
void inicializar_matriz(int filas, int columnas, int matriz[][COLS]) {
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            matriz[i][j] = 0;
}

// Llena la matriz con valores aleatorios entre 0 y 9
void llenar_matriz_aleatoria(int filas, int columnas, int matriz[][COLS]) {
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            matriz[i][j] = rand() % 10; // 0..9
}

// Imprime la matriz y, para cada fila, su suma al final de la fila
void imprimir_matriz_con_sumas(int filas, int columnas, int matriz[][COLS], int sum_filas[]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            printf("%d", matriz[i][j]);
            if (j < columnas - 1) printf("  "); // separación entre columnas
        }
        printf("  | Suma fila %d: %d\n", i, sum_filas[i]);
    }
}

// Calcula las sumas de filas y columnas
void sumar_filas_y_columnas(int filas, int columnas, int matriz[][COLS],
                            int sum_filas[], int sum_columnas[]) {
    // Suma por filas
    for (int i = 0; i < filas; ++i) {
        int s = 0;
        for (int j = 0; j < columnas; ++j) {
            s += matriz[i][j];
        }
        sum_filas[i] = s;
    }

    // Suma por columnas
    for (int j = 0; j < columnas; ++j) {
        int s = 0;
        for (int i = 0; i < filas; ++i) {
            s += matriz[i][j];
        }
        sum_columnas[j] = s;
    }
}

// Imprime las sumas de columnas
void imprimir_sumas_columnas(int sum_columnas[]) {
    for (int j = 0; j < COLS; ++j) {
        printf("%d", sum_columnas[j]);
        if (j < COLS - 1) printf("  ");
    }
}