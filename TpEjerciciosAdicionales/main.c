#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int main()
{
//    nodo* lista=inicLista();
//    nodo* lista2=inicLista();
//    nodo*listaPunto2=inicLista();
//    lista=crearUnNodo(5);
//    lista=agregarAlFinal(lista, crearUnNodo(7));
//    lista=agregarAlFinal(lista, crearUnNodo(9));
//    lista=agregarAlFinal(lista, crearUnNodo(100));
//    lista2=crearUnNodo(2);
//    lista2=agregarAlFinal(lista2, crearUnNodo(3));
//    lista2=agregarAlFinal(lista2, crearUnNodo(5));
//    lista2=agregarAlFinal(lista2, crearUnNodo(100));
//    mostrarLista(lista);
////    lista=borrarRepetidos(lista);
//   puts("--------------------------");
//    mostrarLista(lista2);
//    listaPunto2=intercalarIntersecciones(lista, lista2);
//    puts("--------------------------");
//    mostrarLista(listaPunto2);

nodoDoble* lista=inicNodo();
lista=agregarOrdenado(lista, crearNodo(cargarUnExamen()));
lista=agregarOrdenado(lista, crearNodo(cargarUnExamen()));
lista=agregarOrdenado(lista, crearNodo(cargarUnExamen()));
mostrarListaDoble(lista);
puts("------------------------------------\n");
system("pause");

//lista=borrarNodo(lista, "46112874");
//mostrarListaDoble(lista);

//float promedio=calculoPromedio(lista, "estadistica", "46112874");
//printf("El promedio del alumno con el dni ingresado para esa materia es de: %.2f", promedio);

//int flag=verificarDNIExistente(lista, "programacion", "46112874");
//flag==1? puts("DNI encontrado en la asignatura solicitada") : puts("DNI no encontrado..");

//mostrarNodosEspeciales(lista, "estadistica");

int cntAlumnos=cantAlumnos(lista, "estadistica", "0");
printf("%i", cntAlumnos);
puts("\n\n");
char* arreglo=malloc(cntAlumnos*sizeof(char));
listaToArreglo(lista, "estadistica", arreglo);

for(int i=0; i<cntAlumnos;i++)
{
    printf("DNI: %s\n", arreglo[i]);
}


    return 0;
}
