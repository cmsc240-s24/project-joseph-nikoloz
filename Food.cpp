#include <string>
#include <stdexcept>
#include <iostream>
#include "Consumable.h"
#include "Food.h"
/**
 * @file Food.cpp
 * @brief Implementation file for the Food class functions.
*/

    
/**
 * @brief Takes a bite from the Food.
 * @return Null.
 * @throws "There's no name_of_food left!"
*/
void Food::biteFood() 
{
    std::string foodName = this->getConsumable();

    if (isEmpty == true)
    {
        throw std::invalid_argument("There's no " + foodName + " left!");
    }
    bitesAmount -= 1;
    std::cout << "You take a bite of your food. tasty" << std::endl;

    if (bitesAmount == 0)
    {
        isEmpty = true;
    }
}


/**
 * @brief Eats Food completely.
 * @return Null.
 * @throw "There's no name_of_food left!"
*/
void Food::finishFood() 
{ 
    std::string foodName = this->getConsumable();
    if (isEmpty == true)
    {
        throw std::invalid_argument("There's no " + foodName + " left!");
    }
    bitesAmount = 0;
    isEmpty = true;
    if (bitesAmount == 1)
    {
        std::cout << "You finish your food. Delicious!" << std::endl;
    } else {
        std::cout << "You stuff your mouth with the food. In a rush?" << std::endl;
    }
}

/**
 * @brief Get another order of Food.
 * @return Null.
 * @throw "You already have fresh name_of_food!"
*/
void Food::reorderFood() 
{ 
    std::string foodName = this->getConsumable();
    if (bitesAmount == fullBitesAmount)
    {
        throw std::invalid_argument("You already have fresh " + foodName + " !");
    }
    bitesAmount = fullBitesAmount;    
    std::cout << "The bartender brings you another plate of " << foodName << std::endl;

}