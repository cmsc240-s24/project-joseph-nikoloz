#include <crow.h>
#include <map>
#include <string>
#include <iostream>
#include "Consumable.h"
#include "Drink.h"
#include "Food.h"
#include "drinkFunctions.h"

using namespace std;
using namespace crow;

// Creating a map to store drinks in bars
map<string, Drink> drinksPerBarMap;

// Creating a map to store bars
//map<string, <>> barMap;

int main() 
{
    // Adding some Drinks to the Bar
    //drinksPerBarMap["1"] =  Drink("1", "Water", 1, 4, false, 0);

    //Drink water  = Drink("101", "Water", 2, 4, false, 0);
    // cout << "Drink 101             id : " << water.getId() << endl;
    // cout << "Drink 101           name : " << water.getConsumable() << endl;
    // cout << "Drink 101          price : " << "$" << water.getPrice() << endl;
    // cout << "Drink 101       isDrink? : " << water.getIsDrink() << endl;
    // cout << "Drink 101  fullSipAmount : " << water.getFullSipsAmount() << endl;
    // cout << "Drink 101      sipsAmount: " << water.getSipsAmount() << endl;
    // cout << "Drink 101         isAlc? : " << water.getIsAlc() << endl;
    // cout << "Drink 101 alcPercantage? : " << water.getAlcPercentage() << endl;

    // cout << "#########################" << endl << endl;
    // cout << "Water, #1 drink out there. Now let's see a food, maybe French Fries?" << endl << endl;
    // cout << "#########################" << endl << endl;

    // Food food = Food("201", "French Fries", 4, 23, true);
    // cout << "Food 201              id : " << food.getId() << endl;
    // cout << "Food 201            name : " << food.getConsumable() << endl;
    // cout << "Food 201           price : " << "$" << food.getPrice() << endl;
    // cout << "Food 201        isDrink? : " << food.getIsDrink() << endl;
    // cout << "Food 201 fullBitesAmount : " << food.getFullBitesAmount() << endl;
    // cout << "Food 201      bitesAmount: " << food.getBitesAmount() << endl;

    // drinksPerBarMap["1"] = Drink("101", "Water", 2, 4, false, 0);
    // drinksPerBarMap["2"] = Drink("102", "Beer", 4, 9, true, 5);
    // drinksPerBarMap["3"] = Drink("103", "Vodka", 4, 1, true, 40);
    // drinksPerBarMap["4"] = Drink("104", "Whiskey", 7, 6, true, 45);
    // drinksPerBarMap["5"] = Drink("105", "Tequila", 7, 2, true, 42);
    // drinksPerBarMap["6"] = Drink("106", "Milk", 3, 10, false, 0);
    // drinksPerBarMap["7"] = Drink("107", "OJ", 4, 9, false, 0);
    // drinksPerBarMap["8"] = Drink("108", "Soda", 4, 14, false, 0);

    // Adding some Bars to the map
    // CODE HERE

    // Read data from a file to continue saved gameplay
    drinksPerBarMap = loadFromFile("singleBar.json");

    // Setup the simple web service.
    SimpleApp app;

    //Define endpoints and CRUD methods for the Bar and/or Drink resource.
    CROW_ROUTE(app, "/api/bar").methods(HTTPMethod::POST)(createDrink);
    CROW_ROUTE(app, "/api/bar").methods(HTTPMethod::GET)(readAllDrinks);
    CROW_ROUTE(app, "/api/bar/<string>").methods(HTTPMethod::GET)(readDrink);
    CROW_ROUTE(app, "/api/bar/<string>").methods(HTTPMethod::PUT)(updateDrink);
    CROW_ROUTE(app, "/api/bar/<string>").methods(HTTPMethod::DELETE)(deleteDrink);


    // Run the web service app. 
    // *****************  MAKE SURE TO USE A UNIQUE PORT NUMBER ******************/
    app.port(17123).run();

    //Save the resources to a file to save game.
    saveToFile(drinksPerBarMap, "singleBar.json");

    return 0;
}