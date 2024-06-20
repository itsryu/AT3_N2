#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "../includes/functions.h"

static Torre* createStack() {
	Torre* torre = (Torre*) malloc(sizeof(Torre));

	if(torre == NULL) {
		printf("Erro ao alocar memória. Encerrando o programa...\n");
		exit(1);
	} else {
		torre->topo = NULL;
		torre->tam = 0;

		return torre;
	}
}

static int isEmpty(Torre* torre) {
	return torre->tam == 0;
}

static void push(Torre* torre, int num) {
	No* novoNo = (No*) malloc(sizeof(No));

	if(novoNo == NULL) {
		printf("Erro ao alocar memória. Encerrando o programa...\n");
		exit(1);
	} else {
		novoNo->num = num;
		novoNo->prox = torre->topo;
		torre->topo = novoNo;
		torre->tam++;
	}
}

static int pop(Torre* torre) {
	if(isEmpty(torre)) {
		return -1;
	} else {
		No* temp = torre->topo;
		int num = temp->num;

		torre->topo = torre->topo->prox;
		free(temp);
		torre->tam--;

		return num;
	}
}

static void initializeGame(Torre** torre, int num) {
	for(int i = 0; i < TORRES; i++) {
		torre[i] = createStack();
	}

	for(int i = num; i > 0; i--) {
		push(torre[0], i);
	}
}

static int isGameWon(Torre** torre, int num) {
	return torre[2]->tam == num;
}

static void moveDisk(Torre* origem, Torre* dest, int* movements) {
	if(origem->topo == NULL) {
		clearScreen();
		textBackground(RED);
		printf("\nMovimento incorreto! A torre selecionada está vazia.");
	} else if(dest->topo != NULL && origem->topo->num > dest->topo->num) {
		clearScreen();
		textBackground(RED);
		printf("\nMovimento incorreto! Não se pode colocar um disco maior sobre um menor.");
	} else {
		clearScreen();
		(*movements)++;
		return push(dest, pop(origem));
	}
}

static void getUserInput(Torre** torre, int num, int* movements) {
	int i = 0, key = 0, selectedIndex = -1, y = (10 + num);
	int coordTorre[TORRES] = { 42, 64, 86 };
	char de, para;

	printXY(coordTorre[0], y, "^\n");

	while(true) {
		key = getch();

		if(key == 224) {
			switch(getch()) {
				case LEFT:
					if(i > 0) {
						gotoXY(coordTorre[i], y);
						printf("  ");

						i--;
						gotoXY(coordTorre[i], y);
						printf("^");
					}
					break;
				case RIGHT:
					if(i < (TORRES - 1)) {
						gotoXY(coordTorre[i], y);
						printf("  ");

						i++;
						gotoXY(coordTorre[i], y);
						printf("^");
					}
					break;
			}
		} else if(key == ENTER) {
			textColor(RED);
			de = (coordTorre[i] == 42) ? 'A' : (coordTorre[i] == 64) ? 'B' : 'C';
			selectedIndex = i;
			break;
		} else if(key == ESC) {
			printf("\n\n");
			textBackground(BLUE);
			backToMenu(45, 5);
			break;
		}
	}

	textColor(WHITE);
	i = (selectedIndex == 0) ? 1 : 0;
	y = (10 + num);

	printXY(coordTorre[i], y, "^\n");

	while(true) {
		key = getch();

		if(key == 224) {
			switch(getch()) {
				case LEFT:
					if(i > 0) {
						int newIndex = i - 1;
						if(newIndex == selectedIndex) newIndex--;
						if(newIndex >= 0) {
							gotoXY(coordTorre[i], y);
							printf("  ");

							i = newIndex;
							gotoXY(coordTorre[i], y);
							printf("^");
						}
					}
					break;
				case RIGHT:
					if(i < (TORRES - 1)) {
						int newIndex = i + 1;
						if(newIndex == selectedIndex) newIndex++;
						if(newIndex < TORRES) {
							gotoXY(coordTorre[i], y);
							printf("  ");

							i = newIndex;
							gotoXY(coordTorre[i], y);
							printf("^");
						}
					}
					break;
			}
		} else if(key == ENTER) {
			para = (coordTorre[i] == 42) ? 'A' : (coordTorre[i] == 64) ? 'B' : 'C';
			break;
		} else if(key == ESC) {
			printf("\n\n");
			textBackground(BLUE);
			backToMenu(45, 5);
			break;
		}
	}

	moveDisk(torre[de - 'A'], torre[para - 'A'], movements);
}

