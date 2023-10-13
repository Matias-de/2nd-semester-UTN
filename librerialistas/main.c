#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"


int main()
{
   nodoDoble* lista=iniclistaDoble();
    lista=agregarOrdenadoDoble(lista, crearNodoDoble(11));
   lista=agregarOrdenadoDoble(lista, crearNodoDoble(10));
    lista=agregarOrdenadoDoble(lista, crearNodoDoble(30));
    mostrarListaDoble(lista);

//
    lista=borrarNodoDoble(lista, 3);
   puts("\n");
    mostrarListaDoble(lista);

    return 0;
}
