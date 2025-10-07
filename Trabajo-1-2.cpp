#include <stdio.h>
#include <stdlib.h>

// Constantes de dimensiones
#define MAX_FILAS 10
#define MAX_COLS 10

// Prototipos de funciones
int validar_dimensiones(int filas, int cols);
void inicializar_matriz(int filas, int cols, int matriz[][MAX_COLS]);
void imprimir_matriz(int filas, int cols, int matriz[][MAX_COLS]);
void llenar_matriz_manual(int filas, int cols, int matriz[][MAX_COLS]);
void ejecutar_ejercicio1(void);
void ejecutar_ejercicio2(void);
void prueba_extremos(void);

int main(void) {
    // Ejercicio 1: Declaración e Inicialización
    ejecutar_ejercicio1();

    // Ejercicio 2: Llenar Matriz Manualmente
    ejecutar_ejercicio2();

    // Pruebas con casos extremos
    prueba_extremos();

    return 0;
}

/* Valida que las dimensiones sean positivas y no excedan MAX_* */
int validar_dimensiones(int filas, int cols) {
    if (filas <= 0 || cols <= 0) {
        fprintf(stderr, "Error: las dimensiones deben ser > 0.\n");
        return 0;
    }
    if (filas > MAX_FILAS || cols > MAX_COLS) {
        fprintf(stderr, "Error: dimensiones exceden el tamaño máximo permitido (%dx%d).\n", MAX_FILAS, MAX_COLS);
        return 0;
    }
    return 1;
}

/* Inicializa una matriz de dimensiones filas x cols a 0 */
void inicializar_matriz(int filas, int cols, int matriz[][MAX_COLS]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) {
            matriz[i][j] = 0;
        }
    }
}

/* Imprime la matriz en formato de tabla */
void imprimir_matriz(int filas, int cols, int matriz[][MAX_COLS]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Espaciado para alineación similar a tabla
            printf("%d", matriz[i][j]);
            if (j < cols - 1) printf("  "); // separador entre columnas
        }
        printf("\n");
    }
}

/* Pide al usuario llenar la matriz 1..1 en 4x4 (o en dimensiones dadas) */
void llenar_matriz_manual(int filas, int cols, int matriz[][MAX_COLS]) {
    printf("Ingrese %d valores (%dx%d) para la matriz:\n", filas * cols, filas, cols);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Valor para[%d][%d]: ", i, j);
            if (scanf("%d", &matriz[i][j]) != 1) {
                fprintf(stderr, "Entrada no válida. Abortando.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/* Ejercicio 1: Declaración e Inicialización de 4x4 a 0, imprimir */
void ejecutar_ejercicio1(void) {
    const int filas = 4;
    const int cols = 4;
    int matriz[filas][MAX_COLS]; // MAX_COLS >= cols

    // Validar dimensiones
    if (!validar_dimensiones(filas, cols)) return;

    // Inicializar a 0
    inicializar_matriz(filas, cols, matriz);

    // Imprimir resultado
    printf("Ejercicio 1: Matriz %dx%d inicializada a 0\n", filas, cols);
    imprimir_matriz(filas, cols, matriz);
    printf("\n");
}

/* Ejercicio 2: Llenar matriz manualmente y imprimir */
void ejecutar_ejercicio2(void) {
    const int filas = 4;
    const int cols = 4;
    int matriz[filas][MAX_COLS];

    if (!validar_dimensiones(filas, cols)) return;

    // Llenar manualmente
    llenar_matriz_manual(filas, cols, matriz);

    // Imprimir matriz final
    printf("Ejercicio 2: Matriz %dx%d ingresada por usuario\n", filas, cols);
    imprimir_matriz(filas, cols, matriz);
    printf("\n");
}

/* Pruebas con casos extremos: 1x1, grandes y negativos */
void prueba_extremos(void) {
    printf("Prueba extremo: 1x1\n");
    const int f1 = 1, c1 = 1;
    int m1[f1][MAX_COLS];
    inicializar_matriz(f1, c1, m1);
    m1[0][0] = -7; // valor negativo para validar manejo
    imprimir_matriz(f1, c1, m1);
    printf("\n");

    printf("Prueba extremo: matriz grande (10x10) con valores iniciales\n");
    const int f2 = 10, c2 = 10;
    int m2[f2][MAX_COLS];
    inicializar_matriz(f2, c2, m2);
    // rellenar un patrón sencillo para lectura
    for (int i = 0; i < f2; ++i) {
        for (int j = 0; j < c2; ++j) {
            m2[i][j] = i * c2 + j;
        }
    }
    imprimir_matriz(f2, c2, m2);
    printf("\n");

    printf("Prueba extremo: entradas negativas y positivas\n");
    const int f3 = 3, c3 = 4;
    int m3[f3][MAX_COLS];
    if (!validar_dimensiones(f3, c3)) return;
    // llenar con una combinación de valores
    int counter = -5;
    for (int i = 0; i < f3; ++i) {
        for (int j = 0; j < c3; ++j) {
            m3[i][j] = counter;
            counter += 3;
        }
    }
    imprimir_matriz(f3, c3, m3);
    printf("\n");
}