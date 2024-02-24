#include "map.h"
#include "constants.h"

void Map::drawName() {
    gotoxy(MAP_ORIGIN_X, MAP_ORIGIN_Y - 2);
    printf("%s", this->name.c_str());
}

void Map::drawBorders() {
    // Top left
    gotoxy(MAP_ORIGIN_X, MAP_ORIGIN_Y);
    printf("\u250F");

    // Top
    for(int i=0; i<this->width-2; i++) {
        printf("\u2501");
    }

    // Top right
    printf("\u2513");

    // Left
    for(int i=0; i<this->height-2; i++) {
        gotoxy(MAP_ORIGIN_X, MAP_ORIGIN_Y + i + 1);
        printf("\u2503");
    }

    // Right
    for(int i=0; i<this->height-2; i++) {
        gotoxy(MAP_ORIGIN_X + this->width - 1, MAP_ORIGIN_Y + i + 1);
        printf("\u2503");
    }

    // Bottom left
    gotoxy(MAP_ORIGIN_X, MAP_ORIGIN_Y + this->height - 1);
    printf("\u2517");

    // Bottom
    for(int i=0; i<this->width-2; i++) {
        printf("\u2501");
    }

    // Bottom right
    printf("\u251B");
}

void Map::drawFlags() {
    for(auto i = this->winningFlags.begin(); i != this->winningFlags.end(); ++i) {
        Position flag = *i;
        gotoxy(MAP_ORIGIN_X + flag.x, MAP_ORIGIN_Y + flag.y);
        printf("X");
    }
}

Map::Map(std::string name, unsigned int width, unsigned int height) {
    this->name = name;
    this->width = width;
    this->height = height;
}

void Map::draw() {
    this->drawName();
    this->drawBorders();
    this->drawFlags();
}

bool Map::positionIsFree(unsigned int x, unsigned int y) {
    return (
        (x > 0) &&
        (x < this->width - 1) &&
        (y > 0) &&
        (y < this->height - 1)
    );
}

int Map::getItemAtPosition(unsigned int x, unsigned int y) {
    if(x == 0 || x == this->width -1 || y == 0 || y == this->height - 1) {
        return WALL;
    }

    for(auto i = this->winningFlags.begin(); i != this->winningFlags.end(); ++i) {
        Position flag = *i;
        if(flag.x == x && flag.y == y) {
            return WINNING_FLAG;
        }
    }

    return EMPTY;
}

void Map::addWinningFlag(unsigned int x, unsigned int y) {
    this->winningFlags.push_back({x: x, y: y});
}
