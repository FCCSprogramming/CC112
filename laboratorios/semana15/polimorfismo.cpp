#include <iostream>
#include <string>
using namespace std;

// Clase base con método virtual
class Animal {
public:
    virtual void hablar() {
        cout << "El animal hace un sonido." << endl;
    }

    virtual ~Animal() {} // buena práctica
};

// Clases derivadas
class Perro : public Animal {
public:
    void hablar() override {
        cout << "El perro ladra." << endl;
    }
};

class Gato : public Animal {
public:
    void hablar() override {
        cout << "El gato maúlla." << endl;
    }
};

int main() {
    Animal* a = new Perro();
    Animal* b = new Gato();

    // POLIMORFISMO: se ejecuta la versión correcta
    a->hablar();  // Perro
    b->hablar();  // Gato

    delete a;
    delete b;
    return 0;
}
