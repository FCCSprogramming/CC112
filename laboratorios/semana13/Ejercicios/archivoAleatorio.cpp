/*
Implementar un programa para guardar
un conjunto de estudiantes en un archivo binario de registros
de tamaño fijo, y luego modificar directamente el estudiante
número k, sin leer ni reescribir todo el archivo.
(Use archivos de acceso aleatorio)
*/

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// 1 Creamos el registro
struct Estudiante {
    char nombre[20]; // tamaño fijo
    int edad; // tamaño fijo
};
// 24 bytes

// 2 Agregamos estudiante al final
void agregarEstudiante(const char* archivo, Estudiante & e){ 
    ofstream out(archivo, ios::binary | ios::app);
    out.write(reinterpret_cast<char*>(&e), sizeof(Estudiante));
}


// 3. Leer un registro específico por indice
bool leerEstudiante(const char* archivo, Estudiante & e, int indice) {
    ifstream in(archivo, ios::binary);
    if (!in.is_open()) {
        return false;
    }

    int posicion = indice * sizeof(Estudiante);

    //  POSICIONAR EL PUNTERO DE LECTURA 
    in.seekg(posicion);

    // leermos el registro específico
    in.read(reinterpret_cast<char*>(&e), sizeof(Estudiante));

    return in.good(); //in.fail()
    
}


// 4 . Modificar el estudiante especifico (ACCESO ALEATORIO)

bool modificarEstudiante(const char* archivo, Estudiante & otro, int indice) {
    fstream file(archivo, ios::in | ios::out |ios::binary);
    if (!file.is_open()) {
        return false;
    }

    int posicion = indice * sizeof(Estudiante);

    //  POSICIONAR EL PUNTERO DE ESCRITURA 
    file.seekp(posicion);

    // reescribimos en  el registro específico
    file.write(reinterpret_cast<char*>(&otro), sizeof(Estudiante));

    return file.good(); //in.fail()
    
}


int main(){

    const char* archivo = "alumnos.dat";

    // Agrego el primer estudiante
    Estudiante e;
    strcpy(e.nombre, "Juan");
    e.edad = 24;
    agregarEstudiante(archivo,e);

    strcpy(e.nombre, "Pedro");
    e.edad = 21;
    agregarEstudiante(archivo,e);

    strcpy(e.nombre, "Maria");
    e.edad = 17;
    agregarEstudiante(archivo,e);


    // modificando estudiante en la posicion 1
    Estudiante temp;

    if(leerEstudiante(archivo,temp,1)) {
        cout << "Datos originales:  " << temp.nombre << " - " << temp.edad <<endl;
    }


    Estudiante otro;
    strcpy(otro.nombre, "Pedro Perez");
    otro.edad = 24;

    modificarEstudiante(archivo,otro,1);

     if(leerEstudiante(archivo,temp,1)) {
        cout << "Datos Modificados:  " << temp.nombre << " - " << temp.edad <<endl;
    }








    return 0;
}





















/*
Ejercicio
Crear un archivo binario llamado "empleados.dat" que almacene registros de tamaño fijo de empleados.
Cada empleado debe tener la siguiente estructura:
struct Empleado {
    char nombre[30];
    int edad;
    float sueldo;
};


Valide que el índice no sea mayor al número de empleados.
No reescribir todo el archivo para modificar un registro (acceso directo obligatorio).

Implemente funciones  y presente la salida como un menú interactivo
1. Agregar empleado
2. Mostrar empleado por índice
3. Modificar empleado por índice
4. Mostrar número total de empleados
5. Salir

*/