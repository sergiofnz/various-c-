#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo {
		int dato;
		Nodo *siguiente;
};

void addPila(Nodo *&, int); //Prototipo de la funcion
void sacarPila(Nodo *&, int &);

int main (){
	Nodo *pila = NULL;
	int dato;
	
	cout<<"Write a number: ";
	cin>> dato;
	addPila(pila, dato);
	
	cout<<"Write another number: ";
	cin>>dato;
	addPila(pila, dato);
	
	cout<<"\nSacando los elementos de la pila: ";
	while(pila != NULL){ //mientras no sea el final de la pila
		sacarPila(pila, dato);
		if(pila != NULL){
		cout <<dato<<" ,";	
		}
		else {
			cout <<dato<<" . ";
		}
	}
	getch;
	return 0;
}

void addPila(Nodo *&pila, int n){
		Nodo *nuevo_nodo = new Nodo(); //1. Crear el espacio en memoria para almacenar un 
		nuevo_nodo ->dato = n; //2. cargar el valor dentro del nodo(dato)
		nuevo_nodo->siguiente = pila; //3. Cargar el puntero pila dentro del nodo(*siguiente)
		pila = nuevo_nodo; //4. Asignar el nuevo nodo a pila
		
		cout<<"\tElemento "<<n<<" ha sido agregado a PILA correctamente"<<endl;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;
	n= aux ->dato;
	pila = aux ->siguiente;
	delete aux;
}
