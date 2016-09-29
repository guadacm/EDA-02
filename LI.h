/* Funciones para Lista Invertida */
#ifndef LI_H_INCLUDED
#define LI_H_INCLUDED


char c[8];
Articulo temp;
int celda;

void menu_LI(int *op)
{
    //cant_LI = 0;

    while (*op != 0)
    {
        encabezado();
        printf("Lista Invertida\n");
        printf("_____________________________\n");
        printf("\n[1] Nuevo articulo");
        printf("\n[2] Eliminar articulo");
        printf("\n[3] Consultar articulo");
        printf("\n[4] Mostrar articulos");
        printf("\n[5] Memorizacion previa");
        printf("\n\n[0] Volver\n");
        printf("\nElija una opcion: ");
        scanf("%d", op);

        switch (*op)
        {
        case 0:
            break;

        case 1:
            encabezado();
            printf("Lista Invertida\n");
            printf("_________________________\n");
            printf("\n[1] Nuevo articulo");
            Articulo nuevo;
            printf("\n\n Codigo: \t");
            fflush(stdin);
            scanf("%s", nuevo.codigo);
            strupr(nuevo.codigo);
            printf(" Articulo:\t");
            fflush(stdin);
            scanf(" %[^\n]",nuevo.articulo);
            printf(" Marca:\t\t");
            fflush(stdin);
            scanf(" %[^\n]",nuevo.marca);
            printf(" Club:\t\t");
            fflush(stdin);
            scanf(" %[^\n]",nuevo.club);
            printf(" Cantidad:\t");
            fflush(stdin);
            scanf("%d",&nuevo.cantidad);
            printf(" Valor($):\t");
            fflush(stdin);
            scanf("%f",&nuevo.valor);
            //if(alta_LSD(nuevo) == 1) printf("\n Enhorabuena tio, El articulo fue agregado con exito\n\n");
            //else printf("\nYa existe ese codigo, ingresaste los datos al pe :( \n\n");
            system("pause");
            break;

        case 2:
            encabezado();
            printf("Lista Invertida\n");
            printf("_________________________\n");
            printf("\n[2] Eliminar articulo");
            printf("\n\n Codigo: \t");
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            //if(baja_LDS(c,0)==1) printf("\nEl articulo %s fue eliminado con exito\n\n",c);
            //else printf("\nEl articulo %s no fue eliminado o no existe\n\n",c);
            system("pause");
            break;

        case 3:
            encabezado();
            printf("Lista Invertida\n");
            printf("_________________________\n");
            printf("\n[3] Consultar articulo\n");
            printf("\n\n Codigo: \t");
            int aux;
            Articulo temp;
            fflush(stdin);
            scanf("%s",c);
            strupr(c);
            //temp=evocar_LSD(c,&aux);
            if (aux==1)
            {
                //imprimirArt(temp);
            }
            else printf("\n\t El articulo %s no existe\n\n",c);
            system("pause");
            break;


        case 4:
            encabezado();
            printf("Lista Invertida\n");
            printf("_________________________\n");
            printf("\n[5] Mostrar Estructura\n");
            //mostrar_LS(LSD,cant_LSD);
            system("pause");
            break;

        case 5:
            encabezado();
            printf("Lista Invertida\n");
            printf("_________________________\n");
            printf("\n[6] Memorizacion Previa\n");
            //memorizacion_previa(1);
            system("pause");
            break;
        }
    }
    *op = -1;

}

#endif // LI_H_INCLUDED
