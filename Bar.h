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
        std::string getId();
        std::string getName();
        Bartender getBartender();

        // setters
        void setId();
        void setName();
        void setBartender(Bartender bartender);

    private:
        std::string id;
        std::string name;
        Bartender bartender;

};

#endif 