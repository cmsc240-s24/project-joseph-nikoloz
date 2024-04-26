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
    // Adding some Bars to the map
    // CODE HERE

    // Read data from a file to continue saved gameplay
    drinksPerBarMap = loadFromFile("velvetMartiniConsumables.json");

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
    saveToFile(drinksPerBarMap, "velvetMartiniConsumables.json");

    return 0;
}