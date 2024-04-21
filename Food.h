#ifndef FOOD_H
#define FOOD_H

#include "Consumable.h"

/**
 * @brief Represents a Food item, inheriting from Consumable.
 * 
 * The Food class inherits from the Consumable class and represents
 * a consumable item that is specifically a Food.
 */
class Food : public Consumable 
{
public:
    //Default Constructor
    Food(std::string id, std::string consumable, int price)
        : Consumable(id, consumable, price, false) {} 
    /**
     * @brief Constructor for Food.
     * @param bitesAmount The amount of bites left in the Food before its empty.
     * @param isHot Boolean value telling us whether or not Food is hot.
     * @return Null.
    */
    Food(std::string id, std::string consumable, int price, int bites, bool isHot)
        : Consumable(id, consumable, price, false),  
        bitesAmount(bites), fullBitesAmount(bites), isHot(isHot) {} 


    /**
     * @brief Get the boolean value for whether or not Food is hot.
     * @return The boolean value for whether or not Food is alcoholic.
    */
    bool getIsHot() { return isHot; }

    /**
     * @brief Get the amount of bites left.
     * @return Int of bites remaining.
    */
    int getBitesAmount() { return bitesAmount; }

    /**
     * @brief Takes a bite from the Food.
     * @return Null.
     * @throws "There's no name_of_food left!"
    */
    void biteFood();

    /**
     * @brief Get the amount of bites Food can hold at max capacity.
     * @return Int of max bites possible in Food.
    */
    int getFullBitesAmount() { return fullBitesAmount; }
    
    /**
     * @brief Eats Food completely.
     * @return Null.
     * @throw "There's no name_of_food left!"
    */
    void finishFood();
    
    /**
     * @brief Get another order of Food.
     * @return Null.
     * @throw "You already have fresh name_of_food!"
    */
    void reorderFood();

private:
    int fullBitesAmount;
    int bitesAmount;
    bool isHot;
    bool isEmpty;
    
};

#endif // FOOD_H