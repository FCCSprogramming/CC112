/*
Escribe un programa que permita al usuario ingresar una matriz dinámica
de enteros de tamaño MxN y luego imprima la transpuesta de esa matriz
*/

#include <iostream>
using namespace std;

int** transpuesta(int ** matriz, int M, int N) {
    int **trans = new int*[N];
    for(int i = 0; i < N; ++i) {
        trans[i] = new int[M];
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            trans[j][i] = matriz[i][j];
        }
    }

    return trans;
}

int main(){

    int M = 3; //filas
    int N = 4; // columnas

    int **matriz = new int*[M];

    for (int i = 0; i < M; ++i) {
        matriz[i] = new int[N];
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = j*i;
        }
    }


    int** tr = transpuesta(matriz, M, N);

    for (int i = 0; i < M; ++i) {
        delete[] matriz[i];
        matriz[i] = nullptr;
    }

    delete[] matriz;
    matriz = nullptr;

    for (int i = 0; i < N; ++i) {
        delete[] tr[i];
        tr[i] = nullptr;
    }

    delete[] tr;
    tr = nullptr;



    return 0;
}
