/* Funciones para Arbol Binario de Busqueda */
#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED



char c[8];
Articulo temp;
int celda;

void menu_ABB(int *op)
{
    //cant_ABB = 0;

    while (*op != 0)
    {
        encabezado();
        printf("Arbol Binario de Busqueda\n");
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
            printf("Arbol Binario de Busqueda\n");
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
            alta_ABB(nuevo,1);

            system("pause");
            break;

        case 2:
            encabezado();
            printf("Arbol Binario de Busqueda\n");
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
            printf("Arbol Binario de Busqueda\n");
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
            int ord;
            printf("Arbol Binario de Busqueda\n");
            printf("_________________________\n");
            printf("\n[4] Mostrar Estructura\n");
            if (ABB == NULL) printf("\n\t Estructura VACIA...\n");
            if(ABB!=NULL){
                printf("\n == Opciones de Mostrar Estructura del ABB: ==");
                printf("\n\tOPCION 1) ---> Orden sugerido de Practico.");
                printf("\n\tOPCION 2) ---> Orden sugerido de Practico (Dibujado solo codigos).");
                printf("\n\tOPCION 3) ---> InOrden.");
                printf("\n\tOPCION 4) ---> PreOrden.");
                printf("\n\tOPCION 5) ---> PostOrden.\n");
                scanf("%d",&ord);
                printf("\n\t ----------LISTA DE ARTICULOS----------\n");
                switch(ord){
                    case 1:
                        printf("\t(Con Recorrido Como lo Sugiere el Practico)");
                        mostrarArbol(ABB);
                        break;

                    case 2:
                        printf("    (Con Recorrido Como lo Sugiere el Practico (Dibujado)");
                        mostrarArbolDibujado(ABB);
                        break;

                    case 3:
                        printf("\t\t(Con Recorrido IN-ORDEN)");
                        InOrden(ABB);
                        break;

                    case 4:
                        printf("\t\t(Con Recorrido PRE-ORDEN)");
                        //PreOrden(abb);
                        break;

                    case 5:
                        printf("\t\t(Con Recorrido POST-ORDEN)");
                        //PostOrden(abb);
                        break;
                    }
            }

            system("pause");
            break;

        case 5:
            encabezado();
            printf("Arbol Binario de Busqueda\n");
            printf("_________________________\n");
            printf("\n[5] Memorizacion Previa\n");
            memorizacion_previa(1);
            system("pause");
            break;
        }
    }
    *op = -1;

}

int localizar_ABB(char code[],pNodo *padre, pNodo *actual, int ConCosto)
{
    *padre = NULL;
    *actual = ABB;

    while(((*actual)!= NULL) && (strcmp(code,(*actual)->a.codigo)!=0))
    {
        *padre = *actual;
        if(strcmp(code,(*actual)->a.codigo)== -1 ) (*actual) = (*actual)->izq;
        else if(strcmp(code,(*actual)->a.codigo)==1) (*actual) = (*actual)->der;
    }
    if((*actual)!=NULL) return 1; //Si se encontro el empleado, no hace nada y sale de la funcion
    else return 0; //Si no se encontro el empleado devuelve 0, y los punteros en donde quedaron
}

int alta_ABB(Articulo dat, int tipo) //Entrada por teclado (1) //Entrada por archivo (0)
{
    int exito;
    pNodo padre = NULL;
    pNodo actual = ABB;
    exito=localizar_ABB(strupr(dat.codigo),&padre,&actual,0); //Uso LOCALIZAR para buscar el codigo del empleado en la estructura.
    printf("\n\t exito: %d \n",exito);
    if (tipo==1 && exito==0)
    {
        strcpy(dat.articulo,"Pantalon");
        strcpy(dat.marca,"Adidas Arg.");
        strcpy(dat.club,"Boca Js");
        strcpy(dat.codigo,"AAA111");
        dat.cantidad = 102;
        dat.valor = 789.96;
    }
    if ( (exito == 1) || (malloc(sizeof(aNodo))==NULL) ) return 0; //localizar devolvio true, por lo tanto no se hace el alta.
    else //localizar devolvio false, se procede a realizar el alta.
    {
        // Si padre es NULL, entonces el arbol estaba vacio, el nuevo nodo sera la raiz
        if((padre)==NULL)
        {
            ABB = (Arbol)malloc(sizeof(aNodo));
            (ABB)->a = dat;
            (ABB)->izq = (ABB)->der = NULL;
            return 1;
        }
        // Si el articulo.codigo es menor que el que contiene el nodo padre, lo insertamosen la rama izquierda
        else if( (strcmp(dat.codigo,padre->a.codigo)) < 0 )
        {
            actual = (Arbol)malloc(sizeof(aNodo));
            padre->izq = actual;
            actual->a = dat;
            actual->izq = actual->der = NULL;
            return 1;
        }
        // Si el articulo.codigo es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha
        else if( (strcmp(dat.codigo,padre->a.codigo)) > 0 )
        {
            actual = (Arbol)malloc(sizeof(aNodo));
            padre->der = actual;
            actual->a = dat;
            actual->izq = actual->der = NULL;
            return 1;
        }
    }

}


