#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Prototipos
void inicializar_matriz(int filas, int columnas, int matriz[][COLS]);
void imprimir_matriz(int filas, int columnas, int matriz[][COLS]);
void llenar_matriz_aleatoria(int filas, int columnas, int matriz[][COLS]);
void encontrar_maximo_minimo(int filas, int columnas, int matriz[][COLS],
                          int *max, int *max_i, int *max_j,
                          int *min, int *min_i, int *min_j);
void ejecutar_ejercicio5(void);

int main(void) {
    ejecutar_ejercicio5();
    return 0;
}

// Inicializa la matriz a 0 (opcional)
void inicializar_matriz(int filas, int columnas, int matriz[][COLS]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = 0;
        }
    }
}

// Imprime la matriz en formato de tabla
void imprimir_matriz(int filas, int columnas, int matriz[][COLS]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            printf("%d", matriz[i][j]);
            if (j < columnas - 1) printf("  ");
        }
        printf("\n");
    }
}

// Llena la matriz con valores aleatorios entre 0 y 99 (ajusta rango si lo deseas)
void llenar_matriz_aleatoria(int filas, int columnas, int matriz[][COLS]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 100; // 0..99
        }
    }
}

// Encuentra el máximo y mínimo y sus posiciones
void encontrar_maximo_minimo(int filas, int columnas, int matriz[][COLS],
                          int *max, int *max_i, int *max_j,
                          int *min, int *min_i, int *min_j) {
    // Inicializar con el primer elemento
    *max = matriz[0][0];
    *min = matriz[0][0];
    *max_i = 0; *max_j = 0;
    *min_i = 0; *min_j = 0;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] > *max) {
                *max = matriz[i][j];
                *max_i = i;
                *max_j = j;
            }
            if (matriz[i][j] < *min) {
                *min = matriz[i][j];
                *min_i = i;
                *min_j = j;
            }
        }
    }
}

// Ejecución del ejercicio 5
void ejecutar_ejercicio5(void) {
    int matriz[FILAS][COLS];

    // Semilla de aleatoriedad
    srand((unsigned int)time(NULL));

    // Inicializar y llenar
    inicializar_matriz(FILAS, COLS, matriz);
    llenar_matriz_aleatoria(FILAS, COLS, matriz);

    // Imprimir la matriz
    printf("Matriz %dx%d aleatoria (0..99):\n", FILAS, COLS);
    imprimir_matriz(FILAS, COLS, matriz);
    printf("\n");

    // Encontrar máximo y mínimo y sus posiciones
    int max, max_i, max_j;
    int min, min_i, min_j;
    encontrar_maximo_minimo(FILAS, COLS, matriz, &max, &max_i, &max_j,
                          &min, &min_i, &min_j);

    // Mostrar resultados
    printf("Máximo: %d en posición [%d][%d]\n", max, max_i, max_j);
    printf("Mínimo: %d en posición [%d][%d]\n", min, min_i, min_j);
}