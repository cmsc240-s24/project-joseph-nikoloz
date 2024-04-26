#include <crow.h>
#include <map>
#include <string>
#include "Drink.h"

using namespace std;
using namespace crow;

extern map<string, Drink> drinksPerBarMap;

json::wvalue convertDrinkToJson(Drink drink) 
{
    json::wvalue writeValueJson;
    writeValueJson["id"] = drink.getId();
    writeValueJson["name"] = drink.getConsumable();
    writeValueJson["price"] = drink.getPrice();
    writeValueJson["isAlc"] = drink.getIsAlc();
    writeValueJson["fullSipsAmount"] = drink.getFullSipsAmount();
    writeValueJson["sipsAmount"] = drink.getSipsAmount();
    writeValueJson["alcPercentage"] = drink.getAlcPercentage();

     
    return writeValueJson;
}
// Function to handle the GET request that includes the search parameter for searching drinks.
response searchDrinks(string searchString) 
{
    vector<Drink> found;
    // For each string/Drink pair in the drinksPerBarMap.
    for (pair<string, Drink> drinkPair : drinksPerBarMap) 
    {
        // If the search string is found in the drink as a substring then add it to the found vector.
        if (drinkPair.second.getConsumable().find(searchString) != string::npos) 
        {
            found.push_back(drinkPair.second);
        }
    }

    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each drink in the vector, convert the drink to JSON and add to the write value.
    int index = 0;
    for (Drink drink : found)
    {
        jsonWriteValue[index] = convertDrinkToJson(drink);
        index++;
    }

    return response(jsonWriteValue.dump());
}

// Comparator to sort pairs according to third value drink's price.
struct
{
   bool operator()(pair<string, Drink>& a, pair<string, Drink>& b) 
   { 
       return a.second.getPrice() < b.second.getPrice(); 
   } 
} comparatorDrinkPrice;

// Comparator to sort pairs according to seventh value drink's alcohol percentage.
struct
{
   bool operator()(pair<string, Drink>& a, pair<string, Drink>& b) 
   { 
       return a.second.getAlcPercentage() < b.second.getAlcPercentage(); 
   } 
} comparatorDrinkAlcPerc;


// Function to handle the GET request that includes the sort parameter for sorting drinks
response sortDrinks(string sortString) 
{
   // Vector to store the pizza sizes pairs.
   vector<pair<string, Drink>> drinksToSort;

   // For each string/Drink pair in the drinks map.
   for (pair<string, Drink> drinksPair : drinksPerBarMap) 
    {
        drinksToSort.push_back(drinksPair);
    }

   if (sortString == "price")
    {
        // Sort using price comparator function 
        sort(drinksToSort.begin(), drinksToSort.end(), comparatorDrinkPrice); 
    } else if (sortString == "alcPercentage" || sortString == "alcoholPercentage") {
        // Sort using alcPercentage comparator function
        sort(drinksToSort.begin(), drinksToSort.end(), comparatorDrinkAlcPerc); 
    }

   // Create a new JSON write value use to write to the file.
   json::wvalue jsonWriteValue;
   
   // For each drink  in the vector, convert the drink to JSON and add to the write value.
   int index = 0;
   for (pair<string, Drink> drinksPair : drinksToSort)
   {
       jsonWriteValue[index] = convertDrinkToJson(drinksPair.second);
       index++;
   }

   return response(jsonWriteValue.dump());
}


// Function to handle the GET request that filters drinks.
response filterDrinks(bool isAlc) 
{
    vector<Drink> found;
    // For each string/Drink pair in the drinksPerBarMap
    for (pair<string, Drink> drinkPair : drinksPerBarMap) 
    {
        if (drinkPair.second.getIsAlc() == isAlc) 
        {
            found.push_back(drinkPair.second);
        }
    }

    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each drink in the vector, convert the drink to JSON and add to the write value.
    int index = 0;
    for (Drink drink : found)
    {
        jsonWriteValue[index] = convertDrinkToJson(drink);
        index++;
    }

    return response(jsonWriteValue.dump());
}

response createDrink(request req) 
{
    // Load the request body string into a JSON read value.
    json::rvalue readValueJson = json::load(req.body);

    // If there was a problem converting the body text to JSON return an error.
    if (!readValueJson) 
        return response(400, "Invalid JSON");
    
    // Create a new drink. 
    Drink drink{
    readValueJson["id"].s(),
    readValueJson["name"].s(),
    static_cast<int>(readValueJson["price"].d()),
    static_cast<int>(readValueJson["sipsAmount"].d()),
    readValueJson["isAlc"].b(),
    static_cast<int>(readValueJson["alcPercentage"].d())
    };
    // Add the new drink to the map.
    drinksPerBarMap[drink.getId()] = drink;

    // Return the created drink as a JSON string.
    return response(201, convertDrinkToJson(drink).dump());
}

