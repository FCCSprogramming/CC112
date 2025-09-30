/*
Crea una función que determine si una cadena es un palíndromo utilizando punteros. Un
palíndromo es una palabra o frase que se lee igual de izquierda a derecha que de derecha
a izquierda. Por simplicidad, ignora los espacios y considera las mayúsculas/minúsculas
como iguales.
Entrada: Una cadena de caracteres.
Proceso:
• Ignorar espacios.
• Convertir todas las letras a minúsculas (si es necesario).
• Comparar usando dos punteros: uno que avance desde el inicio, y otro que re-
troceda desde el final.
• Si todas las letras coinciden, es un palíndromo.
Salida: Un mensaje indicando si la cadena es un palíndromo o no.
*/

#include <iostream>
#include <cstring> // para strlen()
using namespace std;

bool esPalindromo(const char * cadena) {
    // declare punteros al inicio y al final de cadena
    const char * inicio = cadena;
    const char * fin = cadena + strlen(cadena) - 1;

    // procesar (ignorar) los espacios en blanco
    // compare si los caracteres respectivos son iguales

    while(inicio < fin) {
        if (*inicio == ' ') {
            inicio++;
        } else if (*fin == ' ') {
            fin--;
        } else if (tolower(*inicio) != tolower(*fin)) {
            return false;
        }else {
            inicio++;
            fin--;
        }
    }

    return true;
}

int main(){

    const char cadena[] = "Anita lava la tina";

    if (esPalindromo(cadena)){
        cout << "La cadena es palíndroma" <<endl;
    } else {
        cout << "La cadena no es palíndroma" <<endl;
    }

    cout << "La cadena original es: " << cadena <<endl;
    return 0;
}