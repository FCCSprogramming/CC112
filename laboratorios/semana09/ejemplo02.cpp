#include <iostream>
using namespace std;

int main(){
    int *ptr = new int; //solicitamos reservar 4 bytes en el Heap

    cout << "ingrese un valor entero: ";
    cin >> *ptr; // almacena el valor
    cout << *ptr <<endl; // imprime el valor almacenado en el Heap
    
    delete ptr; // libera memoria dinámica
    ptr = nullptr; // evitamos puntero colgante
    
    // new - delete
    return 0;
}