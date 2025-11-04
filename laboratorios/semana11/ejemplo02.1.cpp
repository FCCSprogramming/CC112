/*
Ejercicio 2.1
 
autor :
Harold Corimanya
20242164J
 
Crea un arreglo de estructuras Empleado con los campos nombre, sueldo, area.
Calcula y muestra el promedio de sueldos del área "Ingeniería".
 
*/
#include <iostream>
#include <string>
using namespace std;
 
 
struct Empleado{
  string nombre;
  float sueldo;
  string area;
};
 
 
 
void LeerDato(Empleado &e){
   
   cout<<"Ingrese el nombre del empleado: ";
   getline(cin,e.nombre);
   cout<<"Ingrese el sueldo: ";
   cin>>e.sueldo;
   cin.ignore(); //limpiar el buffer
   cout<<"Ingrese el area: ";
   getline(cin,e.area);
 
}
 
void mostrarDato(Empleado e){
 
cout<<"Nombre: "<<e.nombre<<endl;
cout<<"Sueldo: s/"<<e.sueldo<<endl;
cout<<"Area: "<<e.area<<endl;
 
}
 
int main(){
 
Empleado emp[3];
 
cout<<"\n---Empleados---\n";
 
for(int i=0;i<3;i++){
    LeerDato(emp[i]);
}
 
for(int i=0;i<3;i++){
    cout<<"\nEmpleado "<<i+1<<" "<<endl;
    mostrarDato(emp[i]);
}
 
float suma = 0;
int num_ing = 0;
 
for(int i=0;i<3;i++){
    if(emp[i].area == "ingenieria"){
    suma += emp[i].sueldo;
    num_ing ++;
    }
}
 
float promedio = suma/num_ing;
 
cout<<"\nEl promedio de los sueldos de ingenieria es: "<<promedio;
 
    return 0;
}
 