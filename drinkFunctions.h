#ifndef DRINK_FUNCTIONS_H
#define DRINK_FUNCTIONS_H


#include <crow.h>
#include <map>
#include <string>
//#include “Consumable.h”
#include "Drink.h"

// Functions used to handle POST, GET, PUT, and DELETE requests for the Drink resource.
crow::response createDrink(crow::request req);
crow::response readDrink(std::string id);
crow::response readAllDrinks(crow::request req);
void updateDrink(crow::request req, crow::response& res, std::string id); 
crow::response deleteDrink(std::string id);

void saveToFile(std::map<std::string, Drink> data, std::string filename);
std::map<std::string, Drink> loadFromFile(std::string filename);

#endif // DRINK_FUNCTIONS_H
