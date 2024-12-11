//Tarea 1 Pilas. Desarrollar un programa en C++ que permita realizar las siguientes operaciones en una Pila que tiene n elementos (4pts c/u):


//insertar, contar y eliminar elementos de una pila. 
//obtener la inversa de una pila. 
//Si se tiene una Pila de n elementos crear una nueva pila que contenga los elementos en orden de mayor a menor (el mayor debería estar en el fondo de la pila, y el menor en la cima). 




#include <iostream> 
#include <stack>
 
using namespace std;

void imprimirPila(stack<int> stack);
void rellenarPila(stack<int> &stack, int numero);
void rellenarPilaAlteatorio(stack<int> &stack, int numero);
stack<int> invertirPila(stack<int> pila);
int contarElementos(stack<int> pila);
stack<int> ordenarPilaDeMenorAMayor(stack<int> pila);
stack<int> ordenarPilaDeMayorAMenor(stack<int> pila);
stack<int> eliminarPrimerElemento(stack<int> pila);

int main() {
    stack<int> pila;
    stack<int> pilaInvertida;
    stack<int> pilaDesordenada;
    stack<int> pilaOrdenadaMayorAMenor;
    stack<int> pilaOrdenadaMenorAMayor;
    stack<int> pilaEliminarPrimerElemento;
    
    cout<<endl<<"Pila creada"<<endl;
    rellenarPila(pila, 10);
    cout<<"Elementos de la pila: ";
    imprimirPila(pila);

    cout<<endl<<"Se cuentan los elementos de la pila"<<endl;
    cout<<"El numero de elementos en la pila es: "<<contarElementos(pila)<<endl;

    cout<<endl<<"Se invierte la pila generada"<<endl;
    pilaInvertida = invertirPila(pila);
    cout<<"Pila inversa: ";
    imprimirPila(pilaInvertida);

    cout<<endl<<"Se crea una pila desordenada para luego ordenarla"<<endl;
    //se pasa como segundo argumento el numero de elementos de la pila
    rellenarPilaAlteatorio(pilaDesordenada, 10);
    cout<<"\n Pila desordenada: ";
    imprimirPila(pilaDesordenada);

    pilaOrdenadaMayorAMenor = ordenarPilaDeMayorAMenor(pilaDesordenada);
    cout<<"\n Pila ordenada de Mayor a Menor: ";
    imprimirPila(pilaOrdenadaMayorAMenor);

    pilaOrdenadaMenorAMayor = ordenarPilaDeMenorAMayor(pilaDesordenada);
    cout<<"\n Pila ordenada de Menor a Mayor: ";
    imprimirPila(pilaOrdenadaMenorAMayor);

    cout<<"\n Elementos de la pila ordenada de menor a mayor eliminando el primer elemento: ";
	pilaEliminarPrimerElemento = eliminarPrimerElemento(pilaOrdenadaMenorAMayor);
	imprimirPila(pilaEliminarPrimerElemento);
}

void imprimirPila(stack<int> stack){
    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    }
    cout<<endl;
}

void rellenarPila(stack<int> &stack, int numero){
    int dato;
    for (int i = 0; i < numero; i++)
    {	
        dato = i + 1;
        stack.push(dato);
    }
}

void rellenarPilaAlteatorio(stack<int> &stack, int numero){
    int dato;
    for (int i = 0; i < numero; i++)
    {	
        dato = rand() % numero + 1;
        stack.push(dato);
    }
}

stack<int> invertirPila(stack<int> pila){
    stack<int> pilaOrdenada;
    int dato;
    while (!pila.empty()) {
        dato = pila.top();
        pila.pop();
        pilaOrdenada.push(dato);
    }
    return pilaOrdenada;
}

int contarElementos(stack<int> pila){
    int numero = 0;
    while (!pila.empty()) {
        pila.pop();
        numero++;
    }
    return numero;
}

stack<int> ordenarPilaDeMayorAMenor(stack<int> pila)
{
    stack<int> aux;
  
    while (!pila.empty())
    {
        int aux2 = pila.top();
        pila.pop();

        while (!aux.empty() && aux.top() > aux2)
        {
            pila.push(aux.top());
            aux.pop();
        }
        aux.push(aux2);
    }
  
    return aux;
}

stack<int> ordenarPilaDeMenorAMayor(stack<int> pila)
{
    stack<int> aux;
  
    while (!pila.empty())
    {
        int aux2 = pila.top();
        pila.pop();

        while (!aux.empty() && aux.top() < aux2)
        {
            pila.push(aux.top());
            aux.pop();
        }
        aux.push(aux2);
    }
  
    return aux;
}

stack<int> eliminarPrimerElemento(stack<int> pila){
    stack<int> aux = invertirPila(pila);
    aux.pop();
    stack<int> aux2 = invertirPila(aux);
	return aux2;
}