#ifndef BAR_H
#define BAR_H

#include <string>
#include <vector>
#include "Bartender.h"
#include "Building.h"

class Bar : public Building
{
    public:
        Bar(std::string name, Bartender bartender ) 
            : Building(name, true, false, false),
            bartender(bartender) { }

        // getters 
        std::string getName() { return name; }
        Bartender getBartender() { return bartender; }

        // setters
        void setName(std::string newName) { name = newName; }
        void setBartender(Bartender newBart) { bartender = newBart; }

    private:
        std::string name;
        Bartender bartender;

};

#endif 