# Laboratorio 11: Estructuras en C++
---

## 1. Estructuras en C++

### Definición

Una **estructura** es un tipo de dato compuesto (definido por el usuario) que permite agrupar variables de diferentes tipos bajo un mismo nombre.

```cpp
struct Persona {
    string nombre;
    int edad;
    float estatura;
};
```


```cpp
struct Estudiante {
    string nombre;
    int codigo;
    float promedio;
    char carrera[50];
};
```

### Declaración e Inicialización

```cpp
Persona p1 = {"Juan", 20, 1.75};
Persona p2;   // declaración
p2.nombre = "Ana";
p2.edad = 22;
p2.estatura = 1.68;
```


```cpp
// Formas de inicilizar una estructura
#include <iostream>
using namespace std;

struct Punto {
    int x;
    int y;
    char nombre;
};

int main() {
    // Método 1: Inicialización directa
    Punto p1 = {10, 20, 'A'};
    
    // Método 2: Asignación individual
    Punto p2;
    p2.x = 5;
    p2.y = 15;
    p2.nombre = 'B';
    
    // Método 3: Inicialización uniforme (C++11)
    Punto p3 {30, 40, 'C'};
    
    cout << "Punto 1: " << p1.x << ", " << p1.y << ", " << p1.nombre << endl;
    cout << "Punto 2: " << p2.x << ", " << p2.y << ", " << p2.nombre << endl;
    cout << "Punto 3: " << p3.x << ", " << p3.y << ", " << p3.nombre << endl;
    
    return 0;
}
```

### Asignación

Podemos asignar estructuras del mismo tipo directamente:

```cpp
Persona p3;
p3 = p1; // Copia todos los campos de p1 a p3
```

### Lectura y Escritura

```cpp
#include <iostream>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    float estatura;
};

int main() {
    Persona p;
    cout << "Ingrese nombre: ";
    cin >> p.nombre;
    cout << "Ingrese edad: ";
    cin >> p.edad;
    cout << "Ingrese estatura: ";
    cin >> p.estatura;

    cout << "\nDatos registrados:\n";
    cout << "Nombre: " << p.nombre << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Estatura: " << p.estatura << " m\n";
}
```

```cpp
// Asignación, lectura, escritura, asignación entre estructuras
#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;
};

int main() {
    Producto prod1, prod2;
    
    // ASIGNACIÓN
    prod1.nombre = "Laptop";
    prod1.precio = 2500.50;
    prod1.stock = 10;
    
    // LECTURA DESDE TECLADO
    cout << "Ingrese nombre del producto: ";
    getline(cin, prod2.nombre);
    cout << "Ingrese precio: ";
    cin >> prod2.precio;
    cout << "Ingrese stock: ";
    cin >> prod2.stock;
    
    // ESCRITURA
    cout << "\n--- PRODUCTOS REGISTRADOS ---" << endl;
    cout << "Producto 1: " << prod1.nombre << ", S/" << prod1.precio 
         << ", Stock: " << prod1.stock << endl;
    cout << "Producto 2: " << prod2.nombre << ", S/" << prod2.precio 
         << ", Stock: " << prod2.stock << endl;
    
    // ASIGNACIÓN ENTRE ESTRUCTURAS
    Producto prod3 = prod1;  // Copia todos los miembros
    
    return 0;
}
```
---

### Ejercicios Propuestos 1

1. Crea una estructura `Producto` con los campos: `codigo`, `descripcion`, `precio`, `stock`.  
Luego, declara dos productos, pide sus datos por teclado y muestra el producto con **mayor precio**.

2. Crea un programa que defina una estructura Libro con los siguientes miembros: título, autor, año de publicación y precio. El programa debe:
    - Declarar 2 variables de tipo Libro
    - Leer los datos desde teclado
    - Mostrar la información de ambos libros
    - Calcular y mostrar el precio promedio de los libros
---

