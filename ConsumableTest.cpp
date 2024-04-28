#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Consumable.h"
#include <string>

TEST_CASE("Consumable Tests") {

    SUBCASE("Parameterized Constructor") 
    {
        Consumable consumable("1", "Cola", 10, true);
        CHECK(consumable.getId() == "1");
        CHECK(consumable.getConsumable() == "Cola");
        CHECK(consumable.getPrice() == 10);
        CHECK(consumable.getIsDrink() == true);
    }

    SUBCASE("JSON Conversion") 
    {
        Consumable consumable("1", "Cola", 10, true);
        crow::json::wvalue result = consumable.convertToJson();
        crow::json::rvalue rValue = crow::json::load(result.dump());
        CHECK(rValue["id"].s() == "1");
        CHECK(rValue["name"].s() == "Cola");
        CHECK(rValue["price"].i() == 10);
        CHECK(bool(rValue["isDrink"]) == true);
    }

    SUBCASE("Update from JSON") 
    {
        Consumable consumable;
        crow::json::rvalue fakeJson = crow::json::load("{\"id\":\"2\", \"name\":\"Pepsi\", \"price\":15, \"isDrink\":false}");
        consumable.updateFromJson(fakeJson);
        CHECK(consumable.getId() == "2");
        CHECK(consumable.getConsumable() == "Pepsi");
        CHECK(consumable.getPrice() == 15);
        CHECK(consumable.getIsDrink() == false);
    }
}