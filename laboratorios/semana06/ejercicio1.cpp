/*
Generar 20 caracteres alfabéticos mayúsculas
y contar el númerode ocurrencias de cada caracter generado
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


char generarCaracter() {
    return char('A' + rand() % 26);
}


void contarRepeticiones(char caracteres[], int n) {
    for (char letra = 'A'; letra <= 'Z'; ++letra) {
        int contador = 0;
        for(int i = 0; i < n; ++i) {
            if (caracteres[i] == letra) {
                contador++;
            }
        }
        if (contador > 0) {
            cout << letra << " aparece " << contador << " veces "  <<endl;
        }
    }
}



int main(){
    srand(time(0));
    const int N = 20;

    char caracteres[N];

    cout << "Caracteres generados" <<endl;

    for (int i = 0 ; i < N; ++i) {
        caracteres[i] = generarCaracter();
        cout << caracteres[i] <<" ";
    }

    contarRepeticiones(caracteres, N);



    return 0;
}