## 2. Arreglo de Estructuras

Podemos almacenar varias estructuras (instancias) en un arreglo.

```cpp
#include <iostream>
using namespace std;

struct Alumno {
    string nombre;
    float nota;
};

int main() {
    Alumno grupo[3];

    for (int i = 0; i < 3; i++) {
        cout << "Alumno " << i + 1 << ":\n";
        cout << "Nombre: "; cin >> grupo[i].nombre;
        cout << "Nota: "; cin >> grupo[i].nota;
    }

    cout << "\nListado:\n";
    for (int i = 0; i < 3; i++) {
        cout << grupo[i].nombre << " - " << grupo[i].nota << endl;
    }
}
```

```cpp
// BÚSQUEDA EN ARREGLO DE ESTRUCTURAS
#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    int id;
    string nombre;
    string puesto;
    double salario;
};

int main() {
    Empleado empleados[5] = {
        {101, "Juan Perez", "Analista", 3500},
        {102, "Maria Lopez", "Programador", 3200},
        {103, "Carlos Ruiz", "Diseñador", 2800},
        {104, "Ana Torres", "Gerente", 5000},
        {105, "Luis Garcia", "Programador", 3300}
    };
    
    // Buscar empleados por puesto
    string puestoBuscado;
    cout << "Ingrese puesto a buscar: ";
    getline(cin, puestoBuscado);
    
    bool encontrado = false;
    cout << "\nEmpleados en puesto '" << puestoBuscado << "':" << endl;
    for (int i = 0; i < 5; i++) {
        if (empleados[i].puesto == puestoBuscado) {
            cout << "ID: " << empleados[i].id << ", Nombre: " << empleados[i].nombre 
                 << ", Salario: S/" << empleados[i].salario << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontraron empleados con ese puesto." << endl;
    }
    
    return 0;
}
```

---

###  Ejercicios Propuestos 2

1. Crea un arreglo de estructuras `Empleado` con los campos `nombre`, `sueldo`, `area`.  
Calcula y muestra el **promedio de sueldos** del área `"Ingeniería"`.

2. Crea un programa para gestionar un inventario de productos. Define una estructura Producto con: código, nombre, precio y cantidad. El programa debe:

    - Almacenar 5 productos en un arreglo
    - Permitir buscar productos por código
    - Mostrar todos los productos con stock menor a 10 unidades
    - Calcular el valor total del inventario (suma de precio × cantidad)
---

## 3. Anidamiento de una Estructura

Una estructura puede contener otra estructura como campo.

```cpp
#include <iostream>
using namespace std;

struct Fecha {
    int dia, mes, anio;
};

struct Persona {
    string nombre;
    Fecha nacimiento; // estructura anidada
};

int main() {
    Persona p;
    cout << "Nombre: "; cin >> p.nombre;
    cout << "Fecha de nacimiento (dd mm aaaa): ";
    cin >> p.nacimiento.dia >> p.nacimiento.mes >> p.nacimiento.anio;

    cout << "\n" << p.nombre << " nació el "
         << p.nacimiento.dia << "/" << p.nacimiento.mes << "/" << p.nacimiento.anio << endl;
}
```

