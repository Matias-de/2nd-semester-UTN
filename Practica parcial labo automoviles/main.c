#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"
#include "menu.h"
#define MAXDIM 30
int main()
{
    nodoAuto* listaAutos=inicLista();
    automovil arreglo[MAXDIM];
    int validos=0;
    int suma=0;
    menu(listaAutos, arreglo, validos, suma);
    return 0;
}
