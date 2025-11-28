#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    // Constructores (funciones especiales)
    Fecha(int d, int m, int a); // constructor de paremetros
    Fecha(): dia(0), mes(0), anio(0){}; // constructor por defencto (con lista de inicializadores)
    void mostrar();

    // implementando un destructor
    ~Fecha(){
        cout << "Llamando al destructor" << endl;
    };
};

//Definicion de funciones miembro
Fecha :: Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

 void Fecha::mostrar() {
cout << dia << "/" << mes << "/" << anio <<endl;
 }


int main(){

    Fecha cumple1(12,12,2025);

    Fecha cumple2; // se crea el objeto y se inicializan con 0 0 0
    

    //cumple1.mostrar();
    cumple2.mostrar();
    return 0;
}