```cpp
//Ejemplo Estructuras anidadas
#include <iostream>
#include <string>
using namespace std;

struct Notas {
    float teoria;
    float practica;
    float laboratorio;
};

struct Curso {
    string codigo;
    string nombre;
    int creditos;
    Notas evaluacion; // Estructura anidada
};

int main() {
    const int NUM_CURSOS = 2;
    Curso cursos[NUM_CURSOS];
    
    // Leer datos de cursos
    for (int i = 0; i < NUM_CURSOS; i++) {
        cout << "\n--- CURSO " << (i + 1) << " ---" << endl;
        cout << "Código: ";
        getline(cin, cursos[i].codigo);
        cout << "Nombre: ";
        getline(cin, cursos[i].nombre);
        cout << "Créditos: ";
        cin >> cursos[i].creditos;
        
        cout << "Nota Teoría: ";
        cin >> cursos[i].evaluacion.teoria;
        cout << "Nota Práctica: ";
        cin >> cursos[i].evaluacion.practica;
        cout << "Nota Laboratorio: ";
        cin >> cursos[i].evaluacion.laboratorio;
        cin.ignore(); // Limpiar buffer
    }
    
    // Calcular promedios y mostrar
    cout << "\n--- PROMEDIOS DE CURSOS ---" << endl;
    for (int i = 0; i < NUM_CURSOS; i++) {
        float promedio = (cursos[i].evaluacion.teoria + 
                         cursos[i].evaluacion.practica + 
                         cursos[i].evaluacion.laboratorio) / 3;
        
        cout << "Curso: " << cursos[i].nombre << " (" << cursos[i].codigo << ")" << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Estado: " << (promedio >= 10.5 ? "Aprobado" : "Desaprobado") << endl;
        cout << "---------------------" << endl;
    }
    
    return 0;
}
```

---

### Ejercicios Propuestos 3

1. Crea una estructura `Direccion` con campos `calle`, `ciudad`, `pais`.  
Inclúyela dentro de una estructura `Cliente` y muestra la dirección completa del cliente.

2. Crea un programa para gestionar información de vehículos. Define las siguientes estructuras:
    - Motor: cilindrada, caballos de fuerza, tipo (gasolina/diesel/electrico)
    - Vehiculo: marca, modelo, año, precio, motor (estructura anidada)
    - El programa debe:
        - Almacenar 3 vehículos con toda su información
        - Mostrar todos los vehículos de tipo "gasolina"
        - Encontrar el vehículo con mayor caballos de fuerza

---

## 4. Puntero a Estructura

Un **puntero a estructura** permite manipular los campos mediante el operador `->`.

```cpp
#include <iostream>
using namespace std;

struct Punto {
    float x, y;
};

int main() {
    Punto p = {3.5, 7.2};
    Punto *ptr = &p;

    cout << "Coordenadas: (" << ptr->x << ", " << ptr->y << ")\n";

    ptr->x = 10.0;
    ptr->y = 20.0;

    cout << "Nuevas coordenadas: (" << p.x << ", " << p.y << ")\n";
}
```

```cpp
// Ejemplo: ACCESO A MIEMBROS MEDIANTE PUNTEROS
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int codigo;
    float promedio;
};

int main() {
    Estudiante est1 = {"Ana Garcia", 2023001, 16.5};
    Estudiante *ptrEst; // Puntero a estructura
    
    ptrEst = &est1; // Apuntar a la estructura
    
    // Acceso a miembros mediante puntero
    // Método 1: Operador ->
    cout << "Acceso con ->" << endl;
    cout << "Nombre: " << ptrEst->nombre << endl;
    cout << "Código: " << ptrEst->codigo << endl;
    cout << "Promedio: " << ptrEst->promedio << endl;
    
    // Método 2: Operador * y .
    cout << "\nAcceso con * y ." << endl;
    cout << "Nombre: " << (*ptrEst).nombre << endl;
    cout << "Código: " << (*ptrEst).codigo << endl;
    cout << "Promedio: " << (*ptrEst).promedio << endl;
    
    // Modificar valores mediante puntero
    ptrEst->promedio = 17.2;
    cout << "\nNuevo promedio: " << est1.promedio << endl;
    
    return 0;
}
```



