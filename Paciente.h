#pragma once
# include <string>
using namespace std;

class Paciente{
private:
    int ID;
    string nombre;
    int edad;
    string servicio;
public:
    Paciente(int ID & edad, string nombre & servicio);
    ~Paciente();
    

}