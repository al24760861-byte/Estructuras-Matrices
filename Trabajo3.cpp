#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLS 4

// Prototipos
void validar_dimensiones(int f, int c);
void inicializar_matriz(int filas, int columnas, int matriz[][COLS]);
void imprimir_matriz(int filas, int columnas, int matriz[][COLS]);
void llenar_matriz_aleatoria(int filas, int columnas, int matriz[][COLS]);
void contar_pares_impares(int filas, int columnas, int matriz[][COLS], int *pares, int *impares);
void ejecutar_ejercicio3(void);

int main(void) {
    // Ejecutar el ejercicio 3
    ejecutar_ejercicio3();
    return 0;
}

// Valida dimensiones básicas (solo como guardado de buenas prácticas)
void validar_dimensiones(int f, int c) {
    if (f <= 0 || c <= 0) {
        fprintf(stderr, "Error: dimensiones deben ser > 0.\n");
        exit(EXIT_FAILURE);
    }
    if (f != FILAS || c != COLS) {
        // En este ejemplo específico mantenemos 4x4 para el ejercicio.
        // Puedes adaptar para aceptar dinámico si lo deseas.
        fprintf(stderr, "Advertencia: se espera una matriz %dx%d. Se seguirá usando %dx%d.\n", COLS, COLS, f, c);
        // No salimos; solo advertimos.
    }
}

// Inicializa la matriz con ceros (opcional antes de llenarla)
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
    // Asegurar semilla solo una vez
    // En este diseño, la semilla se inicializa en la función de ejecución
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 10; // 0..9
        }
    }
}

// Cuenta pares e impares en la matriz
void contar_pares_impares(int filas, int columnas, int matriz[][COLS], int *pares, int *impares) {
    *pares = 0;
    *impares = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] % 2 == 0) (*pares)++;
            else (*impares)++;
        }
    }
}

// Ejercicio 3: implementación completa
void ejecutar_ejercicio3(void) {
    int matriz[FILAS][COLS];

    // Validar dimensiones (opcional en este caso)
    validar_dimensiones(FILAS, COLS);

    // Inicializar ya que trabajaremos con una matriz fija
    inicializar_matriz(FILAS, COLS, matriz);

    // Inicializar semilla
    srand((unsigned int)time(NULL));

    // Llenar de forma aleatoria (0..9)
    llenar_matriz_aleatoria(FILAS, COLS, matriz);

    // Imprimir la matriz
    printf("Matriz 4x4 llena con valores aleatorios (0..9):\n");
    imprimir_matriz(FILAS, COLS, matriz);
    printf("\n");

    // Contar pares e impares
    int pares = 0, impares = 0;
    contar_pares_impares(FILAS, COLS, matriz, &pares, &impares);

    // Mostrar conteos
    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);
}