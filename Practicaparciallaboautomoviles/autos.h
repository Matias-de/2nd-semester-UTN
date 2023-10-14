#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#define MAXDIM 30


typedef struct {
   char patente[10];
   char marca[20];
   int valor;
} automovil;


typedef struct {
   automovil dato;
   struct nodoAuto * siguiente;
} nodoAuto;

automovil crearUnAuto ();

nodoAuto* inicLista();
nodoAuto* crearNodoAuto(automovil aux);

void mostrarUnAuto(automovil aux);
void mostrarUnNodo(nodoAuto* aux);
void mostrarNodoAutos(nodoAuto* autitos);
nodoAuto* buscarUltimo (nodoAuto* autitos);
void agregarFinal(nodoAuto * * lista, nodoAuto * nuevo);
void agregarMuchos(nodoAuto * * lista);
int insertarCelda(automovil arreglo[MAXDIM], automovil dato, int validos);
int pasar(nodoAuto * listaAutos, automovil arreglo[]);
void mostrarArregloRecursivo(automovil arreglo[ ], int i, int pos);
void mostrarArreglo (automovil arreglo[], int validos);
int esPar (nodoAuto* lista);
int sumarValores (nodoAuto* lista);
#endif // AUTOS_H_INCLUDED
