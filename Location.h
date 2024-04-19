#ifndef LOCATION_H
#define LOCATION_H

#include "Bar.h"
#include <string>
#include <vector>

class Location 
{
    public:
        Location(std::string id, std::string name, std::vector<Bar> barList)
            : id(id), name(name), barList(barList) { }

        // getters
        std::string getId() { return id; }
        std::string getName() { return name; }
        std::vector<Bar> getBarList() { return barList; }

        // setters
        void setId(std::string newId) { id = newId; }
        void setName(std::string newName) { name = newName; }
        void setBarList(std::vector<Bar> newList) { barList = newList; }

    private:
        std::string id;
        std::string name;
        std::vector<Bar> barList;

};

#endif