#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

void gotoxy(Position position) {
    gotoxy(position.x, position.y);
}

// void gotoxy(short a, short b) {
//     COORD coordinates;
//     coordinates.X = a;
//     coordinates.Y = b;
 
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
// }