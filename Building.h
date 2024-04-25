#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>

class Building
{
    public:
        Building(std::string name, bool bar, bool airport, bool magicTree) 
            : name(name), bar(bar), airport(airport), magicTree(magicTree) { }
        
        // getters 
        std::string getName() { return name; }
        bool getIsBar() { return bar; }

        // setters
        void setName(std::string newName) { name = newName; }

    private:
        std::string name;
        bool bar;
        bool airport;
        bool magicTree;

};

#endif //BUILDING_H