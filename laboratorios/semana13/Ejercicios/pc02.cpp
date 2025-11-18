#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string archLaguna = "laguna.txt";

    string archArea = "area.txt";

    ifstream in;
    in.open(archLaguna);



    ofstream out;
    out.open(archArea);


    // Asumimos que se abrió correctamente

    int nt;
    int nv;

    in >> nt; //5
    in >> nv; // 7

    // Declarar aggreglos dinamicos para 
    // las coordenas y los vectices

    float **P = new float*[nv]; // arreglo para los vertices

    for (int i = 0 ; i < nv; ++i) {
        P[i] = new float[2];
    }

    int  **T = new int*[nt];
    for (int i = 0 ; i < nt; ++i) {
        T[i] = new int[3];
    }

    int i = 0;
    while(i < nv) {
        in >> P[i][0] >> P[i][1];
        i++;
    }

    i = 0;
    while(i < nt) {
        in >> T[i][0] >> T[i][1] >> T[i][2];
        i++;
    }

    float area = 0.0;

    for(int i = 0; i < nt; ++i) {
        float x1 = P[T[i][0]- 1][0];
        float y1 = P[][1];

        float x2 = P[][0];
        float y2 = P[][1];

        float x3 = P[][0];
        float y3 = P[][1];
    }


    // COMPLETAR 





    return 0;
}