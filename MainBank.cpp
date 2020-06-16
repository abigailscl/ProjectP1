#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <iostream>
using namespace std;

#define MenuInicio 1     // Establecer el primer numero del menu
#define MenuFin 5	 // Establecer último numero del menu
#define LineaDeInicio 2  // Establecer la linea donde empieza el menu

// ir a una línea determinada
void goy(int y);

int main() {
	int Menu; // Controla el menu seleccionado actualmente
	
	printf("---MENU DINAMICO EN C---\nSeleccione opcion:");
	// ir a la linea de inicio, DEBE ir antes del menu seleccionable!!! No olvidar
	goy(LineaDeInicio); 
/*	printf("\t1. Descripcion de la opcion 1\n");
	printf("\t2. Descripcion de la opcion 2\n");
	printf("\t3. Descripcion de la opcion 3\n");
	printf("\t4. Descripcion de la opcion 4\n");
	printf("\t5. Descripcion de la opcion 5\n");*/

	Menu = 1;
	goy(LineaDeInicio);
	printf("---->");


	while(true) {
		// Retrasar el ciclo un poco
		Sleep(100);
		// Saber si la flecha de arriba fue pulsada
		if (GetAsyncKeyState(VK_UP)) {
			// Si Menu == 1, Menu = MenuFin, sino, Menu = Menu -1
			Menu = Menu == MenuInicio ? MenuFin: --Menu;
			// Eliminar la flecha actual
			printf("\r     ");
			// Ir a la linea del próximo menu
			goy(LineaDeInicio + Menu-1);
			// Poner la nueva flecha
			printf("---->");
		} else if (GetAsyncKeyState(VK_DOWN)) {
			Menu = Menu == MenuFin ? MenuInicio: ++Menu;
			printf("\r     ");
			goy(LineaDeInicio + Menu-1);
			printf("---->");
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
	cout<<"ingreso a goy";
	// Obtener handle de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Establecer posición del nuevo cursor
	COORD pos;
	pos.X = 0;
	pos.Y = y;
	// Colocar el cursor en el nuevo sitio
	SetConsoleCursorPosition(hConsole, pos);
}
