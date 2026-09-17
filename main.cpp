#include <iostream>
#include <fstream> //para recibir texto
#include <sstream> //para separar el texto
//hay que incluir el h y copilar con el cpp... 
#include "Paciente.h" // para copilar hay que poner las clases "g++ main.cpp Paciente.cpp -o main.exe"
#include "Servicios.h" //es exponencial, ahora hay que poner este en el copilar
using namespace std;


void atenderPacientes(){ //metodo para atender pacientes
     cout << "1" << endl;
}
void verDepartamento(){//metodo para ver los departamentos/servicio
     cout << "2" << endl;
}
void historialAtencion(){// metodo para ver el historial de atencion
     cout << "3" << endl;
}


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

    int opcion = 0;
    while (opcion!= 4)
    {
        cout << "=== HOSPITAL MARMAJA ===" << endl;// texto menu
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atención" << endl;
        cout << "4. Salir" << endl;
        cout << "seleccione opcion: ";
        cin >>opcion;
        switch (opcion)
        {
        case 1:
            atenderPacientes();
            break;
        case 2:
            verDepartamento();
            break;
        case 3:
            historialAtencion();
            
        default:
            break;
        }

    }
    
    
    
    return 0;
}

