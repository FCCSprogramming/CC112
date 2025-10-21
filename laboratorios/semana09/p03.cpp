/*
Escribe un programa que pida al usuario una cadena de caracteres y la
almacene dinámicamente en memoria.
*/

#include <iostream>
#include <cstring>
using namespace std;

char* lecturaCadenaDinamica() {
    char cad[100];
    cout << "Ingrese la cadena: ";

    cin.getline(cad, 100);

    int len = strlen(cad);


    char* cadDinamica = new char[len + 1]; // reservamos espacio en el heap

    strcpy(cadDinamica, cad);

    return cadDinamica;
}

int main(){

    char* c = lecturaCadenaDinamica();

    cout << c <<endl;

    delete[] c;
    c = nullptr;

    return 0;
}