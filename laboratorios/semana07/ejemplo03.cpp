/*
Dada la siguiente cadena: “--Aqui tenemos, un ejemplo de cadena.”, escribir una función que elimine los caracteres - , y . 
La salida debe ser:  “Aqui tenemos un ejemplo de cadena”

*/

#include <iostream>
using namespace std;

void eliminaCaracteres(char * cadena) {
    char * recCadena = cadena;
    char * resultado = cadena;
    while (*recCadena != '\0') {
        if (*recCadena != '-' && *recCadena != '.' && *recCadena != ',') {
            *resultado = *recCadena;
            resultado++;
        }
        recCadena++;
    }
    *resultado = '\0';
}

int main(){
    char cadena[] = "------Aqui tenemos, un, ejemplo de cadena....";
    eliminaCaracteres(cadena);
    cout << "Resultado: " << cadena <<endl;
    return 0;
}