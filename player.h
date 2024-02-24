#include <string>
#include "constants.h"
#include "map.h"

class Player {
    private:
        std::string name;
        unsigned int x;
        unsigned int y;
        Map *map;

    public:
        Player(std::string name, unsigned int x, unsigned int y);
        void setMap(Map map);
        void draw();
        void undraw();
        bool moveTo(unsigned int new_x, unsigned int new_y);
        bool moveUp();
        bool moveDown();
        bool moveLeft();
        bool moveRight();
        void debugPosition();
        Position position();
};