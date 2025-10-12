// Ejercicio 1

#include <iostream>
#include <iomanip> // para formato del flujo de salida
// setw(), setprecision()
using namespace std;

double promedio(double *E, int n) {
    double suma = 0.0;
    for (double *p = E; p < E + n; ++p) {
        suma += *p;
    }

    return (suma/n);
}

void diferencias(double *E, double *D, int n) {
     
     double *pd = D + 1;
     double *pf = E + n - 1;

     for (double *p1 = E + 1; p1 < pf; ++p1, ++pd) {
          *pd = (*(p1 + 1) - *(p1 - 1))/2.0;
     }
}


int main(){
    const int MAX  = 10;
    double E[MAX] = {2, 5, 3, 7, 6};
    double D[MAX];

    int n = 5;

    double prom = promedio(E, n);

    diferencias(E,D,n);
    cout << left << setw(8) << "Indice" << setw(14) << "E_original"
    << setw(14) << "D_centrada" << endl;

    cout << fixed << setprecision(3);
    for (int i = 0; i < n; ++i) {
        cout <<setw(8) <<i << setw(14) << *(E + i);
        if (i == 0 || i == n-1) {
            cout <<setw(14)<<"--";
        } else {
            cout << setw(14) << *(D + i);
        }
        cout << endl; 
    }

    cout << "Promedio de energía: " << prom <<endl;

    

    return 0;
}