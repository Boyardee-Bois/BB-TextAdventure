#pragma once

#include <string>
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

public:
    
    Room();
    Room(string newRoomName, string newRoomDescription);

    // Methods
    void enterRoom();
    string getRoomName();
    void setRoomName(string newName);

    string getRoomDescription();
    void setRoomDescription(string newDescription);

    bool getIsVisited();
    void setVisited(bool visited);

    void printRoomInformation();
};