/*
Autor: Franz Aguedo Lucero
 
Crea un programa que defina una estructura Libro con los siguientes miembros: título, autor, año de publicación y precio. El programa debe:
 
Declarar 2 variables de tipo Libro
Leer los datos desde teclado
Mostrar la información de ambos libros
Calcular y mostrar el precio promedio de los libros*/
 
 
#include <iostream>
#include <string>
using namespace std;
 
struct Libro {
    string titulo;
    string autor;
    int anioPublicacion;
    int precio;    
};
 
 
int main() {
 
    Libro libro1, libro2; // instanciamos 2 estructuras
 
    cout << "Ingrese el titulo del primer libro: ";
    getline(cin, libro1.titulo);
    cout << "Ingrese el autor del primer libro: ";
    getline(cin, libro1.autor);
    cout << "Ingrese el anio de publicacion del primer libro: ";
    cin >> libro1.anioPublicacion;
    cout << "Ingrese el precio del primer libro: ";
    cin >> libro1.precio;


    cin.ignore(); // Limpiar el buffer
    cout << "Ingrese el titulo del segundo libro: ";
    getline(cin, libro2.titulo);
    cout << "Ingrese el autor del segundo libro: ";
    getline(cin, libro2.autor);
    cout << "Ingrese el anio de publicacion del segundo libro: ";
    cin >> libro2.anioPublicacion;
    cout << "Ingrese el precio del segundo libro: ";
    cin >> libro2.precio;
 
    cout << "\nDetalles del primer libro:\n";
    cout << "Titulo: " << libro1.titulo << "\n";
    cout << "Autor: " << libro1.autor << "\n";
    cout << "Anio de Publicacion: " << libro1.anioPublicacion <<"\n";
    cout << "Precio: $" << libro1.precio << "\n";

    cout << "\nDetalles del segundo libro:\n";
    cout << "Titulo: " << libro2.titulo << "\n";
    cout << "Autor: " << libro2.autor << "\n";
    cout << "Anio de Publicacion: " << libro2.anioPublicacion <<"\n";
    cout << "Precio: $" << libro2.precio << "\n";
    cout << "Promedio de precio: $" << (libro1.precio + libro2.precio) / 2 << "\n";
    return 0;
}