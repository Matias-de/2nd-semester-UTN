#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

nodo* iniclista()
{
    return NULL;
}

nodo* crearNodo(int dato)
{
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;
}

nodo* agregarPpio(nodo* lista, nodo* nuevoNodo)
{
    if(lista!=NULL)
    {
        nuevoNodo->siguiente=lista;
    }

    return nuevoNodo;
}

nodo* buscarUltimo(nodo* lista)
{
    while(lista!=NULL && lista->siguiente!=NULL)
    {
        lista=lista->siguiente;
    }

    return lista;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo* ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevoNodo;
    }


    return lista;
}

nodo* agregarOrdenado(nodo* lista, nodo* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(lista->dato > nuevoNodo->dato)
        {
            lista=agregarPpio(lista, nuevoNodo);
        }
        else
        {
            nodo* seg=lista;
            nodo* ante;
            while(seg!=NULL && seg->dato< nuevoNodo->dato)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;


        }
    }



    return lista;
}


nodo* borrarNodo(nodo* lista, int dato)
{
    if(lista!=NULL)
    {
        nodo*seg=lista;
        nodo* ante;
        if(lista->dato==dato)
        {
            lista=lista->siguiente;
            free(seg);
        }
        else
        {
            while(seg!=NULL && seg->dato!=dato)
            {
                ante=seg;
                seg=seg->siguiente;

            }
            if(seg!=NULL)
            {
                ante->siguiente=seg->siguiente;
                free(seg);

            }
            else
                puts("no se encontro el dato");

        }
    }




    return lista;


}



void mostrarLista(nodo* lista)
{
    nodo* seg=lista;
    while(seg!=NULL)
    {
        printf("DATO EN NODO: %i\n", seg->dato);
        seg=seg->siguiente;
    }

}


nodoDoble* iniclistaDoble()
{
    return NULL;
}

nodoDoble* crearNodoDoble(int dato)
{
    nodoDoble* nuevo=(nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    nuevo->anterior=NULL;
    return nuevo;
}

nodoDoble* agregarPPioDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    nuevoNodo->siguiente=lista;
    if(lista!=NULL)
    {
        lista->anterior=nuevoNodo;
    }

    return nuevoNodo;
}

nodoDoble* buscarUltimoDoble(nodoDoble* lista)
{
    while(lista->siguiente!=NULL)
    {
        lista=lista->siguiente;
    }

    return lista;
}

nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;

    }
    else
    {
        nodoDoble* ultimo=buscarUltimoDoble(lista);
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->anterior=ultimo;
    }




    return lista;
}

nodoDoble* agregarOrdenadoDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(lista->dato > nuevoNodo->dato)
        {
            lista=agregarPPioDoble(lista, nuevoNodo);
        }
        else
        {
            nodoDoble* seg=lista;
            nodoDoble* ante;
            while(seg!=NULL && seg->dato < nuevoNodo->dato)
            {
                ante=seg;
                seg=seg->siguiente;
            }

                ante->siguiente=nuevoNodo;
                nuevoNodo->siguiente=seg;
                if(seg!=NULL)
                {
                nuevoNodo->anterior=ante;
                seg->anterior=nuevoNodo;

                }



        }
    }



    return lista;
}

nodoDoble* borrarNodoDoble(nodoDoble* lista, int dato)
{
    if(lista!=NULL)
    {
        nodoDoble* seg=lista;
        nodoDoble* ante=NULL;
        nodoDoble* aux=NULL;
        if(lista->dato==dato)
        {
            lista=lista->siguiente;
            free(seg);
            lista->anterior=NULL;
        }else
        {
            while(seg!=NULL && seg->dato!=dato)
            {
                ante=seg;
                seg=seg->siguiente;
                if(seg!=NULL)
                aux=seg->siguiente;
            }
           if (seg != NULL)
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
                printf("El dato no se encontro en la lista\n");
            }

        }
    }



    return lista;
}


void mostrarListaDoble(nodoDoble* lista)
{
    nodoDoble* seg=lista;
    while(seg!=NULL)
    {
        printf("DATO EN LISTA DOBLE: %i\n", seg->dato);
        seg=seg->siguiente;
    }

}
















































































































































































































































































