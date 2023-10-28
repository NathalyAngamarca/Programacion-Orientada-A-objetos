/**
 * @file informeventas.c
 * @author Nathaly Silvana Angamarca Angamarca 
 * @brief Emitir un informe de una Empresa
 * @version 0.1
 * @date 2023-08-25
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#define MESES 12

void ingresarVentas(int ventas[MESES]);
int calcularTotalVentas(int ventas[MESES]);
int calcularPromedioVentas(int ventas[MESES]);
void encontrarMesVentasAltasYBajas(int ventas[MESES], int *mesVentasAltas, int *mesVentasBajas);
int proyectarVentasSiguienteAnio(int ventas[MESES]);
void imprimirInformeVentas(int ventas[MESES], int anio);

int main(int argc, char const *argv[])
{
    int ventas[MESES];
    int anio;
    printf("\t\t \033[92mBIENVENIDO A NUESTRO PROGRAMA!!! \033[0m\t\t\n");
    printf("--------------------------------------------------------\n");
    printf("Ingrese el anio del informe: ");
    scanf("%d", &anio);
    printf("\n");
    ingresarVentas(ventas);
    imprimirInformeVentas(ventas, anio);
    printf("========================================================\n");
    printf("\033[93m DESARROLLADO POR: Nathaly Silvana Angamarca \033[0m");
    return 0;
}

void ingresarVentas(int ventas[MESES])
{
    for (int mes = 0; mes < MESES; mes++)
    {
        printf("Ingrese el total de ventas del mes %d: $", mes + 1);
        scanf("%d", &ventas[mes]);
    }
}

int calcularTotalVentas(int ventas[MESES])
{
    int total = 0;
    for (int mes = 0; mes < MESES; mes++)
    {
        total += ventas[mes];
    }
    return total;
}

int calcularPromedioVentas(int ventas[MESES])
{
    int total = calcularTotalVentas(ventas);
    return total / MESES;
}

void encontrarMesVentasAltasYBajas(int ventas[MESES], int *mesVentasAltas, int *mesVentasBajas)
{
    int maximo = ventas[0];
    int minimo = ventas[0];
    *mesVentasAltas = 0;
    *mesVentasBajas = 0;

    for (int mes = 1; mes < MESES; mes++)
    {
        if (ventas[mes] > maximo)
        {
            maximo = ventas[mes];
            *mesVentasAltas = mes;
        }
        if (ventas[mes] < minimo)
        {
            minimo = ventas[mes];
            *mesVentasBajas = mes;
        }
    }
}

int proyectarVentasSiguienteAnio(int ventas[MESES])
{
    int total = calcularTotalVentas(ventas);
    return total * 1.1;
}

void imprimirInformeVentas(int ventas[MESES], int anio)
{
     printf("\n");
    printf("========================================================\n");
    printf("\033[91m \t INFORME DE VENTAS DEL ANIO %d:\033[0m\n", anio);
    printf("========================================================\n");
    for (int mes = 0; mes < MESES; mes++)
    {
        printf("Ventas del mes %d: $%d\n", mes + 1, ventas[mes]);
    }
    int totalVentas = calcularTotalVentas(ventas);
    printf("========================================================\n");
    printf("Total de ventas del anio: $%d\n", totalVentas);
    printf("========================================================\n");
    int promedioVentas = calcularPromedioVentas(ventas);
    printf("Promedio de ventas del anio: $%d\n", promedioVentas);
    printf("========================================================\n");
    int mesVentasAltas, mesVentasBajas;
    encontrarMesVentasAltasYBajas(ventas, &mesVentasAltas, &mesVentasBajas);
    printf("Mes con ventas mas altas: %d (ventas: $%d)\n", mesVentasAltas + 1, ventas[mesVentasAltas]);
    printf("========================================================\n");
    printf("Mes con ventas mas bajas: %d (ventas: $%d)\n", mesVentasBajas + 1, ventas[mesVentasBajas]);
    printf("========================================================\n");
    int ventasProyectadas = proyectarVentasSiguienteAnio(ventas);
    printf("Proyeccion de ventas para el proximo anio: $%d\n", ventasProyectadas);
}
