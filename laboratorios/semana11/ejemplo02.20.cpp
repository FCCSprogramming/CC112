//Ejercicio 2.2 // caso sin arreglo de estructuras
//AUTOR: YAGO GONZALES
/*Crea una estructura Productocon los campos: codigo, descripcion, precio, stock.
Luego, declara dos productos, pide sus datos por teclado y muestra el producto con mayor precio .
*/
#include <iostream>
#include <string>
using namespace std;
 
struct Producto {
    int codigo;
    string descripcion;
    float precio;
    int stock;
};
 
int main() {
    Producto producto1, producto2;
 
    cout << "Ingrese el codigo del producto1: ";
    cin >> producto1.codigo;
    cin.ignore();
    cout << "Ingrese descripcion del producto1: ";
    getline(cin, producto1.descripcion);
    cout << "Ingrese precio: ";
    cin >> producto1.precio;
    cout << "Ingrese stock: ";
    cin >> producto1.stock;
 
    cout << "Ingrese el codigo del producto 2: ";
    cin >> producto2.codigo;
    cin.ignore();
    cout << "Ingrese descripcion del producto 2: ";
    getline(cin, producto2.descripcion);
    cout << "Ingrese precio: ";
    cin >> producto2.precio;
    cout << "Ingrese stock: ";
    cin >> producto2.stock;
 
    cout << "\nPRODUCTOS REGISTRADOS" << endl;
    cout << "Producto 1 codigo: " << producto1.codigo << ", Descripcion: " << producto1.descripcion << ", S/" << producto1.precio
         << ", Stock: " << producto1.stock << endl;
    cout << "Producto 2 codigo: " << producto2.codigo << ", Descripcion: " << producto2.descripcion << ", S/" << producto2.precio
         << ", Stock: " << producto2.stock << endl;
 
    cout << "¿Que producto tiene mayor precio?" << endl;
    if (producto1.precio < producto2.precio) {
        cout << "El producto 2 tiene mayor precio" << endl;
    } else {
        cout << "El producto 1 tiene mayor precio" << endl;
    }
 
    return 0;
}
 