static void printVictoryScreen(const int X, int Y, const int movements) {
	char buffer[50];

	textBackground(GREEN);
	printXY(X, Y++, "+---------------- VENCEU ------------------+");
	printXY(X, Y++, "|                                          |");
	printXY(X, Y++, "|             Seus movimentos:             |");
	printXY(X, Y++, "|                                          |");
	sprintf(buffer, "|                   %d                      |", movements);
	printXY(X, Y++, buffer);
	printXY(X, Y++, "|                                          |");
	printXY(X, Y++, "+------------------------------------------+");
	printf("\n\n");

	textBackground(BLUE);
}

static void printTowers(Torre** torre, int num, const int X, const int Y) {
	int y = Y, key = 0;
	char caractere[100];

	textBackground(GREEN);
	printXY(X, y++, " +------------------------ Torre de Hanoi --------------------------+");
	printXY(X, y++, " |                                                                  |");
	printXY(X, y++, " |          A                     B                     C           |");
	printXY(X, y++, " |                                                                  |");

	for(int i = num - 1; i >= 0; i--) {
		sprintf(caractere, " |");

		for(int j = 0; j < TORRES; j++) {
			if(i < torre[j]->tam) {
				No* atual = torre[j]->topo;

				for(int k = 0; k < torre[j]->tam - i - 1; k++) {
					atual = atual->prox;
				}

				char disco[50];

				sprintf(disco, "          %d", atual->num);
				strcat(caractere, disco);
			} else {
				strcat(caractere, "          |");
			}
			strcat(caractere, "           ");
		}

		strcat(caractere, "|");
		printXY(X, y++, caractere);
	}

	printXY(X, y++, " +------------------------------------------------------------------+");
	textBackground(BLUE);
	printXY(X, y++, "                                                                     ");
	printf("\n\n");

	printf("Aperte ESC para voltar ao menu principal.");
}

void gameEngine(const int X, const int Y) {
	int num = 0, y = 5;

	textBackground(GREEN);
	printXY(X, y++, "+----------------- Discos -----------------+");
	printXY(X, y++, "|                                          |");
	printXY(X, y++, "|      Digite a quantidade de discos:      |");
	printXY(X, y++, "|                                          |");
	printXY(X, y++, "|                                          |");
	printXY(X, y++, "+------------------------------------------+");
	textBackground(BLUE);

	while(scanfXY(60, 8, " %d", &num) != 1 || (num < 3 || num > 9)) {
		y = 5;

		clearScreen();

		textBackground(RED);
		textColor(WHITE);
		printXY(X, y++, "+----------------- Discos -----------------+");
		printXY(X, y++, "|                                          |");
		printXY(X, y++, "|      Digite a quantidade de discos:      |");
		printXY(X, y++, "|                                          |");
		printXY(X, y++, "|                                          |");
		printXY(X, y++, "|  * Deve ser maior que 2 ou menor que 10  |");
		printXY(X, y++, "|                                          |");
		printXY(X, y++, "+------------------------------------------+");
		textBackground(BLUE);

		while(getchar() != '\n');
	}

	textBackground(BLUE);
	clearScreen();

	y = 5;

	Torre** torre = (Torre**) malloc(TORRES * sizeof(Torre*));

	if(torre == NULL) {
		printf("Erro ao alocar memória. Encerrando o programa...\n");
		exit(1);
	} else {
		int movements = 0;
		const int minMovements = pow(2, num) - 1; // M(n) = 2^n - 1 
		initializeGame(torre, num);

		while(!isGameWon(torre, num)) {
			textBackground(BLUE);
			printf("\n\nMínimo de movimentos possíveis: %d\n", minMovements);
			printf("Seus movimentos: %d\n", movements);

			printTowers(torre, num, 30, y);
			textBackground(BLUE);
			getUserInput(torre, num, &movements);
		}

		clearScreen();
		printVictoryScreen(X, y, movements);

		for(int i = 0; i < TORRES; i++) {
			while(torre[i]->tam > 0) pop(torre[i]);

			free(torre[i]);
		}

		backToMenu(45, 5);
	}
}