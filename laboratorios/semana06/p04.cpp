/*
Crea una función que reciba dos cadenas y determine si son anagramas utilizando úni-
camente punteros. Un anagrama es cuando dos palabras contienen las mismas letras en
diferente orden. Es decir, ambas palabras deben tener el mismo número de caracteres y
las mismas letras, aunque posiblemente en un orden distinto.
Entrada: Dos cadenas de caracteres.
Proceso: Comprobar que las cadenas tienen la misma longitud, luego ordenar ambas
cadenas alfabéticamente (puedes usar un algoritmo de ordenamiento como burbuja
con punteros) y finalmente comparar letra por letra usando punteros.
Salida: Un mensaje que indique si las cadenas son anagramas o no.
*/

#include <iostream>
#include <cstring>
using namespace std;

void ordenaCadena(char* cadena){
    int n = strlen(cadena);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (*(cadena + j) > *(cadena + j + 1)) {
                swap(*(cadena + j), *(cadena + j + 1));
            }
        }
    }
}

bool esAnagrama(char* cad1, char* cad2){
    if (strlen(cad1) != strlen(cad2)) {
        return false;
    }

    //generando copias
    char copia1[50], copia2[50];

    //usamos la funcion strcpy();
    strcpy(copia1, cad1);
    strcpy(copia2, cad2);

    ordenaCadena(copia1);
    ordenaCadena(copia2);

    char *p1 = copia1;
    char *p2 = copia2;

    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) {
            return false;
        }
        p1++;
        p2++;
    }

    return true;
}

int main(){

    char cad1[]="oir";
    char cad2[]="rio";

    if (esAnagrama(cad1, cad2)) {
        cout << cad1 << " y  " << cad2 << " son anagramas " <<endl;
    } else {
        cout << "no son anagramas" <<endl;
    }

    return 0;
}