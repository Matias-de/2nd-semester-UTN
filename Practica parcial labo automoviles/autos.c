#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#define MAXDIM 30



//1) nodoAuto * crearNodo (automovil auto).
//Crea un nodo de tipo nodoAuto *.

automovil crearUnAuto ()
{
    automovil aux;
    puts("-------------------------------------------------------------\n");
    puts("Ingrese la marca del automovil:");
    fflush(stdin);
    gets(aux.marca);
    puts("Ingrese la patente del vehiculo(6):");
    fflush(stdin);
    gets(aux.patente);
    puts("Ingrese el valor del vehiculo:");
    fflush(stdin);
    scanf("%i",&aux.valor);
    puts("-------------------------------------------------------------\n");

  return aux;

}

nodoAuto* inicLista()
{
    return NULL;
}



nodoAuto* crearNodoAuto(automovil aux)
{
    nodoAuto* autito= (nodoAuto*)malloc(sizeof(nodoAuto));
    autito->dato=aux;
    autito->siguiente=NULL;


return autito;
}



void mostrarUnAuto(automovil aux)
{
    puts("------------------------------------------");
    printf("MARCA: %s\n", aux.marca);
    printf("PATENTE: %s\n", aux.patente);
    printf("VALOR: %i\n", aux.valor);
    puts("------------------------------------------");
}

void mostrarUnNodo(nodoAuto* aux)
{
    mostrarUnAuto(aux->dato);
}

void mostrarNodoAutos(nodoAuto* autitos)
{
    nodoAuto* aux=autitos;
    while (aux!=NULL)
    {
        mostrarUnNodo(aux);
        aux=aux->siguiente;
    }

}

//2) void agregarFinal(nodoAuto * * lista, nodoAuto * nuevo).
//Agrega un nuevo nodo al final de la lista (utilizando puntero doble)

nodoAuto* buscarUltimo (nodoAuto* autitos)
{
    nodoAuto* seg= autitos;
    while(seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }

    return seg;
}


void agregarFinal(nodoAuto * * lista, nodoAuto * nuevo)
{
    if(*lista==NULL)
    {
        *lista=nuevo;
    }else
    {
        nodoAuto*  ultimo=buscarUltimo(*lista);
        ultimo->siguiente=nuevo;

    }

}

//3) int insertarCelda(automovil A [ ], int dim, automovil dato, int validos).
//Inserta el nuevo automóvil en el arreglo, de manera de conservarlo ordenado por valor en forma creciente.
//válidos es la cantidad de datos que tiene el arreglo y retorna validos+1. Al inicio validos vale 0.

int insertarCelda(automovil arreglo[MAXDIM], automovil dato, int validos)
{
    if (validos<MAXDIM)
    {
    int i=validos-1;

    while(i>=0 && arreglo[i].valor>dato.valor)
    {
        arreglo[i+1]=arreglo[i];
        i--;
    }
    arreglo[i+1]=dato;
    validos++;
    }



    return validos;
}


//5) int pasar(nodoAuto * lista, automovil A[ ], int dim).
//Esta función pasa el contenido de la lista al arreglo A, de forma de crear un arreglo ordenado.
//Para ello debe recorrer la lista e insertar los datos al arreglo usando la función 3.

int pasar(nodoAuto * listaAutos, automovil arreglo[])
{
    int validos=0;
    while(listaAutos!=NULL)
    {
        validos=insertarCelda(arreglo, listaAutos->dato, validos);
        listaAutos=listaAutos->siguiente;
    }

    return validos;
}






//4) void agregarMuchos(nodoAuto * * lista).
//Esta función pide al usuario el ingreso de los datos de un automovil,
///crea un nodo y lo agrega al final de la lista (invocando a la función 2).


void agregarMuchos(nodoAuto ** lista)
{
    char op='S';
    do
    {
    agregarFinal(lista, crearNodoAuto(crearUnAuto()));
    puts("\nDesea continuar?(s/n)");
    fflush(stdin);
    scanf("%c", &op);
    }while (op=='s' || op=='S');


}

//6) void mostrarArregloRecursivo(automovil A[ ], int i, int pos).
//Muestra el arreglo en forma recursiva, desde la posición cero hasta la posición pos.
// El parámetro i representa la posición actual del arreglo a mostrar.


void mostrarArreglo (automovil arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        mostrarUnAuto(arreglo[i]);
    }


}
void mostrarArregloRecursivo(automovil arreglo[], int i, int pos)
{
    if (i<pos)
    {
        mostrarUnAuto(arreglo[i]);
        mostrarArregloRecursivo(arreglo, i+1, pos);
    }

}

//7) Hacer una función recursiva que sume el valor de los automóviles de la lista que tengan patente “par”.
// Además, deberá pensar una función que determine si la patente es par o no.
//(Aclaración: las patentes tienen el formato “AAA123”, piense cómo hará para evaluar si el componente numérico es par o impar).


int esPar (nodoAuto* lista)
{
    int flag=0;
    while(lista!=NULL)
    {
        if(lista->dato.patente[6] %2 ==0)
        {
            flag=1;
        }

        lista=lista->siguiente;
    }

    return flag;
}

int sumarValores (nodoAuto* lista)
{
    int suma=0;
    int flag=esPar(lista);
    if(lista!=NULL)
    {
        if(flag==1)
        {
        suma+=lista->dato.valor;
        suma+=sumarValores(lista->siguiente);
        }
    }

    return suma;
}




































































