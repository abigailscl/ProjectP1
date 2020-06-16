#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <iostream>
using namespace std;

#define MenuInicio 1     // Establecer el primer numero del menu
#define MenuFin 3	 // Establecer último numero del menu
#define LineaDeInicio 2  // Establecer la linea donde empieza el menu

// ir a una línea determinada
void goy(int y);

int main() {
	int Menu; // Controla el menu seleccionado actualmente
	
	printf("\n---MENU DINAMICO EN C---\nSeleccione opcion:\n");
	// ir a la linea de inicio, DEBE ir antes del menu seleccionable!!! No olvidar
	goy(LineaDeInicio); 
	printf("\tRegistrar Cliente\n");
	printf("\tTransacciones \n");
	printf("\tSalir \n");

	Menu = 1;
	goy(LineaDeInicio);
	printf("----->");


	while(true) {
		// Retrasar el ciclo un poco
		Sleep(100);
		// Saber si la flecha de arriba fue pulsada
		if (GetAsyncKeyState(VK_UP)) {
			// Si Menu == 1, Menu = MenuFin, sino, Menu = Menu -1
			Menu = Menu == MenuInicio ? MenuFin: --Menu;
			// Eliminar la flecha actual
			printf("\r      ");
			// Ir a la linea del próximo menu
			goy(LineaDeInicio + Menu-1);
			// Poner la nueva flecha
			printf("----->");
		} else if (GetAsyncKeyState(VK_DOWN)) {
			Menu = Menu == MenuFin ? MenuInicio: ++Menu;
			printf("\r      ");
			goy(LineaDeInicio + Menu-1);
			printf("----->");
		} else if (GetAsyncKeyState(VK_RETURN)) { 
			break;
		}
	}

	// Opcional... Mostrar en pantalla el numero seleccionado
	goy(10);
	printf("Has seleccionado la opcion %d!\n\n\n", Menu);

	/*
	
	AQUI SE PUEDE HACER EL TIPICO SWITCH ANALIZANDO LA OPCION
        QUE SELECCIONÓ EL USUARIO
	
	*/

	system("pause");
}


void goy(int y) {
	// Obtener handle de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Establecer posición del nuevo cursor
	COORD pos;
	pos.X = 0;
	pos.Y = y;
	// Colocar el cursor en el nuevo sitio
	SetConsoleCursorPosition(hConsole, pos);
}
