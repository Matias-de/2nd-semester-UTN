#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct{

int dato;
struct nodo* siguiente;
}nodo;
typedef struct {

int dato;
struct nodo* siguiente;
struct nodo* anterior;


}nodoDoble;

nodo* iniclista();
nodo* crearNodo (int aux);
nodo* agregarPpio(nodo* lista, nodo* nuevoNodo);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal (nodo* lista, nodo* nuevoNodo);
nodo* agregarOrdenado (nodo* lista, nodo* nuevoNodo);
nodo* borrarNodo(nodo* lista, int dato);
void mostrarLista(nodo* lista);

///LISTAS DOBLES:

nodoDoble* iniclistaDoble();
nodoDoble* crearNodoDoble (int dato);
nodoDoble* agregarPPioDoble (nodoDoble* lista, nodoDoble* nuevoNodo);
void mostrarListaDoble(nodoDoble* lista);
nodoDoble* buscarUltimoDoble (nodoDoble* lista);
nodoDoble* agregarAlFinalDoble (nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* agregarOrdenadoDoble(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* borrarNodoDoble(nodoDoble* lista, int dato);






#endif // LISTAS_H_INCLUDED
