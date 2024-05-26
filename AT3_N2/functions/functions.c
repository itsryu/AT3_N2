#include <stdlib.h>
#include <locale.h>

#include "../includes/functions.h"

void configEnviroment() {
	system("color F0");
	setlocale(LC_ALL, "");
}

void clearScreen() {
	#ifdef _WIN32
	system("cls");
	#elif __linux__
	system("clear");
	#endif
}

void backToMenu() {
	system("pause");

	clearScreen();
	showMenu();
}