/*
Crea una función que reciba un entero como parámetro y devuelva un
puntero a un arreglo dinámico de ese tamaño, lleno de números aleatorios.
Muestre el arreglo en pantalla
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int * arregloAleatorio(int n) {
    int* arr = new int[n];
    srand(time(0));
    for (int i = 0; i < n; ++i ){
        arr[i] = rand() % 50;
    }
    return arr;
} 

void imprimir(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}

int main(){

    int* arr = arregloAleatorio(5);
    imprimir(arr, 5);

    return 0;
}