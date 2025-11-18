/*
Ejemplo de archivo binario
Aprenderemos a:
- usar fstream con los modos ios::binary, ios::in, ios::out, ios::app.
- usar write() y read() en lugar de << o >>.
- guardar y recuperar estructuras.



Implementar un programa para almacenar una lista de estudiantes con:
nombre (máx 20 caracteres),
código (entero),
nota (float).

Use un archivo binario llamado "estudiantes.dat".
*/

#include <iostream>
#include <fstream>
using namespace std;

// 1. Definir la estructura
struct Estudiante {
    char nombre[20];  //usar arreglos estaticos
    int codigo;
    float nota; 
};

// 2. funcion para agregar un estudiante (ESCRITURA BINARIA)

void agregarEstudiante() {
    ofstream archivo("estudiantes.dat", ios:: app | ios::binary);
    if (!archivo) {
        cout << "Error, no se pudo abrir";
    } else {
      Estudiante e1;
      cout << "Nombre: ";
      cin.getline(e1.nombre,20);
      
      cout << "Código: ";
      cin >> e1.codigo;

      cout << "Nota: ";
      cin >> e1.nota;
      cin.ignore();

      //ESCRITURA BINARIA
      archivo.write(reinterpret_cast<char*>(&e1),sizeof(Estudiante));

      archivo.close();

    }
}


// 3. Función para mostrar los registros (LECTURA BINARIA)

void mostrarEstudiantes() {
    fstream archivo("estudiantes.dat", ios::in|ios::binary);
    if (!archivo) {
        cout << "Error, no se pudo abrir";
    } else {
      Estudiante e1;
      

      //LECTURA BINARIA
      cout << "\nLISTA DE ESTUDIANTES\n";
      while (archivo.read(reinterpret_cast<char*>(&e1),sizeof(Estudiante))) {
        cout << "Nombre: " << e1.nombre << endl;
        cout << "Código: " << e1.codigo << endl;
        cout << "Nota: "  << e1.nota << endl;
        cout << "******************************\n";
      }

      archivo.close();

    }

}

int main(){

    int opcion;

    do {
        cout << "\nMenu\n";
        cout << "1. Agregar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Salir\n";
        cin >> opcion;

        cin.ignore();

        switch(opcion) {
            case 1: agregarEstudiante();
            break;
            case 2: mostrarEstudiantes();
            break;
            case 3: cout << "Saliendo...\n";
        }

    } while (opcion != 3);

    return 0;
}



/*
Ejercicio
Crea un archivo binario llamado "productos.dat" que almacene:
- nombre del producto (char[20])
- código (int)
- precio (float)
- stock (int)

Implementar:
- Agregar producto
- Mostrar productos
- Buscar producto por código
- Actualizar el stock de un producto (lectura/escritura binaria)
*/


