#ifndef _TILE_
#define _TILE_

#include <string>

class Player;
class QWidget;

class Tile  {

public:
    friend class Board;

    Tile ()            : tileNumber(0)         {}
    Tile (int _tileNum, Board* _board): tileNumber(_tileNum), board(_board)  {}

	
	
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
    Board* board;

};

/**
abstract base class for tiles that can be purchased/ owned.
Includes regular properties, utilities and railroads.
implements landing event as an option to purchase or charges rent.
*/
class ownableTile : public Tile {

public:

    ownableTile(int _tileNum, Board* _board);

    virtual void landingEvent(Player *currPlayer) override;

    virtual QWidget * generateView() =0;

    virtual int currentRent() const = 0;

    /**
    @return owner of this tile
    */
    Player* propOwner() const;

    /**
    Changes owner of this tile to specified player.
    @param newOwner will become owner of this tile
    */
    void transfer( Player* newOwner);

    virtual ~ownableTile() override= default;

protected:
    Player* owner;

private:

};



class eventTile : public Tile {
public:


    virtual ~eventTile() = default;

};

#endif
