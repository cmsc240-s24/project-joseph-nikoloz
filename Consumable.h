#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>

/**
 * @brief Represents a consumable item.
 * 
 * The Consumable class holds information about a consumable item,
 * including its ID, name, and whether or not it's a drink.
 */
class Consumable 
{
public:
    /**
     * @brief Initializer for a Consumable instance.
     * @param id The id of the consumable item.
     * @param consumable The name of the consumable item.
     * @param price The price of the consumable item.
     * @param isDrink Boolean value representing whether ot not the consumable item is a drink.
     * @return Null.
     */
    Consumable(std::string id, std::string consumable, int price, bool isDrink)
        : id(id), consumable(consumable), isDrink(isDrink) { }

    /**
     * @brief Gets the id of the consumable item.
     * @return The id of the consumable item.
    */
    std::string getId() { return id; }

    /**
     * @brief Gets the name of the consumable item.
     * @return The name of the consumable item.
    */
    std::string getConsumable() { return consumable; }

    /**
     * @brief Gets the value for isDrink.
     * @return Bool for isDrink for the consumable item.
    */
    bool getIsDrink() { return isDrink; }

    /**
     * @brief Gets the current price of the consumable item.
    */
    int getPrice() { return price; }

    /**
     * @brief Sets a new price for the consumable item.
     * @param prc The new price for the consumable item.
     * @return Null.
    */
    void setPrice(int prc) { price = prc; }

private:

    std::string id;
    std::string consumable;
    int price;
    bool isDrink;
};

#endif // CONSUMABLE_H 