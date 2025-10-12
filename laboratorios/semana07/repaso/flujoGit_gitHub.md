# Flujo de trabajo con Git y GitHub

Pasos básicos que debes seguir para trabajar
correctamente con un repositorio usando Git y
GitHub.

## 1. Clonar el repositorio

Después de aceptar la tarea en GitHub, se creará un repositorio personal. Debes clonarlo a tu computadora. Reemplaza la URL por la de tu repositorio personal

```bash
git clone https://github.com/usuario/nombre-del-repositorio.git
```

para ello es necesario que instales git (https://git-scm.com/downloads) en tu pc.

## 2. Agregar los archivos necesarios

Copia dentro del repositorio clonado el archivo ejerciciosParcial.md (u otros archivos que necesites, como un README.md que explique brevemente tus implementaciones, tus códigos .cpp nombrados como ejercicio01.cpp, ejercicio02.cpp. etc, debes agregar comentarios relevantes a tu implementación).

## 3. Confirmar los cambios (commit)

Después de editar tus archivos y resolver los ejercicios, guarda los cambios y ejecuta los siguientes comandos:

```bash
git add .
git commit -m "Resolví los ejercicios del parcial"
```

Usa mensajes de commit claros y descriptivos. Es recomendable que hagas commits con frecuencia con cada  avance relevante que vayas realizando.

## 4. Subir los cambios (push)

Finalmente, sube tus cambios a tu repositorio remoto en GitHub:

```bash
git push origin main
```

Si tu rama principal tiene otro nombre (como master), reemplaza main por el nombre correcto.

## 5. Verifica en GitHub

Ingresa a tu repositorio en GitHub y asegúrate de que tus archivos y respuestas estén correctamente subidos.

Cualquier consulta o dificultad adicional, puede 
escribirme al correo achulluncuyr@uni.edu.pe
