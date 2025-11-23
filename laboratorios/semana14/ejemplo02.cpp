#include <iostream>
using namespace std;


// 1. Defninición de clase
class Rectangulo {
private:
    double ancho;
    double largo;

public:
    void inicializar(double a, double l);
    double area() const; // indicamos que la función no puede modificar los mienbros de datos de la clase
    double perimetro() const;
    void mostrar() const;
};


// 2. implementacion de las funciones
void Rectangulo:: inicializar(double a, double l) {
    ancho = a;
    largo = l;
}

double Rectangulo:: area() const {
    return ancho * largo;
}
double Rectangulo:: perimetro() const {
    return 2* (largo + ancho);
}

void Rectangulo:: mostrar()  const {
    cout<< "Ancho: " << ancho <<endl;
    cout << "Altura: " << largo <<endl;
    cout << "Área: " << area() <<endl;
    cout << "Perimetro: " << perimetro() <<endl;

}




int main(){

    // # aplicaion
    Rectangulo r;

    r. inicializar(4,3);

    r.mostrar();


    


    return 0;
}