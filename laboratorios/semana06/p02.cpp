/*
implementa una función que invierta una cadena de caracteres
utilizando punteros.
*/



#include <iostream>
#include <cstring> // strlen();
using namespace std;

void invertirCadena(char * cadena) {
    int n = strlen(cadena);
    char *inicio = cadena;
    char *fin = cadena + n -1;

    while(inicio < fin) {
        //completar el intercambio   .....otra froma: swap(*inicio,*fin);
        char temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--; 
    }
}

int main(){
    char cadena[] = "Fundamentos de programacion";

    invertirCadena(cadena);

    cout << "Cadena invertida " << endl;
    cout << cadena << endl;

    return 0;
}