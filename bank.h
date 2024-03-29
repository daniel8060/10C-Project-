#ifndef _BANK_
#define _BANK_

#include "statics.h"

#include <vector> 
#include <memory> 


class Player;
class Property;

class Bank
{
public:

friend Property;

Bank() {}
//	moneyRemaining (Statics::getMONEY_MAX()- (Statics::getSTARTING_AMOUNT() * players.size())),
//    housesRemaining(Statics::getHOUSES_MAX()),
//	hotelsRemaining(Statics::getHOTELS_MAX())


/**
Bank pays a player from its moneyRemaining 
@param payee player being paid
@return true if successful
*/
bool pay (Player& payee, int amt);

/**
Bank takes money from a player and adds it to its moneyRemaining.
Can reduce payer's money to 0.
@param payer player that is paying the bank

*/
void take (Player& payer, int amt);

/**
checks if there are any houses in the houses pool
@return true if housesLeft != zero
*/
bool housesLeft() const;

/**
checks if there are any hotels in the hotel pool
@return true if hotelsLeft != zero
*/
bool hotelsLeft() const;


private:
int bankMoney;
std::vector <Property*> properties;
int housesRemaining;
int hotelsRemaining;

};

#endif
