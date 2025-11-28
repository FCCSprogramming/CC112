#include <iostream>
using namespace std;

// Una clase puede agrupar atributos y funciones

// 1. Definir la clase

class Alumno {
    int edad;
    string nombres;
};


class Punto {
private:
    double x; // Datos
    double y;

public:
    void inicializar(double px, double py); // funciones
    void mostrar();
};

// 2. Implementacion de las funciones
void Punto:: inicializar(double px, double py) {
    x = px;
    y = py;
}
void Punto:: mostrar(){
    cout << "(" << x << "; " << y << ")" <<endl;
}


int main(){
    // 3. Aplicación
    Punto p; // crear, instanciar un objeto

    p.inicializar(3,4);

    p.mostrar();

    return 0;
}