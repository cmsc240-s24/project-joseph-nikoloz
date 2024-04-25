#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Location.h"
#include "Building.h"

class Player
{
    public:
        Player(std::string name, Location currentLocation, Building currentBuilding) 
            : name(name), currentLocation(currentLocation), currentBuilding(currentBuilding) { }
        
        // getters 
        std::string getName() { return name; }
        Location getLocation() { return currentLocation; }
        Building getBuilding() { return currentBuilding; }

        // setters
        void setName(std::string newName) { name = newName; }
        void setLocation(Location newLocation) { currentLocation = newLocation; }
        void setBuilding(Building newBuilding) { currentBuilding = newBuilding; }

    private:
        std::string name;
        Location currentLocation;
        Building currentBuilding;

};

#endif //BUILDING_H