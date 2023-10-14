#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
int main()
{
    Pila pilita;
    Pila pilota;
    inicPila(&pilita);
    inicPila(&pilota);
    pilavacia(&pilita)? puts("pila vacia") : puts("pila con elementos");
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    mostrar(&pilita);
    apilar(&pilota, desapilar(&pilita));
    mostrar(&pilita);
    mostrar(&pilota);
    system("pause");
stPersona aux= tope(&pilita);
mostrarUnaPersona(aux);
    return 0;
}
