/*
Ejercicio 1.1
Autor: Manuel Rojas Tuyen
 
Crea una estructura Producto con los campos:
codigo, descripcion, precio, stock.
Luego, declara dos productos, pide sus datos por teclado y muestra el
producto con mayor precio.
*/
 
#include<iostream>
#include<string>
using namespace std;
 


struct Producto
{
    int codigo;
    string descripcion;
    double precio;
    int stock;
};
 
int main(){
    const int NUM_PRODUCTOS = 2; // tamaño conocido en tiempo de compilación

    Producto productos[NUM_PRODUCTOS];
 
    for (int i = 0; i < NUM_PRODUCTOS; i++)
    {
        cout<<"\ningrese los datos del producto "<<i+1<<" :"<<endl;
 
        cout<<"descripcion: "; 
        getline(cin, productos[i].descripcion);
        cout<<"\ncodigo: ";
        cin>>productos[i].codigo;
        cout<<"\nprecio: ";
        cin>>productos[i].precio;
        cout<<"\nstock: ";
        cin>>productos[i].stock;
 
        cin.ignore(); // limpiar el buffer
 
    }
 
    int idx = 0;
    int idx_mayor;
    double mayorPrecio = productos[0].precio;
    while (idx<NUM_PRODUCTOS)
    {
        if (productos[idx].precio > mayorPrecio)
        {
            mayorPrecio = productos[idx].precio;
            idx_mayor = idx;
        }
        idx++;
    }
 
    cout<<"el codigo del producto con mayor precio es: "<<productos[idx_mayor].codigo<<endl;
    cout<<"el precio mas alto es: "<<productos[idx_mayor].precio<<endl;
 
    return 0;
}
 