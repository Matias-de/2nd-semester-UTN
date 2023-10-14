#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#define MAXDIM 30


typedef struct
{
    char nombre[MAXDIM];
    int edad;

}stPersona;


typedef struct
{
    stPersona datos;
    struct nodo* siguiente;

} nodo;


typedef struct{
    struct nodo*lista;
}Pila;


nodo* iniclista();
nodo* crearNodo (stPersona aux);
nodo*agregarNodoPpio(nodo*lista,nodo*nuevoNodo);
nodo* cargarNodosPpio (nodo* lista);
nodo* agregarOrdenado (nodo* lista, nodo* nuevoNodo);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo);
nodo* borrarNodo (nodo* lista, char nombre[40]);
nodo* borrarPrimerNodo (nodo* lista);
stPersona cargarUnaPersona();
void mostrarUnaPersona(stPersona aux);
void mostrarUnNodo(nodo* aux);
void mostrarNodo (nodo* lista);
///FUNCIONES PILAS
int pilavacia(Pila* p);
void inicPila (Pila* p);
void apilar(Pila * p, stPersona dato);
void mostrar(Pila* p);
void leer (Pila* p);
stPersona desapilar (Pila* p);
stPersona tope (Pila* p);

#endif // PILAS_H_INCLUDED
