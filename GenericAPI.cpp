/**
 * @file GenericAPI.cpp
 * @brief Implementation of the Generic API for RESTful services.
 *
 * This file provides the implementation for a generic API that can be
 * specialized for different types of consumables in a RESTful service.
 */

#include <stdexcept>
#include "GenericAPI.h"
#include "Drink.h"
#include "Food.h"

using namespace std;
using namespace crow;


template<typename T> 
map<string, T> GenericAPI<T>::consumableMap;

/**
 * @brief Create a new consumable.
 * 
 * This method handles the creation of a new consumable based on the data
 * received in the request body.
 * 
 * @param req The HTTP request object.
 * @return res The HTTP response object.
 */
template<typename T> 
response GenericAPI<T>::createConsumable(request req) 
{
    // Load the request body string into a JSON read value.
    json::rvalue readValueJson = json::load(req.body);

    // If there was a problem converting the body text to JSON return an error.
    // 400 Bad Request: The server cannot or will not process the request due to something
    // that is perceived to be a client error (e.g., malformed request syntax, invalid 
    // request message framing, or deceptive request routing).
    if (!readValueJson) 
        return response(400, "Invalid JSON");
    
    // Create a new consumable.
    T consumable{readValueJson};

    // Add the new consumable to the map.
    consumableMap[consumable.getId()] = consumable;

    // Return the create consumable as a JSON string.
    // 201 Created: The request succeeded, and a new consumable was created as a result.
    // This is typically the response sent after POST requests, or some PUT requests.
    return response(201, consumable.convertToJson().dump());
}

/**
 * @brief Read a specific consumable.
 * 
 * This method retrieves a consumable identified by a unique ID.
 * 
 * @param id The unique identifier of the consumable.
 * @return res The HTTP response object.
 */
template<typename T> 
response GenericAPI<T>::readConsumable(string id) 
{
    try 
    {
        // Get the consumable from the consumable map.
        T consumable = consumableMap.at(id);

        // Return the consumable as a JSON string.
        return response(consumable.convertToJson().dump());
    } 
    catch (out_of_range& exception) 
    {
        // If the consumable was not found in the map return a 404 not found error.
        // 404 Not Found: The server cannot find the requested consumable.
        return response(404, "consumable Not Found");
    }
}

/**
 * @brief Update a specific consumable.
 * 
 * This method updates the data of a consumable identified by a unique ID.
 * 
 * @param req The HTTP request object.
 * @param res The HTTP response object.
 * @param id The unique identifier of the consumable.
 */
template<typename T> 
void GenericAPI<T>::updateConsumable(request req, response& res, string id) 
{
    try 
    {
        // Get the consumable from the consumable map.
        T consumable = consumableMap.at(id);

        // Convert the request body to JSON.
        json::rvalue readValueJson = json::load(req.body);

        // If there was a problem converting the body text to JSON return an error.
        if (!readValueJson) 
        {
            res.code = 400;
            res.end("Invalid JSON");
            return;
        }

        // Update the consumable.
        consumable.updateFromJson(readValueJson);
        consumableMap[id] = consumable;

        // Return the updated consumable as a JSON string.
        // 200 OK: The request succeeded.
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(consumable.convertToJson().dump());
        res.end();
    } 
    catch (out_of_range& exception) 
    {
        // If the consumable was not found in the map return a 404 not found error.
        res.code = 404;
        res.end("consumable Not Found");
    }
}

/**
 * @brief Delete a specific consumable.
 * 
 * This method deletes a consumable identified by a unique ID.
 * 
 * @param id The unique identifier of the consumable.
 * @return res The HTTP response object.
 */
template<typename T> 
response GenericAPI<T>::deleteConsumable(string id) 
{
    try 
    {
        // Get the consumable from the consumable map.
        T consumable = consumableMap.at(id);

        // Remove the consumable from the consumable map.
        consumableMap.erase(id);

        // Return a successful code 204 which means success but no content to return.
        return response(204);
    } 
    catch (out_of_range& exception) 
    {
        // If the consumable was not found in the map return a 404 not found error.
        return response(404, "consumable Not Found");
    }
}

