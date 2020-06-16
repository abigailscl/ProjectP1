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
class MenuBank
{
	public:
		MenuBank(int);
		int getMenu();
		void setMenu(int);
		void goy(int y);
	private:
		int Menu;
		
};
MenuBank::MenuBank(int n)
{
	
}
void MenuBank::setMenu(int n)
{
	Menu = n;
}
int MenuBank::getMenu()
{
	 return Menu;
}
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


#endif
