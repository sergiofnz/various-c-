// insertar elementos en la pila

#include<iostream>
#include<conio.h>

using namespace std;


struct Node {

		int dato;
		Node *next;
};

void addPila(Node *&, int); //Prototipo


int main() {

	Node *pila = NULL;
	int n1, n2;

	cout <<"Write a number:";
	cin>>n1;
	addPila(pila, n1);

	cout <<"Write another number";
	cin>>n2;
	addPila(pila, n2)

	getch();
	return 0;
}

void addPila(Node *&pila, int n){
		Node *new_node = new Node();
		new_node - > dato = n;
		new_node - > siguiente = pila;
		pila = new_node;  

		cpit <<"\n Element "<<n<<" added to stack correctly" <<endl;
}