// Function to handle the GET request that includes the search parameter for searching consumables.
template<typename T>
response searchConsumable(string searchString, const map<string, T>& consumableMap) 
{
    vector<T> found;
    // For each string/consumable pair in the consumableMap.
    for (pair<string, T> consumablePair : consumableMap) 
    {
        // If the search string is found in the consumable as a substring then add it to the found vector.
        if (consumablePair.second.getConsumable().find(searchString) != string::npos) 
        {
            found.push_back(consumablePair.second);
        }
    }

    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each consumable in the vector, convert the consumable to JSON and add to the write value.
    int index = 0;
    for (T consumable : found)
    {
        jsonWriteValue[index] = convertToJson(consumable);
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

// Function to handle the GET request that includes the sort parameter for sorting consumables
template<typename T>
response sortConsumables(string sortString, map<string, T>& consumableMap) 
{
   // Vector to store the consumable pairs.
   vector<pair<string, T>> consumablesToSort;

   // For each string/consumable pair in the consumablemap.
   for (pair<string, T> consumablesPair : consumableMap) 
    {
        consumablesToSort.push_back(consumablesPair);
    }

    if (sortString == "price")
    {
        if (T.isDrink())
        {
            // Sort using price comparator function 
            sort(consumablesToSort.begin(), consumablesToSort.end(), comparatorDrinkPrice); 

        } else if (sortString == "alcPercentage" || sortString == "alcoholPercentage") {
            // Sort using alcPercentage comparator function
            sort(consumablesToSort.begin(), consumablesToSort.end(), comparatorDrinkAlcPerc); 
        }
    }

   // Create a new JSON write value use to write to the file.
   json::wvalue jsonWriteValue;
   
   // For each consumable in the vector, convert the consumable to JSON and add to the write value.
   int index = 0;
   for (pair<string, T> consumablesPair : consumablesToSort)
   {
       jsonWriteValue[index] = convertToJson(consumablesPair.second);
       index++;
   }

   return response(jsonWriteValue.dump());
}




// Define a common interface for consumables(Food, Drink)
template<typename T>
bool getIsSpecial(T consumable);

template<>
bool getIsSpecial(Drink drink) 
{
    return drink.getIsAlc();
}

template<>
bool getIsSpecial(Food food) 
{
    return food.getIsHot();
}

// Function to handle the GET request that filters consumables.
template<typename T>
response filterConsumables(bool isSpecial, map<string, T>& consumableMap) 
{
    vector<T> found;
    // For each string/consumable pair in the consumables map
    for (pair<string, T> consumablePair : consumableMap) 
    {
        if (getIsSpecial(consumablePair.second) == isSpecial) 
        {
            found.push_back(consumablePair.second);
        }
    }

    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each consumable in the vector, convert the consumable to JSON and add to the write value.
    int index = 0;
    for (T consumable : found)
    {
        jsonWriteValue[index] = convertToJson(consumable);
        index++;
    }

    return response(jsonWriteValue.dump());
}

/**
 * @brief Read all consumables.
 * 
 * This method retrieves a consumable identified by a unique ID.
 * 
 * @return res The HTTP response object.
 */
template<typename T> 
response GenericAPI<T>::readAllConsumables(request req) 
{
    // If there is a search parameter on the request, then search for consumables.
    if (req.url_params.get("search"))
    {
        return searchConsumables(req.url_params.get("search"), consumableMap);
    }

    // If there is a sort parameter on the request, then sort the consumables.
    if (req.url_params.get("sort"))
    {
        return sortConsumables(req.url_params.get("sort"), consumableMap);
    }

    // If there is a isSpecial parameter on the request, then filter for special consumables(alcoholic drinks or hot foods).
    if (req.url_params.get("isAlc")) // Checking if filtering by alcoholic consumables
    {
        bool isAlc = (string(req.url_params.get("isAlc")) == "TRUE" || string(req.url_params.get("isAlc")) == "true");
        return filterConsumables(isAlc);
    }
    else if (req.url_params.get("isHot")) // Checking if filtering by hot foods
    {
        bool isHot = (string(req.url_params.get("isHot")) == "TRUE" || string(req.url_params.get("isHot")) == "true");
        return filterConsumables(isHot);
    }

    // Create a new JSON write value use to write to the file.
    json::wvalue jsonWriteValue;
    
    // For each consumable in the map, convert the consumable to JSON and add to the write value.
    int index = 0;
    for (pair<string, T> keyValuePair : consumableMap)
    {
        // first: gives you access to the first item in the pair.
        // second: gives you access to the second item in the pair.
        jsonWriteValue[index] = keyValuePair.second.convertToJson();
        index++;
    }

    return response(jsonWriteValue.dump());
}

// Explicit template instantiation
template class GenericAPI<Drink>;

