#include <iostream>
#include <fstream> // para manipular archivos
using namespace std;

// Funcion para abrir un archivo para lectura
ifstream & abrirArchivo(string nombreArchivo, ifstream & in) {
    in.open(nombreArchivo);

    return in;
}

// Procesamos el archivo
void Lectura(ifstream & in) {
    if(!in.is_open()) {
        cout << "Error al abrir el archivo" << endl;
    } else {
        string linea;

        while(getline(in, linea)) {
            cout << linea << endl;
        }
    }
}




int main(){

    string nombreArchivo = "archivo1.txt";
    ifstream in;

    ifstream &refArchivo = abrirArchivo(nombreArchivo, in);

    Lectura(refArchivo);

    // // Paso 1 instanciar el objeto
    // ifstream in;

    // // Paso 2 Conectar el objeto con la fuente
    // in.open("archivo1.txt");

    // // Paso 3: Leer el archivo

    // if(!in.is_open()) {
    //     cout << "Error al abrir el archivo" << endl;
    // } else {
    //     string linea;

    //     while(getline(in, linea)) {
    //         cout << linea << endl;
    //     }
    // }

    // // Paso 4:  Desconetar de la fuente
    // in.close();



    return 0;
}