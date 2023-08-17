# Estructuras de Datos - Proyecto Final / Estructura de Árbol
Este proyecto fue creado como un programa de consola escrito en el lenguaje C++ en el cual se realizará una simulación de un sistema sencillo para un sistema hospitalario, que realice las funciones de ingresar pacientes, medicamentos y doctores, así como registrar, modificar y eliminar citas, las cuales generen una factura por cada cita y una receta médica que indique los medicamenteos recomendados originarios de un catálogo de medicamentos general para el hospital. El sistema utiliza el manejo de archivos para resguardar la información y resgitros del sistema.
Puedes consultar la documentacion que viene incluida con el proyecto para más informacion de como funciona el programa.

## Tabla de Contenido
* [Objetivos](#objetivos)
* [Requisitos](#requisitos)
* [Instalación](#instalación)
* [Desarrolladores](#desarrolladores)

## Objetivos
- El objetivo general y principal de este manual de usuario es buscar otorgar un soporte del desarrollo hacia los usuarios que tengan la intención de utilizar el proyecto dándole como apoyo un control e información sobre la creación del proyecto y su desarrollo.
- Un objetivo específico del programa es que tiene como propósito aplicar conceptos teóricos, principios y técnicas referentes a la estructura de datos basada en árboles, para optimizar la organización de los datos del sistema.

## Requisitos
- El programa debe ser desarrollado en Visual Studio 2022 en C++, y debe ser apartir de un proyecto vacio.
- Las clases deben ser separadas correctamente, junto de la declaracion de interfaz, usando los headers ```.h``` y el codigo fuente ```.cpp```
- Los headers deben siempre guardas.
- El manejo de la interfaz con el usuario debe de hacerse por medio de una o varias clases diseñadas.
- El proyecto debe hacer uso de la estructura de datos basada en arboles en un proyecto de C++.
- El sistema debe de llevar un control de las citas que se asignan, los pacientes, los doctores, medicamentos, facturas y recetas medicas que se registran en el sistema.
- Los datos guardados en el sistema deberan ser persistentes, por lo que se debe hacer manejo de archivos.
- Se utilizarán excepciones para controlar posibles errores durante la ejecución del programa, asegurando la robustez de la aplicación.
- Se tomará en cuenta el manejo de memoria (asignacion y desasignación).

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
* Gabriel de Pedro Brenes Vega
* Luis Fabian Arrieta Gonzalez