```cpp
// Ejemplo PUNTEROS CON ARREGLOS DE ESTRUCTURAS
#include <iostream>
#include <string>
using namespace std;

struct Producto {
    int id;
    string nombre;
    double precio;
    int stock;
};

int main() {
    const int NUM_PRODUCTOS = 4;
    Producto productos[NUM_PRODUCTOS] = {
        {1, "Laptop", 2500.0, 5},
        {2, "Mouse", 25.5, 20},
        {3, "Teclado", 45.0, 15},
        {4, "Monitor", 800.0, 8}
    };
    
    Producto *ptr = productos; // Puntero al inicio del arreglo
    
    // Recorrer arreglo con puntero
    cout << "INVENTARIO DE PRODUCTOS" << endl;
    cout << "======================" << endl;
    
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        cout << "Producto " << (i + 1) << ":" << endl;
        cout << "  ID: " << ptr->id << endl;
        cout << "  Nombre: " << ptr->nombre << endl;
        cout << "  Precio: S/" << ptr->precio << endl;
        cout << "  Stock: " << ptr->stock << endl;
        cout << "  Valor: S/" << (ptr->precio * ptr->stock) << endl;
        cout << "---------------------" << endl;
        ptr++; // Avanzar al siguiente elemento
    }
    
    // Buscar producto con menor stock
    ptr = productos; // Reiniciar puntero
    Producto *ptrMenorStock = ptr;
    
    for (int i = 1; i < NUM_PRODUCTOS; i++) {
        if ((ptr + i)->stock < ptrMenorStock->stock) {
            ptrMenorStock = ptr + i;
        }
    }
    
    cout << "\nPRODUCTO CON MENOR STOCK:" << endl;
    cout << "Nombre: " << ptrMenorStock->nombre << endl;
    cout << "Stock: " << ptrMenorStock->stock << endl;
    
    return 0;
}
```

```cpp
// Ejemplo ASIGNACIÓN DINÁMICA CON ESTRUTURAS (sesión 12)
#include <iostream>
#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int paginas;
    double precio;
};

int main() {
    Libro *libroPtr;
    
    // Asignación dinámica de memoria
    libroPtr = new Libro;
    
    // Verificar si la memoria fue asignada
    if (libroPtr == nullptr) {
        cout << "Error: No se pudo asignar memoria" << endl;
        return 1;
    }
    
    // Asignar valores mediante puntero
    cout << "Ingrese título del libro: ";
    getline(cin, libroPtr->titulo);
    cout << "Ingrese autor: ";
    getline(cin, libroPtr->autor);
    cout << "Ingrese número de páginas: ";
    cin >> libroPtr->paginas;
    cout << "Ingrese precio: ";
    cin >> libroPtr->precio;
    
    // Mostrar información
    cout << "\n--- LIBRO REGISTRADO ---" << endl;
    cout << "Título: " << libroPtr->titulo << endl;
    cout << "Autor: " << libroPtr->autor << endl;
    cout << "Páginas: " << libroPtr->paginas << endl;
    cout << "Precio: S/" << libroPtr->precio << endl;
    
    // Liberar memoria
    delete libroPtr;
    libroPtr = nullptr;
    
    return 0;
}
```

---

###  Ejercicios Propuestos 4

1. Declara un puntero a una estructura `Rectangulo` con campos `base` y `altura`.  
Asigna valores y calcula el **área** y el **perímetro** usando el puntero.

2. Crea un programa que use punteros para manejar un catálogo de películas. Define una estructura Pelicula con: título, director, año, duración (minutos) y rating. El programa debe:
    - Usar memoria dinámica para almacenar 3 películas
    - Permitir al usuario ingresar los datos
    - Usar punteros para encontrar la película con mayor rating
    - Usar punteros para mostrar todas las películas de un director específico
    - Liberar correctamente la memoria al final
---

## 5. Paso de Estructura como Parámetro de una Función

Las estructuras pueden pasarse **por valor** o **por referencia** a funciones.


