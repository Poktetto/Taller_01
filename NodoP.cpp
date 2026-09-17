#include "NodoP.h"
#include "Paciente.h"

using namespace std;

NodoP::NodoP(Paciente paciente){
    this->paciente= paciente;
    this->next =nullptr;
}
Paciente NodoP ::getPaciente(){return this->paciente;}
NodoP* NodoP::getNext(){return this ->next;}

NodoP::~NodoP(){}

