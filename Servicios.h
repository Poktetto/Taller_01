#pragma once
# include <string>
using namespace std;

class Servicios{
private:
    string nombre; //despues hay que cambiarlo por el Stack correspondiente
    Servicios* siguiente; 
public:
    Servicios(string nombre);
    void setSiguiente(Servicios* siguiente);

    ~Servicios();
};