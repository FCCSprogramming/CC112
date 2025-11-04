/*
Ejercicio 1.2:
Autor: Lesly Baltazar
Crea un programa que defina una estructura Libro con los siguientes miembros: título, autor, año de publicación y precio. El programa debe:
 
Declarar 2 variables de tipo Libro
Leer los datos desde teclado
Mostrar la información de ambos libros
Calcular y mostrar el precio promedio de los libros
 
*/
#include <iostream>
using namespace std;
struct Libro{
    char title[30];  // para lectura cin.getline(cad,30);
    char author[20];
    int anio;
    double precio;
} lib1, lib2; //declarando 2 variables de tipo Libro

// en el caso de trabajar con string -->  gtline(cin,cad);

// Prototipos de la funciones
void pedirDatos();
void mostrarDatos();
void promedio();


int main(){
    pedirDatos();
    mostrarDatos();
    promedio();
    return 0;
}
void pedirDatos(){
    cout<<"===Registro de libros==="<<endl;
    cout<<"Libro 1 "<<endl;
    cout<<"Titulo: ";
    cin.getline(lib1.title,30,'\n');
    cout<<"Autor: ";
    cin.getline(lib1.author,20,'\n');
    cout<<"Anio: ";
    cin>>lib1.anio;
    cout<<"Precio: ";
    cin>>lib1.precio;
    cin.ignore();
    cout<<"\n";
    cout<<"Libro 2 "<<endl;
    cout<<"Titulo: ";
    cin.getline(lib2.title,30,'\n');
    cout<<"Autor: ";
    cin.getline(lib2.author,20,'\n');
    cout<<"Anio: ";
    cin>>lib2.anio;
    cout<<"Precio: ";
    cin>>lib2.precio;
}
void mostrarDatos(){
    cout<<"\n===Mostrando datos==="<<endl;
    cout<<"Libro 1 "<<endl;
    cout<<"Nombre: "<<lib1.title<<endl;
    cout<<"Autor: "<<lib1.author<<endl;
    cout<<"Anio: "<<lib1.anio<<endl;
    cout<<"Precio: "<<lib1.precio<<endl;
    cout<<"\n";
    cout<<"Libro 2 "<<endl;
    cout<<"Nombre: "<<lib2.title<<endl;
    cout<<"Autor: "<<lib2.author<<endl;
    cout<<"Anio: "<<lib2.anio<<endl;
    cout<<"Precio: "<<lib2.precio<<endl;
}
void promedio(){
    double prom;
    prom=(lib1.precio+lib2.precio)/2;
    cout<<"\nPromedio de precios: "<<prom;
}