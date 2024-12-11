//insertar elementos en una cola
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo {
		int dato;
		Nodo *siguiente;
};


//prototipos de funcion
void insertarCola(Nodo *&,Nodo *&,int);
bool cola_vacia(Nodo *);
int main(){
	Nodo  *frente = NULL;
	Nodo *fin = NULL;
	
	int dato;
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente, fin, dato); 
	
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente, fin, dato); 
	
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente, fin, dato); 
	
	getch();
	return 0;
}


//FUNCION PARA INSERTAR ELEMENTOS EN UNA COLA

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
	Nodo *nuevo_nodo = new	Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
	
	cout<<"\tElemento "<<n<<" insertado a la cola correctamente\n";
}

//funcion para determinar si la cola esta vacia o no
bool cola_vacia(Nodo *frente){
	return(frente == NULL)? true : false;	
}