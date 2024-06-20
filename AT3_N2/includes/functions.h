#pragma	once

typedef struct No {
    int num;
    struct No* prox;
} No;

typedef struct Torre {
    No* topo;
    int tam;
} Torre;

typedef enum DOS_COLORS {
  BLACK,
  BLUE,
  GREEN,
  CYAN,
  RED,
  MAGENTA,
  BROWN,
  LIGHT_GRAY,
  DARK_GRAY,
  LIGHT_BLUE,
  LIGHT_GREEN,
  LIGHT_CYAN,
  LIGHT_RED,
  LIGHT_MAGENTA,
  YELLOW,
  WHITE
} DOS_COLORS;

#define true 1
#define false 0
#define UP 80
#define DOWN 72
#define ENTER 13
#define TORRES 3

void configEnviroment();
void clearScreen();
void pauseScreen();
void showMenu(int X, int Y);
void backToMenu(int X, int Y);
void gotoXY(int X, int Y);
void textColor(DOS_COLORS color);
void textBackground(DOS_COLORS color);
void printXY(int X, int Y, char* input);
int scanfXY(const int X, const int Y, const char* format, ...);
void waitScreen();
void gameEngine(const int X, const int Y);