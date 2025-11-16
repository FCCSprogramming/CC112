#include <iostream> // flujo de consola
#include <fstream> // flujo de archivos
using namespace std;

int main(){
    //1. instanciar (crear un objeto) para escribir
    ofstream out("miprimerArchivo.txt"); // crea (o sobreescribe) 

    // 2. buena práctica verificar si el archivo se abrio
    if (!out.is_open()) {
        cout << "Error, el archivo no pudo crearse\n";
    } else {
        //3. 
        out << "Este es el contenido de\n";
        out << "de mi primer archivo de texto.\n"; 

        // 5. cerrando el archivo
        out.close();  // RAII

        cout << "Archivo creado exitosamente\n";
    }

    ofstream out2("miprimerArchivo.txt",ios::app);
    out2 << "Texto agregado\n";


    // MODOS DE APERTURA DE UN ARCHIVO
    // ios::in modo lectura
    // ios::out modo escritura
    // ios::app añadir al final 
    // ios::binary  modo binario
    



    return 0;
}