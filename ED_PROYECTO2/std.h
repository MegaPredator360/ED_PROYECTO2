#pragma once
#include <iostream>			// Para interactuar con la consola
#include <string>			// Para poder usar el tipo de dato "string"
#include <iostream>			// Permite al usuario interactuar con la aplicacion de consola
#include <conio.h>			// Para obtener caracter en formato ASCII
#include <queue>			// Para poder realizar listas en colas
#include <Windows.h>		// Libreria de C++ exclusiva para Windows

using namespace std;

/*
// Paleta de colores completa
cout << "\033[30m"; // Set text color to black
cout << "\033[31m"; // Set text color to red
cout << "\033[32m"; // Set text color to green
cout << "\033[33m"; // Set text color to yellow
cout << "\033[34m"; // Set text color to blue
cout << "\033[35m"; // Set text color to magenta
cout << "\033[36m"; // Set text color to cyan
cout << "\033[37m"; // Set text color to white
cout << "\033[39m"; // Reset text color to default

// Background color
cout << "\033[40m"; // Set background color to black
cout << "\033[41m"; // Set background color to red
cout << "\033[42m"; // Set background color to green
cout << "\033[43m"; // Set background color to yellow
cout << "\033[44m"; // Set background color to blue
cout << "\033[45m"; // Set background color to magenta
cout << "\033[46m"; // Set background color to cyan
cout << "\033[47m"; // Set background color to white
cout << "\033[49m"; // Reset background color to default
*/

// Colores de Texto
#define RED     "\033[31m"
#define WHITE   "\033[0m"
#define YELLOW	"\x1B[33m"
#define GREEN	"\x1B[32m"
