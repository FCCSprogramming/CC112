# Asignación Dinámica con Estructuras en C++

## 1. Repaso: estructuras en C++

Una **estructura** (`struct`) permite agrupar diferentes tipos de datos bajo un solo identificador.

```cpp
#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

int main() {
    Estudiante e1 = {"Carlos", 19, 15.8};
    cout << "Nombre: " << e1.nombre << ", Edad: " << e1.edad 
         << ", Promedio: " << e1.promedio << endl;
    return 0;
}
```
---

## 2. Asignación dinámica con estructura

En C++, la **memoria dinámica** permite reservar espacio durante la ejecución del programa. Esto resulta útil cuando no se conoce de antemano cuántos datos se necesitarán.

**Operadores fundamentales:**
- `new`: reserva memoria en el heap.
- `delete`: libera la memoria previamente reservada.

**Ejemplo:**

```cpp
#include <iostream>
using namespace std;

struct Persona {
    string nombre;
    int edad;
};

int main() {
    Persona* p = new Persona; // creación dinámica
    cout << "Ingrese nombre: ";
    getline(cin, p->nombre);
    cout << "Ingrese edad: ";
    cin >> p->edad;

    cout << "Datos ingresados: " << p->nombre << " (" << p->edad << ")" << endl;

    delete p; // liberar memoria
    return 0;
}
```

**Importante:** todo bloque de memoria creado con `new` debe liberarse con `delete` para evitar **fugas de memoria**.

---

## 4. Arreglos dinámicos de estructuras

Podemos reservar un conjunto de estructuras de tamaño variable usando `new`.

```cpp
#include <iostream>
using namespace std;

struct Libro {
    string titulo;
    int anio;
};

int main() {
    int n;
    cout << "¿Cuántos libros desea registrar? ";
    cin >> n;
    cin.ignore();

    Libro* biblioteca = new Libro[n];

    for (int i = 0; i < n; i++) {
        cout << "Libro " << i + 1 << ": ";
        cout << "Título: ";
        getline(cin, biblioteca[i].titulo);
        cout << "Año: ";
        cin >> biblioteca[i].anio;
        cin.ignore();
    }

    cout << "Listado de libros:";
    for (int i = 0; i < n; i++) {
        cout << biblioteca[i].titulo << " (" << biblioteca[i].anio << ")";
    }

    delete[] biblioteca; // liberar memoria
    return 0;
}
```

---

## 5. Redimensionamiento dinámico de estructuras

Una de las principales ventajas de la asignación dinámica es la **posibilidad de redimensionar estructuras** en tiempo de ejecución.

**Ejemplo:** aumentar el tamaño de un arreglo de estructuras.

```cpp
#include <iostream>
using namespace std;

struct Sensor {
    int id;
    float lectura;
};

int main() {
    int n;
    cout << "Número inicial de sensores: ";
    cin >> n;

    Sensor* sensores = new Sensor[n];

    for (int i = 0; i < n; i++) {
        sensores[i].id = i + 1;
        sensores[i].lectura = (i + 1) * 1.5;
    }

    cout << "¿Cuántos sensores desea agregar? ";
    int m;
    cin >> m;

    Sensor* nuevos = new Sensor[n + m];
    for (int i = 0; i < n; i++) {
        nuevos[i] = sensores[i];
    }

    for (int i = n; i < n + m; i++) {
        nuevos[i].id = i + 1;
        nuevos[i].lectura = (i + 1) * 1.5;
    }

    delete[] sensores; // liberar el arreglo anterior
    sensores = nuevos; // apuntar al nuevo arreglo

    cout << "Lecturas actuales:
";
    for (int i = 0; i < n + m; i++) {
        cout << "Sensor " << sensores[i].id << ": " << sensores[i].lectura << endl;
    }

    delete[] sensores;
    return 0;
}
```

Este ejercicio muestra cómo **duplicar o ampliar** estructuras en tiempo de ejecución sin conocer su tamaño previamente.

---

## 6. Estructuras enlazadas y punteros autorreferenciados

La asignación dinámica permite crear estructuras que se referencian a sí mismas, dando origen a las **listas enlazadas**, **árboles** y **grafos**.

```cpp
struct Nodo {
    int dato;
    Nodo* siguiente;
};
```

---

## 7. Ejemplo: lista enlazada simple

```cpp
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarInicio(Nodo*& lista, int valor) {
    Nodo* nuevo = new Nodo{valor, lista};
    lista = nuevo;
}

void mostrar(Nodo* lista) {
    while (lista) {
        cout << lista->dato << " -> ";
        lista = lista->siguiente;
    }
    cout << "NULL";
}

int main() {
    Nodo* lista = nullptr;
    insertarInicio(lista, 10);
    insertarInicio(lista, 20);
    insertarInicio(lista, 30);

    mostrar(lista);

    // Liberar memoria
    while (lista) {
        Nodo* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
    return 0;
}
```

---

## 8. Herramientas modernas de C++ para manejo dinámico

En C++ moderno, el manejo manual con `new` y `delete` puede sustituirse por **punteros inteligentes**, que liberan memoria automáticamente.

### 8.1 `std::unique_ptr`

```cpp
#include <memory>

struct Persona {
    string nombre;
    int edad;
};

int main() {
    auto p = std::make_unique<Persona>();
    p->nombre = "María";
    p->edad = 21;
}
```

### 8.2 `std::shared_ptr`

Permite compartir un mismo recurso dinámico entre múltiples punteros.

```cpp
#include <memory>
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    shared_ptr<Nodo> siguiente;
};

int main() {
    auto n1 = make_shared<Nodo>();
    auto n2 = make_shared<Nodo>();
    n1->valor = 10;
    n2->valor = 20;
    n1->siguiente = n2;

    cout << n1->valor << " -> " << n1->siguiente->valor << endl;
}
```

### 8.3 `std::vector`

Permite manejar arreglos dinámicos sin usar `new` ni `delete`, ajustando automáticamente su tamaño.

```cpp
#include <vector>
#include <iostream>
using namespace std;

struct Punto {
    float x, y;
};

int main() {
    vector<Punto> trayectoria;
    trayectoria.push_back({1.0, 2.0});
    trayectoria.push_back({2.5, 3.1});
    trayectoria.push_back({3.8, 5.0});

    for (const auto& p : trayectoria)
        cout << "(" << p.x << ", " << p.y << ")
";
}
```

---

## 9. Ejercicio: Lista enlazada simple

### Requisitos
Implementar un programa que permita:
1. Insertar elementos al inicio y al final.
2. Mostrar la lista.
3. Eliminar elementos específicos.
4. Liberar memoria antes de salir.

### Implementación sugerida

```cpp
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarInicio(Nodo*&, int);
void insertarFinal(Nodo*&, int);
void mostrarLista(Nodo*);
void eliminarElemento(Nodo*&, int);
void liberarLista(Nodo*&);
```
---

## 10. Conclusiones

- La asignación dinámica proporciona flexibilidad y eficiencia en el uso de memoria.
- Es esencial para construir estructuras de datos avanzadas como listas, pilas, colas, árboles y grafos.
- En C++ moderno, el uso de **punteros inteligentes** y **contenedores estándar** mejora la seguridad y reduce los errores.

