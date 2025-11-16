#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("miprimerArchivo.txt");

    if (!in.is_open()) {
        cerr << "No se pudo abrir \n";
    } else {
        string linea; 
        while (getline(in, linea)) {
            cout << linea << endl;
        }

        in.close();
    }

    return 0;
}