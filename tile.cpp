#include "tile.h"
#include "QLandingWindows.h"
#include "player.h"
#include <string>




ownableTile::ownableTile(int _tileNum, Board* _board):
    Tile(_tileNum, _board), owner(nullptr)
    {}

void ownableTile::landingEvent(Player *currPlayer){
    if(!propOwner()) { //property is unowned
        QLandingOptions* propWindow = new QLandingOptions
                                    (generateView(),
                                    "Unowned!\n Purchase this property?",
                                    "Yes",
                                    "No");

        QObject::connect(propWindow->getLeft(),&QPushButton::clicked,     //connects Yes button to player buy fxn
                         currPlayer->interactor, &Player::QInteractor::buyBankProp);

    }
    else if (propOwner() = currPlayer) {//player lands on their own property

    }

    else { //someone else owns the property so pay them rent
        std::string popupMessage = "Rent due:" +

    }
}

Player* ownableTile::propOwner() const {return owner;}

//void ownableTile::transfer(const Player& newOwner){ owner = &newOwner;}

void ownableTile::transfer(Player* newOwner){owner = newOwner;}

