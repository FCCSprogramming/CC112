/*
Crea una función que reciba dos arreglos dinámicos y su tamaño, y
devuelva un nuevo arreglo dinámico que sea la concatenación de ambos.
*/

#include <iostream>
using namespace std;

int* concatenacionDinamica (int* a, int n1, int *b, int n2) {
    int *pcat = new int[n1 + n2];

    for(int i= 0; i < n1; ++i) {
        pcat[i] = a[i];
    }

     for(int j= 0; j < n2; ++j) {
        pcat[j + n1] = b[j];
    }

    return pcat;

}

void imprimir(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}


int main(){
    int*a = new int[5]{0};
    int*b = new int[8]{1,3,4,5,6}; // brace inicialization 
    
    int *acat = concatenacionDinamica(a, 5, b, 8);

    imprimir(acat, 13);

    delete[] a;
    delete[] b;
    delete[] acat;

    a =nullptr;
    b = nullptr;
    acat =nullptr;


    return 0;
}