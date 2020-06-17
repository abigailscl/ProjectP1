/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
******************************************************************/
/***********************************************************************
 * Module:  Vectores.h
 * Author:  Abigail Cabascango
 * Modified: Lunes, 15 de junio de 2020 18:30:19
 * Purpose: Declaration of the class Vectores
 ***********************************************************************/
#if !defined(__MenuBank_h)
#define __MenuBank_h
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <iostream>

#define MenuInicio 1     // Establecer el primer numero del menu
#define MenuFin 3	 // Establecer último numero del menu
#define LineaDeInicio 2  // Establecer la linea donde empieza el menu


using namespace std;

class MenuBank
{
	public:
		MenuBank(int);
		int getMenu();
		void setMenu(int);
		void goy(int y);
		int menuOptions();
	private:
		int Menu;
		
};
////////////////////////////////////////////////////////////////////////
// Name:    	MenuBank::MenuBank(int n)
// Purpose:    Constructor of  class MenuBank
// Parameters: int n
// Return:     
////////////////////////////////////////////////////////////////////////
MenuBank::MenuBank(int n)
{
	setMenu(n);
}

////////////////////////////////////////////////////////////////////////
// Name:       void MenuBank::setMenu(int n)
// Purpose:     Implementation of  MenuBank::setMenu(int n)
// Parameters: int n
// Return:     void
////////////////////////////////////////////////////////////////////////
void MenuBank::setMenu(int n)
{
	Menu = n;
}

////////////////////////////////////////////////////////////////////////
// Name:       int MenuBank::setMenu()
// Purpose:     Implementation of  MenuBank::getMenu(int n)
// Parameters:  void
// Return:     int
////////////////////////////////////////////////////////////////////////
int MenuBank::getMenu()
{
	 return Menu;
}

////////////////////////////////////////////////////////////////////////
// Name:       void MenuBank::goy(int y)
// Purpose:     Implementation of  MenuBank::goy(int y)
// Parameters:  int y
// Return:     void
////////////////////////////////////////////////////////////////////////
void MenuBank::goy(int y) {
	// Obtener handle de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Establecer posición del nuevo cursor
	COORD pos;
	pos.X = 0;
	pos.Y = y;
	// Colocar el cursor en el nuevo sitio
	SetConsoleCursorPosition(hConsole, pos);
}

////////////////////////////////////////////////////////////////////////
// Name:       int MenuBank::menuOptions()
// Purpose:     Implementation of  int MenuBank::menuOptions()
// Parameters:  void 
// Return:     int
////////////////////////////////////////////////////////////////////////
int MenuBank::menuOptions()
{
	printf("\n\t------Bank------\n\n");
	goy(LineaDeInicio); 
	printf("\tRegistrar Cliente\n");
	printf("\tTransacciones \n");
	printf("\tSalir \n");
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

	goy(25);
	printf("Has seleccionado la opcion %d!\n\n\n", Menu);
	return getMenu();
}

#endif
