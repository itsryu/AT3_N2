#pragma	once

typedef struct {
    int value;
    struct Node* top;
} Node;

void configEnviroment();
void clearScreen();
void showMenu();
void backToMenu();