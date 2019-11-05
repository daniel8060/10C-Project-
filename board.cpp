#include "board.h"

Tile * Board::getTile(int boardPos)  {
    return tiles.at(boardPos);
}
