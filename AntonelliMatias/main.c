#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    ///si funciones.h y funciones.c no se pueden ver, apretando en mi nombre y en add files se pueden agregar :)
   nodoPersona* lista=inicNodoPersona();
   lista=cargarListaPersonas(lista);
   mostrarNodosPersona(lista);
   printf("\n\n");
   nodoContacto* liston= inicNodoContacto();
   liston=agregarOrdenadoContacto(liston, crearNodoContacto(cargarUnContacto(lista)));

   nodoContacto* ultimo=buscarUltimoContacto(liston);
  // mostrarNodoContacto(liston);
    mostrarNodoContactoInversoRecursivo(ultimo);
   int contadorActivos=contarActivos(liston);
   printf("\nCANT ACTIVOS: %i\n", contadorActivos);


    return 0;
}
