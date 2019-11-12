#include "bank.h"
#include "board.h"
#include "player.h"
#include "property.h"
#include "statics.h"
#include "tile.h"


#include <QApplication>
#include <QLabel>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    Board board;
    Bank bank;


     std::string name("jeff");
     Player* jeff = new Player(name,&bank,&board) ;
     jeff->move(9);

    board.getTile(jeff->getPos())->landingEvent(jeff);



     return a.exec();

}