response readDrink(string id) 
{
    try 
    {
        // Get the drink from the drinksPerBarMap map.
        Drink drink = drinksPerBarMap.at(id);

        // Return the drink as a JSON string.
        return response(convertDrinkToJson(drink).dump());
    } 
    catch (out_of_range& exception) 
    {
        // If the drink was not found in the map return a 404 not found error.
        return response(404, "Drink Not Found");
    }
}

response readAllDrinks(request req) 
{
    // If there is a search parameter on the request, then search for drinks.
    if (req.url_params.get("search"))
    {
        return searchDrinks(req.url_params.get("search"));
    }

    // If there is a sort parameter on the request, then sort the drinks.
    if (req.url_params.get("sort"))
    {
        return sortDrinks(req.url_params.get("sort"));
    }

    // If there is a isAlc parameter on the request, then filter for alcoholic drinks.
    if (req.url_params.get("isAlc"))
    {
        bool isAlc = false;
        if (string(req.url_params.get("isAlc")) == "TRUE" || string(req.url_params.get("isAlc")) == "true")
        {
           isAlc = true; 
        }
        return filterDrinks(isAlc);
    }

    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each drink in the map, convert the drink to JSON and add to the write value.
    int index = 0;
    for (pair<string, Drink> keyValuePair : drinksPerBarMap)
    {

        jsonWriteValue[index] = convertDrinkToJson(keyValuePair.second);
        index++;
    }

    return response(jsonWriteValue.dump());
}

void updateDrink(request req, response& res, string id) 
{
    try 
    {
        // Get the drink from the drinksPerBarMap map.
        Drink drink = drinksPerBarMap.at(id);

        // Convert the request body to JSON.
        json::rvalue readValueJson = json::load(req.body);

        // If there was a problem converting the body text to JSON return an error.
        if (!readValueJson) 
        {
            res.code = 400;
            res.end("Invalid JSON");
            return;
        }

        // Update the drink.
        drink.setConsumable(readValueJson["consumable"].s());
        drink.setIsAlc(readValueJson["isAlc"].b());
        drinksPerBarMap[id] = drink;

        // Return the updated drink as a JSON string.
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(convertDrinkToJson(drink).dump());
        res.end();
    } 
    catch (out_of_range& exception) 
    {
        // If the drink was not found in the map return a 404 not found error.
        res.code = 404;
        res.end("Drink Not Found");
    }
}

response deleteDrink(string id) 
{
    try 
    {
        // Get the drink from the drinksPerBarMap map.
        Drink drink = drinksPerBarMap.at(id);

        // Remove the drink from the drinksPerBarMap map.
        drinksPerBarMap.erase(id);

        // Return a successful code 204 which means success but no content to return.
        return response(204);
    } 
    catch (out_of_range& exception) 
    {
        // If the drink was not found in the map return a 404 not found error.
        return response(404, "Drink not found");
    }
}

void saveToFile(map<string, Drink> data, string filename)  
{
    // Open the file for writing
    ofstream file(filename);

    if (file.is_open()) 
    {
        // Create a new JSON write value use to write to the file.
        json::wvalue jsonWriteValue;
        
        // For each object in the map, convert the object to JSON and add to the write value.
        int index = 0;
        for (pair<string, Drink> keyValuePair : data)
        {
            // first: gives you access to the first item in the pair.
            // second: gives you access to the second item in the pair.
            jsonWriteValue[index] = convertDrinkToJson(keyValuePair.second);
            index++;
        }

        // Write the JSON to the file.
        file << jsonWriteValue.dump();
        file.close();
    }
}


map<string, Drink> loadFromFile(string filename) 
{
    map<string, Drink> data;
    
    // Open the file for reading.
    ifstream file(filename);

    // If the file is open. 
    if (file.is_open()) 
    {      
        // Create a stream for reading in the file.
        ostringstream stringStreamJson;

        // Read the entire JSON string.
        stringStreamJson << file.rdbuf();

        // Load the string into a JSON read value object.
        json::rvalue jsonReadValue = json::load(stringStreamJson.str());

        // Close the file.
        file.close();

        // For each item in the JSON convert it to an object, 
        // and add it to the data map.
        for (json::rvalue item : jsonReadValue) 
        {
            Drink drink{            item["id"].s(), 
                                    item["name"].s(), 
                    static_cast<int>(item["price"].d()), 
                    static_cast<int>(item["sipsAmount"].d()), 
                                    item["isAlc"].b(), 
                    static_cast<int>(item["alcPercentage"].d())};
            data[drink.getId()] = drink;
        }
    }
    
    return data;
}
