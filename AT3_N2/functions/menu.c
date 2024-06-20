#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/functions.h"

static int option(const int X, const int Y);

void showMenu(const int X, int Y) {
	int key = 0;

	textBackground(GREEN);
	textColor(WHITE);
	printXY(X, Y++, " +------ Menu Principal ------+");
	printXY(X, Y++, " |                            |");
	printXY(X, Y++, " | - Jogar                    |");
	printXY(X, Y++, " | - Sobre                    |");
	printXY(X, Y++, " | - Sair                     |");
	printXY(X, Y++, " +----------------------------+");

	int y = 7;

	printXY(X, y, ">\n");

	while(true) {
		key = getch();

		if(key == 224) {
			switch(getch()) {
				case DOWN: {
					if(y > 7) {
						gotoXY(X, y);
						printf(" ");
						gotoXY(X, --y);
						printf(">");
					}
					break;
				}
				case UP: {
					if(y < 9) {
						gotoXY(X, y);
						printf(" ");
						gotoXY(X, ++y);
						printf(">");
					}
					break;
				}
			}
		} else if(key == ENTER) {
			textBackground(BLUE);
			int choice = option(X, y);

			if(choice == 1) {
				goto end;
			} else {
				backToMenu(X, 5);
			}
		}
	}

	end: {
		textBackground(BLUE);
		pauseScreen();
		exit(0);
	}
}

static int option(const int X, const int Y) {
	clearScreen();

	int center = 0, y = 5;

	switch(Y) {
		case 7: {
			center = 40;
			textBackground(BLUE);
			gameEngine(center, Y);
			break;
		}

		case 8: {
			center = 30;

			textBackground(GREEN);
			printXY(center, y++,
				"+----------------------------- Sobre -------------------------------+");
			printXY(center, y++,
				"| A Torre de Hanoi e um dos mais famosos jogos de Matematica.       |");
			printXY(center, y++,
				"| Ele consiste de uma base contendo tres pilares (hastes), em um    |");
			printXY(center, y++,
				"| dos quais esta disposta uma torre formada por alguns discos de    |");
			printXY(center, y++,
				"| diametros diferentes, furados no centro e colocados uns sobre     |");
			printXY(center, y++,
				"| os outros, em ordem crescente de diametro, de cima para baixo     |");
			printXY(center, y++,
				"| O numero de discos pode variar.                                   |");
			printXY(center, y++,
				"+-------------------------------------------------------------------+");
			printf("\n\n\n");

			break;
		}

		case 9: {
			center = 30;

			textBackground(RED);
			printXY(center, y++,
				"+-------------------------------------------------------------------+");
			printXY(center, y++,
				"|                                                                   |");
			printXY(center, y++,
				"|                                                                   |");
			printXY(center, y++,
				"|                           FIM DO PROGRAMA                         |");
			printXY(center, y++,
				"|                                                                   |");
			printXY(center, y++,
				"|                                                                   |");
			printXY(center, y++,
				"+-------------------------------------------------------------------+");
			printf("\n\n\n");

			return 1;
		}
	}

	textBackground(BLUE);

	return 0;
}
