# Asignación Dinámica de Memoria en C++
La asignación dinámica de memoria en C++ se realiza usando `new` y `delete`.
---

## Ejemplo 1: Reservar un solo entero dinámicamente

Escribe un programa que:
1. Reserve dinámicamente memoria para un entero.
2. Le asigne un valor ingresado por el usuario.
3. Imprima el valor almacenado.
4. Libere la memoria reservada.

```cpp
int* ptr = new int;
cin >> *ptr;
cout << "Valor: " << *ptr << endl;
delete ptr;
```

## Ejemplo 2: Arreglo dinámico de N elementos
Haz un programa que:
1. Pida al usuario cuántos números desea ingresar.

2. Reserve memoria para un arreglo dinámico.

3. Permita ingresar los números y luego los imprima.

4. Libere la memoria usada.

```cpp
int n;
cin >> n;
int* arr = new int[n];
delete[] arr;
```

## Ejemplo 3: Función que retorna un arreglo dinámico
Escribe una función que:

1. Reciba un entero n.

2. Devuelva un puntero a un arreglo dinámico de tamaño n, con valores del 1 al n.

```cpp
int* crearArreglo(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = i + 1;
    return arr;
}
```

## Ejemplo 4: Estructuras dinámicas

Define un struct Persona con nombre y edad. Reserva memoria para una persona con new, pide los datos al usuario, y muéstralos.

```cpp
struct Persona {
    string nombre;
    int edad;
};

Persona* p = new Persona;

// ingresar datos

// imprimir datos

delete p;
```

## Ejemplo 5: Crear una matriz dinámica (2D)

1. Pide al usuario el número de filas y columnas. Luego:

2. Reserva memoria para una matriz (utilizando arreglo de punteros).

3. Permite llenar la matriz con valores.

4. Imprime la matriz.

5. Libera toda la memoria correctamente.

```cpp
int** matriz = new int*[filas];
for (int i = 0; i < filas; ++i) {
    matriz[i] = new int[columnas];
}

// liberar memoria
for (int i = 0; i < filas; ++i) {
    delete[] matriz[i];
}
delete[] matriz;
```

# Errores comunes en Asignación Dinámica en C++

La asignación dinámica de memoria en C++ usando new y delete está propensa a errores. A continuación se detalla los errores más comunes y cómo evitarlos.

## Error 1: Olvidar liberar memoria (Memory Leaks)

No liberar la memoria asignada con new usando delete.

Ejemplo

```cpp
void memoryLeak() {
    int* ptr = new int(42);
    // OLVIDAMOS: delete ptr;
    // La memoria nunca se libera
}

void memoryLeakArray() {
    int* arr = new int[100];
    // OLVIDAMOS: delete[] arr;
    // Fuga de 100 * sizeof(int) bytes
}
```

Consecuencias
 - Fuga de memoria progresiva
 - El programa consume cada vez más memoria
 - Posible crash por falta de memoria

Solución
```cpp
void correctMemoryManagement() {
    int* ptr = new int(42);
    // Usar inmediatamente después de new
    delete ptr;
    
    int* arr = new int[100];
    delete[] arr; // Usar delete[] para arrays
}
```
## Error 2: Usar delete en lugar de delete[]

Usar delete en lugar de delete[] para liberar arrays.


Ejemplo
```cpp
void wrongDelete() {
    int* arr = new int[10];
    
    // INCORRECTO:
    delete arr; // Debería ser delete[] arr
    
    // Solo libera el primer elemento
    // Los otros 9 elementos quedan con fugas
}

Consecuencias
 - Comportamiento indefinido (Undefined Behavior)
 - Posible corrupción de memoria
 - Fuga de memoria para elementos restantes


Solución
```cpp
void correctArrayDeletion() {
    int* arr = new int[10];
    
    // CORRECTO:
    delete[] arr; // Usar delete[] para arrays
    
    // Regla: new[] ↔ delete[]
    //        new  ↔ delete
}
```
## Error 3: Acceder a memoria ya liberada (Dangling Pointers)

Usar un puntero después de haber liberado la memoria a la que apunta.

Ejemplo

```cpp
void danglingPointer() {
    int* ptr = new int(100);
    delete ptr; // Memoria liberada
    
    // PELIGRO: ptr ahora es un dangling pointer
    *ptr = 50; // COMPORTAMIENTO INDEFINIDO
    cout << *ptr; // LEE MEMORIA INVALIDA
}

