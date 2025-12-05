// EJEMPLO DE HERENCIA  Y POLIMORFISMO EN C++

#include <iostream>
#include <string>
using namespace std;

/*
CLASE BASE
    - Contiene al menos un método virtual (para alcanzar el polimorfismo)
    - Los destructores deben ser virtuales para evitar fugas de memoria cuando 
      se usa polimorfismo con punteros a la clase base.
*/
class Animal {
protected:   // Protegido (en lugar de private) para que sea accesible en clases derivadas
    string nombre;  
public:
    /*
        Uso del constructor de parametro por referencia constante:
        - (const string& n): evita crear copias innecesarias del string.
        - Pasar una cadena por valor implica generar una copia  del objeto (string).
        - Pasar por referencia evita la copia.
        - const evita que accidentalmente modifiquemos el parámetro.
    */
                              // lista de inicializadores: Permite inicializar const, referencias y objetos complejos.
    Animal(const string& n) : nombre(n) {
        cout << "Construyendo Animal: " << this->nombre << endl;  // note que podemos precindir de this (es claro que n = parametro, nombre=miembro de dato)
    }

    /*
        El destructor  virtual es obligatorio cuando vamos a destruir objetos derivados mediante punteros
        a la clase base. Permite que primero se llame al destructor de la clase derivada, y luego
          al destructor de la clase base.
    */
    virtual ~Animal() {
        cout << "Destruyendo Animal: " << this->nombre << endl;
    }

    /*
        Método virtual: Permite redefinir comportamiento en clases derivadas.
        Si NO fuera virtual, se ejecutaría la versión base incluso si el puntero
        apunta a un objeto derivado.
    */
    virtual void hablar() {
        cout << nombre << " hace un sonido desconocido." << endl;
    }

    /*
        No virtual: Los métodos no virtuales no se pueden polimorfizar.
        Su comportamiento será siempre el mismo, sin importar la instancia real.
    */
    void informacion() {
        cout << "Mi nombre es " << this->nombre << endl;
    }
};


/*
    CLASE DERIVADA 1
*/
class Perro : public Animal {
public:
    // Las clases base deben construirse antes que las derivadas, por lo que es obligarotio Animal(n)
    Perro(const string& n) : Animal(n) {
        cout << "Construyendo Perro: " << nombre << endl;
    }

    ~Perro() override {
        cout << "Destruyendo Perro: " << nombre << endl;
    }

    /*
        Redefinimos (override) el método virtual "hablar".
        Esto permite el polimorfismo.
        El programa ejecutará esta versión cuando un Animal* apunte a un Perro.
    */
    void hablar() override {
        cout << nombre << " ladra." << endl;
    }
};


/*
    CLASE DERIVADA 2
*/
class Gato : public Animal {
public:
    // IMPORTANTE: los miembros heredados (nombre) se inicializan a través del constructor
    // de la clase base, no desde la derivada.
    Gato(const string& n): Animal(n) {
        cout << "Construyendo Gato: " << nombre << endl;
    }

    ~Gato() override {
        cout << "Destruyendo Gato: " << nombre << endl;
    }

    void hablar() override {
        cout << nombre << " maúlla." << endl;
    }
};



int main() {

    /*
        1. Polimorfismo mediante punteros a la clase base:
           Animal* puede apuntar a un Perro o un Gato.

        2. new crea objetos en memoria dinámica.
           Luego estos deben eliminarse manualmente con delete.

        3. Este ejemplo usa puntero nativo;... se prefiere smart pointers (Proyecto Final).
    */
    Animal* a = new Perro("Bethoven");
    Animal* b = new Gato("Felix");


    // POLIMORFISMO:
    // Se llama al método redefinido en la clase correcta.
    a->hablar();  // Llama a Perro::hablar
    b->hablar();  // Llama a Gato::hablar

    // Método NO virtual:
    // Siempre se ejecuta desde la clase base.
    a->informacion();
    b->informacion();

    /*
        IMPORTANTE:
        Los destructores NO liberan automáticamente la memoria creada con new,
        porque liberar memoria dinámica NO es responsabilidad del destructor.
        
        delete:
        1. Ejecuta el destructor del objeto (derivado y luego del objeto base)
        2. Libera la memoria asociada al objeto
    */
    delete a;
    delete b;

    return 0;
}


