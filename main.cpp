#include <iostream>
#include <fstream> //para recibir texto
#include <sstream> //para separar el texto
//hay que incluir el h y copilar con el cpp... 
#include "Paciente.h" // para copilar hay que poner las clases "g++ main.cpp Paciente.cpp -o main.exe"
#include "Servicios.h" //es exponencial, ahora hay que poner este en el copilar
#include "NodoP.h"
using namespace std;

NodoP* pacientesHead=nullptr; //Cabezera de los pacientes a atender
Servicios* serviciosHead=nullptr; //cabezera de los servicios

void atenderPacientes(){ //metodo para atender pacientes
    cout << endl;
    int cantidad=0;
    NodoP* pacienteActual = pacientesHead; //para indicar el paciente actual... lo se algo inecesario la descripcion
    int iteracion =0; //para los numeros de pacientes;

    while (pacienteActual!=nullptr){
        iteracion += 1;
        //       |
        //print \ / 
        cout << iteracion <<". "<<pacienteActual->getPaciente().getID()<<" - "<<pacienteActual->getPaciente().getNombre()<<endl;
        pacienteActual=pacienteActual->getNext(); //posicionar el siguiente en la lista

    }
    cout << "Indique cantidad de pacientes: ";
    cin>>cantidad;
    cout << endl;
    pacienteActual = pacientesHead; //reset el leer la lista
    for (int i=0; i<cantidad;i++){
        cout<< "=== ATENDIENDO PACIENTES ==="<<endl;
        cout<< "ID: "<<pacienteActual->getPaciente().getID()<<endl;
        cout<< "Nombre: " <<pacienteActual->getPaciente().getNombre()<<endl;
        cout<< "Edad: "<<pacienteActual->getPaciente().getEdad()<<endl;
        cout<< "Servicio: " <<pacienteActual->getPaciente().getServicio()<<endl;
        cout<<endl;
        
        
        //Posicionar paciente actual en el servicio, luego borrar de la lista de pacientes en espera (pacientesHead)
        Servicios* servicioActual = serviciosHead; 
        while (servicioActual!=nullptr){

            if (pacienteActual->getPaciente().getServicio()==servicioActual->getNombre()){
                //se cumple cuando coinciden los nombres de los Servicios
                cout<<"Paciente enviado a "<<pacienteActual->getPaciente().getServicio()<<endl;
                if (servicioActual->getNodoP()==nullptr){
                    servicioActual->setNodoP(pacienteActual);
                } else {
                    servicioActual->getNodoP()->setNext(pacienteActual);
                    //no esta comprobado que funcione
                }

                //borrar de pacienteHead
            }
            servicioActual = servicioActual->getNext();
        }
        pacienteActual = pacienteActual->getNext();
        cout<<endl;
    }
     
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

    
    NodoP* pacientesLast=nullptr;
    
    //creacion de pacientes
    while (getline(arch,linea)){
        //Separacion del texto
        stringstream ss(linea);
        string ID, nombre, edad, servicio;
        getline(ss, ID ,';'); //para almacenar las partes
        getline(ss, nombre, ';');
        getline(ss, edad, ';');
        getline(ss, servicio, ';');

        int intEdad = stoi(edad); //para pasarlo a int
        

        Paciente cliente(ID,nombre,intEdad,servicio); //crea el paciente (Sinceramente desconozco porque lo llame cliente)
        cout << cliente.getNombre() << endl;

        NodoP* pacienteNew = new NodoP(cliente);

        if (pacientesHead == nullptr){
            pacientesHead = pacienteNew; //guardas el primero
            pacientesLast = pacienteNew; //guardas el ultimo que es el primero
        } else {
            pacientesLast->setNext(pacienteNew); //el anterior que era el ultimo almacena el actual en su siguiente
            pacientesLast = pacienteNew; //se pociciona el actual como ultimo
        }
       
    }

    //creacion de departamentos
    //supongo que solo son los 8 departamentos
    NodoP* urgencias(nullptr);
    serviciosHead =new Servicios("Urgencias", urgencias);

    NodoP* medicinaGeneral(nullptr);
    Servicios* servicioMedGen=new Servicios("Medicina General", medicinaGeneral);
    serviciosHead->setNext(servicioMedGen); 

    NodoP* cardiologia(nullptr);
    Servicios* servicioCardio=new Servicios("Cardiologia", cardiologia);
    servicioMedGen->setNext(servicioCardio);

    NodoP* neulogia(nullptr);
    Servicios* servicioNeuro=new Servicios("Neurologia", neulogia);
    servicioCardio->setNext(servicioNeuro);

    NodoP* traumatologia(nullptr);
    Servicios* servicioTrauma=new Servicios("Traumatologia", traumatologia);
    servicioNeuro->setNext(servicioTrauma);

    NodoP* cirugia(nullptr);
    Servicios* servicioCirugia=new Servicios("Cirugia", cirugia);
    servicioTrauma->setNext(servicioCirugia);

    NodoP* pediatria(nullptr);
    Servicios* servicioPed=new Servicios("Pediatria", pediatria);
    servicioCirugia->setNext(servicioPed);

    NodoP* hospital(nullptr);
    Servicios* servicioHospital=new Servicios("Hospitalizacion", hospital);
    servicioPed->setNext(servicioHospital); 

    //siento que debe haber una mejor manera... 
    


    //menu
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

