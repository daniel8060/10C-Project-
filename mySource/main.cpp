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
     QLabel* test =new QLabel("hello!");
     test->show();

     std::string name("jeff");
     Player* jeff = new Player(name) ;

     Property* teest = new Property;

     teest->landingEvent(jeff);


     return a.exec();

}