```cpp
// Ejemplo PASO POR VALOR EN ESTRUCTURAS
#include <iostream>
#include <string>
using namespace std;

struct Punto {
    double x;
    double y;
};

// Función que recibe estructura por valor
void mostrarPunto(Punto p) {
    cout << "Coordenadas: (" << p.x << ", " << p.y << ")" << endl;
}

// Función que retorna estructura
Punto crearPunto(double x, double y) {
    Punto temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

// Función que opera sobre estructura (paso por valor)
Punto sumarPuntos(Punto p1, Punto p2) {
    Punto resultado;
    resultado.x = p1.x + p2.x;
    resultado.y = p1.y + p2.y;
    return resultado;
}

int main() {
    Punto punto1 = {3.5, 2.8};
    Punto punto2 = crearPunto(1.2, 4.7);
    
    cout << "Punto 1: ";
    mostrarPunto(punto1);
    
    cout << "Punto 2: ";
    mostrarPunto(punto2);
    
    Punto suma = sumarPuntos(punto1, punto2);
    cout << "Suma de puntos: ";
    mostrarPunto(suma);
    
    return 0;
}
```



```cpp
// Ejemplo: PASO POR REFERENCIA EN ESTRUCTURAS
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    float notas[3];
    float promedio;
};

// Función que modifica estructura por referencia
void calcularPromedio(Estudiante &est) {
    float suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += est.notas[i];
    }
    est.promedio = suma / 3;
}

// Función que lee datos de estudiante por referencia
void leerEstudiante(Estudiante &est) {
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, est.nombre);
    
    cout << "Ingrese 3 notas:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Nota " << (i + 1) << ": ";
        cin >> est.notas[i];
    }
    
    calcularPromedio(est); // Llamar a otra función
}

// Función que muestra estudiante (const para evitar modificaciones)
void mostrarEstudiante(const Estudiante &est) {
    cout << "\n--- DATOS DEL ESTUDIANTE ---" << endl;
    cout << "Nombre: " << est.nombre << endl;
    cout << "Notas: " << est.notas[0] << ", " << est.notas[1] 
         << ", " << est.notas[2] << endl;
    cout << "Promedio: " << est.promedio << endl;
    cout << "Estado: " << (est.promedio >= 10.5 ? "Aprobado" : "Desaprobado") << endl;
}

int main() {
    Estudiante estudiante1;
    
    leerEstudiante(estudiante1);
    mostrarEstudiante(estudiante1);
    
    return 0;
}
```

```cpp
// Ejemplo PASO DE ARREGLO DE ESTRUTURAS
#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    string nombre;
    string departamento;
    double salario;
};

// Función para ingresar empleados
void ingresarEmpleados(Empleado emp[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- EMPLEADO " << (i + 1) << " ---" << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, emp[i].nombre);
        cout << "Departamento: ";
        getline(cin, emp[i].departamento);
        cout << "Salario: ";
        cin >> emp[i].salario;
    }
}

// Función para mostrar empleados
void mostrarEmpleados(const Empleado emp[], int cantidad) {
    cout << "\n--- LISTA DE EMPLEADOS ---" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Nombre: " << emp[i].nombre << endl;
        cout << "Departamento: " << emp[i].departamento << endl;
        cout << "Salario: S/" << emp[i].salario << endl;
        cout << "---------------------" << endl;
    }
}

// Función para calcular salario promedio por departamento
double salarioPromedioDepartamento(const Empleado emp[], int cantidad, string depto) {
    double suma = 0;
    int contador = 0;
    
    for (int i = 0; i < cantidad; i++) {
        if (emp[i].departamento == depto) {
            suma += emp[i].salario;
            contador++;
        }
    }
    
    return (contador > 0) ? (suma / contador) : 0;
}

int main() {
    const int NUM_EMPLEADOS = 3;
    Empleado empleados[NUM_EMPLEADOS];
    
    ingresarEmpleados(empleados, NUM_EMPLEADOS);
    mostrarEmpleados(empleados, NUM_EMPLEADOS);
    
    string departamento;
    cout << "Ingrese departamento para calcular promedio salarial: ";
    cin.ignore();
    getline(cin, departamento);
    
    double promedio = salarioPromedioDepartamento(empleados, NUM_EMPLEADOS, departamento);
    if (promedio > 0) {
        cout << "Salario promedio en " << departamento << ": S/" << promedio << endl;
    } else {
        cout << "No hay empleados en el departamento " << departamento << endl;
    }
    
    return 0;
}
```

