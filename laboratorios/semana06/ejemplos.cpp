#include <iostream>
using namespace std;

int main() {
    

    // Declaración e inicialización de cadenas de caracteres
    char c[] = "Hola Mundo"; //  // {'H', 'o', 'l', 'a','\0'}; 

    // c es un puntero const a 'H'  (tipo de c es char *)
     c[0] = 'S'; // cambiando el primer caracter
     cout << c << endl;

    //c++; // c = c + 1;ERROR el nombre de un arreglo es un puntero CONSTANTE
    cout << "sizeof(c) = " << sizeof(c) <<endl; //tamaño del arreglo en bytes


    // manejo de arreglo de caracteres usando un puntero a char
    const char *d = "Mundo";
    const char * pch = d;
    d++; //d = d + 1;aritmetica de punteros
    cout << d <<endl;
    cout << "sizeof(d) = " << sizeof(d) <<endl; //tamaño del puntero
    cout << *d <<endl; //desrreferencia , *d es de tipo char
    
    // cout << (void *) &d[0] <<endl;
    

    //imprimir direcciones de cada caracter
    //La conversión explícita al estilo C++ seria// reinterpret_cast<void*>(&d[0])
    for (int i = 0; i < 5; ++i) {
        cout << (void *) &pch[i] <<endl; //Conversión estilo C direccion del carácter
    }
     
 
    
    // Manejo correcto de lectura para combinacion de cin, getline
    char nombre[50];
    int edad;

    cout << "Ingresa tu edad: ";
    cin >> edad;

    // Aquí hay un '\n' pendiente en el buffer, lo eliminamos
    cin.ignore(); // Elimina el salto de línea que quedó después de cin

    cout << "Ingresa tu nombre completo: ";
    cin.getline(nombre, 50);

    cout << "\nResumen:\n";
    cout << "Edad: " << edad << endl;
    cout << "Nombre: " << nombre << endl;

    return 0;
}
