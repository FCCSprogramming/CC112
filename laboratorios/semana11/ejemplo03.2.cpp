//Problema 6.
/*autor: Anyelo Gomero*/
 
#include <iostream>
#include <cstring>
using namespace std;
 
struct Motor{
    string forma;
    float fuerza;
    string tipo;
};
 
struct Vehiculo {
    string marca;
    int anio;
    float precio;
    Motor motor;
};
 
int main(){
    Vehiculo datos[3];
    cout<<"Ingrese los datos de los vehiculos:\n";
   
    for (int i=0; i<3; i++){
    cout<<"Vehiculo "<<i+1<<":"<<endl;
    cout<<"Marca: ";
    getline(cin, datos[i].marca);
    cout<<"Anio: ";
    cin>>datos[i].anio;
    cout<<"Precio: ";
    cin>>datos[i].precio;
    cin.ignore();
    cout<<"\nMotor: "<<endl;
    cout<<"Forma: "; getline(cin, datos[i].motor.forma);
    cout<<" Caballos de fuerza: "; cin>>datos[i].motor.fuerza;
    cin.ignore();
    cout<<" Tipo de motor: "; getline(cin, datos[i].motor.tipo);
    }

    // utilizar adecuadamente cin.ignore()
 
    //Busqueda lineal
    bool encontrado = false;
    cout<<"Vehiculos de tipo gasolina:\n";
    for (int i=0; i<3; i++){
        if (datos[i].motor.tipo == "gasolina"){
            cout<<"Vehiculo "<<i+1<<": "<<datos[i].marca<<", "<<datos[i].anio<<", "
                <<datos[i].precio<<", "<<datos[i].motor.forma<<", "<<datos[i].motor.fuerza<<", "
                <<datos[i].motor.tipo<<"\n";
            encontrado =true;
        }
    }
    if (!encontrado){
        cout<<"\nNo existen vehiculos de ese tipo.";
    }
 
return 0;
}