#include "property.h"
#include "player.h"
#include "bank.h"
#include "QLandingWindows.h"

#include <QGridLayout>
#include <QPainter>


Player* Property::propOwner() const {return owner;}

QWidget*  Property::generateView() {
    return (new View(*this));
}


void Property::landingEvent(Player* currPlayer) {
    if(!propOwner()) { //property is unowned
        QLandingOptions* propWindow = new QLandingOptions
                                    (generateView(),
                                    "Unowned!\n Purchase this property?",
                                    "Yes",
                                    "No");

        QObject::connect(propWindow->getLeft(),&QPushButton::clicked,     //connects Yes button to player buy fxn
                         currPlayer->interactor, &Player::QInteractor::buyBankProp);

        QObject::connect(propWindow->getRight(), &QPushButton::clicked,   //connect No button to closing pop up window
                         propWindow, &QWidget::close);

	
	}
	
}


void Property::transfer(Player* newOwner) {
    owner = newOwner;
	}

bool Property::buildHouse(Bank* bank) {
	if (houseCount<4){ //trying to build a house
		if (bank->housesLeft() && (owner->playerMoney >=houseCost)){//bank has houses left to build and owner has enough money
            bank->take(*owner, houseCost);//charge player for house
			++houseCount;
            --bank->housesRemaining;
			return true;
		}
		else {return false;} //no houses left do nothing
		//TODO: figure out how to output error message 
		
	}
	else if (houseCount==4 ) {//building a hotel
        if(bank->hotelsLeft() && (owner->playerMoney >=hotelCost)) {//hotels left and owner has enough money
        bank->take(*owner,hotelCost);//charge owner for a hotel
		++houseCount;
        --bank->hotelsRemaining;
		return true;
		}
		else {return false;} 
		//TODO:figure out how to output error messsage
		
	}
	else { return false;} 
	//TODO: figure out how to output error message 
	
}

int Property::currentRent() const {
    if(propOwner()) {//if property is owned
        return rents[houseCount]; //return rent corresponding to current number of houses
	}
	return 0; //if unowned, no rent is due.
}

//Property::View class stuff

Property::View::View(const Property& prop)  {


    //std::string fileName= "Assets\\Properties\\Prop"+std::to_string(prop.tileNumber)+".png";
    //QString qfileName(QString::fromStdString(fileName));
    //image = QPixmap(qfileName);

    image= QPixmap(":/Properties/Assets/Properties/BlueProperty.png");



}

void Property::View::paintEvent(QPaintEvent *){

    QPainter p(this);
    QPoint point(0,0);

    p.drawPixmap(point,image);
}

