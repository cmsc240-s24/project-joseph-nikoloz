#include <crow.h>
#include <map>
#include <string>
#include "Consumable.h"
#include "Drink.h"

using namespace std;
using namespace crow;

// Creating a map to store drinks in bars
map<string, Drink> drinkPerBarMap;

// Creating a map to store bars
map<string, drinkPerBarMap> barMap;

int main() 
{
    // Adding some Bars to the map
    // CODE HERE

    // Read data from a file to continue saved gameplay
    // CODE HERE

    // Setup the simple web service.
    SimpleApp app;

    // Define endpoints and CRUD methods for the Bar and/or Drink resource.
    CROW_ROUTE(app, "/api/###").methods(HTTPMethod::POST)(create###);
    CROW_ROUTE(app, "/api/###").methods(HTTPMethod::GET)(readAll###);
    CROW_ROUTE(app, "/api/###/<string>").methods(HTTPMethod::GET)(read###);
    CROW_ROUTE(app, "/api/###/<string>").methods(HTTPMethod::PUT)(update###);
    CROW_ROUTE(app, "/api/###/<string>").methods(HTTPMethod::DELETE)(delete###);


    // Run the web service app. 
    // *****************  MAKE SURE TO USE A UNIQUE PORT NUMBER ******************/
    app.port(17123).run();

    //  Save the resources to a file to save game.
    saveToFile(###, "###.json");

    return 0;
}