#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Cuántos números ingresará: ";
    cin >> n;

    int *ptr = new int[n]; // reserva memoria dinámica en el Heap

    cout << "Ingrese los " << n << " números:";
    for (int i = 0; i < n; ++i) {
        cin >> ptr[i];
    }

    cout << "Arreglo ingresado" <<endl;
    for (int i = 0; i < n; ++i) {
        cout << ptr[i];
    }

    delete[] ptr;
    ptr = nullptr; //evitamos puntero colgante




    return 0;

    
}