void mostrarArbol(Arbol r)
{
    if (r !=NULL )
    {
        printf("\n\n-----------------------------------------\n");
        printf("\n=== PADRE: === ");
        //printf("\nDire Puntero %p",r);
            printf("\n Codigo: \t%s",r->a.codigo);
            printf("\n Articulo: \t%s",r->a.articulo);
            printf("\n Marca: \t%s",r->a.marca);
            printf("\n Club: \t\t%s",r->a.club);
            printf("\n Cantidad: \t%d",r->a.cantidad);
            printf("\n Valor: \t$%.2f",r->a.valor);
        printf("\n== HIJO IZQ == ");
        if(r->izq == NULL) printf("\nVacio.\n");
        else
        {
            //printf("\nDire Puntero %p",r->izq);
            printf("\n Codigo: \t%s",r->izq->a.codigo);
            printf("\n Articulo: \t%s",r->izq->a.articulo);
            printf("\n Marca: \t%s",r->izq->a.marca);
            printf("\n Club: \t\t%s",r->izq->a.club);
            printf("\n Cantidad: \t%d",r->izq->a.cantidad);
            printf("\n Valor: \t$%.2f",r->izq->a.valor);
        }
        printf("\n== HIJO DER == ");
        if (r->der == NULL) printf("\nVacio.\n");
        else
        {
            //printf("\nDire Puntero %p",r->der);
            printf("\n Codigo: \t%s",r->der->a.codigo);
            printf("\n Articulo: \t%s",r->der->a.articulo);
            printf("\n Marca: \t%s",r->der->a.marca);
            printf("\n Club: \t\t%s",r->der->a.club);
            printf("\n Cantidad: \t%d",r->der->a.cantidad);
            printf("\n Valor: \t$%.2f",r->der->a.valor);
        }
        mostrarArbol(r->izq);
        mostrarArbol(r->der);
    }
}


void mostrarArbolDibujado(Arbol r)
{
    if (r != NULL )
    {
        printf("\n--------------------------------------------------------\n");
        printf("\t\t\tPADRE:");
        //printf("\n\t\t\tValor: %f", r->a.valor);
        printf("\n\t\t\tCodigo: %s\n",r->a.codigo);
        printf("\t\t     /\t\t\t\\ \n");
        printf("\t\t    /\t\t\t \\ \n");
        printf("\t\t   /\t\t\t  \\ \n");
        printf("\t\t  /\t\t\t   \\ \n");
        printf("\t\t /\t\t\t    \\ \n");
        printf("\t\t/\t\t\t     \\ \n");
        printf("   HIJO IZQUIERDO:\t\t\t      \\");
        if(r->izq == NULL) printf("\n   Vacio.");
        else
        {
            //printf("\nValor: %f", r->izq->a.valor);
            printf("\n   Codigo: %s",r->izq->a.codigo);
        }
        printf("\n\t\t\t\t\tHIJO DERERCHO:");
        if (r->der == NULL) printf("\n\t\t\t\t\tVacio.\n");
        else
        {
            //printf("\n\t\t\t\t\tValor: %f", r->der->a.valor);
            printf("\n\t\t\t\t\tCodigo: %s\n",r->der->a.codigo);
        }
        mostrarArbolDibujado(r->izq);
        mostrarArbolDibujado(r->der);
    }
}


