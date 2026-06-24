# Clatro++ (Blackjack)

Este proyecto es una recreación del clásico juego de casino Blackjack o Veintiuna, diseñado para ser jugado a través de la consola de comandos. Fue desarrollado como proyecto final para la asignatura de Programación de Computadores de la Universidad Nacional de Colombia. El juego cuenta con un sistema de apuestas con diferentes tipos de mesas, mecánicas clásicas de cartas como pedir, plantarse y doblar, manejo dinámico del valor de los Ases, y una interfaz de consola con menús interactivos y música de fondo.

## Comenzando 

Estas instrucciones le permitirán obtener una copia del proyecto en funcionamiento en una máquina local para propósitos de juego, desarrollo o pruebas.

Se puede consultar la sección de Despliegue para conocer cómo distribuir el proyecto.

## Pre-requisitos 

Se requiere un compilador capaz de interpretar el lenguaje C++. Se recomienda el uso de un entorno de desarrollo integrado como Dev-C++ o cualquier entorno configurado con el compilador GCC/MinGW en un sistema operativo Windows, debido a las librerías nativas empleadas.

```
Compilador recomendado: GCC/MinGW en Windows con Dev-C++ u otro IDE compatible
```

## Instalación 

A continuación se describen los pasos necesarios para tener el juego ejecutándose correctamente en el equipo.

Se debe clonar o descargar los archivos del repositorio en una carpeta local:

```
git clone https://github.com/usuario/clatro-blackjack.git
```

Se debe verificar que la carpeta music, que contiene las pistas de audio cancion1.mp3, cancion2.mp3 y cancion3.mp3, se encuentre en el mismo directorio que el archivo principal del código:

```
clatro-blackjack/
 ─ main.cpp
 ─ music/
     ─ cancion1.mp3
     ─ cancion2.mp3
     ─ cancion3.mp3
```

Al momento de compilar el código, es obligatorio incluir la bandera de compilación -lwinmm, ya que esta enlaza la librería multimedia de Windows a través de mmsystem.h, necesaria para la reproducción de la música de fondo:

```
g++ main.cpp -o clatro -lwinmm
```

Una vez compilado de manera exitosa, se ejecuta el archivo .exe generado para iniciar el juego:

```
./clatro.exe
```

## Ejecutando las pruebas 

A continuación se explica cómo verificar que las mecánicas principales del juego y el sistema de guardado funcionan correctamente.

### Analice el funcionamiento del juego 

Se verifica que el flujo lógico del juego responda a las reglas clásicas del Blackjack. Para ello, se debe iniciar una partida nueva y seleccionar el tamaño de la mesa: Corta, Mediana o Larga, con el fin de fijar el saldo inicial. Luego se realiza una apuesta con un mínimo del 5% del saldo disponible. Durante la partida, se ingresan las siguientes opciones:

```
Y -> Pedir otra carta
D -> Doblar la apuesta
Cualquier otra letra -> Plantarse
```

Se verifica que al finalizar la mano, la consola aplique correctamente las reglas de victoria, derrota o empate frente al puntaje del crupier.

### Verificación del sistema de guardado e historial 

Se verifica que el programa almacene el progreso de manera correcta. Para ello, se juegan un par de rondas y se accede al menú de pausa para seleccionar la opción de guardar partida. Luego se comprueba en la carpeta local del proyecto que se hayan generado o actualizado los siguientes archivos:

```
historial.txt    -> Registro de todas las rondas jugadas
gameRecords.txt  -> Historial de partidas guardadas
saveFile.txt     -> Archivo para reanudar el último saldo
```

## Despliegue 

Para distribuir el juego, se comparte el archivo ejecutable .exe junto con la carpeta music. Dado que el proyecto utiliza llamadas directas a la API de Windows a través de windows.h, está diseñado exclusivamente para ejecutarse de manera nativa en este sistema operativo.

## Construido con 

* C++ - Lenguaje de programación base
* iostream, vector, chrono, thread, random - Librerías estándar utilizadas para la lógica, el manejo del tiempo y la aleatoriedad del mazo
* windows.h - API de Windows para la gestión de la consola de comandos
* mmsystem.h - Librería multimedia de Windows utilizada para el control de la música mediante Windows Media Control Interface

## Autores 

Este proyecto fue desarrollado por estudiantes de la Facultad de Ingeniería de la Universidad Nacional de Colombia:

* Manuel Enrique Castañeda Buitrago
* Jason Alejandro Gonzales Martínez
* Juan Esteban Giraldo Marín
