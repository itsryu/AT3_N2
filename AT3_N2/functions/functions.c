#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdarg.h>

#include "../includes/functions.h"

void configEnviroment() {
	system("color 17");
	system("title Torre de Hanoi");

	char* local = setlocale(LC_ALL, "");

	if(local == NULL || strcmp(local, "Portuguese_Brazil.1252") != 0) {
		#ifdef _WIN32
			setlocale(LC_ALL, "Portuguese");
		#endif
	}
}

void pauseScreen() {
	#ifdef _WIN32
		system("pause");
	#endif
}

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#endif
}

void backToMenu(int X, int Y) {
	pauseScreen();
	clearScreen();
	showMenu(X, Y);
}

void gotoXY(int X, int Y) {
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textColor(DOS_COLORS color) {
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x00F0;
	SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= color);
}

void textBackground(DOS_COLORS color) {
	HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hl, &bufferInfo);
	bufferInfo.wAttributes &= 0x000F;
	SetConsoleTextAttribute(hl, bufferInfo.wAttributes |= (color << 4));
}

void printXY(int X, int Y, char* input) {
	gotoXY(X, Y);
	printf("%s", input);
}

int scanfXY(const int X, const int Y, const char* format, ...) {
	gotoXY(X, Y);

    va_list args;
    va_start(args, format);
    int scan = vscanf(format, args);
    va_end(args);

	return scan;
}

void waitScreen() {
	int i = 0;
	char str[120] = {""};

	while(i <= 100) {
		if(i % 2) strcat(str, "=");

		clearScreen();

		printf("                      ""+-------------------------------------------------+");
		printf("\n  Carregando programa |");

		textColor(YELLOW);
		printf("  %s ", str);

		textColor(WHITE);
		printf("\n                      ""+-------------------------------------------------+");
		gotoXY(64, 1);
		printf("        ""| %d%% ", i);
		Sleep(5);
		textColor(WHITE);

		i++;
	}

	clearScreen();
	printf("Carregado %d%%", i - 1);
	Sleep(1000);
}