# Ejercicio 1 
En un experimento se registran los valores de energía de una partícula en distintos instantes de tiempo, obteniendo un conjunto de mediciones:

$$
E = [E_0, E_1, E_2, \ldots, E_{n-1}]
$$

donde $E_i$ representa la energía medida en el instante $i$.

Se desea procesar esta información para obtener:

1. **La energía promedio**, definida como  
$$
   \overline{E} = \frac{1}{n} \sum_{i=0}^{n-1} E_i
$$

2. **Las diferencias centradas** entre mediciones sucesivas, que se calculan para los puntos interiores $(1 ≤ i ≤ n−2)$ mediante la expresión:  
$$
   D_i = \frac{E_{i+1} - E_{i-1}}{2}
$$

   (Los valores en los extremos $i = 0$ y $i = n-1$ no se calculan).

- Lea el número de datos $n$ (máximo 10) y los valores $E_i$.  
- Implemente **dos funciones** que reciban **punteros** como parámetros:
  1. Una función para calcular el **promedio de energía**.
  2. Una función para calcular las **diferencias centradas**.
- Muestre los resultados en una **tabla formateada** usando manipuladores de flujo (`<iomanip>`), con las columnas:
  - Índice  
  - Energía original  
  - Diferencia centrada  
- Muestre además el **promedio de energía total** al final.

## Ejemplo de entrada

```
n = 5
E = [2, 5, 3, 7, 6]
```

## Salida esperada

```
Indice  E_original  D_centrada
----------------------------------
0       2.000       --
1       5.000       0.500
2       3.000       1.000
3       7.000       0.500
4       6.000       --
Promedio de energía = 4.600
```


# Ejercicio 2

Se tiene una placa cuadrada representada por una matriz de densidades $A \in \mathbb{R}^{N\times N}$, con $N \leq 10$.

Cada elemento $A_{ij}$ indica la densidad en el punto $(i,j)$.

Se pide:

1. Leer el valor de $N$ y los elementos de la matriz $A$.
2. Calcular la **transpuesta** $A^T$.
3. Calcular la **matriz de inercia** $I = A \cdot A^T$.
4. Calcular:
   - La **traza** de $I$:
   $$
     \text{tr}(I) = \sum_{i=1}^{N} I_{ii}
   $$
   - La **energía normalizada**:
     $$
     E = \frac{1}{N^2} \sum_{i,j} I_{ij}^2
     $$
5. Mostrar todas las matrices con formato tabular usando `<iomanip>`.

6. Debe manipular las matrices utilizando doble puntero (no usar notación []). Esto servirá para el tema de asignación dinámica.



##  Ejemplo de ejecución

```text
N = 3
Matriz A:
1 2 3
0 1 4
2 0 1

Salida esperada

Matriz A:
1.00 2.00 3.00
0.00 1.00 4.00
2.00 0.00 1.00

Transpuesta A^T:
1.00 0.00 2.00
2.00 1.00 0.00
3.00 4.00 1.00

Matriz de Inercia I = A * A^T:
14.00 14.00 05.00
14.00 17.00 04.00
05.00 04.00 05.00

Traza(I) = 36.00
Energía normalizada E = 0.67
```

# Ejercicio 3
En un laboratorio ambiental se registran varias mediciones.  
Cada medición contiene:

- un **ID del sensor** (entero), y  
- un **valor medido de concentración de CO₂** (real).

Se desea escribir un programa en **C++** que:

1. Lea `n` mediciones (máximo 100).  
2. Guarde los datos en **arreglos paralelos**, accediendo a ellos mediante **punteros**.  
3. Ordene las mediciones por **ID de sensor** de manera **estable**, usando el algoritmo **Merge Sort**.  
4. Permita buscar, mediante **búsqueda binaria**, **todas las mediciones de un sensor dado**.  
5. Muestre:
   - la **lista original**,  
   - la **lista ordenada**,  
   - y las **mediciones encontradas**.

- Implemente funciones para:
  - Lectura de datos.  
  - Impresión de listas.  
  - Ordenamiento (Merge Sort estable).  
  - Búsqueda binaria.  
- Utilice punteros (`int*`, `float*`) para recorrer los arreglos.  

## Ejemplo de ejecución

```text
Ingrese número de mediciones: 6

ID[1]: 2   Valor[1]: 410.5
ID[2]: 1   Valor[2]: 398.2
ID[3]: 2   Valor[3]: 409.8
ID[4]: 3   Valor[4]: 420.1
ID[5]: 1   Valor[5]: 399.5
ID[6]: 2   Valor[6]: 410.1

--- Lista original ---
(2, 410.5)
(1, 398.2)
(2, 409.8)
(3, 420.1)
(1, 399.5)
(2, 410.1)

--- Lista ordenada por ID (estable) ---
(1, 398.2)
(1, 399.5)
(2, 410.5)
(2, 409.8)
(2, 410.1)
(3, 420.1)

Buscar mediciones del sensor ID = 2

--- Resultados ---
(2, 410.5)
(2, 409.8)
(2, 410.1)
```

# Ejercicio 4
Se desea desarrollar un programa **modular** que lea **N frases** ingresadas por el usuario y determine en cuál de ellas aparece **más veces una palabra clave**.


1. El programa debe permitir ingresar hasta **5 frases**, cada una de **máximo 100 caracteres**, usando `cin.getline`.  
2. Luego debe solicitar una **palabra clave** (máximo 20 caracteres).  
3. Las palabras dentro de las frases se considerarán **separadas por cualquiera de los siguientes delimitadores**:

   > espacio, coma, punto, punto y coma, dos puntos, signo de exclamación o signo de interrogación

   Es decir, se tomarán como delimitadores los caracteres:

   ```
   ' ', ',', '.', ';', ':', '!', '?'
   ```

4. El programa debe contar cuántas veces aparece **exactamente** la palabra clave (coincidencia exacta, respetando mayúsculas/minúsculas) en cada frase.  
5. Debe mostrar:
   - El número de apariciones de la palabra en cada frase.  
   - La frase que tiene el **mayor número de apariciones**.  
   - La **longitud total** de esa frase (usando `strlen`).  
6. Si la palabra no aparece en ninguna frase, mostrar un mensaje apropiado.  
7. Se debe usar **programación modular**, definiendo funciones que realicen tareas específicas como:
   - Lectura de frases  
   - Conteo de apariciones  
   - Búsqueda de la frase con más coincidencias  
   - Presentación de resultados  


## Ejemplo de entrada y salida

```
Ingrese el número de frases (máx. 5): 3
Frase 1: El agua limpia es esencial para la vida
Frase 2: Cuidar el agua, es cuidar la vida, el agua es vida.
Frase 3: El aire y el agua son vitales

Ingrese la palabra clave: agua

---- Resultados ----
Frase 1 → 1 aparición(es)
Frase 2 → 2 aparición(es)
Frase 3 → 1 aparición(es)

La palabra aparece más veces en la frase 2:
"Cuidar el agua, es cuidar la vida."
Longitud de la frase: 34 caracteres
```