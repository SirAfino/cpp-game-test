#ifndef UTILS
#define UTILS

struct Position {
    unsigned int x;
    unsigned int y;
};

void gotoxy(int x,int y);
void gotoxy(Position position);

#endif