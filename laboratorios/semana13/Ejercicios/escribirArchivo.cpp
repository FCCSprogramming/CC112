#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream wfile("archivo2.txt");

    // Esccribimos en el archivo 
    if (!wfile.is_open()) {
        cout << "Error al abrir el archivo" <<endl;
    } else {
        string linea;

        cout << " Ingrese un texto: ";
        getline(cin, linea);
        
        wfile << linea << endl;

        cout << "Se realizo la escritura de forma correcta" <<endl;

        wfile.close();
    }

    ofstream wfile1("archivo2.txt", ios::app);

    wfile1 << "seccion A" <<endl;

    return 0;
}