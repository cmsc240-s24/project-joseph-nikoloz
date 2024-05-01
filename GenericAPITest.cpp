#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Drink.h"
#include "Food.h"
#include "GenericAPI.h"
#include <crow.h>
#include <string>

using namespace std;
using namespace crow;

// Define the maps for resources
map<string, Drink> drinksMap;
map<string, Food> foodsMap;

// Testing the Drink class
TEST_CASE("Creating a new Drink resource") 
{
    // Clear the map before testing
    GenericAPI<Drink>::consumableMap.clear();

    // Set up the request object
    request req;
    req.body = R"({"id":"1","name":"Coca-Cola","price":5,"sipsAmount":10,"alcPercentage":0,"isAlc":false})"; 

    // Perform the action
    response res = GenericAPI<Drink>::createConsumable(req);

    // Check the results
    CHECK(res.code == 201);
    CHECK(res.body == req.body);
    CHECK(GenericAPI<Drink>::consumableMap.size() == 1);
    CHECK(GenericAPI<Drink>::consumableMap.at("1").getId() == "1");
    CHECK(GenericAPI<Drink>::consumableMap.at("1").getConsumable() == "Coca-Cola");
}

TEST_CASE("Reading a Drink resource") 
{
    // Load a resource into the map
    drinksMap["1"] = Drink(json::load(R"({"id":"1","name":"Coca-Cola","price":5,"sips":10,"alcPercentage":0,"isAlc":false})"));

    // Set the map before the test
    GenericAPI<Drink>::consumableMap = drinksMap;

    // Perform the action
    response res = GenericAPI<Drink>::readConsumable("1");

    // Check the results
    CHECK(res.code == 200);
    CHECK(res.body == drinksMap["1"].convertToJson().dump());
    CHECK(GenericAPI<Drink>::consumableMap.size() == 1);
}

TEST_CASE("Reading all Drink resources") 
{
    // Load multiple resources
    drinksMap["1"] = Drink(json::load(R"({"id":"1","name":"Coca-Cola","price":5,"sips":10,"alcPercentage":0,"isAlc":false})"));
    drinksMap["2"] = Drink(json::load(R"({"id":"2","name":"Pepsi","price":5,"sips":10,"alcPercentage":0,"isAlc":false})"));

    // Set the map before the test
    GenericAPI<Drink>::consumableMap = drinksMap;

    // Perform the action
    response res = GenericAPI<Drink>::readAllConsumables(request());

    // Create the expected response body
    string expectedResponseBody = R"([{"id":"1","name":"Coca-Cola","price":5,"sips":10,"alcPercentage":0,"isAlc":false},{"id":"2","name":"Pepsi","price":5,"sips":10,"alcPercentage":0,"isAlc":false}])";

    // Check the results
    CHECK(res.code == 200);
    CHECK(res.body == expectedResponseBody);
    CHECK(GenericAPI<Drink>::consumableMap.size() == 2);
}

TEST_CASE("Updating a Drink resource") {
    // Load a resource to update
    drinksMap["1"] = Drink(json::load(R"({"id":"1","name":"Coca-Cola","price":5,"sips":10,"alcPercentage":0,"isAlc":false})"));

    // Set the map before the test
    GenericAPI<Drink>::consumableMap = drinksMap;

    // Setup request object to change the drink's details
    request req;
    req.body = R"({"id":"1","name":"Diet Coke","price":5,"sips":10,"alcPercentage":0,"isAlc":false})";

    // Setup a response object
    response res;

    // Perform the action
    GenericAPI<Drink>::updateConsumable(req, res, "1");

    // Check the results
    CHECK(res.code == 200);
    CHECK(res.body == req.body);
    CHECK(GenericAPI<Drink>::consumableMap.size() == 1);
    CHECK(GenericAPI<Drink>::consumableMap.at("1").getId() == "1");
    CHECK(GenericAPI<Drink>::consumableMap.at("1").getConsumable() == "Diet Coke");
}

