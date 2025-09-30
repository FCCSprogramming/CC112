/*
Escribe una función que reciba una cadena y elimine todos
los espacios en blanco, modificando la cadena original
mediante punteros
*/
#include <iostream>
using namespace std;

void eliminaEspacios(char * cadena) {
    char* cad_original = cadena;
    char* cad_modificada = cadena;

    while(*cad_original != '\0') {
        if (*cad_original != ' ') {
            *cad_modificada = *cad_original;
            cad_modificada++;
        }
        cad_original++;
    }
    *cad_modificada = '\0';

}
int main(){

    char cadena[] = "  Cadena      modificable ";
    eliminaEspacios(cadena);

    cout << "REsultado: " << cadena;
    return 0;
}