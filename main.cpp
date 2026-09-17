#include <iostream>
#include <fstream> //para recibir texto
#include <sstream> //para separar el texto
//hay que incluir el h y copilar con el cpp... 
#include "Paciente.h" // para copilar hay que poner las clases "g++ main.cpp Paciente.cpp -o main.exe"
#include "Servicios.h" //es exponencial, ahora hay que poner este en el copilar
using namespace std;



int main(){
    ifstream arch("pacientes.txt");
    string linea;
    while (getline(arch,linea)){
        //Separacion del texto
        stringstream ss(linea);
        string id, nombre, edad, servicio;
        getline(ss, id ,';'); //para almacenar las partes
        getline(ss, nombre, ';');
        getline(ss, edad, ';');
        getline(ss, servicio, ';');

        int intID = stoi(id); //para pasarlo a int
        int intEdad = stoi(edad); 
        

        Paciente cliente(intID,nombre,intEdad,servicio); //crea el paciente (Sinceramente desconozco porque lo llame cliente)
        cout << cliente.getNombre() << endl;
        cout << linea<< endl;
    }

    cout << "compila" << endl;
    
    return 0;
}