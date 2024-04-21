#ifndef DRINK_H
#define DRINK_H

#include "Consumable.h"

/**
 * @brief Represents a drink item, inheriting from Consumable.
 * 
 * The Drink class inherits from the Consumable class and represents
 * a consumable item that is specifically a drink.
 */
class Drink : public Consumable 
{
public:
    //Default Constructor
    Drink(std::string id, std::string consumable, int price)
        : Consumable(id, consumable, price, true) {} 
    /**
     * @brief Constructor for Drink.
     * @param sipsAmount The amount of sips left in the drink before its empty.
     * @param isAlc Boolean value regarding the alcohol content of the Drink.
     * @param alcPerc The % alcohol content of the Drink.
     * @return Null.
    */
    Drink(std::string id, std::string consumable, int price, int sips, bool isAlc, int alcPerc)
        : Consumable(id, consumable, price, true),  
        sipsAmount(sips), fullSipsAmount(sips), isAlc(isAlc), alcPercentage(alcPerc)  {} 


    /**
     * @brief Get the boolean value for whether or not Drink is alcoholic.
     * @return The boolean value for whether or not Drink is alcoholic.
    */
    bool getIsAlc() { return isAlc; }

    /**
     * @brief Get the amount of sips left in Drink.
     * @return Int of sips remaining.
    */
    int getSipsAmount() { return sipsAmount; }

    /**
     * @brief Get the amount of sips Drink can hold at max capacity.
     * @return Int of max sips possible in Drink.
    */
    int getFullSipsAmount() { return fullSipsAmount; }

    /**
     * @brief Takes a sip from the Drink.
     * @return Null.
     * @throws "Drink is empty!"
    */
    void sipDrink();

    /**
     * @brief Chugs Drink fully.
     * @return Null.
     * @throw "Drink is already emtpy!"
    */
    void chugDrink();
    
    /**
     * @brief Refill Drink to fullSipsAmount.
     * @return Null.
     * @throw "Drink already full!"
    */
    void refillDrink();

private:
    int fullSipsAmount;
    int sipsAmount;
    int alcPercentage;
    bool isAlc;
    bool isEmpty;
    
};

#endif // DRINK_H