---

### Ejercicios Propuestos 5

1. Crea una estructura `Rectangulo` y una función que reciba un `Rectangulo` y retorne su área.  
Luego crea otra función que reciba el mismo `Rectangulo` por referencia y **duplique sus dimensiones**.


2. Crea un programa para gestionar una biblioteca. Define una estructura Libro con: ISBN, título, autor, año, y estado (disponible/prestado). Crea las siguientes funciones:

    - `void prestarLibro(Libro &libro)`: cambia el estado a "prestado"

    - `void devolverLibro(Libro &libro)`: cambia el estado a "disponible"

    - `void mostrarLibros(const Libro libros[], int cantidad)`: muestra todos los libros
    
    - `int contarLibrosPrestados(const Libro libros[], int cantidad)`: retorna cantidad de libros prestados

    El programa principal debe manejar un arreglo de 5 libros.
---

## 6. Funciones y Estructuras

Podemos combinar estructuras y funciones para modularizar programas más grandes.

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    float nota1, nota2, nota3;
};

float promedio(Estudiante e) {
    return (e.nota1 + e.nota2 + e.nota3) / 3.0;
}

void mostrar(Estudiante e) {
    cout << e.nombre << " - Promedio: " << promedio(e) << endl;
}

int main() {
    Estudiante e1 = {"Carlos", 15.5, 17.0, 16.0};
    mostrar(e1);
}
```



```cpp
// Ejemplo FUNCIONES QUE RETORNAN ESTRUCTURAS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Complejo {
    double real;
    double imaginaria;
};

struct Rectangulo {
    double largo;
    double ancho;
};

// Función que crea y retorna una estructura
Complejo crearComplejo(double real, double imaginaria) {
    Complejo c;
    c.real = real;
    c.imaginaria = imaginaria;
    return c;
}

// Función que realiza operaciones y retorna estructura
Complejo sumarComplejos(Complejo c1, Complejo c2) {
    Complejo resultado;
    resultado.real = c1.real + c2.real;
    resultado.imaginaria = c1.imaginaria + c2.imaginaria;
    return resultado;
}

Complejo multiplicarComplejos(Complejo c1, Complejo c2) {
    Complejo resultado;
    resultado.real = (c1.real * c2.real) - (c1.imaginaria * c2.imaginaria);
    resultado.imaginaria = (c1.real * c2.imaginaria) + (c1.imaginaria * c2.real);
    return resultado;
}

// Función que calcula propiedades de estructura
double calcularArea(Rectangulo r) {
    return r.largo * r.ancho;
}

double calcularPerimetro(Rectangulo r) {
    return 2 * (r.largo + r.ancho);
}

// Función para mostrar estructura
void mostrarComplejo(Complejo c) {
    cout << c.real;
    if (c.imaginaria >= 0) {
        cout << " + " << c.imaginaria << "i";
    } else {
        cout << " - " << -c.imaginaria << "i";
    }
}

