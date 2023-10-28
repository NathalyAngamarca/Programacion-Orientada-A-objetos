**
 * @file SumaMatrices.c
 * @author Nathaly Angamarca
 * @brief Sumar dos matrices de tipo flotante ingresadas por el ususario
 * @version 0.1
 * @date 2023-08-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
void ingresarDimension(int *filas, int *columnas);
void ingresarMatriz(int filas, int columna, float matriz[filas][columna]);
void presentarMatriz(int filas, int columnas, float matriz[filas][columnas]);
void sumar(int filas, int columnas, float matriz1[filas][columnas], float matriz2[filas][columnas], float matrizRta[filas][columnas]);

int main(int argc, char const *argv[])
{
    system("@cls|| clear");
    int filas, columnas;
    ingresarDimension(&filas, &columnas);
    float matriz1[filas][columnas];
    float matriz2[filas][columnas];

    float matrizRta[filas][columnas];
    // float **matrizRta

    ingresarMatriz(filas, columnas, matriz1);
    ingresarMatriz(filas, columnas, matriz2);
    printf("\n");
    presentarMatriz(filas, columnas, matriz1);
    printf("+\n");
    presentarMatriz(filas, columnas, matriz2);

    sumar(filas, columnas, matriz1, matriz2, matrizRta);
    printf("=\n");
    presentarMatriz(filas, columnas, matrizRta);

    return 0;
}

void ingresarDimension(int *filas, int *columnas)
{
    printf("TIP: \n");
    printf("Para sumar matrices se necesita que las matrices a sumar \n");
    printf("sean de las misma dimensio: \n");

    printf("Ingrese el numero de filas: ");
    scanf("%d", filas);
    getchar();

    printf("Ingrese el numero de columnas: ");
    scanf("%d", columnas);
    getchar();
    printf("\n");
}

void ingresarMatriz(int filas, int columnas, float matriz[filas][columnas])
{
    printf("=====================================\n");
    printf("Ingrese matriz: \n");
    int i, j;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingrese el elemento[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void presentarMatriz(int filas, int columnas, float matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}
void sumar(int filas, int columnas, float matriz1[filas][columnas], float matriz2[filas][columnas], float matrizRta[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizRta[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}
