#include <stdio.h>

#include "../includes/functions.h"

void gameEngine(const int X, const int Y) {
	int num = 0, y = 5;

	textBackground(GREEN);
	printXY(X, y++, " +-------------- Discos --------------+");
	printXY(X, y++, " |                                    |");
	printXY(X, y++, " | - Digite a qtd de discos:          |");
	printXY(X, y++, " |                                    |");
	printXY(X, y++, " +------------------------------------+");
	scanfXY(70, 7, "%d", &num);

	y = 5;
	
	printXY(X, y++, " +-------------- Tela 2 --------------+");
	printXY(X, y++, " |                                    |");
	printXY(X, y++, " |                                    |");
	printXY(X, y++, " |                                    |");
	printXY(X, y++, " +------------------------------------+");
	printf("\n\n");
}