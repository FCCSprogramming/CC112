/*
Escribir un programa que reciba la siguiente cadena
"123, 45.67, -89, 1001, 23.45, 6789, 12.45"
y calcule la suma de todos los números enteros contenidos en ella

*/

#include <iostream>
#include <>
#include <cmath> // floor()
using namespace std;

int sumarEnteros(char * cadena) {
    int suma = 0;
    char* token = strtok(cadena, ", ");

    while (token != nullptr) {
        double n = atof(token);
        if (floor(n) == n) {
            suma += n;
            cout << n << endl;
        }
        token = strtok(nullptr,", ");
    }
    return suma;
}

int main(){
    char cadena[] = "123, 45.67, -89, 1001, 23.45, 6789, 12.45";

    int res = sumarEnteros(cadena);

    cout << "La suma es: " << res << endl;

    return 0;
}