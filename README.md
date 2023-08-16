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

- **Opción 1 - Ingresar Doctor:** Si seleccionas la primera opción, se te solicitará ingresar el numero de cédula del doctor a registrar, la cual deberá de ser de 9 dígitos numéricos de extensión (inlcuyendo los ceros), esta opción no permite ingresar una cédula ya registrada. Posteriormente se te solicitará el nombre completo del doctor, seguidamente se te presentará una pantalla en al cual podrás utilizar las teclas de arriba y abajo, junto con la tecla Enter para seleccionar la correspondiente al doctor. En las siguientes pantallas podrás ingresar la dirección del doctor, y las horas de entrada y salida del mismo, las cuales se pueden ajustar por medio de las teclas de arriba y abajo, y seleccionarlas con la tecla Enter. Por último, se te solicitará ingresar el número telefónico del doctor, el cual debe constar de 8 dígitos numéricos válidos.
  En primera instancia, el sistema te mostrará una pantalla con el resumen de los datos a ingresar, ante el cual se te solicitará confrimar los datos con "Sí" o "No". De seleccionar "Si" el nuevo doctor será guardado y registrado en el sistema y en el archivo "datosDoctor", de lo contrario se le solicitará ingresar nuevamente la información del doctor.

- **Opción 2 - Ingresar Paciente:** En caso de seleccionar la segunda opción, se te solicitará ingresar el numero de cédula del paciente que deseas ingresar, la cual deberá de ser de 9 dígitos numéricos de extensión (inlcuyendo los ceros), esta opción no permite ingresar una cédula ya registrada. Posteriormente se te solicitará el nombre completo del paciente, su dirección y número telefónico, el cual debe constar de 8 dígitos numéricos válidos.
  Seguidamente, el sistema te mostrará una pantalla con el resumen de los datos a ingresar, ante el cual se te solicitará confrimar los datos con "Sí" o "No". De seleccionar "Si" el nuevo paciente será guardado y registrado en el sistema y en el archivo "datosPaciente", de lo contrario se le solicitará ingresar nuevamente la información del paciente.

