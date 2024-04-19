#ifndef BARTENDER_H
#define BARTENDER_H

#include "crow.h"
#include <string>
#include <vector>
#include "Consumable.h"

class Bartender 
{
    public:
        // constructor
        Bartender(std::string id, std::string name, std::string recommendation, std::vector<Consumable> consumableList)
            : id(id), name(name), recommendation(recommendation), consumableList(consumableList) { }

        // getters 
        std::string getId() { return id; }
        std::string getName() { return name; }
        std::string getRecommendation() { return recommendation; }
        std::vector<Consumable> getConsumables() { return consumableList; }
        
        // setters
        void setId(std::string newId) { id = newId; }
        void setName(std::string newName) { name = newName; }
        void setRecommendation(std::string rec) { recommendation = rec; }
        void setConsumableList(std::vector<Consumable> newList) { consumableList = newList; }

    private:
        std::string id;
        std::string name;
        std::string recommendation;
        std::vector<Consumable> consumableList;

};

#endif
