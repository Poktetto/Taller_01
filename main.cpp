#include <iostream>
#include <fstream> //para recibir texto
using namespace std;



int main(){
    ifstream arch("pacientes.txt");
    string linea;
    while (getline(arch,linea)){
        cout << linea<< endl;
    }

    cout << "compila" << endl;
    
    return 0;
}