int main() {
    // Ejemplo con números complejos
    Complejo num1 = crearComplejo(3, 4);
    Complejo num2 = crearComplejo(1, -2);
    
    cout << "Número complejo 1: ";
    mostrarComplejo(num1);
    cout << endl;
    
    cout << "Número complejo 2: ";
    mostrarComplejo(num2);
    cout << endl;
    
    Complejo suma = sumarComplejos(num1, num2);
    cout << "Suma: ";
    mostrarComplejo(suma);
    cout << endl;
    
    Complejo producto = multiplicarComplejos(num1, num2);
    cout << "Producto: ";
    mostrarComplejo(producto);
    cout << endl;
    
    // Ejemplo con rectángulo
    Rectangulo rect = {5.0, 3.0};
    cout << "\nRectángulo: " << rect.largo << " x " << rect.ancho << endl;
    cout << "Área: " << calcularArea(rect) << endl;
    cout << "Perímetro: " << calcularPerimetro(rect) << endl;
    
    return 0;
}
```

**Funciones miembros en estructuras**

En C++, las estructuras pueden tener funciones miembro como las clases (sesiones 14 y 15)

```cpp
// Ejemplo FUNCIONES MIEMBROS EN ESTRUCTURAS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Vector3D {
    double x, y, z;
    
    // Constructor
    Vector3D(double x_val = 0, double y_val = 0, double z_val = 0) {
        x = x_val;
        y = y_val;
        z = z_val;
    }
    
    // Función miembro para calcular magnitud
    double magnitud() {
        return sqrt(x*x + y*y + z*z);
    }
    
    // Función miembro para producto punto
    double productoPunto(Vector3D otro) {
        return x * otro.x + y * otro.y + z * otro.z;
    }
    
    // Función miembro para mostrar vector
    void mostrar() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
    
    // Función miembro para sumar vectores
    Vector3D sumar(Vector3D otro) {
        return Vector3D(x + otro.x, y + otro.y, z + otro.z);
    }
};

int main() {
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    
    cout << "Vector 1: ";
    v1.mostrar();
    cout << ", Magnitud: " << v1.magnitud() << endl;
    
    cout << "Vector 2: ";
    v2.mostrar();
    cout << ", Magnitud: " << v2.magnitud() << endl;
    
    Vector3D suma = v1.sumar(v2);
    cout << "Suma: ";
    suma.mostrar();
    cout << endl;
    
    cout << "Producto punto: " << v1.productoPunto(v2) << endl;
    
    return 0;
}
```


---

###  Ejercicios Propuestos 6

1. Crea un programa que defina una estructura `Alumno` con tres notas.  
Implementa funciones:
    - `leerAlumno()`: para ingresar datos  
    - `calcularPromedio()`: que devuelve el promedio  
    - `mostrarAlumno()`: que imprime los datos y el promedio  

    Usa estas funciones para procesar varios alumnos en un arreglo.

2. Diseña un programa que registre los datos de **n empleados** (nombre, cargo, sueldo, fecha de ingreso).  
Luego:
    - Muestre al empleado con mayor antigüedad.  
    - Calcule el sueldo promedio.  
    - Permita buscar empleados por año de ingreso.
---

### Tarea 

Entregar mediante GitHub, aceptando la tarea en el siguiente enlace

https://classroom.github.com/a/IGpkfMpK


Desarrolla un sistema de gestión académica para la UNI que permita administrar la información de estudiantes, cursos y sus calificaciones. El sistema debe utilizar estructuras en C++ para organizar los datos de manera eficiente. Su implementación debe 

    - Aplicar conceptos de estructuras en C++
    - Implementar arreglos de estructuras
    - Usar anidamiento de estructuras
    - Trabajar con punteros a estructuras
    - Pasar estructuras como parámetros de funciones
    - Implementar funciones miembro en estructuras

Estructuras requeridas

```cpp
struct Notas {
    float EP;  // Examen Parcial (30%)
    float EF;  // Examen Final (50%)
    float PP;  // Promedio de Prácticas (20%)
    
    // Función para calcular promedio final
    float calcularPromedio() {
        return EP * 0.3 + EF * 0.5 + PP * 0.2;
    }
    
    // Función para determinar estado
    string obtenerEstado() {
        float prom = calcularPromedio();
        if (prom >= 10.5) return "Aprobado";
        else return "Desaprobado";
    }
};
```

```cpp
struct Curso {
    string codigo;
    string nombre;
    int creditos;
    string profesor;
    Notas notas;  // Estructura anidada
    
