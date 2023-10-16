#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

nodoPersona* inicNodoPersona()
{
    return NULL;
}

nodoContacto* inicNodoContacto()
{
    return NULL;
}

///--------------------------------------------PUNTO 1----------------------------------------------

int validarDniEnLista (nodoPersona* lista, int dni)
{

int flag=0;

    if(lista!=NULL)
    {
       if( lista->dato.DNI == dni)
        {
            flag=1;
        }else
        {
        flag=validarDniEnLista(lista->siguiente, dni);

        }
    }

    return flag;
}

//int flag=0;
//    if(lista!=NULL && lista->siguiente!=NULL)
//    {
//        nodoPersona* seg=lista->siguiente;
//        if(lista->dato.DNI == seg->dato.DNI)
//        {
//            flag=1;
//        }else
//        {
//        flag=validarDniEnLista(lista->siguiente);
//
//        }
//    }



///----------------------------------------PUNTO 2------------------------------------------------------------



stPersona cargarUnaPersona()
{
    int flag=0;
    stPersona aux;
    puts("ingrese el nombre de la persona:");
    fflush(stdin);
    gets(aux.nombre);
    puts("Ingrese el telefono de la persona:");
    fflush(stdin);
    gets(aux.telefono);
    do
    {
        puts("ingrese el DNI de la persona:");
        fflush(stdin);
        scanf("%i", &aux.DNI);
        flag=validarDNI(aux.DNI);
    }
    while(flag==0);


    return aux;
}

int validarDNI(int dni)
{
    int flag=0;
    if(dni <=0 || dni >100)
    {
        puts("ERROR, fuera de rango. REINTENTE:");

    }
    else
    {
        flag=1;
    }
    return flag;
}

nodoPersona* crearNodoPersona (stPersona aux)
{
    nodoPersona* nuevo=(nodoPersona*)malloc(sizeof(stPersona));
    nuevo->dato=aux;
    nuevo->siguiente=NULL;
    return nuevo;
}



///----------------------------PUNTO 3--------------------------

void mostrarUnaPersona(stPersona aux)
{
    printf("NOMBRE: %s\n", aux.nombre);
    printf("DNI: %i\n", aux.DNI);
    printf("TELEFONO: %s\n", aux.telefono);
}
void mostrarUnNodoPersona(nodoPersona* lista)
{
    mostrarUnaPersona(lista->dato);

}

void mostrarNodosPersona(nodoPersona* lista)
{
    if(lista!=NULL)
    {
        mostrarUnaPersona(lista->dato);
        mostrarNodosPersona(lista->siguiente);
    }


}


///-----------------------PUNTO 4-----------------------



nodoPersona* buscarUltimoPersona(nodoPersona* lista)
{
    while(lista!=NULL && lista->siguiente!=NULL)
    {
        lista=lista->siguiente;
    }

    return lista;
}


nodoPersona* agregarAlFinalPersona (nodoPersona* lista, nodoPersona* nuevoNodo)
{
    int flag=0;

    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        flag=validarDniEnLista(lista, nuevoNodo->dato.DNI);

        if(flag==0)
        {
        nodoPersona* ultimo=buscarUltimoPersona(lista);
        ultimo->siguiente=nuevoNodo;
        }else
        {
            puts("DNI REPETIDOS, NO SE CARGA");
        }

    }


    return lista;
}

nodoPersona* cargarListaPersonas(nodoPersona* lista)
{
    char continuar='s';
    do
    {
        lista=agregarAlFinalPersona(lista, crearNodoPersona(cargarUnaPersona()));
        puts("Desea cargar otra persona? (s/n)");
        fflush(stdin);
        scanf("%c", &continuar);


    }while(continuar=='s' || continuar=='s');

    return lista;
}


nodoPersona* agregarPpio(nodoPersona* lista, nodoPersona* nuevoNodo)
{
    if(lista!=NULL)
    {
        nuevoNodo->siguiente=lista;
    }


    return nuevoNodo;
}




