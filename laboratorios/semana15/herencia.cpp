#include <iostream>
#include <string>
using namespace std;

// Clase base
class Animal {
public:
    string nombre;

    Animal(const string& n) : nombre(n) {}

    void informacion() {
        cout << "Soy un animal llamado " << nombre << endl;
    }
};

// Clase derivada
class Perro : public Animal {
public:
    Perro(const string& n) : Animal(n) {}

    void ladrar() {
        cout << nombre << " está ladrando." << endl;
    }
};

int main() {
    Perro p("Bobby");

    // Métodos heredados
    p.informacion();  
    // Método propio de Perro
    p.ladrar();

    return 0;
}
