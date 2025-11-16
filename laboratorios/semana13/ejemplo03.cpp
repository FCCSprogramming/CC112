// ARCHIVO SECUENCIAL

#include <iostream>
#include <fstream>
using namespace std;

struct Alumno {
    string nombre;
    int edad;
    double promedio;
};

int main(){
    ofstream out("alumnos.txt");

    if (!out.is_open()) {
        cerr << "Error al abrir.\n";
    } else {
        Alumno a = {"Mariana", 20, 16.5};
        Alumno b = {"Manuel", 22, 15.5};

        out << a.nombre << " " << a.edad << " " << a.promedio << "\n";
        out << b.nombre << " " << b.edad << " " << b.promedio << "\n";
        
        out.close();

        cout << "Archivo secuencial creado.\n";
    }

    return 0;
}