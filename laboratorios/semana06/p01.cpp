/*
Escribe una función que reciba una cadena como puntero
 y cuente el número de vocales.
*/

#include <iostream>
using namespace std;

int contarVocales(char * cadena) {
    int contador = 0;

    // recorriendo la cadena
    while (*cadena != '\0') {
        // considerando mayúsculas
        tolower(*cadena);

        // Solucion de 2
        //usando aritmetica de caracteres:  A ...Z     A + 32 == a
        // char c = *cadena;

        // Comparando
        if (*cadena == 'a' || *cadena == 'e' || *cadena == 'i' || *cadena == 'o' || *cadena == 'u') {
            contador++;
        }
        cadena++; // nos novemos a la siguiente caracter
    }

    return contador;

}


// Ejercicio 1 considerar también a las vocales mayúsculas

// Ejercicios 2 contar las frecuencias con las que aparecen cada vocal
void contarFrecuencias(char * cadena, int frecuencias[5]) {
    for (int i = 0; i < 5; i++) {
        frecuencias[i] = 0;
    }

    while (*cadena != '\0') {
        // considerando mayúsculas
        tolower(*cadena);
        switch (*cadena) {
            case 'a': frecuencias[0]++; break;
            case 'e': frecuencias[1]++; break;
            case 'i': frecuencias[2]++; break;
            case 'o': frecuencias[3]++; break;
            case 'u': frecuencias[4]++; break;
            default:
                // bloque por defecto
                break;
        }
        cadena++;
    }
}

int main(){

    char cadena[] = "Fundamentos de programacion";

    int frecuencias[5];
    char vocales[] = "aeiou";

    int resultado = contarVocales(cadena);

    cout << "La cadena:  " << cadena << endl;
    cout << "tiene " << resultado << " vocales." << endl;

    contarFrecuencias(cadena, frecuencias);

    // Imprimiendo resultados
    for (int i = 0; i < 5; ++i) {
        cout << vocales[i] << " se repite " << frecuencias[i] << endl;
    }

    for (int i = 0; i < 255; ++i) {
        cout << i << " le corresponde " << (char)i <<endl;
    }

    return 0;
}