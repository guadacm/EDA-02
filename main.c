/* -- Grupo 5: Medina, Guadalupe
 *             Montenegro, Luis
 *
 * -- Estructura elegida:
 *
 * -- Funciones de costos:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "ABB.h"
#include "LI.h"


int opcion = -1;

void encabezado()
{
    system("cls");
    printf("\n\t****************************************\n"
             "\t*** ESTRUCTURA DE DATOS Y ALGORITMOS ***\n"
             "\t****************************************\n");
}

// -- MENU ADMINISTRACION
void administracion()
{
    while (opcion !=0)
    {
        encabezado();
        printf("\n\t      Administracion de estructuras      \n"
                 "\t      -----------------------------      \n"
                "\n[1] Arbol Binario de Busqueda (A.B.B.)"
                "\n[2] Lista Invertida (L.I.)"
                "\n\n[0] Volver\n"
                "\nElija una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 0: break;
            case 1: menu_ABB(&opcion); break;
            case 2: menu_LI(&opcion); break;
        }
    }
    opcion = -1;
}

// -- MENU COMPARACION
void comparacion()
{
    limpiar_contadores();
    ABB = NULL;
    cant_ABB = 0;


    encabezado();
    printf("\t       Comparacion de estructuras       \n"
           "\t       --------------------------       \n");
    lectura_archivo_operaciones();

    encabezado();
    printf("\t       Comparacion de estructuras       \n"
           "\t\tTotal de Articulos: %d\n"
           "\t       --------------------------       \n"

           "\nCant. de Altas:\t\t\tABB: %d \tLI: 0 "
           "\nCant. de Bajas:\t\t\tABB: %d \tLI: 0 "
           "\nCant. de Evocaciones-Exito:\tABB: %d \tLI: 0 "
           "\nCant. de Evocaciones-Fracaso:\tABB: %d \tLI: 0\n"
           ,cant_ABB,altas_abb,bajas_abb,evoE_abb,evoF_abb
           );

    printf("\nCostos de Altas"
           "\n---------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nABB:\t0\t\t0"
           "\nLI:\t0\t\t0"


           );
    printf("\n\nCostos de Bajas"
             "\n---------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nABB:\t.2f\t\t0"
           "\nLI:\t.2f\t\t0"

           );

    printf("\n\nCostos de Evocaciones Exitosas"
             "\n------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nABB:\t.2f\t\td"
           "\nLI:\t.2f\t\td"

           );
    printf("\n\nCostos de Evocaciones NO Exitosas"
             "\n---------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\nABB:\t.2f\t\td"
           "\nLI:\t.2f\t\td"

           );
    system("pause");
}

// -- MENU PRINCIPAL
void principal()
{
    encabezado();
    printf("\n[1] Administracion de estructuras");
    printf("\n[2] Comparacion de estructuras");
    printf("\n\n[0] Salir\n");
    printf("\nElija una opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
        case 0: break;
        case 1: administracion(); break;
        case 2: comparacion(); break;
    }
}

int main()
{

// -- MENU PRINCIPAL
    while (opcion != 0)
    {
        principal(&opcion);
    }
    return 0;
}
