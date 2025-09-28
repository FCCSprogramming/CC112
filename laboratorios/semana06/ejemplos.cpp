#include <iostream>
using namespace std;

int main() {

    char c[] = "Hola Mundo"; // {'H', 'o', 'l', 'a','\0'}; 
    // c es un puntero const a 'H'  (tipo de c es char *)
    c[0] = 'S'; // cambiando el primer caracter
    cout << c << endl;

    //c++; // c = c + 1;ERROR el nombre de un arreglo es un puntero CONSTANTE

    cout << "sizeof(c) = " << sizeof(c) <<endl; //tamaño del arreglo en bytes

    const char *d = "Mundo";
    const char * pch = d;
    d++; //d = d + 1;aritmetica de punteros
    cout << d <<endl;
    cout << "sizeof(d) = " << sizeof(d) <<endl; //tamaño del puntero
    cout << *d <<endl; //desrreferencia , *d es de tipo char
    
    cout << (void *) &d[0] <<endl;
    
    for (int i = 0; i < 5; ++i) {
        cout << (void *) &pch[i] <<endl;
    }
     //Conversión estilo C direccion del carácter
 
// //La conversión explícita al estilo C++ seria// reinterpret_cast<void*>(&d[0])

    return 0;
}
