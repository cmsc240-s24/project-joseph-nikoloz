#ifndef BARTENDER_H
#define BARTENDER_H

#include "crow.h"
#include <string>
#include <map>
#include "Consumable.h"

class Bartender 
{
    public:
        // constructor and destructor 
        Bartender(std::string id, std::string name,/*std::string recommendation,*/ std::map<std::string, Consumable> consumableList)
            : id(id), name(name), /*recommendation(recommendation),*/ consumableList(consumableList) { }
        ~Bartender();

        // getters 
        std::string getId() { return id; }
        std::string getName() { return name; }
       // std::string getRecommendation() { return recommendation; }
        std::map<std::string, Consumable> getConsumables() { return consumableList; }
        
        // setters
        void setId(std::string newId) { id = newId; }
        void setName(std::string newName) { name = newName; }
       // void setRec(std::string rec) { recommendation = rec; }
        void setConsumableList(std::map<std::string, Consumable> newList) { consumableList = newList; }

    private:
        std::string id;
        std::string name;
        //std::string recommendation;
        std::map<std::string, Consumable> consumableList;

};

#endif
