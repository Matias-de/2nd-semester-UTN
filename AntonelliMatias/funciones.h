#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
char nombre[50];
char telefono[500];
int DNI; // valores del 1 al 100
}stPersona;

typedef struct{
	stPersona dato;
	struct nodoPersona* siguiente;
}nodoPersona;

typedef struct {
 int DNI;
 int tipoContacto; //1-familia 2-trabajo 3-amigos
int activo; //1-true 0-false
}stContacto;

typedef struct nodoCliente{
	stContacto dato;
	struct nodoContacto* siguiente;
	struct nodoContacto* anterior;
}nodoContacto;


//1
int validarDniEnLista (nodoPersona* lista, int dni);

//2
stPersona cargarUnaPersona();
int validarDNI(int dni);
nodoPersona* inicNodoPersona();
nodoContacto* inicNodoContacto();
nodoPersona* crearNodoPersona (stPersona aux);

//3
void mostrarUnaPersona(stPersona aux);
void mostrarUnNodoPersona(nodoPersona* lista);
void mostrarNodosPersona(nodoPersona* lista);

//4
nodoPersona* cargarListaPersonas(nodoPersona* lista);
nodoPersona* buscarUltimoPersona(nodoPersona* lista);
nodoPersona* agregarAlFinalPersona (nodoPersona* lista, nodoPersona* nuevoNodo);
nodoPersona* agregarPpio(nodoPersona* lista, nodoPersona* nuevoNodo);

//5
nodoContacto* crearNodoContacto(stContacto aux);
stContacto cargarUnContacto(nodoPersona* lista);


//6
nodoContacto* agregarPpioContacto (nodoContacto* lista, nodoContacto* nuevoNodo);
nodoContacto* agregarOrdenadoContacto (nodoContacto* lista, nodoContacto* nuevoNodo);

//7
void mostrarUnContacto(stContacto aux);
void mostrarUnNodoContacto(nodoContacto* lista);
nodoContacto* buscarUltimoContacto(nodoContacto* lista);
void mostrarNodoContactoInversoRecursivo(nodoContacto* lista);
void mostrarNodoContacto(nodoContacto* lista);



///8
int contarActivos (nodoContacto* lista);
#endif // FUNCIONES_H_INCLUDED
