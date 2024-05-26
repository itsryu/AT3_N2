#include <stdlib.h>
#include <stdio.h>

#include "../includes/functions.h"

void showMenu() {
	int option = 0;

	system("cls");
	printf("|-------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                                                                                                   |\n");
	printf("|                                  ,--,                                                                              |\n");
	printf("|                                ,--.'|                                                                              |\n");
	printf("|                             ,--,  | :                                         ,--,                                 |\n");
	printf("|                          ,---.'|  : '                     ,---,     ,---.   ,--.'|                                 |\n");
	printf("|                          |   | : _' |                 ,-+-. /  |   '   ,'\\  |  |,                                  |\n");
	printf("|                          :   : |.'  |    ,--.--.     ,--.'|'   |  /   /   | `--'_                                  |\n");
	printf("|                          |   ' '  ; :   /       \\   |   |  ,\"' | .   ; ,. : ,' ,'|                                |\n");
	printf("|                          '   |  .'. |  .--.  .-. |  |   | /  | | '   | |: : '  | |                                 |\n");
	printf("|                          |   | :  | '   \\__\\/: . .  |   | |  | | '   | .; : |  | :                                 |\n");
	printf("|                          '   : |  : ;   ,\" .--.; |  |   | |  |/  |   :    | '  : |__                              |\n");
	printf("|                          |   | '  ,/   /  /  ,.  |  |   | |--'    \\   \\  /  |  | '.'|                              |\n");
	printf("|                          ;   : ;--'   ;  :   .'   \\ |   |/         `----'   ;  :    ;                              |\n");
	printf("|                          |   ,/       |  ,     .-./ '---'                   |  ,   /                               |\n");
	printf("|                         '---'         `--`---'                              ---`-'                                |\n");
	printf("|                                                                                                                   |\n");
	printf("|                                                    (pressione)                                                    |\n");
	printf("|                                                                                                                   |\n");
	printf("|                                                 1 - INICIAR JOGO                                                  |\n");
	printf("|                                              2 - REGRAS E INSTRUÇÕES                                              |\n");
	printf("|                                                     3 - SAIR                                                      |\n");
	printf("|                                                                                                                   |\n");
	printf("|-------------------------------------------------------------------------------------------------------------------|\n");
	printf("\n\n");
	printf("Escolha uma opção: ");

	while(scanf("%d", &option) != 1 && option < 1 || option > 3) {
		printf("Opção inválida, tente novamente: ");
		while(getchar() != '\n');
	};

	switch(option) {
		case 1:
		{
			clearScreen();
			printf("Opção 1\n\n");
			backToMenu();
			break;
		}
		case 2:
		{
			clearScreen();
			printf("Opção 2\n\n");
			backToMenu();
			break;
		}
		case 3:
		{
			clearScreen();
			break;
		}
	}
}