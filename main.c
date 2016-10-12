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
    printf("\n\t\t****************************************\n"
             "\t\t*** ESTRUCTURA DE DATOS Y ALGORITMOS ***\n"
             "\t\t****************************************\n");
}

// -- MENU ADMINISTRACION
void administracion()
{
    limpiar_contadores();

    while (opcion !=0)
    {
        encabezado();
        printf("\n\t\t      Administracion de estructuras      \n"
                 "\t\t      -----------------------------      \n"
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


    encabezado();
    printf("\t\t       Comparacion de estructuras       \n"
           "\t\t       --------------------------       \n");
    lectura_archivo_operaciones();

    encabezado();
    printf("\t\t       Comparacion de estructuras       \n"
           "\t\t\tTotal de Articulos: %d\n"
           "\t\t       --------------------------       \n"

           "\n Cant. de Altas:\t\tABB: %d \tLI: %d "
           "\n Cant. de Bajas:\t\tABB: %d \tLI: %d "
           "\n Cant. de Evocaciones-Exito:\tABB: %d \tLI: 0 "
           "\n Cant. de Evocaciones-Fracaso:\tABB: %d \tLI: 0\n"
           ,cant_ABB,altas_abb,altas_LI,bajas_abb,bajas_LI,evoE_abb,evoF_abb

           );

    printf("\n Costos de Altas:"
           "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%.2f"
           "\n LI:\t0\t\t0"
           ,alta_nCorr_abb/(float)altas_abb,alta_MCorr_abb

           );
    printf("\n\n Costos de Bajas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%.2f"
           "\n LI:\t.2f\t\t0"
           ,baja_nCorr_abb/(float)bajas_abb,baja_MCorr_abb

           );

    printf("\n\n Costos de Evocaciones Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%d"
           "\n LI:\t.2f\t\td"
           ,(float)nodosConsE_abb/(float)evoE_abb,Max_EvoE_abb

           );
    printf("\n\n Costos de Evocaciones NO Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%d"
           "\n LI:\t.2f\t\td \n"
           ,(float)nodosConsF_abb/(float)evoF_abb,Max_EvoF_abb

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
