#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


nodo * inicLista()
{
    return NULL;
}

nodo * crearUnNodo(int aux)
{

    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo * agregarAlFinal(nodo *lista, nodo * nuevoNodo)
{
    if(lista!= NULL)
    {
        nodo * ulti = buscarUltimoLista(lista);
        ulti->siguiente = nuevoNodo;

    }
    else
    {
        lista = nuevoNodo;
    }


    return lista;
}

nodo * buscarUltimoLista(nodo *lista)
{

    while(lista!= NULL && lista->siguiente != NULL)
    {
        lista = lista->siguiente;
    }
    return lista;
}

void mostrarLista(nodo * lista)
{

    if(lista != NULL)
    {
        while(lista!= NULL)
        {
            mostrarDatoEntero(lista->dato);
            lista = lista->siguiente;
        }
    }
    else
    {
        puts("Lista vacia");
    }
}

void mostrarDatoEntero(int dato)
{
    printf("Dato:|%i| \n",dato);
}

//1. Dada una lista simplemente enlazada cargada con valores enteros de manera
//ordenada (menor a mayor), eliminar los elementos que se encuentran repetidos.

nodo* borrarRepetidos (nodo* lista)
{
    nodo* principio=lista;
    if(lista!=NULL)
    {
        nodo* seg=lista;
        nodo* ante=seg;

        while(lista!=NULL)
        {
            ante=lista;
            seg=lista->siguiente;
            while(seg!=NULL)
            {
                if (lista->dato==seg->dato)
                {
                    ante->siguiente=seg->siguiente;
                    seg->siguiente=NULL;
                    free(seg);
                    seg=ante->siguiente;
                }
                else
                {
                    ante=seg;
                    seg=seg->siguiente;
                }
                // ante=ante->siguiente;

            }

            lista=lista->siguiente;
        }
    }


    return principio;
}


///2. Dadas dos listas A y B cargadas con números enteros de manera ordenada, insertar
///en una 3er lista la intersección de ambas.

//nodo* intercalarIntersecciones(nodo* lista, nodo* lista2, nodo* nuevaLista)
//{
//    nodo*principio=lista2;
//    nodo*seg;
//    nodo*ante;
//    while(lista!=NULL && lista2!=NULL)
//    {
//        if(lista->dato== lista2->dato)
//        {
//            ante=seg;
//            seg=seg->siguiente;
//            lista2=lista2->siguiente;
//            nuevaLista=seg;
//            nuevaLista->siguiente=NULL;
//            ante->siguiente=lista2;
//        }
//        else
//        {
//            seg=lista2;
//            lista2=lista2->siguiente;
//        }
//
//    }
//    lista=lista->siguiente;
//    while(principio!=NULL && lista!=NULL)
//    {
//        if(lista->dato==principio->dato)
//        {
//
//        }else
//        {
//
//        }
//    }
//                                 revisar
//
//
//
//    return nuevaLista;
//}
nodo* intercalarIntersecciones(nodo* lista, nodo* lista2)
{
    nodo* intercalada=inicLista();
    nodo*seg;
    nodo*segLista;
    while(lista2!=NULL)
    {
        segLista=lista;
        while(segLista!=NULL)
        {
            if(segLista->dato==lista2->dato)
            {
                seg=crearUnNodo(lista2->dato);
                intercalada=agregarAlFinal(intercalada, seg);

            }
            segLista=segLista->siguiente;
        }
        lista2=lista2->siguiente;
    }
    return intercalada;
}

nodoDoble* inicNodo()
{
    return NULL;
}

nodoDoble* crearNodo(examen examen)
{
    nodoDoble* aux=(nodoDoble*)malloc(sizeof(nodoDoble));
    aux->aux=examen;
    aux->siguiente=NULL;
    aux->anterior=NULL;

    return aux;
}
//typedef struct{
//int nroParcial;
//char dni[9];
//char asignatura[20];
//float Nota;
//}examen;
examen cargarUnExamen()
{
    examen aux;
    puts("---------------------------");
    puts("Ingrese el numero del parcial:");
    fflush(stdin);
    scanf("%i", &aux.nroParcial);
    puts("Ingrese el DNI del alumno que realizo el examen:");
    fflush(stdin);
    scanf("%s", aux.dni);
    puts("Ingrese la asignatura correspondiente:");
    fflush(stdin);
    gets(aux.asignatura);
    puts("Ingrese la nota:");
    fflush(stdin);
    scanf("%f", &aux.Nota);
    puts("---------------------------");
    return aux;
}

void mostrarUnExamen(examen aux)
{
    puts("\n-----------------------------------------------");
    printf("NRO DE PARCIAL: %i\n", aux.nroParcial);
    printf("DNI: %s\n", aux.dni);
    printf("ASIGNATURA: %s\n", aux.asignatura);
    printf("NOTA: %.2f\n", aux.Nota);
}

void mostrarUnNodo(nodoDoble* aux)
{
    mostrarUnExamen(aux->aux);


}

void mostrarListaDoble(nodoDoble* lista)
{
    nodoDoble* seg=lista;
    while(seg!=NULL)
    {
        mostrarUnNodo(seg);
        seg=seg->siguiente;
    }


}

//b. Declarar una lista y cargar los datos ordenados por DNI.

nodoDoble* agregarPpioPuntero (nodoDoble** lista, nodoDoble* nuevoNodo)
{
    nuevoNodo->siguiente=(*lista);
    if((*lista)!=NULL)
    {
        (*lista)->anterior=nuevoNodo;
    }
return nuevoNodo;
}
//nodoDoble* agregarPpio(nodoDoble* lista, nodoDoble* nuevoNodo)
//{
//    nuevoNodo->siguiente=lista;
//    if(lista!=NULL)
//    {
//        lista->anterior=nuevoNodo;
//    }
//
//    return nuevoNodo;
//}

nodoDoble* agregarOrdenado (nodoDoble* lista, nodoDoble* nuevoNodo)
{
    nodoDoble* seg;
    nodoDoble* ante;
    if (lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if(strcmpi(lista->aux.dni, nuevoNodo->aux.dni)>0)
    {
//        lista=agregarPpio(lista, nuevoNodo);

    }
    else
    {
        seg=lista;
        ante=lista;
        while(seg!=NULL && strcmpi(seg->aux.dni, nuevoNodo->aux.dni)<0)
        {
            ante=seg;
            seg=seg->siguiente;
        }

        if(seg!=NULL)
        {
            seg->anterior=nuevoNodo;

        }

        ante->siguiente=nuevoNodo;
        nuevoNodo->siguiente=seg;
        nuevoNodo->anterior=ante;

    }

    return lista;
}

//c. Eliminar de la lista aquellos nodos que contengan un DNI en
//particular. (Tener en cuenta que puede existir más de 1).

nodoDoble* borrarNodo (nodoDoble* lista, char dni[9])
{

    nodoDoble* seg=lista;
    nodoDoble* ante;
    nodoDoble* aux;
    if(lista!=NULL)
    {
        while(seg!=NULL)
        {
            if(strcmpi(seg->aux.dni, dni)==0)
            {
                aux=seg->siguiente;
                ante->siguiente=aux;
                if(aux!=NULL)
                {
                    aux->anterior=ante;
                }
                free(seg);

            }
            else
            {
                ante=seg;
                seg=seg->siguiente;
            }

        }

    }

    return lista;

}

///d.Realizar un algoritmo que informe el promedio de nota por DNI de una
///asignatura en particular

float calculoPromedio (nodoDoble* lista, char asignatura[20], char dni[9])
{
    float nota=0, promedio=0;
    int i=0;
    nodoDoble* seg=lista;
    if(seg!=NULL)
    {

        while(seg!=NULL)
        {
            if(strcmpi(seg->aux.asignatura, asignatura)==0 && strcmpi(seg->aux.dni, dni)==0)
            {
                nota+=seg->aux.Nota;
                i++;
                seg=seg->siguiente;
            }
            else
            {
                seg=seg->siguiente;
            }

        }

    }
    else
    {
        puts("la lista esta vacia");
    }

    promedio=nota/i;


    return promedio;
}


///(Recursivo) Verificar si existe un determinado DNI en una asignatura
///dada

int verificarDNIExistente (nodoDoble* lista, char asignatura[20], char dni[9])
{
    int flag=0;
    if (lista!=NULL)
    {
        if(strcmpi(lista->aux.asignatura, asignatura)==0 && strcmpi(lista->aux.dni, dni)==0)
        {
            flag=1;

        }
        else
        {
            flag=verificarDNIExistente(lista->siguiente, asignatura, dni);
        }
    }

    return flag;
}

//f. (Recursivo) Mostrar todos los nodos con DNI, Nro. parcial y Nota de una asignatura en particular

void mostrarNodosEspeciales (nodoDoble* lista, char asignatura[20])
{
    if(lista!=NULL)
    {
        if(strcmpi(lista->aux.asignatura, asignatura)==0)
        {
            mostrarUnExamen(lista->aux);
            mostrarNodosEspeciales(lista->siguiente, asignatura);
        }
        else
        {
            mostrarNodosEspeciales(lista->siguiente, asignatura);
        }
    }


}

///g. (Recursivo) Devolver la cantidad de alumnos(DNI) de una asignatura
///en particular. Tener en cuenta de NO contar dos veces el mismo DNI,
///pensar bien la resolución.

int cantAlumnos(nodoDoble* lista, char asignatura[20], char dni[9])
{
    int i=0;
    if(lista!=NULL)
    {
        if(strcmpi(lista->aux.asignatura, asignatura)==0)
        {
            if(strcmpi(lista->aux.dni, dni)!=0)
            {
                i++;
                i=i+cantAlumnos(lista->siguiente, asignatura, lista->aux.dni);
            }
            else
            {
                i=i+cantAlumnos(lista->siguiente, asignatura, dni);

            }

        }
        else
        {
            i=cantAlumnos(lista->siguiente, asignatura, dni);
        }
    }


    return i;
}

///4.Pasar a un arreglo dinámico del tamaño justo aquellos DNI que pertenezcan a una
///asignatura en particular. (Utilizar función del inciso 3g)

void listaToArreglo(nodoDoble* lista, char asignatura[20], char arreglo[])
{
    int i=0;
    nodoDoble* aux=lista->siguiente;
    if(lista!=NULL)
    {
        while(lista!=NULL)
        {
            if(strcmpi(lista->aux.asignatura, asignatura)==0)
            {
                if(strcmpi(lista->aux.dni, aux->aux.dni)!=0)
                {
                    arreglo[i]=lista->aux.dni;
                    i++;
                    lista=lista->siguiente;
                    aux=aux->siguiente;
                }
                else
                {
                    lista=lista->siguiente;
                    aux=aux->siguiente;
                }
            }
            else
            {
                lista=lista->siguiente;
                aux=aux->siguiente;
            }
        }

    }


}



