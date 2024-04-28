#include <crow.h>
#include <map>
#include <string>
#include <iostream>
#include "Consumable.h"
#include "Drink.h"
#include "Food.h"
#include "GenericAPI.h"
#include "persistence.h"

using namespace std;
using namespace crow;

// Creating a map to store drinks in bars
map<string, Drink> drinksMap = loadFromFile<Drink>("velvetMartiniConsumables.json");

// Creating a map to store bars
//map<string, <>> barMap;

int main() 
{
    // Create GenericAPIs to use in the CROW_ROUTES
    GenericAPI<Drink>::consumableMap = drinksMap;

    // Setup the simple web service.
    SimpleApp app;

    //Define endpoints and CRUD methods for the Bar and/or Drink consumable.
    CROW_ROUTE(app, "/api/bar").methods("POST"_method)(GenericAPI<Drink>::createConsumable);
    CROW_ROUTE(app, "/api/bar").methods("GET"_method)(GenericAPI<Drink>::readAllConsumables);
    CROW_ROUTE(app, "/api/bar/<string>").methods("GET"_method)(GenericAPI<Drink>::readConsumable);
    CROW_ROUTE(app, "/api/bar/<string>").methods("PUT"_method)(GenericAPI<Drink>::updateConsumable);
    CROW_ROUTE(app, "/api/bar/<string>").methods("DELETE"_method)(GenericAPI<Drink>::deleteConsumable);
    
    // //Define endpoints and CRUD methods for the Bar and/or Drink consumable.
    // CROW_ROUTE(app, "/api/bar").methods(HTTPMethod::POST)(createDrink);
    // CROW_ROUTE(app, "/api/bar").methods(HTTPMethod::GET)(readAllDrinks);
    // CROW_ROUTE(app, "/api/bar/<string>").methods(HTTPMethod::GET)(readDrink);
    // CROW_ROUTE(app, "/api/bar/<string>").methods(HTTPMethod::PUT)(updateDrink);
    // CROW_ROUTE(app, "/api/bar/<string>").methods(HTTPMethod::DELETE)(deleteDrink);


    // Run the web service app. 
    // *****************  MAKE SURE TO USE A UNIQUE PORT NUMBER ******************/
    app.port(17123).run();

    //Save the consumables to a file to save game.
    saveToFile<Drink>(GenericAPI<Drink>::consumableMap, "velvetMartiniConsumables.json");

    return 0;
}