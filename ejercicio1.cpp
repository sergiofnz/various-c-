// EJercicio 1: Hacer un programa para agregar numeros enteros a una pila, hasta que el usuario lo decida, despues ostrar todos los numeros en la pila

#include<iostream>
#include<conio.h>
using namespace std;

struct Nodo{
		int dato;
		Nodo *siguiente;
};

//Prototipo de funcion
void agregarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);





int main(){
	Nodo *pila = NULL;
	int dato;
	char rpt;
	
	do{
		cout<<"Digite un numero: ";
		cin>>dato;
		agregarPila(pila, dato);
		
		cout<<"\nDesea agregaro otro elemento a PILA(s/n): ";
		cin>>rpt;
	}while((rpt=='S')||(rpt=='s'));
	
	cout<<"\nSacanto todos los elementos de la pila: ";
	while(pila != NULL){ //mientras no sea el final de la pila
		sacarPila(pila, dato);
		if(pila != NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	getch();
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}