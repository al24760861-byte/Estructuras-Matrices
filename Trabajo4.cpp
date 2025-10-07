#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Prototipos
void inicializar_matriz(int filas, int columnas, int matriz[][COLS]);
void imprimir_matriz(int filas, int columnas, int matriz[][COLS]);
void llenar_matriz_aleatoria(int filas, int columnas, int matriz[][COLS]);
long long sumar_matriz(int filas, int columnas, int matriz[][COLS]);
double calcular_promedio(int filas, int columnas, long long suma);
void ejecutar_ejercicio4(void);

int main(void) {
    ejecutar_ejercicio4();
    return 0;
}

// Inicializa la matriz a 0 (opcional, pero útil para consistencia)
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
            if (j < columnas - 1) printf("  "); // separador entre columnas
        }
        printf("\n");
    }
}

// Llena la matriz con valores aleatorios entre 0 y 9
void llenar_matriz_aleatoria(int filas, int columnas, int matriz[][COLS]) {
    // Semilla debe inicializarse una vez; aquí asumimos que main/llamante lo hace.
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 10; // 0..9
        }
    }
}

// Suma todos los elementos de la matriz
long long sumar_matriz(int filas, int columnas, int matriz[][COLS]) {
    long long suma = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

// Calcula el promedio a partir de la suma
double calcular_promedio(int filas, int columnas, long long suma) {
    int total = filas * columnas;
    if (total == 0) return 0.0;
    return (double)suma / (double)total;
}

// Ejecución del ejercicio 4
void ejecutar_ejercicio4(void) {
    int matriz[FILAS][COLS];

    // Inicializar semilla de aleatoriedad
    srand((unsigned int)time(NULL));

    // Inicializar y llenar
    inicializar_matriz(FILAS, COLS, matriz);
    llenar_matriz_aleatoria(FILAS, COLS, matriz);

    // Imprimir la matriz
    printf("Matriz %dx%d aleatoria (0..9):\n", FILAS, COLS);
    imprimir_matriz(FILAS, COLS, matriz);
    printf("\n");

    // Calcular suma y promedio
    long long suma = sumar_matriz(FILAS, COLS, matriz);
    double promedio = calcular_promedio(FILAS, COLS, suma);

    // Mostrar resultados
    printf("Suma de elementos: %lld\n", suma);
    printf("Promedio de elementos: %.2f\n", promedio);
}