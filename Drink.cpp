#include <string>
#include <stdexcept>
#include "Consumable.h"
#include "Drink.h"
/*! @file cpp file for Drink class functions.

/**
 * @brief Takes a sip from the Drink
 * @return Null.
 * @throws "Drink is empty!"
*/
void Drink::sipDrink() 
{
    sipsAmount -= 1;
    if (isEmpty == true)
    {
        throw std::invalid_argument("Your drink is already empty!");
    }
    if (sipsAmount == 0)
    {
        isEmpty = true;
    }

}

/**
 * @brief Chugs Drink fully.
 * @return Null.
 * @throw "Drink is already emtpy!"
*/
void Drink::chugDrink()
{
    if (isEmpty == true)
    {
        throw std::invalid_argument("Your drink is already empty!");
    }
    sipsAmount = 0;
    isEmpty = true;

}

/**
 * @brief Refill Drink to fullSipsAmount.
 * @return Null.
 * @throw "Drink already full!"
*/
void Drink::refillDrink()
{
    if (sipsAmount == fullSipsAmount)
    {
        throw std::invalid_argument("Your drink is already full!");
    }
    sipsAmount = fullSipsAmount;    
}