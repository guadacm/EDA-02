/* -- Grupo 5: Medina, Guadalupe
               Montenegro, Luis

  -- Estructura elegida: Arbol Binario de Busqueda (ABB), porque si bien los costos a posteriori indican un total de 150 evocaciones y 72 altas y 13 bajas,
                         en los cuales la lista invertida mejora el costo maximo de evocacion (exitosa o no), es poca la diferencia con el maximo de evocaciones del ABB.

                         Por otra parte, el costo medio a posteriori de evocacion (exitosa o no) es levemente mejor en el ABB que en la LI. Por lo que podemos concluir
                         que los costos de evocacion del ABB y LI estan bastante parejos, las diferencias no son muy considerables

                         En ultimo lugar, el ABB Tiene una mejora enorme comparado con la LI, en cuanto a Altas y Bajas...
                         - en altas(abb) no hay corrimientos (pero si una unica modificacion de puntero), en altas(li) se producen corrimientos.
                         - en bajas(abb) el peor caso es 1.5 corrimiento, en bajas(li) se producen muchos corrimientos.

                         Por consiguiente, ABB es considerablemente mucho mejor en Altas y Bajas, y en Evocaciones, la diferencia entre ambas estructuras es minimo.


    El Siguiente cuadro indica que estructura es mejor en costos cada caso (alta,baja, evocacion) siendo la primera la mejor.

m: medio
M: máximo      _____________________ ______________________ ________________________ _______________________
              |               (m/M) |                (m/M) |                (m) (M) |               (m) (M) |
              | Altas:MEJOR--> ABB  | Bajas: MEJOR--> ABB  | EvoE: MEJOR--> ABB L.I | EvoF:MEJOR--> ABB L.I |
              |                L.I  |                 L.I  |                L.I ABB |               L.I ABB |
              |                     |                      |                        |                       |
              |_____________________|______________________|________________________|_______________________|

  -- Funciones de costos:
                         - Alta y Baja -> Cantidad de corrimientos y/o actualizacion de punteros
                         - Evocaciones -> Cantidad de celdas consultadas



 ------------------------------------------ NOTAS y ACLARACIONES: ------------------------------------------

* Utilizamos un parametro extra en la funcion Localizar de cada estructura llamado "conCosto", el cual si es 1(cuando
es llamado por evocar) voy a contar las celdas consultadas.

-- estructuras.h:
* Se encuentran definiciones de constantes, variables y estructuras.
* Tambien estan las funciones comunes a ambas estructuras (memorizacion previa, codigo operaciones, limpiar contadores, etc).

-- Arbol Binario de Busqueda -> ABB.h
* Para la opcion "mostrar estructura" (Dentro de la misma) tenemos 4 opciones, las cuales hay diferentes tipos de barridos, estan indicados por su nombre
El barrido de la primer opcion "Como lo sugiere el practico" es un barrido por niveles, muestra en el siguiente orden: Padre, H.Izq, H.Der.
* Para el calculo de los costos de ingreso y eliminacion en el ABB, cada intercambio de nupla entre celdas se cuenta como un corrimiento.
En el caso de la actualizacion de punteros, cada modificacion se cuenta como la mitad de un corrimiento.

-- Lista Invertida -> LI.h
* Al final de la lista usamos un Articulo con codigo "ZZZZZZ"(+inf) para el correcto funcionamiento de la busqueda
binaria

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
    LI[0] = malloc(sizeof(Articulo));
    strcpy(LI[0]->codigo, "ZZZZZZ"); // +inf

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
           "\n Cant. de Evocaciones-Exito:\tABB: %d \tLI: %d "
           "\n Cant. de Evocaciones-Fracaso:\tABB: %d \tLI: %d\n",
           cant_ABB,
           altas_abb, altas_LI,
           bajas_abb, bajas_LI,
           evoE_abb, evoE_LI,
           evoF_abb, evoF_LI);

    printf("\n Costos de Altas:"
           "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%.2f"
           "\n LI:\t%.2f\t\t%.2f",
           alta_nCorr_abb/(float)altas_abb,alta_MCorr_abb,
           cor_alta_LI/(float)altas_LI, max_alta_LI);

    printf("\n\n Costos de Bajas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%.2f"
           "\n LI:\t%.2f\t\t%d",
           baja_nCorr_abb/(float)bajas_abb, baja_MCorr_abb,
           cor_baja_LI/(float)bajas_LI, max_baja_LI);

    printf("\n\n Costos de Evocaciones Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%d"
           "\n LI:\t%.2f\t\t%d",
           (float)nodosConsE_abb/(float)evoE_abb, Max_EvoE_abb,
           (float)consE_LI/(float)evoE_LI, max_evoE_LI);

    printf("\n\n Costos de Evocaciones NO Exitosas:"
             "\n------------------------------------"
           "\n\tMEDIOS:\t\tMAXIMOS:"
           "\n ABB:\t%.2f\t\t%d"
           "\n LI:\t%.2f\t\t%d \n\n",
           (float)nodosConsF_abb/(float)evoF_abb,Max_EvoF_abb,
           (float)consF_LI/(float)evoF_LI, max_evoF_LI);

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
