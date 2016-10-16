/* Funciones para Arbol Binario de Busqueda */
#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED


char c[8];
Articulo temp;
int celda;

void menu_ABB(int *op)
{
    cant_ABB = 0;

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
            if(alta_ABB(nuevo) == 1) printf("\n El articulo fue agregado con exito\n\n");
            else printf("\nError, el codigo %s ya existe \n\n",nuevo.codigo);
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
            if(baja_ABB(c,0)==1) printf("\nEl articulo %s fue eliminado con exito\n\n",c);
            else printf("\nEl articulo %s no fue eliminado o no existe\n\n",c);
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
            temp=evocar_ABB(c,&aux);
            if (aux==1)
            {
                imprimirArt(temp);
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
                encabezado();
                j=1;
                printf("Opciones de Mostrar Estructura del ABB: \n");
                printf("_________________________\n");
                printf("\n [1] Orden sugerido de Practico.");
                printf("\n [2] Orden sugerido de Practico (Dibujado solo codigos).");
                printf("\n [3] InOrden.");
                printf("\n [4] PreOrden.");
                printf("\n [5] PostOrden.");
                printf("\n\n Elija una Opcion: ");
                fflush(stdin);
                scanf("%d",&ord);
                encabezado();
                printf("\n-------------------------- LISTA DE ARTICULOS --------------------------\n");
                switch(ord){
                    case 1:
                        printf("     \t\t(Recorrido como lo sugiere el Practico)");
                        mostrarArbol(ABB);
                        break;

                    case 2:
                        printf("\t Recorrido como lo sugiere el Practico (Dibujado)\n");
                        mostrarArbolDibujado(ABB);
                        break;

                    case 3:
                        printf("\t\t(Recorrido IN-ORDEN)\n");
                        InOrden(ABB);
                        break;

                    case 4:
                        printf("\t\t(Recorrido PRE-ORDEN)\n");
                        PreOrden(ABB);
                        break;

                    case 5:
                        printf("\t\t(Recorrido POST-ORDEN)\n");
                        PostOrden(ABB);
                        break;
                    }
            }
            printf("\n\tTotal de Articulos: %d\n",cant_ABB);
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

int localizar_ABB(char codArt[],Arbol *padre, Arbol *actual, int ConCosto)
{
    if (ConCosto == 1) consultados_abb = 0;
    *padre = NULL;
    *actual = ABB;

    while(((*actual)!= NULL) && (strcmp(codArt,(*actual)->a.codigo)!=0))
    {
        *padre = *actual;
        if(strcmp(codArt,(*actual)->a.codigo)== -1 ) {
                (*actual) = (*actual)->izq;
                if (ConCosto == 1) consultados_abb++;
        }
        else if(strcmp(codArt,(*actual)->a.codigo)==1) {
                (*actual) = (*actual)->der;
                if (ConCosto == 1) consultados_abb++;
        }
    }
    if((*actual)!=NULL) {
        if (ConCosto == 1) consultados_abb++;
        return 1; //Si se encontro el articulo, no hace nada y sale de la funcion
        }
    else return 0; //Si no se encontro el articulo devuelve 0, y los punteros en donde quedaron
}

int alta_ABB(Articulo dat)
{
    int exito;
    Arbol padre = NULL;
    Arbol actual = ABB;
    if (cant_ABB >= 170 ) return 0;
    exito=localizar_ABB(dat.codigo,&padre,&actual,0); //Uso LOCALIZAR para buscar el codigo del articulo en la estructura.
    if ( (exito == 1) || (malloc(sizeof(aNodo))==NULL) ) return 0; //localizar devolvio true, por lo tanto no se hace el alta.
    else //localizar devolvio false, se procede a realizar el alta.
    {
        cant_ABB++;
        altas_abb++;
        // Si padre es NULL, entonces el arbol estaba vacio, el nuevo nodo sera la raiz
        if((padre)==NULL)
        {
            ABB = (Arbol)malloc(sizeof(aNodo));
            (ABB)->a = dat;
            (ABB)->izq = (ABB)->der = NULL;
            alta_nCorr_abb += 0.5;
            if (alta_MCorr_abb < 0.5) alta_MCorr_abb = 0.5;
            return 1;
        }
        // Si el articulo.codigo es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda
        else if( (strcmp(dat.codigo,padre->a.codigo)) < 0 )
        {
            actual = (Arbol)malloc(sizeof(aNodo));
            padre->izq = actual;
            actual->a = dat;
            actual->izq = actual->der = NULL;
            alta_nCorr_abb += 0.5;
            if (alta_MCorr_abb < 0.5) alta_MCorr_abb = 0.5;
            return 1;
        }
        // Si el articulo.codigo es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha
        else if( (strcmp(dat.codigo,padre->a.codigo)) > 0 )
        {
            actual = (Arbol)malloc(sizeof(aNodo));
            padre->der = actual;
            actual->a = dat;
            actual->izq = actual->der = NULL;
            alta_nCorr_abb += 0.5;
            if (alta_MCorr_abb < 0.5) alta_MCorr_abb = 0.5;
            return 1;
        }
    }
}

int baja_ABB(char codArt[], int tipo)
{
    Arbol padre,pa;
    Arbol actual,ac;
    Arbol temp;
    char c = 'S';
    int exito,n;
    exito=localizar_ABB(codArt,&padre,&actual,0);
    if (exito==0) return 0;
    else
    {
        //if(ABB == NULL) return 0; //significa que el arbol esta vacio, no se hacen bajaas (no es necsario, ya que localizar seria 1 antes de aca)
        if(tipo == 0) c = confirmacion_baja(actual->a);
        if(c == 'N' || c == 'n' ) return 0;

        if ((ABB->izq == NULL) && (ABB->der == NULL)) // significa q solo hay un nodo en el arbol, por lo tanto lo inicializo directamente
        {
            ABB=NULL;
            free(actual);
            baja_nCorr_abb += 0.5;
            if (baja_MCorr_abb < 0.5) baja_MCorr_abb = 0.5;
            //printf("\nCaso 1\n");
        }

        else if ((actual->izq !=NULL) && (actual->der != NULL))     //El nodo (o Raiz) a eliminar tiene dos hijos
        {
            temp=menorDeMayores(actual);                    //Busco el menor de mayores para reemplazar "actual", coloco en temp el menorDeMayores
            localizar_ABB(temp->a.codigo,&pa,&ac,0);        //Localizo "temp" para ubicar a su padre
            actual->a = temp->a;                            //sobreescribo la informacion del nodo en cuestion a dar de baja, por la del menorDeMayores
            if (strcmp(ac->a.codigo,pa->a.codigo)<0)        //cuando su hijo derecho no es el menorDeMayores
                (pa->izq) = ac->der;
            if (strcmp(ac->a.codigo,pa->a.codigo)>=0)       // cuando su hijo derecho es el menorDeMayores
                (pa->der) = ac->der;
            free(temp);
            baja_nCorr_abb += 1.5;
            if (baja_MCorr_abb < 1.5) baja_MCorr_abb = 1.5;
            //printf("\nCaso 2\n");
        }
        else if ( (actual->izq != NULL) && (actual->der == NULL)) //el nodo a eliminar tiene un hijo izquierdo
        {
            if (padre==NULL) //quiero eliminar la raiz sin hijo derecho
            {
                ABB=actual->izq;
                free(actual);
                baja_nCorr_abb += 0.5;
                if (baja_MCorr_abb < 0.5) baja_MCorr_abb = 0.5;
            }
            else {
            if (strcmp(actual->a.codigo,padre->a.codigo)<0)
                padre->izq = actual->izq;
            if (strcmp(actual->a.codigo,padre->a.codigo)>0)
                padre->der = actual->izq;
            free(actual);
            baja_nCorr_abb += 0.5;
            if (baja_MCorr_abb < 0.5) baja_MCorr_abb = 0.5;
            }
            //printf("\nCaso 3\n");
        }
        else if ( (actual->izq == NULL) && (actual->der != NULL)) //el nodo a eliminar tiene un hijo derecho
        {
            if (padre==NULL) //quiero eliminar la raiz sin hijo izquierdo
            {
                ABB=actual->der;
                free(actual);
                baja_nCorr_abb += 0.5;
                if (baja_MCorr_abb < 0.5) baja_MCorr_abb = 0.5;
            }
            else{
            if (strcmp(actual->a.codigo,padre->a.codigo)<0)
                padre->izq = actual->der;
            if (strcmp(actual->a.codigo,padre->a.codigo)>0)
                padre->der = actual->der;
            free(actual);
            baja_nCorr_abb += 0.5;
            if (baja_MCorr_abb < 0.5) baja_MCorr_abb = 0.5;
            }
            //printf("\nCaso 4\n");
        }
        else if (esHoja(actual))
        {
            if (strcmp(actual->a.codigo,padre->a.codigo)<0) //es descendiente izquierdo
                padre->izq = NULL;
            if (strcmp(actual->a.codigo,padre->a.codigo)>0) //es descendiente derecho
                padre->der = NULL;
            free(actual);
            baja_nCorr_abb += 0.5;
            if (baja_MCorr_abb < 0.5) baja_MCorr_abb = 0.5;
            //printf("\nCaso 5\n");
        }
    }
    cant_ABB--;
    bajas_abb++;
    return 1;
}


void mostrarArbol(Arbol r)
{
    if (r !=NULL )
    {
        printf("\n__________________________________________\n");
        printf("\n============= PADRE: ============= ");
            //printf("\nDire Puntero %p",r);
            imprimirArt(r->a);

        printf("\n============ HIJO IZQ ============ ");
        if(r->izq == NULL) printf("\nVacio.");
        else
        {
            //printf("\nDire Puntero %p",r->izq);
            imprimirArt(r->izq->a);

        }
        printf("\n============ HIJO DER ============ ");
        if (r->der == NULL) printf("\nVacio.\n");
        else
        {
            //printf("\nDire Puntero %p",r->der);
            imprimirArt(r->der->a);

        }
        if ((j % 5) == 0){system("\n pause");}j++;  //Limitador de articulos a mostrar
        mostrarArbol(r->izq);
        mostrarArbol(r->der);
    }
}


void mostrarArbolDibujado(Arbol r)
{
    if (r != NULL )
    {
        printf("\n______________________________________________________________\n");
        printf("\t\t\tPADRE:");
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
            printf("\n   Codigo: %s",r->izq->a.codigo);
        }
        printf("\n\t\t\t\t\tHIJO DERERCHO:");
        if (r->der == NULL) printf("\n\t\t\t\t\tVacio.\n");
        else
        {
            printf("\n\t\t\t\t\tCodigo: %s\n",r->der->a.codigo);
        }
        if ((j % 5) == 0){system("\n pause");}j++;  //Limitador de articulos a mostrar
        mostrarArbolDibujado(r->izq);
        mostrarArbolDibujado(r->der);
    }
}


