#pragma once
#include "Paciente.h" //aca se coloca?
# include <string>
using namespace std; 
// nodo para crear la lista de pacientes
class NodoP{
private:
    Paciente paciente;
    NodoP* next;
public:
    NodoP(Paciente paciente);
    Paciente getPaciente(); //deberia entregar el paciente
    NodoP* getNext();

    ~NodoP();
};


