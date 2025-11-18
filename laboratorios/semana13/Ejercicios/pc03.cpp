#include <iostream>
#include <fstream>
using namespace std;

void escribirFibonacciBinario() {
    ofstream archivo("fibonacci.bin", ios::binary);

    int a = 0;
    int b = 1;

    for(int i = 0; i < 20; ++i) {
        //cout << a << endl; // escribe en consola
        archivo.write(reinterpret_cast<char*>(&a), sizeof(int));
        int actual = a + b;
        a = b;
        b = actual;
    }

    archivo.close();
    cout << "Funcion escribirFibonacciBinario:\n";
    cout << "Términos de Fibonacci escritos en el archivo crrectamente\n";
}


void leerFibonacciBinario() {
    cout << "Funcion leerFibonacciBinario:\n";
    ifstream archivo("fibonacci.bin", ios::binary);

    int contador = 1;
    int termino;

    while(archivo.read(reinterpret_cast<char*>(&termino), sizeof(int))) {
        cout << "Termino " << contador << ": " <<termino << endl;
        contador++;
    }

    archivo.close();
}

int main(){
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}