void InOrden(Arbol r)  // INORDEN
{
    if (r != NULL)
    {
        InOrden (r->izq);
        imprimirArt(r->a);
        if ((j % 5) == 0){system("\n pause");}j++;  //Limitador de articulos a mostrar
        InOrden (r->der);
    }
}

void PreOrden(Arbol r)  // PREORDEN
{
    if (r != NULL)
    {
        imprimirArt(r->a);
        if ((j % 5) == 0){system("\n pause");}j++;  //Limitador de articulos a mostrar
        PreOrden (r->izq);
        PreOrden (r->der);
    }
}

void PostOrden(Arbol r)  // POSTORDEN
{
    if (r != NULL)
    {
        PostOrden (r->izq);
        PostOrden (r->der);
        imprimirArt(r->a);
        if ((j % 5) == 0){system("\n pause");}j++;  //Limitador de articulos a mostrar
    }
}

int esHoja(Arbol r) //Si un articulo (nodo) es hoja devuelve 1
{
    return ((r->der == NULL) && (r->izq == NULL));
}

Arbol buscarMinimo(Arbol p)
{
    while((p)!=NULL)
    {
        if((p)->izq==NULL) return (p);
        else (p)=(p)->izq;
    }
    return p;
}

Arbol menorDeMayores(Arbol p)
{
    if((p)==NULL) return p;
    if((p)->der==NULL) return NULL;
    return buscarMinimo ((p)->der);
}

Articulo evocar_ABB(char codArt[],int *exito){
    Arbol padre,actual;
    Articulo temp;
    (*exito)=localizar_ABB(codArt,&padre,&actual,1);
    if (*exito == 1){
        evoE_abb++;
        nodosConsE_abb += consultados_abb;
        if (Max_EvoE_abb < consultados_abb) Max_EvoE_abb=consultados_abb;
        return actual->a;
    }
    else {
        evoF_abb++;
        nodosConsF_abb += consultados_abb;
        if (Max_EvoF_abb < consultados_abb) Max_EvoF_abb=consultados_abb;
        return temp;
    }
}


#endif // ABB_H_INCLUDED
