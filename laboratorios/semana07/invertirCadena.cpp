#include <iostream>
#include <cstring> // strlen()
using namespace std;

void invertirCadena(char *cadena) {
    char *inicio = cadena;
    char *fin = cadena + strlen(cadena) - 1;

    while (inicio < fin) {
        char temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        //actualizamos los punteros
        inicio++;
        fin--;
    }
}

int main(){
    char cadena[] = "Cadena de prueba";

    cout << "Cadena original: " << cadena << endl;

    invertirCadena(cadena);

    cout << "Cadena invertida: " << cadena << endl;



    return 0;
}