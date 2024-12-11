#include <iostream>
#include <bits/stdc++.h>
#include <list>

/* Desarrollar un programa en c++, utilizando listas simplemente enlazadas, que dadas dos listas de n elementos, 
devuelva otra lista con todos los elementos de las dos listas originales y ordenada de menor a mayor. 
Por Ejemplo L1 = (4, 9, 7, 1) y L2 = (8, 2, 6, 0), obtenga una lista Z = (0, 1, 2, 4, 6, 7, 8, 9). 
Si hay valores repetidos en la listas L1 y L2 solo se ingresa una vez a la lista Z. Luego solicitar un valor al 
usuario y eliminarlo de la lista. Por ejemplo valor = 7 la lista Z  = (0, 1, 2, 4, 6, 8, 9). Si el valor que se pide 
no se encuentra en la lista mostrar un mensaje "valor no encontrado"
Los valores de las Listas L1 y L2 son ingresadas por el usuario.

 */

using namespace std;

void imprimir(list <int> &);
void eliminar(list <int> &);
void orden(list <int> &);
void pedirDatos(list <int> &, int);

int main(){

    list <int> l1;
    list <int> l2;
    list <int> z;

    //AGREGAR ELEMENTOS A UNA PILA
    int n = 0, n2 = 0;
    cout << "Cuantos elementos desea ingresar en L1: ";
    cin >> n;
    pedirDatos(l1,n);
    cout << "\n";

    cout << "Cuantos elementos desea ingresar en L2: ";
    cin >> n2;
    pedirDatos(l2,n2);
    cout << "\n";

    //GUARDAR LAS DOS LISTAS EN UNA LISTA
    l1.splice(l1.begin(),l2);
    z.splice(z.begin(), l1);
    
    orden(z);

    eliminar(z);
    
    return 0;
}

void imprimir(list <int> &lista){
    for (auto x : lista) {
        cout << x << "  ";
    }
}

void eliminar(list <int> &z){
    //ELIMINAMOS EL VALOR PEDIDO POR EL USUARIO
    int eliminar = 0;
    cout << "\n\nElemento que desea eliminar de la lista: ";
    cin >> eliminar;

    bool aux = false;
        list<int>::iterator it;
        for (it = z.begin(); it != z.end(); ++it)
            if (*it == eliminar)
                aux = true;
            if(aux == true){   
                z.remove(eliminar);
                cout<<"\nLISTA Z: ";
                imprimir(z);
                cout<<"\n";
            }else{
                cout << "Elemento " << eliminar << " no encontrado\n";
                cout<<"\nLISTA Z: ";
                imprimir(z);
                cout<<"\n";
        }
}

void orden(list <int> &z){
    //ORDENAR LA LISTA
    z.sort();

    //ELIMINAMOS ELEMENTOS DUPLICADOS Y MOSTRAMOS LOS ELEMENTOS YA ORDENADOS
    z.unique();
    
    cout << "LISTA Z: ";
    imprimir(z);
}

void pedirDatos(list <int> &lista, int n){
    int aux = 0;

    for(int i = 0; i < n; i++){ 
        cout << "Elemento [ "<< i+1 <<" ]: ";
        cin >> aux;
        lista.push_front(aux);
    }
}
