#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#define MAXDIM 30

int preguntarDato()
{
    int dato;
    puts("Ingrese la opcion a realizar:");
    fflush(stdin);
    scanf("%i", &dato);
    return dato;
}

void opcionesSwitch()
{
    puts("------------------------------------------------------------------\n");
    puts("Ingrese un 1 para crear un nodo (punto 1)");
    puts("Ingrese un 2 para agregar un nodo al final de una lista (punto 2 y 4)");
    puts("Ingrese un 3 para mostrar todos los nodos de la lista");
    puts("Ingrese un 4 para pasar de la lista a un arreglo ordenado(punto 5)");
    puts("Ingrese un 5 para mostrar el arreglo pero recursivamente(punto 6)");
    puts("Ingrese un 6 para sumar los valores de los automoviles pares recursivamente (punto 7)");
    puts("------------------------------------------------------------------\n");
}

void menu(nodoAuto* listaAutos, automovil arreglo[], int validos, int suma)
{
    char continuar='s';
    do
    {
        system("cls");
    opcionesSwitch();
    int dato=preguntarDato();

    switch(dato)
    {
    case 1:
        listaAutos=crearNodoAuto(crearUnAuto());
        mostrarUnAuto(listaAutos->dato);
        break;

    case 2:
        agregarMuchos(&listaAutos);
        system("cls");
        mostrarNodoAutos(listaAutos);
        break;

    case 3:
    mostrarNodoAutos(listaAutos);
        break;

    case 4:
        validos=pasar(listaAutos, arreglo);
        mostrarArreglo(arreglo, validos);
        break;

    case 5:
      mostrarArregloRecursivo(arreglo, 0, validos);

        break;

    case 6:
        suma=sumarValores(listaAutos);
        printf("\n%i\n", suma);
        break;

    default:
        puts("ERROR, eleccion invalida, REINTENTE...");
        break;


    }
    puts("Desea realizar otra operacion? (s/n):");
    fflush(stdin);
    scanf("%c", &continuar);


    }while (continuar=='s' || continuar=='S');


}
