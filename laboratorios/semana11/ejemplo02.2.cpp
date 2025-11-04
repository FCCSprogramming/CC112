/* 
Ejercicio 2.2
Autor: Mariana Sisniegas Hinojosa
Crea un programa para gestionar un inventario de productos. Define una estructura Producto con: código, nombre, precio y cantidad. El programa debe:
 
Almacenar 5 productos en un arreglo
Permitir buscar productos por código
Mostrar todos los productos con stock menor a 10 unidades
Calcular el valor total del inventario (suma de precio × cantidad)
*/
 
#include <iostream>
#include <string>
using namespace std;
 
struct Producto {
    int codigo;
    string nombre;
    float precio;
    int cantidad;
};
 
int main() {
    Producto productos[5]={
        {101, "Manzanas", 0.5, 100},
        {102, "Naranjas", 0.6, 5},
        {103, "Platanos", 0.4, 150},
        {104, "Peras", 0.7, 60},
        {105, "Uvas", 1.0, 90}
    };
 
 
    // Buscar productos por código
    int codigoBuscado;
    cout << "Ingrese el código del producto a buscar";
    cin >> codigoBuscado;
    bool encontrado = false;
    cout << "Producto encontrado: "<< endl;
    for (int i = 0; i < 5; i++) {
        if (productos[i].codigo == codigoBuscado) {
            cout << "Nombre: " << productos[i].nombre << "  Precio: " << productos[i].precio <<
            "  Cantidad: " << productos[i].cantidad << endl;
            encontrado = true;
        }
    }
 
     if (!encontrado) {
        cout << "No se encontraron productos con ese código." << endl;
    }
 
 
//Mostrar productos con stock menor a 10 unidades
 cout << "\nProductos con stock menor a 10 unidades:\n";
    bool hayBajos = false;
    for (int i = 0; i < 5; i++) {
        if (productos[i].cantidad < 10) {
            cout << "Código: " << productos[i].codigo << "  Nombre: " << productos[i].nombre << "  Cantidad: " << productos[i].cantidad << endl;
            hayBajos = true;
        }
    }
    if (!hayBajos)
        cout << "\nNo hay productos con stock menor a 10" << endl ;
 
// Calcular el valor total del inventario
    float total = 0;
    for (int i = 0; i < 5; i++) {
        total += productos[i].precio * productos[i].cantidad;
    }
    cout << "\nValor total del inventario: " << total << endl;
 
    return 0;
}
 
 