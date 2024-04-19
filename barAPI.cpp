#include <crow.h>
#include <map>
#include <string>
#include "Consumable.h"
#include "Drink.h"

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
    Drink drink  = Drink("1", "Water", 5, 4, false, 0);
    cout << "Drink 1            id : " << drink.getId() << endl;
    cout << "Drink 1          name : " << drink.getConsumable() << endl;
    cout << "Drink 1         price : " << "$" << drink.getPrice() << endl;
    cout << "Drink 1      isDrink? : " << drink.getIsDrink() << endl;
    cout << "Drink 1 fullSipAmount : " << drink.getFullSipsAmount() << endl;
    cout << "Drink 1     sipsAmount: " << drink.getSipsAmount() << endl;
    cout << "Drink 1        isAlc? : " << drink.getIsAlc() << endl;
    cout << "Drink 1      isEmpty? :" << " No method for GetIsEmpty(dont need) " << endl;


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