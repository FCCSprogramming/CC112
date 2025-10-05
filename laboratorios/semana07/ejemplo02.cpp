/*
Dado una lista de nombres almacenados en un arreglo de cadenas, utilice 
punteros a cadenas de caracteres y

1. Escriba una función que determine si un nombre está o no en el arreglo

2. Escriba una función que permita concatenar 2 nombres elegidos

3. Escriba una función que permita encontrar una subcadena

*/

#include <iostream>
#include <cstring> //strlen(), strcmp(), strstr(),
using namespace std;

bool nombreEnArrerglo(const char *nombres[], int n, const char *nombre) {
    for (int i = 0; i < n; ++i) {
        if(strcmp(*(nombres + i),nombre) == 0){
            return true;
        }
    }

    return false;
}


void concatenaCadenas(char* nombre1, char* nombre2, char* resultado) {

    strcpy(resultado, nombre1);
    strcat(resultado, nombre2);
}

bool encontrarSubcadena (char* nombre, char* subcadena) {
    char *ptr = strstr(nombre, subcadena);
    if(ptr == nullptr) {
        return false;
    }
    return  true;
}

int main(){
    //declaramos un arreglo de punteros a char
    const int N = 4;
    const char *nombres[4] = {"Pedro", "Juan", "Lucia", "Anabel"};
    //char nombres[4][15] = {}; //para modificar las cadenas

    const char* nombre = "Lucia";
    if(nombreEnArrerglo(nombres, N, nombre)){
        cout << nombre << " está en el arreglo" <<endl;
    } else {
        cout << nombre << " no está en el arreglo" <<endl;
    }

    // completar las llamas a las demás funciones
    return 0;
}