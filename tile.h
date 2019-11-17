#ifndef _TILE_
#define _TILE_



class Player;
class QWidget;

class Tile  {

public:
    friend class Board;

    Tile ()            : tileNumber(0)         {}
    Tile (int _tileNum): tileNumber(_tileNum)  {}

	
	
    /**
    most important method of the game, probably.
    called at the end of every movement so that the landed on tile exhibits its
    desired behavior (e.g. a popup window for landing on a property w/ the option to buy.)
    */
	virtual void landingEvent(Player* currPlayer) =0;

    /**
    @return pointer to QWidget displaying the tile.
    */
    virtual QWidget* generateView() = 0;

    virtual ~Tile() = default;


protected:
	int tileNumber;

};


#endif