void InOrden(Arbol r)  //imprime todos los codigos y valor de los empleados
{
    if (r != NULL)
    {
        InOrden (r->izq);
        //printf("\n\n== DATOS ARTICULO Codigo(%s) ==",r->a.codigo);
        //printf ("\nValor: %f", r->e.valor);
        //printf ("\nCodigo: %s",r->e.codigo);
        printf("\n Codigo: \t%s",r->a.codigo);
        printf("\n Articulo: \t%s",r->a.articulo);
        printf("\n Marca: \t%s",r->a.marca);
        printf("\n Club: \t\t%s\n",r->a.club);
        printf("\n Cantidad: \t\t%s\n",r->a.cantidad);
        printf("\n Valor: \t$%.2f",r->a.valor);
        InOrden (r->der);
    }
}

/*int pertenece_LSD (char codArt [])
{
    int exito,celda;
    strupr(codArt);
    exito=localizar_LSD(codArt,&celda,0);
    return exito;
}

int localizar_LSD(char codArt[], int *i, int conCosto)            //Localizacion Exitosa=1, noExitosa=0, i=posicion donde esta el elemento o deberia estar
{
    //strupr(codArt);
    (*i)=0;
    while((*i)<cant_LSD && (strcmp(LSD[*i].codigo,codArt)!=0))
    {
        (*i)++;
    }
    if (((*i)<cant_LSD)==1 && conCosto==1) {
            if (maximo_cons_exito_LSD < (*i)){ maximo_cons_exito_LSD = (*i); }
            celd_cons_exito_LSD+=(*i);}

    if (((*i)<cant_LSD)==0 && conCosto==1){
            if (maximo_cons_fracaso_LSD < (*i)){ maximo_cons_fracaso_LSD = (*i); }
            celd_cons_fracaso_LSD+=(*i);}

    return (*i)<cant_LSD ;
}


int alta_LSD(Articulo nuevo) 	/// return(1)=exito  //return(0)=fracaso
{
    int celda,exito;
    exito=localizar_LSD(nuevo.codigo,&celda,0);
    if (cant_LSD==DIM)
    {
        return 0;
    }
    if ( exito == 0)
    {
        LSD[celda]=nuevo;
        maximo_alta_corr_LSD+=0;
        cant_LSD++;
        cant_altas_LSD++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int baja_LSD(char codArt[], int tipo)
{
    int celda,exito;
    char c;
    strupr(codArt);
    exito=localizar_LSD(codArt,&celda,0);
    if ( exito == 1)
    {
        if(tipo == 0)
           c = confirmacion_baja(LSD[celda]);
        if(c == 'S' || c == 's' || tipo == 1 )
        {
            if (celda==cant_LSD-1)
            {

                celd_corr_baja_LSD+=0;
                cant_LSD--;
                return 1;
            }
            strcpy(LSD[celda].codigo,LSD[cant_LSD-1].codigo);
            strcpy(LSD[celda].articulo,LSD[cant_LSD-1].articulo);
            strcpy(LSD[celda].marca,LSD[cant_LSD-1].marca);
            strcpy(LSD[celda].club,LSD[cant_LSD-1].club);
            LSD[celda].cantidad=LSD[cant_LSD-1].cantidad;
            LSD[celda].valor=LSD[cant_LSD-1].valor;
            cant_LSD--;
            cant_bajas_LSD++;
            celd_corr_baja_LSD+=1;
            if (maximo_baja_corr_LSD < 1) maximo_baja_corr_LSD+=1;
            return 1; // exito dando de baja
        }
    }
    else
    {
        return 0; //fracaso dando de baja
    }

}

Articulo evocar_LSD (char codArt[],int *exito)
{
    int ex,celda;
    Articulo temp;
    strupr(codArt);
    ex=localizar_LSD(codArt,&celda,1);
    if (ex==1)
    {
        *exito=1;
        cant_consultas_exito_LSD++;
        return LSD[celda];
    }
    else
    {
        *exito=0;
        cant_consultas_fracaso_LSD++;
        return temp;
    }
}
*/


#endif // ABB_H_INCLUDED
