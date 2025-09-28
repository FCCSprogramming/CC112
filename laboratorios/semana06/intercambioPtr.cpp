#include <iostream>
using namespace std;


void intercambio(const char **a, const char **b) {
    const char *t = *a; // t apunta a primero
    *a = *b; // a apunta a segundo
    *b = t; // b apunta a primero  
}
int main(){
    const char *a = "primero";
    const char *b = "segundo";

    //llamar a la funcion intercambio
    intercambio(&a,&b);
    cout << "a = " << a <<endl;
    cout << "b = " << b << endl;
    return 0; 
}