int* createDanglingPointer() {
    int value = 42;
    return &value; // Retorna dirección de variable local
} // 'value' se destruye aquí

void useDangling() {
    int* dangling = createDanglingPointer();
    cout << *dangling; // COMPORTAMIENTO INDEFINIDO
}
```
Consecuencias
 - Comportamiento indefinido
 - Lectura de datos corruptos
 - Posible corrupción de otras variables
 - Difícil de depurar

Solución

```cpp
void avoidDanglingPointers() {
    int* ptr = new int(100);
    delete ptr;
    ptr = nullptr; // Marcar como nulo inmediatamente
    
    // Ahora si accedemos, será más obvio el error
    if (ptr != nullptr) {
        *ptr = 50; // No se ejecuta
    }
}
```
## Error 4: No inicializar punteros

Usar punteros sin inicializar, apuntando a memoria aleatoria.

Ejemplo
```cpp
void uninitializedPointer() {
    int* ptr; // NO INICIALIZADO - puntero colgante
    
    // COMPORTAMIENTO INDEFINIDO:
    *ptr = 10; // ¿Dónde estamos escribiendo?
    cout << *ptr; // ¿Qué estamos leyendo?
}

void conditionalInitialization(bool condition) {
    int* ptr;
    
    if (condition) {
        ptr = new int(42);
    }
    // Si condition es false, ptr queda sin inicializar
    
    delete ptr; // COMPORTAMIENTO INDEFINIDO si condition era false
}
```

Consecuencias
 - Comportamiento indefinido
 - Posible escritura en memoria crítica
 - Crash del programa
 - Difícil de reproducir

Solución
```cpp
void safePointerUsage() {
    // Siempre inicializar
    int* ptr = nullptr;
    
    ptr = new int(42);
    
    // Verificar antes de usar
    if (ptr != nullptr) {
        *ptr = 10;
    }
    
    delete ptr;
    ptr = nullptr;
}
```


## Error 5: Double Delete

Intentar liberar la misma memoria dos veces.

Ejemplo
```cpp
void doubleDelete() {
    int* ptr = new int(42);
    
    delete ptr; // Primera liberación - OK
    
    // SEGUNDA LIBERACIÓN - ERROR
    delete ptr; // COMPORTAMIENTO INDEFINIDO
}

void doubleDeleteThroughAlias() {
    int* ptr1 = new int(100);
    int* ptr2 = ptr1; // Dos punteros a misma memoria
    
    delete ptr1; // OK
    delete ptr2; // DOUBLE DELETE - ERROR
}
```
Consecuencias
 - Comportamiento indefinido
 - Corrupción del heap
 - Crash del programa
 - Difícil de depurar

Solución
```cpp
void safeDeletion() {
    int* ptr = new int(42);
    
    delete ptr;
    ptr = nullptr; // Marcar como nulo
    
    // Segundo delete es seguro
    delete ptr; // No hace nada (delete nullptr es seguro)
}

void safeDeletionWithAlias() {
    int* ptr1 = new int(100);
    int* ptr2 = ptr1;
    
    delete ptr1;
    ptr1 = nullptr;
    ptr2 = nullptr; // Ambos a nullptr
}
```

# Herramientas de depuración

1. Uso de Valgrind
```bash
valgrind --leak-check=full ./tu_programa
```

2. Sanitizers (GCC/Clang)
```cpp
// Compilar con:
g++ -fsanitize=address -fsanitize=undefined -g programa.cpp
```

# Consejos de Seguridad
Siempre usar delete después de new

Siempre usar delete[] después de new[]

Establecer punteros a nullptr después de delete

Inicializar todos los punteros

Verificar nullptr antes de desreferenciar


Preferir smart pointers sobre raw pointers

Usar RAII para gestión de recursos

Evitar punteros colgantes

No hacer double delete

Usar herramientas de análisis de memoria


La gestión manual de memoria en C++ es propensa a errores, pero siguiendo estas buenas prácticas podemos escribir código más seguro.

Es recomendable aprender a usar las herramientas modernas del lenguaje (smart pointers, RAII), para automatizar la gestión de memoria y minimizar el uso de punteros nativos.