    void mostrarInformacion() {
        // Implementar: mostrar información del curso
    }
};
```

```cpp
struct Estudiante {
    string codigo;
    string nombre;
    string carrera;
    int ciclo;
    Curso cursos[6];  // Máximo 6 cursos por estudiante
    int cantidadCursos;
    
    void mostrarDatos() {
        // Implementar: mostrar datos del estudiante
    }
};
```

Requisitos del Sistema

**Funciones Básicas** 

1.1 Gestión de Estudiantes
```cpp
// Prototipos de funciones a implementar
void registrarEstudiante(Estudiante estudiantes[], int &cantidad);
void mostrarEstudiantes(const Estudiante estudiantes[], int cantidad);
Estudiante* buscarEstudiante(Estudiante estudiantes[], int cantidad, string codigo);
```
1.2 Gestión de Cursos por Estudiante
```cpp
void matricularCurso(Estudiante &estudiante);
void ingresarNotas(Estudiante &estudiante);
void mostrarCursosEstudiante(const Estudiante &estudiante);
```


**Funciones Avanzadas**

2.1 Cálculos Académicos
```cpp
float calcularPromedioPonderado(const Estudiante &estudiante);
int calcularTotalCreditos(const Estudiante &estudiante);
void generarBoleta(const Estudiante &estudiante);
``` 

2.2 Reportes del Sistema
```cpp
void mostrarMejorPromedio(const Estudiante estudiantes[], int cantidad);
void estudiantesAprobadosCurso(const Estudiante estudiantes[], int cantidad, string codigoCurso);
void reporteGeneral(const Estudiante estudiantes[], int cantidad);
```

**Menú Principal**

El sistema debe incluir un menú interactivo con las siguientes opciones:

```text
=== SISTEMA DE GESTIÓN ACADÉMICA UNI ===
1. Registrar estudiante
2. Matricular curso a estudiante
3. Ingresar notas de curso
4. Mostrar información de estudiante
5. Generar boleta de notas
6. Mostrar mejor promedio
7. Estudiantes aprobados por curso
8. Reporte general
9. Salir

Ejemplo de Implementación Esperada

Entrada/Salida Esperada:

=== REGISTRAR ESTUDIANTE ===
Código: 202300001
Nombre: Ana García Pérez
Carrera: Ciencia de la Computación
Ciclo: 3

=== MATRICULAR CURSO ===
Estudiante: 202300001 - Ana García Pérez
Código curso: CC112
Nombre: Fundamentos de Programación
Créditos: 4
Profesor: Dr. Carlos Ruiz

=== INGRESAR NOTAS ===
Curso: CC112 - Fundamentos de Programación 
Examen Parcial: 15
Examen Final: 16
Promedio de Prácticas: 17

=== BOLETA DE NOTAS ===
Estudiante: Ana García Pérez (202300001)
Carrera: Ciencia de la Computación - Ciclo: 3

Código  Curso                     Créditos  EP   EF   PP   Promedio  Estado
CC112 Fundamentos de Programación 4         15   16   17   15.90     Aprobado
CC201   Base de Datos             3         14   13   16   13.70     Aprobado

Promedio Ponderado: 14.95
Total Créditos: 7
```

**Implementaciones opcionales**

1. Usar Punteros para Búsqueda Eficiente
```cpp
Estudiante** obtenerEstudiantesAprobados(const Estudiante estudiantes[], int cantidad, int &aprobadosCount);
```

2. Estructura Anidada para Fechas
```cpp
struct Fecha {
    int dia, mes, año;
};

struct Matricula {
    Curso curso;
    Fecha fechaMatricula;
    bool estado; // true: activo, false: retirado
};
```

3. Función para Ordenar Estudiantes
```cpp
void ordenarEstudiantesPorPromedio(Estudiante estudiantes[], int cantidad);

```
