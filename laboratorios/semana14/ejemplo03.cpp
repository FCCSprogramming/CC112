#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    // Constructores
    Fecha(int d, int m, int a); // constructor
    Fecha(): dia(0), mes(0), anio(0){};
    void mostrar();
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

    Fecha cumple2; // se crea el objeto y se inicializan con lo que se encuentre en memoria
    

    cumple1.mostrar();
    cumple2.mostrar();
    return 0;
}