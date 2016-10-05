#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#define DIM 170

typedef struct Articulo
{
	char codigo[8];
	char articulo[52];
	char marca[62];
	float valor;
	int cantidad;
	char club[72];
} Articulo;

/* VARIABLES */
// -- A.B.B.
typedef struct Nodo
{
    Articulo a;
    struct Nodo* izq;
    struct Nodo* der;
} aNodo;

//typedef aNodo* pNodo;
typedef aNodo* Arbol;

Arbol ABB = NULL;
int cant_ABB = 0;

// -- L.I.

/* FIN VARIABLES */


/* PROTOTIPOS */
void encabezado();
void borrar_salto(Articulo *art);

// -- A.B.B.
int localizar_ABB(char code[],Arbol *padre, Arbol *actual, int ConCosto);
int alta_ABB(Articulo);
int baja_ABB(char code[],int);
Articulo evocar_ABB(char [], int*);
Arbol menorDeMayores(Arbol p);
Arbol buscarMinimo(Arbol p);
int esHoja(Arbol r);
void mostrarArbol(Arbol r);
void mostrarArbolDibujado(Arbol r);
void InOrden(Arbol r);
void PostOrden(Arbol r);
void PreOrden(Arbol r);

// -- L.I.

/* FIN PROTOTIPOS */

void imprimirArt(Articulo Art)
{
    printf("\n Codigo: \t%s"
           "\n Articulo: \t%s"
           "\n Marca: \t%s"
           "\n Valor: \t$%.2f"
           "\n Cantidad: \t%i"
           "\n Club: \t\t%s\n",
            Art.codigo,
            Art.articulo,
            Art.marca,
            Art.valor,
            Art.cantidad,
            Art.club);
}



void memorizacion_previa(int estr) // estr: 1.ABB || 2.LI
{
    Articulo nuevo;
    FILE *fp;

    if ((fp = fopen("PruebaArticulos.txt", "r")) == NULL)
        printf("\n\nERROR: no se pudo abrir el archivo\n\n");
    else
    {
        while(!(feof(fp)))
        {
            fgets(nuevo.codigo, 8, fp);
            strupr(nuevo.codigo);
            fgets(nuevo.articulo, 52, fp);
            fgets(nuevo.marca, 62, fp);
            fscanf(fp, "%f\n", &nuevo.valor);
            fscanf(fp, "%i\n", &nuevo.cantidad);
            fgets(nuevo.club, 72, fp);
            borrar_salto(&nuevo);

            switch(estr)
            {
                case 1:
                    alta_ABB(nuevo);
                    break;
                case 2:
                    //alta_LI(nuevo);
                    break;

            }
        }
        printf("\n\nLa memorizacion se ha llevado a cabo\n\n");
    }
    fclose(fp);
}

char confirmacion_baja(Articulo baja)
{
    char c;
    printf("\n Codigo: \t%s", baja.codigo);
    printf("\n Articulo: \t%s", baja.articulo);
    printf("\n Marca: \t%s", baja.marca);
    printf("\n Valor: \t$%.2f", baja.valor);
    printf("\n Cantidad: \t%i", baja.cantidad);
    printf("\n Club: \t\t%s", baja.club);
    printf("\n\nEsta seguro que quiere eliminar este articulo? S/N: ");
    fflush(stdin);
    scanf("%c", &c);
    while (!(c=='S' || c=='s' || c=='N' || c=='n')){
        printf("\nIntente de nuevo. Solo se admiten las letras ( S - s - N - n )\n");
        fflush(stdin);
        scanf("%c", &c);
        }
    return c;
}

void borrar_salto(Articulo *art) //Borra en '\n' que almacena fgets.
{
    int i = 0;
    for (i = 0; i < 8; i++) { //Codigo
        if ((*art).codigo[i] == '\n') {
            (*art).codigo[i] = '\0';
        }
    }
    for (i = 0; i < 52; i++) { //Articulo
        if ((*art).articulo[i] == '\n') {
            (*art).articulo[i] = '\0';
        }
    }
    for (i = 0; i < 62; i++) { //Marca
        if ((*art).marca[i] == '\n') {
            (*art).marca[i] = '\0';
        }
    }
    for (i = 0; i < 72; i++) { //Club
        if ((*art).club[i] == '\n') {
            (*art).club[i] = '\0';
        }
    }
}

void lectura_archivo_operaciones()
{
    int cod_op,aux;
    Articulo nuevo;
    FILE *fp;
    if((fp = fopen("Operaciones.txt", "r")) == NULL)
        printf("\n\nERROR: No se pudo abrir el archivo\n\n");
    else
    {
        while (!(feof(fp)))
        {
            fscanf(fp, "%d\n", &cod_op);
            if ((cod_op == 1) || (cod_op == 2)) // -- (1. Alta) (2. Baja)
            {
                fgets(nuevo.codigo, 8, fp);
                fgets(nuevo.articulo, 52, fp);
                fgets(nuevo.marca, 62, fp);
                fscanf(fp, "%f\n", &nuevo.valor);
                fscanf(fp, "%i\n", &nuevo.cantidad);
                fgets(nuevo.club, 72, fp);
            }
            else
                fgets(nuevo.codigo, 8, fp);

            strupr(nuevo.codigo);
            borrar_salto(&nuevo);

            switch(cod_op)
            {
                case 1:
                    alta_ABB(nuevo);
                    break;
                case 2:
                    baja_ABB(nuevo.codigo,1);
                    break;
                case 3:
                    evocar_ABB(nuevo.codigo,&aux);
                    break;

            }
        }
        printf("\n\nLa secuencia de operaciones ha finalizado\n\n");
        fclose(fp);
    }
    system("pause");
}
#endif // ESTRUCTURAS_H_INCLUDED
