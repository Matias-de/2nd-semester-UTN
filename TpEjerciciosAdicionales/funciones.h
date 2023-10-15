#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{

int dato;
struct nodo* siguiente;
}nodo;

typedef struct{
int nroParcial;
char dni[9];
char asignatura[20];
float Nota;
}examen;

typedef struct{

examen aux;
struct nodoDoble* siguiente;
struct nodoDoble* anterior;


}nodoDoble;

nodo * inicLista();
nodo * crearUnNodo(int aux);
nodo * agregarAlFinal(nodo *lista, nodo * nuevoNodo);
nodo * buscarUltimoLista(nodo *lista);
void mostrarLista(nodo * lista);
void mostrarDatoEntero(int dato);
nodo* borrarRepetidos (nodo* lista);
nodo* intercalarIntersecciones(nodo* lista, nodo* lista2);

///---------------------------------------------------------------------///

nodoDoble* inicNodo();
nodoDoble* crearNodo(examen examen);
examen cargarUnExamen();
void mostrarUnExamen(examen aux);
void mostrarUnNodo(nodoDoble* aux);
void mostrarListaDoble(nodoDoble* lista);
nodoDoble* agregarPpioPuntero (nodoDoble** lista, nodoDoble* nuevoNodo);
nodoDoble* agregarPpio(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* agregarOrdenado (nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* borrarNodo (nodoDoble* lista, char dni[9]);
float calculoPromedio (nodoDoble* lista, char asignatura[20], char dni[9]);
int verificarDNIExistente (nodoDoble* lista, char asignatura[20], char dni[9]);
void mostrarNodosEspeciales (nodoDoble* lista, char asignatura[20]);
int cantAlumnos(nodoDoble* lista, char asignatura[20], char dni[9]);
void listaToArreglo(nodoDoble* lista, char asignatura[20], char arreglo[]);

#endif // FUNCIONES_H_INCLUDED
