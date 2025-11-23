#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    string  titular;
    double saldo;

public:
    //Constructor de parametros
    CuentaBancaria(string titular, double saldo);

    void depositar(double monto);
    void mostrar();
};


//PUNTERO OCULTO this

CuentaBancaria::CuentaBancaria(string titular, double saldo) {
    // uso comun de this
    // this->atributo = parametro;
    this->titular = titular;
    this->saldo = saldo;
}


void CuentaBancaria:: depositar(double monto) {
    saldo += monto; 
}
void CuentaBancaria:: mostrar() {
    cout << "Titular: " << titular << endl;
    cout << "Saldo: " << saldo <<endl;
}



int main(){
    CuentaBancaria c1("Maria Ray", 1400);

    c1.depositar(1500);

    c1.mostrar();

    return 0;
}