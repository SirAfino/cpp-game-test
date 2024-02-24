#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ncurses.h>
#include "utils.h"
#include "map.h"
#include "constants.h"
#include "player.h"

int main() {
    WINDOW * mainwin;

    if( (mainwin = initscr()) == NULL ) {
        fprintf(stderr, "Error initializing ncurses.\n");
        exit(EXIT_FAILURE);
    }

    noecho();
    keypad(mainwin, TRUE);

    clear();
    refresh();

    Map map = Map("Map 0", 64, 16);
    map.addWinningFlag(60, 3);

    Player player = Player("Player0", 10, 10);
    player.setMap(map);

    map.draw();
    player.draw();

    // char user_input;
    // while(user_input != 'q') {
    //     user_input = getch();

    //     player.undraw();

    //     if(user_input == 'w') {
    //         player.moveUp();
    //     }
    //     if(user_input == 's') {
    //         player.moveDown();
    //     }
    //     if(user_input == 'a') {
    //         player.moveLeft();
    //     }
    //     if(user_input == 'd') {
    //         player.moveRight();
    //     }

    //     player.draw();
    //     player.debugPosition();

    //     if(map.getItemAtPosition(player.position().x, player.position().y) == WINNING_FLAG) {
    //         gotoxy(MAP_ORIGIN_X, MAP_ORIGIN_Y - 1);
    //         printf("YOU WON!");
    //         user_input = 'q';
    //     }
    // }

    gotoxy(0, SCREEN_SIZE_HEIGHT + 1);
    
    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}