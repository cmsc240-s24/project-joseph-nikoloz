#include <string>
#include <stdexcept>
#include "Consumable.h"
#include "Food.h"
/*! @file cpp file for Food class functions.

    
/**
 * @brief Takes a bite from the Food.
 * @return Null.
 * @throws "There's no name_of_food left!"
*/
void biteFood() 
{
    std::string foodName = self.consumable();
    bitesAmount -= 1;
    if (isEmpty == true)
    {
        throw std::invalid_argument("There's no name_of_food left!");
    }
    if (sipsAmount == 0)
    {
        isEmpty = true;
    }
}


/**
 * @brief Eats Food completely.
 * @return Null.
 * @throw "There's no name_of_food left!"
*/
void chugFood() 
{ 
        if (isEmpty == true)
    {
        throw std::invalid_argument("Your drink is already empty!");
    }
    sipsAmount = 0;
    isEmpty = true;
}

/**
 * @brief Get another order of Food.
 * @return Null.
 * @throw "You already have fresh name_of_food!"
*/
void refillFood() 
{ 
        if (sipsAmount == fullSipsAmount)
    {
        throw std::invalid_argument("Your drink is already full!");
    }
    sipsAmount = fullSipsAmount;    
}