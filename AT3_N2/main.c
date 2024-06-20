#include <stdio.h>

#include "./includes/functions.h"

int main(void) {
    int X = 45, Y = 5;

    #ifdef _WIN32
        configEnviroment();
        showMenu(X, Y);
    #else
        printf("Este programa foi desenvolvido para plataformas Windows. Encerrando o programa...\n");
    #endif

    return 0;
}