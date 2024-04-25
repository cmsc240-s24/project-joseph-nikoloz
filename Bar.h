#ifndef BAR_H
#define BAR_H

#include <string>
#include <vector>
#include "Bartender.h"

class Bar 
{
    public:
        Bar(std::string id, std::string name, Bartender bartender) 
            : id(id), name(name), bartender(bartender) { }
        
        // getters 
        std::string getId() { return id; }
        std::string getName() { return name; }
        Bartender getBartender() { return bartender; }

        // setters
        void setId(std::string newId) { id = newId; }
        void setName(std::string newName) { name = newName; }
        void setBartender(Bartender newBart) { bartender = newBart; }

    private:
        std::string id;
        std::string name;
        Bartender bartender;

};

#endif 