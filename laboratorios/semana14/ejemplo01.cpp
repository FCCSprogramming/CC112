#include <iostream>
using namespace std;

// Una clase puede agrupar atributos y funciones

// 1. Definir la clase
class Punto {
private:
    double x;
    double y;

public:
    void inicializar(double px, double py);
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
    Punto p; // crear un objeto

    p.inicializar(3,4);

    p.mostrar();

    return 0;
}