///----------------------------PUNTO 5------------------------

nodoContacto* crearNodoContacto(stContacto aux)
{
    nodoContacto* nuevo=(nodoContacto*)malloc(sizeof(nodoContacto));
    nuevo->dato=aux;
    nuevo->siguiente=NULL;
    nuevo->anterior=NULL;
    return nuevo;
}

stContacto cargarUnContacto(nodoPersona* lista)
{
    int tipoContactoAux=0;
    int flag=0;
    stContacto aux;
do
{

    puts("Ingrese el DNI del contacto");
    fflush(stdin);
    scanf("%i", &aux.DNI);
    flag=validarDniEnLista(lista, aux.DNI);
}while(flag==0);

    do
    {
        puts("Ingrese el tipo de contacto: (1-familia 2-trabajo 3-amigos):");
        fflush(stdin);
        scanf("%i", &tipoContactoAux);
        switch(tipoContactoAux)
        {
        case 1:
            aux.tipoContacto=1;
            break;
        case 2:
            aux.tipoContacto=2;
            break;
        case 3:
            aux.tipoContacto=3;
            break;
        default:
            puts("ERROR AL INGRESAR");
        }


    }while(tipoContactoAux<1 || tipoContactoAux>3);

    do
    {
//
        puts("ingrese el estado del contacto: (1- activo, 0- inactivo)");
        fflush(stdin);
        scanf("%i", &aux.activo);
    }while (aux.activo <=-1 || aux.activo>1);
//
        return aux;

}



///--------------------------------------------PUNTO 6-------------------------------------

nodoContacto* agregarPpioContacto (nodoContacto* lista, nodoContacto* nuevoNodo)
{
    nuevoNodo->siguiente=lista;
    if(lista!=NULL)
    {
        lista->anterior=nuevoNodo;
    }
    return nuevoNodo;

}

nodoContacto* agregarOrdenadoContacto (nodoContacto* lista, nodoContacto* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }else
    {
        if(lista->dato.DNI > nuevoNodo->dato.DNI)
        {
            lista=agregarPpioContacto(lista, nuevoNodo);
        }else
        {
            nodoContacto* seg=lista;
            nodoContacto* ante;
            while(seg!=NULL && seg->dato.DNI < nuevoNodo->dato.DNI)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
            nuevoNodo->anterior=ante;
            if(seg!=NULL)
            {
                seg->anterior=nuevoNodo;

            }


        }
    }



    return lista;
}


///PUNTO 7

void mostrarUnContacto(stContacto aux)
{
    printf("\nDNI: %i\n", aux.DNI);
    printf("TIPO CONTACTO:%i\n", aux.tipoContacto);
    printf("ACTIVO: %i\n", aux.activo);

}

void mostrarUnNodoContacto(nodoContacto* lista)
{
    mostrarUnContacto(lista->dato);


}

nodoContacto* buscarUltimoContacto(nodoContacto* lista)
{
    while(lista->siguiente!=NULL)
    {
        lista=lista->siguiente;
    }

    return lista;
}

void mostrarNodoContactoInversoRecursivo(nodoContacto* ultimo)
{
    if(ultimo!=NULL)
    {
        mostrarUnContacto(ultimo->dato);
        mostrarNodoContactoInversoRecursivo(ultimo->anterior);
    }

}

void mostrarNodoContacto(nodoContacto* lista)
{
    nodoContacto* seg=lista;
    while(seg!=NULL)
    {
        mostrarUnContacto(seg->dato);
        seg=seg->siguiente;
    }
}


///------------------------------PUNTO 8----------------------

int contarActivos (nodoContacto* lista)
{
    int contador=0;
    nodoContacto* seg=lista;
    while(seg!=NULL)
    {
        if(seg->dato.activo==1)
        {
            contador++;
        }
        seg=seg->siguiente;
    }
    return contador;
}



































