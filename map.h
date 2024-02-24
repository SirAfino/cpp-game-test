#include <string>
#include <vector>
#include "utils.h"

#ifndef MAP
#define MAP

class Map {
    private:
        std::string name;
        unsigned int width;
        unsigned int height;
        std::vector<Position> winningFlags;

        void drawName();
        void drawBorders();
        void drawFlags();

    public:
        Map(std::string name, unsigned int width, unsigned int height);
        void draw();
        bool positionIsFree(unsigned int x, unsigned int y);
        int getItemAtPosition(unsigned int x, unsigned int y);
        void addWinningFlag(unsigned int x, unsigned int y);
};

#endif
