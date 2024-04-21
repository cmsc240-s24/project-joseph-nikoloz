#include <crow.h>
#include <map>
#include <string>
#include <iostream>
#include "Consumable.h"
#include "Drink.h"
#include "Food.h"

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

    Drink drink  = Drink("101", "Water", 2, 4, false, 0);
    cout << "Drink 101            id : " << drink.getId() << endl;
    cout << "Drink 101          name : " << drink.getConsumable() << endl;
    cout << "Drink 101         price : " << "$" << drink.getPrice() << endl;
    cout << "Drink 101      isDrink? : " << drink.getIsDrink() << endl;
    cout << "Drink 101 fullSipAmount : " << drink.getFullSipsAmount() << endl;
    cout << "Drink 101     sipsAmount: " << drink.getSipsAmount() << endl;
    cout << "Drink 101        isAlc? : " << drink.getIsAlc() << endl;

    cout << "#########################" << endl << endl;
    cout << "Water, #1 drink out there. Now let's see a food, maybe French Fries?" << endl << endl;
    cout << "#########################" << endl << endl;

    Food food = Food("201", "French Fries", 4, 23, true);
    cout << "Food 201              id : " << food.getId() << endl;
    cout << "Food 201            name : " << food.getConsumable() << endl;
    cout << "Food 201           price : " << "$" << food.getPrice() << endl;
    cout << "Food 201        isDrink? : " << food.getIsDrink() << endl;
    cout << "Food 201 fullBitesAmount : " << food.getFullBitesAmount() << endl;
    cout << "Food 201      bitesAmount: " << food.getBitesAmount() << endl;


    // Adding some Bars to the map
    // CODE HERE

    // Read data from a file to continue saved gameplay
    // CODE HERE

    // Setup the simple web service.
    SimpleApp app;

    // Define endpoints and CRUD methods for the Bar and/or Drink resource.
    // CROW_ROUTE(app, "/api/###").methods(HTTPMethod::POST)(create###);
    // CROW_ROUTE(app, "/api/###").methods(HTTPMethod::GET)(readAll###);
    // CROW_ROUTE(app, "/api/###/<string>").methods(HTTPMethod::GET)(read###);
    // CROW_ROUTE(app, "/api/###/<string>").methods(HTTPMethod::PUT)(update###);
    // CROW_ROUTE(app, "/api/###/<string>").methods(HTTPMethod::DELETE)(delete###);


    // Run the web service app. 
    // *****************  MAKE SURE TO USE A UNIQUE PORT NUMBER ******************/
    //app.port(17123).run();

    //  Save the resources to a file to save game.
    //saveToFile(###, "###.json");

    return 0;
}