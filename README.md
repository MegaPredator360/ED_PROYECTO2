# ED_PROYECTO2

# Estructuras de Datos - Proyecto Final / Estructura de Árbol
Este proyecto fue creado como un programa de consola escrito en el lenguaje C++ en el cual se realizará una simulación de un sistema sencillo para un sistema hospitalario, que realice las funciones de ingresar pacientes, medicamentos y doctores, así como registrar, modificar y eliminar citas, las cuales generen una factura por cada cita y una receta médica que indique los medicamenteos recomendados originarios de un catálogo de medicamentos general para el hospital. El sistema utiliza el manejo de archivos para resguardar la información y resgitros del sistema.

## Tabla de Contenido
* [Objetivos](#objetivos)
* [Descripción](#descripción)
* [Instalación](#instalación)
* [Desarrolladores](#desarrolladores)

## Objetivos
- El objetivo general y principal de este manual de usuario es buscar otorgar un soporte del desarrollo hacia los usuarios que tengan la intención de utilizar el proyecto dándole como apoyo un control e información sobre la creación del proyecto y su desarrollo.
- Un objetivo específico del programa es que tiene como propósito aplicar conceptos teóricos, principios y técnicas referentes a la estructura de datos basada en árboles, para optimizar la organización de los datos del sistema.

## Descripción
Cuando inicies el programa serás recibido con una pantalla de inicio que despliega todas las funciones del menú inlcuyendo la opción de salir del programa. Podrás utilizar las teclas de arriba y abajo para desplazar entre las opciones, y pulsar Enter para ingresar a la opción deseada.

- **Opción 1:** Si seleccionas la primera opción, se te solicitará ingresar el numero de cédula del doctor a registrar, la cual deberá de ser de 9 dígitos numéricos de extensión (inlcuyendo los ceros), esta opción no permite ingresar una cédula ya registrada. Posteriormente se te solicitará el nombre completo del doctor, seguidamente se te presentará una pantalla en al cual podrás utilizar las teclas de arriba y abajo, junto con la tecla Enter para seleccionar la correspondiente al doctor. En las siguientes pantallas podrás ingresar la dirección del doctor, y las horas de entrada y salida del mismo, las cuales se pueden ajustar por medio de las teclas de arriba y abajo, y seleccionarlas con la tecla Enter. Por último, se te solicitará ingresar el número telefónico del doctor, el cual debe constar de 8 dígitos numéricos válidos. En primera instancia el sistema te mostrará una pantalla con el resumen de los datos a ingresar, ante el cual se te solicitará confrimar los datos con "Sí" o "No". De seleccionar "Si" el nuevo doctor será guardado y registrado en el sistema y en el archivo "datosDoctor", de lo contrario se le solicitará ingresar nuevamente la información del doctor.

- En caso de seleccionar la segunda opción se te preguntará si deseas salir del programa o deseas continuar en él.

## Instalación
Para la ejecución de este programa se necesita un editor como Visual Studio Community 2022 o Visual Studio Code.

Para Visual Studio Community 2022 necesitas tener descargado la carga de trabajo **Desarrollo para el escritorio con C++**, ya con esto será suficiente para poder ejecutar el programa.

![VSWorkloads](https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/f2c055a2-7159-472a-93d8-67d0cb42baf5)

En el caso de Visual Studio Code necesitas tener instalado en tu computadora un compilador de C++ que te permita correr el programa, los más recomendados son [g++](https://www.msys2.org/) o [clang](https://clang.llvm.org/get_started.html).

Se recomienda tener instalado también la extensión de C++ en Visual Studio Code para la detección de errores de sintaxis y ayudas con las librerías. 

![VSCCppExtension](https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/7ac6aa7e-40f1-486e-895d-b304a83484cb)

Una vez instalado, pulsas en el botón de ejecutar en la esquina superior derecha.

<img src="https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/c42286d5-9cad-4a76-9a1e-7764f620b349" width="50%">

Si es tu primer programa de C++ corriendo en Visual Studio Code se te abrirá la paleta de comando pidiendote que selecciones un compilador para debugear el programa...
Te recomiendo que selecciones alguno de los 2 compiladores que están marcados.

![VSCCppSelectDebug](https://github.com/MegaPredator360/ED_EXTRACLASE2/assets/48075699/81a6430d-0e8b-4265-9410-2b88ef083c6c)

Ya que lo tengas seleccionado, Visual Studio Code empezará a compílar el programa. El archivo principal del programa se llama ```main.cpp```

## Desarrolladores:

* Aaron Steve Alfaro Zamora
* Daniela Hidalgo López
* Gabriel de Predro Brenes Vega
* Luis Fabian Arrieta Gonzalez
