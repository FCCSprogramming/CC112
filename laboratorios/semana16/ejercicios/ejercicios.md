# Ejercicios

1. La Escuela de Ciencia de la Computación administra varios servidores donde los alumnos hacen prácticas. Cada servidor registra en un archivo de texto sus accesos en un formato simplificado:

    Archivo: `accesos.log`

    Cada línea tiene el formato: `USUARIO;FECHA_HORA;IP;EVENTO`

    **Ejemplo**:
    ```css
    ana23;2025-11-01 13:25:12;10.0.0.5;LOGIN_OK
    ana23;2025-11-01 13:27:40;10.0.0.5;RUN_CODE
    josep;2025-11-01 18:10:02;10.0.0.15;LOGIN_FAIL
    ana23;2025-11-02 09:10:32;10.0.0.5;LOGIN_FAIL
    carlos;2025-11-02 11:31:09;10.0.0.8;LOGIN_OK
    ```
    Escriba un programa en C++ que:

    a) Lea completamente el archivo `accesos.log`, validando la apertura e informando si el archivo no existe.
    
    b) Analice los datos y genere un archivo de salida `reporte_usuarios.txt` con la siguiente información para cada usuario:
    
    - Total de eventos registrados
    - Cantidad de LOGIN_OK.
    - Cantidad de LOGIN_FAIL.
    - El día con mayor cantidad de accesos (considerar solo AAAA-MM-DD).
    - Dirección IP más frecuente que utilizó.
    - Sospecha de intrusión, si el usuario presenta
3 o más LOGIN_FAIL consecutivos dentro de la misma fecha.

    El reporte debe listar a los usuarios en orden descendente según su número total de eventos.
    
    El formato exacto para cada usuario en el archivo de salida es:
    ```yaml
    USUARIO: <nombre>
    Eventos totales: <num>
    Login exitosos: <num>
    Login fallidos: <num>
    Dia mas activo: <fecha>
    IP mas usada: <ip>
    Intrusion detectada: SI/NO
    ```
2. Escriba un programa en C++ que modele las preferencias de estudiantes respecto a diversas tecnologías. El programa solicitará la cantidad de estudiantes N y la cantidad de tecnologías M, luego debe leer una matriz dinámica N × M, donde cada fila representa un estudiante, y cada columna un puntaje del 1 al 5. a continuación:

    a) Para cada estudiante calcula su promedio:
    
        promedio[i] = (suma de sus M puntajes) / M

        que debe almacenarse en un arreglo dinámico.

    b) Debe crear una matriz (de similitud) dinámica 2D `double** sim`, donde


    `sim(A, B) = 1 - |Promedio A - Promedio B| / 4`
        


    Note que: el resultado debe estar entre 0 y 1. La diagonal debe ser 1.0.

    c) Determinar el par de estudiantes más similares, para ello debe recorrer matriz `sim[i][j] (con i ≠ j)` y encontrar el valor más alto.

    **Ejemplo**

    **Entrada:** 
    ```tex
    Ingrese número de estudiantes: 3
    Ingrese número de tecnologías: 4

    Ingrese puntajes del estudiante 1:
    4 5 3 5
    Ingrese puntajes del estudiante 2:
    5 4 2 3
    Ingrese puntajes del estudiante 3:
    4 5 3 5
    ```

    **Salida**
    ```yaml
    Promedios:
    Estudiante 1: 4.25
    Estudiante 2: 3.50
    Estudiante 3: 4.25

    Matriz de similitud:
            E1      E2      E3
    E1      1.00    0.81    1.00
    E2      0.81    1.00    0.81
    E3      1.00    0.81    1.00

    Los estudiantes más similares: 1 y 3 (similitud = 1.00)
    ```
