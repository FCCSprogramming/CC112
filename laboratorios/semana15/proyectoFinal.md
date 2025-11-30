# Proyecto Final — Fundamentos de Programación CC112

## 1. Descripción general

El presente proyecto tiene como objetivo integrar los conceptos desarrollados durante el curso de Fundamentos de Programación. El estudiante deberá implementar un sistema de gestión orientado a objetos con persistencia de datos, uso de memoria dinámica, punteros inteligentes y herramientas básicas de desarrollo de software.

El trabajo se realizará de forma individual o por equipos de máximo dos integrantes (Ver detalles al final)

La entrega se realizará exclusivamente mediante GitHub.

---

## 2. Enunciado del proyecto

Desarrollar una aplicación en C++ denominada **Sistema de Gestión Académica**, que permita administrar estudiantes, cursos e inscripciones entre ambos.

El programa debe permitir, mediante un menú interactivo en consola:

1. Registrar estudiantes
2. Registrar cursos
3. Inscribir estudiantes a cursos
4. Registrar notas parciales por estudiante y curso
5. Calcular promedios y generar reportes
6. Exportar estudiantes aprobados a un archivo de texto
7. Guardar la base de datos completa en un archivo binario
8. Cargar datos desde archivo binario
9. Acceder a registros mediante acceso directo (random access)
10. Listar datos registrados

---

## 3. Requerimientos

### 3.1 Estructuras y memoria dinámica

Se debe incorporar al menos un módulo implementado inicialmente con `struct`, utilizando memoria dinámica con `new` y `delete`.

Ejemplos aceptables:
- Lista dinámica de estudiantes.
- Registro de notas asociadas a una estructura.

Debe demostrarse comprensión de la gestión manual de memoria antes de migrar a modelos orientados a objetos.

---

### 3.2 Clases y Programación Orientada a Objetos

Implementar como mínimo las siguientes clases:

- `Persona` (clase base)
- `Estudiante` (derivada de Persona)
- `Curso`
- `Sistema` (responsable de gestionar estudiantes, cursos e inscripciones)

Requisitos para las clases:
- Constructores por defecto y con parámetros
- Constructor copia
- Constructor de movimiento (opcional)
- Métodos con uso explícito de `this`
- Encapsulamiento: atributos privados con métodos de acceso

---

### 3.3 Herencia y polimorfismo

La clase base `Persona` debe implementar métodos virtuales y al menos uno virtual puro:

- `virtual void mostrarInfo() const = 0`
- `virtual float calcularDesempeño() const`

La clase `Estudiante` debe sobrescribir dichos métodos.

---

### 3.4 Punteros inteligentes

La aplicación deberá utilizar:
- `std::unique_ptr`
- `std::shared_ptr` cuando corresponda

Se debe justificar el reemplazo de punteros nativos mediante RAII en el archivo README.

---

### 3.5 Archivos

El sistema debe implementar los tres tipos de persistencia:

1. Archivo de texto (txt o csv): exportar el listado de estudiantes con promedio satisfactorio.
2. Archivo binario: almacenar el conjunto completo de datos del sistema.
3. Acceso aleatorio: acceso directo a registros por ID mediante `seekg` / `seekp`.

---

### 3.6 Uso de características modernas de C++

El proyecto puede incluir, justificando adecuadamente su uso

- `std::vector`
- `std::string`
- Operaciones de copia y movimiento (opcional)
- Bucles `for` basados en rango
- `auto`
- Inicializadores de lista

---

## 4. Organización del proyecto

El repositorio debe estar organizado de la siguiente manera:

```css
ProyectoFinal/
  include/
    estudiante.h
    persona.h
    curso.h
    sistema.h
  src/
    estudiante.cpp
    persona.cpp
    curso.cpp
    sistema.cpp
    main.cpp
  data/      (carpeta con archivos generado por el sistema)
  docs/      (diagramas, especificación opcional)
  build/     (carpetas generadas por compilación, ignoradas por git)
  Makefile o CMakeLists.txt
  README.md
```



No se aceptará un único archivo fuente con toda la lógica del programa.

---

## 5. Proceso de compilación

Se debe incluir uno de los siguientes métodos:

### Makefile
- Uso de variables estándar: `CXX`, `CXXFLAGS`
- Compilación incremental
- Un único ejecutable principal

### CMake
- Definir un proyecto mínimo CMake
- Separación por módulos
- Linkeo apropiado entre componentes

No se evaluarán manualmente comandos como  
`g++ main.cpp estudiante.cpp ...`

---

## 6. Requerimientos académicos de entrega

### 6.1 README.md
Debe contener, como mínimo:

- Descripción del proyecto
- Guía de compilación y ejecución
- Explicación del diseño de clases
- Justificación del uso de punteros inteligentes
- Capturas de salida en consola o ejemplos claros de ejecución
- Indicación del autor o integrantes del equipo

---

### 6.2 Validación y pruebas
El estudiante debe incluir:

- Al menos un archivo binario generado
- Un archivo de texto generado
- Ejemplos de entrada que demuestren funcionalidad
- Casos con múltiples registros

---

## 7. Restricciones

- No se aceptarán proyectos que utilicen librerías externas que no hayan sido vistas en clase (salvo las sugeridas en la descripción del proyecto)
- No se permite usar interfaces gráficas o frameworks multimedia.
- No se aceptan soluciones entregadas con todo el código en un único commit al final del proyecto. Se evaluará la evolución del repositorio.
- No se aceptan proyectos generados con herramientas automáticas sin comprensión. Es probable que tenga que explicar/exponer su implementación.

---


## Instrucciones adicionales
Esta tarea está configurada como Group Assignment, lo que significa que puedes trabajar: Individualmente o en pareja (2 estudiantes)

Sigue cuidadosamente las instrucciones según tu caso.

### OPCIÓN 1: Trabajar de forma individual
Si deseas trabajar solo/a:
- Ingresa al enlace de la tarea https://classroom.github.com/a/gDjFIwTM
- Haz clic en "Create a new team".
- Escribe tu nombre como nombre del equipo (ejemplo: Equipo – Ana Pérez).
- Confirma la creación del equipo.
- ¡Listo! GitHub creará tu repositorio individual.

### OPCIÓN 2: Trabajar en pareja (2 estudiantes)

Previamente deben deben coordinar:

**PASO 1** Uno de los dos crea el equipo

- Uno del dúo ingresa al enlace de la tarea https://classroom.github.com/a/gDjFIwTM

- Clic en "Create a new team".

- Pone un nombre al equipo (ejemplo: Equipo – Ana y Luis).

- Confirma la creación del equipo.

**PASO 2** El otro estudiante se une al equipo

- El segundo estudiante entra al enlace de la tarea.

- Verá la lista de equipos disponibles.

- Selecciona el equipo creado por su compañero.

- Confirma unirse al equipo.

GitHub creará un solo repositorio compartido para ambos.

