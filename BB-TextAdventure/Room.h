#pragma once
#include <string>
#include <map>
#include "Item.h" 
using namespace std;

/*
* Header: Room.h
* --------------------------------------------
* Defines the Room class used in the text adventure.
* This header exposes the class structure so it can
* be used by other files
*/

class Room
{
private:
    string roomName;
    string roomDescription;
    bool isVisited;
    map<string, Room*> exits;
    Item* roomItem = nullptr; 

public:
    
    Room();
    Room(string newRoomName, string newRoomDescription);

    // Methods
    void enterRoom();
    string getRoomName();
    void setRoomName(string newName);

    string getRoomDescription();
    void setRoomDescription(string newDescription);

    bool getIsVisited() const;
    void setVisited(bool visited);

    void printRoomInformation();

    void addExit(const string& direction, Room* neighbor);
    Room* getExit(const string& direction);

    Item* getItem(); 
    void setItem(Item* i); 

    void removeItem();
    bool hasItem() const;

};

