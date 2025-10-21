#include <iostream>
using namespace std;

void imprimirMatriz(int** matriz, int m, int n) {
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = i + j;
            cout << matriz[i][j] <<" ";
        }
        cout << endl;
    }
}

int main(){

    int filas, columnas;

    cout << "Ingrese el número de filas y columnas: ";
    cin >> filas >> columnas;

    //reservamos memória dinámica para una matriz
    int** ptr = new int*[filas];

    for (int i = 0; i < filas; ++i) {
        ptr[i] = new int[columnas]; 
    }

    imprimirMatriz(ptr, filas, columnas);

    //Liberando memoria
    for (int i = 0; i < filas; ++i) {
        delete[] ptr[i];
        ptr[i] = nullptr; 
    }

    delete[] ptr;
    ptr = nullptr;

    return 0;
}