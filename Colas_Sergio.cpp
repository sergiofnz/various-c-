/*Desarrollar un programa para simular la cola en un banco y determinar cuántas
personas de cada género son atendidas en un determinado periodo de
tiempo y cuántos depósitos y retiros se hacen. Se debe tomar como
entrada el cliente que llega, el cual debe aportar la edad, sexo, tipo
de transacción y condición de salud. Si el cliente es de la tercera edad
va a una cola, si es mujer y esta  embarazada va a otra cola junto con
los discapacitados, y el resto sin condiciones especiales entran a una
tercera cola. Se debe fijar un tiempo de duración por transacción. El
programa debe ser implementado en C++. Aparte de evaluar los
conocimientos teórico prácticos tendrán puntos extras por su ingenio y
creatividad. Deben entregar la explicación de como se ejecuta la cola
(instructivo), el algoritmo del mismo y su codificación (archivo cpp).
El programa debe correr*/



#include <bits/stdc++.h>
#include "persona.h"
using namespace std;



int main(){

    system("clear");
    // Creamos las colas 
    queue<Persona> Cnormal;     //cola de personas normales 
    queue<Persona> Cdiscaemba;  //cola de personas discapacitados y embarazadas
    queue<Persona> Cviejo;      //cola de personas de tercera edad 
    queue<Persona> Caux;        
    char eleccion;
    int zip;
    
    do{
        //menu
        cout << "\n\t\tELIJA UNA OPERACION\n";
        cout << "\t\t[1]-Agregar a la cola \n";
        cout << "\t\t[2]-Ver estadistas de la cola y finalizar\n";
        cout << "\t\t[3]-salir\n";
        cout << "\t\t------: ";
        cin >> zip;

        if(zip == 1){

            //menu secundario
            system("clear");
            cout << "\n\t\t COLA DE BANCO\n\n";
            cout << "\n\tDebe suministrar los siguientes datos\n\n";
            cout << "\tseleccione su estatus:\n";
            cout << "\t[1]-NORMAL\n";
            cout << "\t[2]-DISCAPACITADO O EMBARAZADA\n";
            cout << "\t[3]-TERCERA EDAD (a partir de 60 años)\n";
            cout << "\t-----------: ";
            cin >> eleccion;
        
            switch(eleccion){
            
            int anios, opT, opG;

                case '1': //NORMAL
                            //datos
                    cout << "\tEdad: ";
                    cin >> anios;
                    cout <<"\n\tGENERO\n";
                    cout <<"\t[1]-Masculino\n";
                    cout <<"\t[2]-Femenino\n";
                    cout << "\t---: ";
                    cin >> opG;
                    cout <<"\tTIPO DE TRASACCION\n";
                    cout <<"\t[1]-Deposito\n";
                    cout <<"\t[2]-Retiro\n";
                    cout << "\t---: ";
                    cin >> opT;
                    //condicionales para cargar datos a la cola segun los datos suministrados
                    if(opG == 1 && opT == 1) encolar(Persona(anios, Tipo::NORMAL, Sexo::Masculino, TransaccionB::Deposito),Cnormal, Cdiscaemba, Cviejo);
                    if(opG == 1 && opT == 2) encolar(Persona(anios, Tipo::NORMAL, Sexo::Masculino, TransaccionB::Retiro),Cnormal, Cdiscaemba, Cviejo);
                    if(opG == 2 && opT == 1) encolar(Persona(anios, Tipo::NORMAL, Sexo::Femenino, TransaccionB::Deposito),Cnormal, Cdiscaemba, Cviejo);
                    if(opG == 2 && opT == 2) encolar(Persona(anios, Tipo::NORMAL, Sexo::Femenino, TransaccionB::Retiro),Cnormal, Cdiscaemba, Cviejo); 
                    break;
        
                case '2': // DISCAPACITADOS Y EMBARAZADAS
                            //datos
                    cout << "\tEdad: ";
                    cin >> anios;
                    cout <<"\n\tGENERO\n";
                    cout <<"\t[1]-Masculino\n";
                    cout <<"\t[2]-Femenino\n";
                    cout << "\t---: ";
                    cin >> opG;
                    cout <<"\tTIPO DE TRASACCION\n";
                    cout <<"\t[1]-Deposito\n";
                    cout <<"\t[2]-Retiro\n";
                    cout << "\t---: ";
                    cin >> opT;
                    //condicionales para cargar datos a la cola segun los datos suministrados
                    if(opG == 1 && opT == 1) encolar(Persona(anios, Tipo::DISCAEMBA, Sexo::Masculino, TransaccionB::Deposito),Cnormal, Cdiscaemba, Cviejo); 
                    if(opG == 1 && opT == 2) encolar(Persona(anios, Tipo::DISCAEMBA, Sexo::Masculino, TransaccionB::Retiro),Cnormal, Cdiscaemba, Cviejo); 
                    if(opG == 2 && opT == 1) encolar(Persona(anios, Tipo::DISCAEMBA, Sexo::Femenino, TransaccionB::Deposito),Cnormal, Cdiscaemba, Cviejo); 
                    if(opG == 2 && opT == 2) encolar(Persona(anios, Tipo::DISCAEMBA, Sexo::Femenino, TransaccionB::Retiro),Cnormal, Cdiscaemba, Cviejo);  
                    break;
        
                case '3': //TERCERA EDAD 
                            //datos
                    cout << "\tEdad: ";
                    cin >> anios;
                    cout <<"\n\tGENERO\n";
                    cout <<"\t[1]-Masculino\n";
                    cout <<"\t[2]-Femenino\n";
                    cout << "\t---: ";
                    cin >> opG;
                    cout <<"\tTIPO DE TRASACCION\n";
                    cout <<"\t[1]-Deposito\n";
                    cout <<"\t[2]-Retiro\n";
                    cout << "\t---: ";
                    cin >> opT;
                    //condicionales para cargar datos a la cola segun los datos suministrados
                    if(opG == 1 && opT == 1) encolar(Persona(anios, Tipo::VIEJO, Sexo::Masculino, TransaccionB::Deposito),Cnormal, Cdiscaemba, Cviejo); 
                    if(opG == 2 && opT == 1) encolar(Persona(anios, Tipo::VIEJO, Sexo::Femenino, TransaccionB::Deposito),Cnormal, Cdiscaemba, Cviejo); 
                    if(opG == 2 && opT == 2) encolar(Persona(anios, Tipo::VIEJO, Sexo::Femenino, TransaccionB::Retiro),Cnormal, Cdiscaemba, Cviejo);   
                    break;
            }

        }else if(zip == 2){
        // COMPROBACION DE CONTENIDO EN COLAS Y EN CASO DE HACER POP A UNA COLA VACIA  
        //INDICA LA ADVERTENCIA 
            Persona normal_aux, discaemba_aux, viejo_aux; //auxiliares 
            bool n_empty = false;
            bool o_empty = false; 
            bool h_empty = false;
            //cola normal
            try{ normal_aux = Cnormal.front();}
            catch (const exception &e){
                cerr << e.what() << '\n';
                cout << "\n\t\tcola de personas normal vacia \n";
                n_empty = true;
            }
            //cola tercera edad 
            try{ viejo_aux = Cviejo.front(); }
            catch (const exception &e){
                cerr << e.what() << '\n';
                cout << "\n\t\tcola de personas de tercera edad vacia \n";
                o_empty = true;
            }
            //cola discapacitados y embarazadas 
            try{ discaemba_aux = Cdiscaemba.front(); }
            catch (const exception &e){
                cerr << e.what() << '\n';
                cout << "\n\t\tcola de discapacitados y embarazadas vacia\n" <<endl;
                h_empty = true;
            }
                     
            cout << "\n\n\t\tcantidad de personas en la cola normal: " << Cnormal.size();
            cout << "\n\t\tcantidad de personas en la cola de discapacitados y embarazadas: " << Cdiscaemba.size();
            cout << "\n\t\tcantidad de personas en la cola de tercera edad: " << Cviejo.size();
            desencolar(Cnormal, Cdiscaemba, Cviejo, Caux);
            return 0;

        }else if(zip == 3)return 0; // salir del programa
    }while(true);
}