- **Opción 3 - Ingresar Medicamentos:** Al seleccionar la tercera opción, se te solicitará ingresar el código del medicamente que se desea añadir, el cual deberá constar de únicamente dígitos numéricos, esta opción no permite ingresar un código ya registrado. Posteriormente se te solicitará el nombre del medicamento, seguido de la cantindad de medicamento disponible en inventario, esta opción permite ingresar únicamente dígitos numéricos. 
  Ahora, el sistema te mostrará una pantalla con el resumen de los datos del medicamento a ingresar, ante el cual se te solicitará confrimar los datos con "Sí" o "No". De seleccionar "Si" el nuevo paciente será guardado y registrado en el sistema y en el archivo "datosMedicamento", de lo contrario se le solicitará ingresar nuevamente la información del mismo.

 - **Opción 4 - Registrar Cita:** Si seleccionas la cuarta opción, se te solicitará ingresar el numero de cédula del paciente a quien le corresponde la cita, y en la siguiente pantalla se te solicitará la cédula del doctor con quien se desea la cita, ambas deberán ser de 9 dígitos numéricos de extensión (inlcuyendo los ceros), esta opción valida que las cédulas ya estén registradas en el sistema. Luego se te solicitará ingresar le fecha en que deseas la cita, para esto podrás utilizar las teclas de arriba y abajo, junto con la tecla Enter para seleccionar el día, mes y año deseados. Posteriormente, se te mostrará el día de la cita ingresado y los horarios disponibles para la misma, ante el cual se te solicitará confrimar los datos con "Sí" o "No". De seleccionar "No" se te volverá a preguntar el día de la cita, de lo contrario, se te redirigirá a una pantalla en dond deber ingresar, por medio de las teclas de arriba y abajo, la hora deseada para la cita y seleccionarla con la tecla Enter.
   Por último, el sistema te mostrará una pantalla con el resumen de la cita, nótese que acá se muestra el código único de la cita que generó el sistema de manera automática. Se te solicitará confrimar los datos con "Sí" o "No". De seleccionar "Si" la cita será guardada y registrado en el sistema y en el archivo "datosCita", de lo contrario se le solicitará ingresar nuevamente la información.

 - **Opción 5 - Atender Cita:** Si seleccionas esta opción, se te solicitará ingresar código de la cita que se desea atender, el cuál es de carácter numérico y debe estar ya registrado en el sistema. Al hacerlo, el sistema te mostrará una pantalla con el resumen de la cita ingresada, ante el cual se te solicitará confrimar si deseas atenderla con "Sí" o "No". De seleccionar "Si", se procede a preguntar sobre el diagnóstico resultante de la cita, así como el código del medicamento a recetas, el cual ya debe de existir en el sistema. También, se le solicitará la cantidad (de carácter numérico) de medicamento, y la dosis en que debe de tomarse. Ahora, el sistema te mostrará una pantalla con el resumen de la receta y se te solicitará confrimar los datos con "Sí" o "No". De seleccionar "No" se te volverán a consultar los datos par ala receta, de lo contrario, atenderá la cita y será eliminada de las citas pendientes del sistema y del archivo "datosCita". Además se creará un registro de la receta expuesta, la cual se guardará en el sistema y en el archivo "datosReceta". De haber seleccionado "No" en el primer resumen, se le solicitará ingresar nuevamente el código de la cita a atender.
  
 - **Opción 6 - Modificar Cita:** Si seleccionas esta opción, se te solicitará ingresar código de la cita que deseas modificar, el cuál es de carácter numérico y debe estar ya registrado en el sistema. Al hacerlo, el sistema te mostrará una pantalla con el resumen de la cita ingresada, ante el cual se te solicitará confrimar si deseas modificarla con "Sí" o "No". De seleccionar "Si", se te solicitarán nuevamente los datos de la **Opción 4** y la cita será  modificada en el sistema y en el archivo "datosCita", de lo contrario se le solicitará ingresar nuevamente el código de la cita a modificar.

 - **Opción 7 - Cancelar Cita:** Al seleccionar esta opción, se te solicitará ingresar código de la cita que deseas modificar, el cuál es de carácter numérico y debe estar ya registrado en el sistema. Al hacerlo, el sistema te mostrará una pantalla con el resumen de la cita ingresada, ante el cual se te solicitará confrimar si deseas cancelarla con "Sí" o "No". De seleccionar "Si", la cita será cancelada y elimada en el sistema y en el archivo "datosCita", de lo contrario se le solicitará ingresar nuevamente el código de la cita a cancelar.

 - **Opción 8 - Consultar Receta Médica:** Cuando seleccionas esta opción, se te solicitará ingresar el código de la receta a consultar, el cuál es de carácter numérico y debe estar ya registrado en el sistema. Al hacerlo, el sistema te mostrará una pantalla con el resumen de la receta expuesta. Posteriormente, el sistema te preguntará si deseas consultar otra receta, con "Sí" o "No". De seleccionar "Si", te volverá a consultar el código de la otra receta, de lo contrario, el sistema regresará al menú principal.
   
 - **Opción 9 - Mostrar Árbol:** En caso de seleccionar esta opción, el sistema te mostrará una pantalla donde se te solicita seleccionar el árbol que desees ver: doctores, pacientes, medicamentos, citas o receta médica. Podrás utilizar las teclas de arriba y abajo para desplazarte entre las opciones y seleccionar la que deseas con la tecla Enter. Seguidamente el sistema mostrará los códigos de los registros ordenados de dicha estructura de árbol por post-orden.
   
 - **Opción 10 - Recorrido Profundo:** Para esta opción, el sistema te mostrará una pantalla donde se te solicita seleccionar el árbol que desees ver: doctores, pacientes, medicamentos, citas o receta médica. Podrás utilizar las teclas de arriba y abajo para desplazarte entre las opciones y seleccionar la que deseas con la tecla Enter. Seguidamente el sistema mostrará los códigos de los registros ordenados de dicha estructura de árbol por pre-orden.

 - **Opción 11 - Recorrido por Niveles:** Al seleccionar esta opción, el sistema te mostrará una pantalla donde se te solicita seleccionar el árbol que desees ver: doctores, pacientes, medicamentos, citas o receta médica. Podrás utilizar las teclas de arriba y abajo para desplazarte entre las opciones y seleccionar la que deseas con la tecla Enter. Seguidamente el sistema mostrará los códigos de los registros ordenados de dicha estructura de árbol por in-orden.

 - **Opción 12 - Altura del Árbol:** En caso de seleccionar esta opción, el sistema te mostrará una pantalla donde se te solicita seleccionar el árbol al que le deseas conocer la altura: doctores, pacientes, medicamentos, citas o receta médica. Podrás utilizar las teclas de arriba y abajo para desplazarte entre las opciones y seleccionar la que deseas con la tecla Enter. Seguidamente el sistema mostrará el valor de la altura de dicho árbol.

 - **Opción 13 - Contar Nodos:** Al seleccionar esta opción, el sistema te mostrará una pantalla donde se te solicita seleccionar el árbol al que le deseas conocer la cantidad de nodos: doctores, pacientes, medicamentos, citas o receta médica. Podrás utilizar las teclas de arriba y abajo para desplazarte entre las opciones y seleccionar la que deseas con la tecla Enter. Seguidamente el sistema mostrará la cantidad de nodos presentes de dicho árbol.
   
 - **Opción 14 - Contar Hojas:** Al seleccionar esta opción, el sistema te mostrará una pantalla donde se te solicita seleccionar el árbol al que le deseas conocer la cantidad de hojas: doctores, pacientes, medicamentos, citas o receta médica. Podrás utilizar las teclas de arriba y abajo para desplazarte entre las opciones y seleccionar la que deseas con la tecla Enter. Seguidamente el sistema mostrará la cantidad de hojas presentes de dicho árbol.
   
 - **Opción 15 - Salir:** En caso de seleccionar la última opción se te preguntará si deseas salir del programa o deseas continuar en él.

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
