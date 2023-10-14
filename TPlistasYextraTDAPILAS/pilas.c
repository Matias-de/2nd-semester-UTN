#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
///FUNCIONES LISTAS

nodo* iniclista() //INICIA LA LISTA EN NULL PARA POSTERIORES COMPARACIONES
{
    return NULL;
}


nodo* crearNodo (stPersona aux)     //CREA UN ESPACIO EN MEMORIA PARA EL NODO
{


    nodo* auxNodo=(nodo*)malloc(sizeof(nodo));
    auxNodo->datos=aux;
    auxNodo->siguiente=NULL;
    return auxNodo;


}

stPersona cargarUnaPersona()
{
    stPersona aux;
    puts("Ingrese el nombre de la persona:");
    fflush(stdin);
    gets(aux.nombre);
    puts("Ingrese la edad de la persona:");
    fflush(stdin);
    scanf("%i", &aux.edad);

    return aux;
}


nodo* cargarNodo (nodo* lista)                                     //CARGA DEL NODO
{
    char op='s';
    do
    {

        lista=agregarAlFinal(lista, crearNodo(cargarUnaPersona()));
        puts("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &op);
    }
    while(op=='s' || op=='S');

    return lista;
}

nodo* agregarPpio (nodo* lista, nodo* nuevoNodo)
{
    nuevoNodo->siguiente=lista;                                                 //

    return nuevoNodo;
}

nodo*agregarNodoPpio(nodo*lista,nodo*nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;

    }
    else
    {
        lista=nuevoNodo;
    }
    return lista;
}

nodo* cargarNodosPpio (nodo* lista)                                              //CARGA Y ASIGNACION AL PRINCIPIO DE LOS NODOS
{
    nodo* nuevoNodo;
    stPersona aux;
    char op='s';
    while(op=='s' || op=='S')
    {
        aux=cargarUnaPersona();
        nuevoNodo=crearNodo(aux);
        lista=agregarPpio(lista, nuevoNodo);
        puts("Desea continuar' (s/n)");
        fflush(stdin);
        scanf("%c", &op);
    }


    return lista;
}

void mostrarUnaPersona(stPersona aux)
{

    printf("NOMBRE: %s\n", aux.nombre);
    printf("EDAD: %i\n", aux.edad);
 puts("------------------------------------------------------");

}

void mostrarNodo (nodo* lista)
{
    nodo* seguidora= lista;                                    ///MUESTRA LA LISTA COMPLETA
    while(seguidora!=NULL)
    {
        mostrarUnNodo(seguidora);
        seguidora=seguidora->siguiente;


    }

}

void mostrarUnNodo(nodo* aux)
{
    //mostrarUnaPersona(aux->datos);                             //MUESTRA SOLO UN NODO

}

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo)
{
    if(lista==NULL)                                             //AGREGA AL FINAL DE LA LISTA UN NUEVO NODO
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo*ultimo= buscarUltimo(lista);
        ultimo->siguiente=nuevoNodo;
    }

    return lista;

}


nodo* buscarUltimo(nodo* lista)
{
    nodo* seg= lista;
    if(seg!=NULL)                                                //BUSCA Y RETORNA EL ULTIMO NODO CON DATOS (!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;

}

nodo* agregarOrdenado (nodo* lista, nodo* nuevoNodo)            //AGREGA ELEMENTOS ORDENADAMENTE
{
    if(lista==NULL)
    {

        lista=nuevoNodo;
    }
    else
    {
        if (lista->datos.edad > nuevoNodo->datos.edad)
        {
            lista=agregarPpio(lista, nuevoNodo);
        }
        else
        {
            nodo* ante= lista;
            nodo* seg= lista;
            while (seg!=NULL && nuevoNodo->datos.edad > seg->datos.edad)
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



nodo* borrarNodo (nodo* lista, char nombre[40])
{
    nodo* seg;
    nodo* ante;
    if(lista!=NULL && strcmpi(nombre, lista->datos.nombre)==0)
    {
        seg=lista;
        lista=lista->siguiente;
        free(seg);
    }
    else
    {
        seg=lista;
        while(seg!=NULL && strcmpi(nombre, seg->datos.nombre)!=0)
        {
            ante=seg;
            seg=seg->siguiente;

        }

        if(seg!=NULL)
        {
            ante->siguiente=seg->siguiente;
            free(seg);
        }


    }

    return lista;
}

nodo* borrarPrimerNodo (nodo* lista)
{
   if(lista!=NULL)
   {
       nodo* aux=lista;
       lista=lista->siguiente;
       free(aux);
   }



   return lista;
}


                                                ///FUNCIONES PILAS///



void inicPila (Pila* p)
{
    p->lista=iniclista();
}



int pilavacia(Pila* p)
{
   return p->lista==NULL? 1 : 0;


}


void apilar(Pila * p, stPersona dato)
{
    nodo* aux=crearNodo(dato);
    p->lista=agregarNodoPpio(p->lista, aux);


}


stPersona desapilar (Pila* p)
{
    stPersona aux = ((nodo*)(p->lista))->datos;
    p->lista = borrarPrimerNodo(p->lista);

    return aux;

}


stPersona tope (Pila* p)
{
    stPersona aux;
    aux=((nodo*)p->lista)->datos;
    return aux;

}


void mostrar(Pila* p)
{
    nodo* aux=p->lista;
    puts("-------------------------TOPE-------------------------");
    while(aux!=NULL)
    {
    mostrarUnaPersona(aux->datos);
    aux=aux->siguiente;
    }
    puts("-------------------------BASE-------------------------");
}



void leer(Pila* p)
{
    p->lista=agregarNodoPpio(p->lista, crearNodo(cargarUnaPersona()));


}


