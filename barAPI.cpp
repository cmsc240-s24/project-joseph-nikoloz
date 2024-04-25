#include <crow.h>
#include <map>
#include <string>
#include <iostream>
#include "Location.h"
#include "Building.h"
#include "Consumable.h"
#include "Drink.h"
#include "Food.h"
#include "drinkFunctions.h"

using namespace std;
using namespace crow;


// Creating a map to store buildings in the starting location, Riverton
map<string, Building> buildingsInRiverton;

// Creating a map to store buildings in the second location, Emerald Gate 
map<string, Building> buildingsInEmeraldGate;

// Creating a map to store buildings in the magic realm, Moonshine Grove
map<string, Building> buildingsInMoonshineGrove;

// Create a list of all locations
map<string, map<string, Building>> barWorld;

int main() 
{
    //Create buildings(airports, magic tree), and add them to their locations.
    buildingsInRiverton["1"] = Building("Airport", false, true, false);
    buildingsInEmeraldGate["1"] = Building("Airport", false, true, false);
    buildingsInEmeraldGate["2"] = Building("Mysterious Tree", false, false, true);
    buildingsInMoonshineGrove["1"] = Building("Mysterious Tree", false, false, true);

    //Create bars for Riverton, and add the list of consumables to it.
    map<string, Consumable> velvectMartiniConsumables;
    buildingsInRiverton["2"] = Bar("Velvet Martini", Bartender("2", "Jasper Marlowe", velvectMartiniConsumables)); 

    map<string, Consumable> rivertonRooftopConsumables;
    buildingsInRiverton["3"] = Bar("Riverton Rooftop", Bartender("3", "Eliza Thorne", rivertonRooftopConsumables)); 

    map<string, Consumable> drunkenDuckConsumables;
    buildingsInRiverton["4"] = Bar("The Drunken Duck", Bartender("4", "Finn Harper", drunkenDuckConsumables)); 

    //Create bars for Emerald Gate
    map<string, Consumable> onyxOakConsumables;
    buildingsInEmeraldGate["3"] = Bar("Onyx & Oak", Bartender("3", "Mira Blackwood", onyxOakConsumables));

    map<string, Consumable> foggyBrewsConsumables;
    buildingsInEmeraldGate["4"] = Bar("Foggy Brews", Bartender("4", "Cedric Fogwell", foggyBrewsConsumables));

    map<string, Consumable> rustyAnchorConsumables;
    buildingsInEmeraldGate["5"] = Bar("The Rusty Anchor", Bartender("5", "Tom 'Old Salt' Maddox", rustyAnchorConsumables));

    //Create bars for Moonshine Grove
    map<string, Consumable> pixiePotConsumables;
    buildingsInMoonshineGrove["2"] = Bar("The Pixie Pot", Bartender("2", "Lilly Fae", pixiePotConsumables));

    map<string, Consumable> phantomPintConsumables;
    buildingsInMoonshineGrove["3"] = Bar("The Phantom Pint", Bartender("3", "Gideon Shade", phantomPintConsumables));

    map<string, Consumable> tipsyTrollConsumables;
    buildingsInMoonshineGrove["4"] = Bar("The Tipsy Troll", Bartender("4", "Borg Grumblefoot", tipsyTrollConsumables));

    map<string, Consumable> goblinsGrogHouseConsumables;
    buildingsInMoonshineGrove["5"] = Bar("Goblin's Grog House", Bartender("5", "Snarltooth Grimfix", goblinsGrogHouseConsumables));

    barWorld["1"] = buildingsInRiverton;
    barWorld["2"] = buildingsInEmeraldGate;
    barWorld["3"] = buildingsInMoonshineGrove;

    // Read data from a file to continue saved gameplay
    for (pair<string, map<string, Building>> buildingsMapPair : barWorld)
    {   
        for (pair<string, Building> locationBuildings : buildingsMapPair.second)
        {
            if ( locationBuildings.second.getIsBar() )
            {
                for (pair<string, Consumable> consumablesPair : locationBuildings.second.getIsBar().getBartender())
                {
                    map<string, Consumable> newList = loadFromFile(locationBuildings.second.getName() + ".json");
                    consumablesPair.second.setConsumableList(newList);
                }
            }
        }
    } 

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
