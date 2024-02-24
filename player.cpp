#include "player.h"

Player::Player(std::string name, unsigned int x, unsigned int y) {
    this->name = name;
    this->x = x;
    this->y = y;
}

void Player::setMap(Map map) {
    this->map = &map;
}

void Player::draw() {
    gotoxy(MAP_ORIGIN_X + this->x, MAP_ORIGIN_Y + this->y);
    printf("%c", (char) 178);
}

void Player::undraw() {
    gotoxy(MAP_ORIGIN_X + this->x, MAP_ORIGIN_Y + this->y);
    printf(" ");
}

bool Player::moveTo(unsigned int new_x, unsigned int new_y) {
    if(this->map == NULL) {
        return false;
    }

    const int item = this->map->getItemAtPosition(new_x, new_y);
    if(item != EMPTY) {
        return false;
    }

    this->x = new_x;
    this->y = new_y;

    return true;
}

bool Player::moveUp() {
    return this->moveTo(this->x, this->y - 1);
}

bool Player::moveDown() {
    return this->moveTo(this->x, this->y + 1);
}

bool Player::moveLeft() {
    return this->moveTo(this->x - 1, this->y);
}

bool Player::moveRight() {
    return this->moveTo(this->x + 1, this->y);
}

void Player::debugPosition() {
    gotoxy(70, 2);
    printf("X: %d   ", this->x);

    gotoxy(70, 3);
    printf("Y: %d   ", this->y);
}

Position Player::position() {
    return {
        x: this->x,
        y: this->y
    };
}
