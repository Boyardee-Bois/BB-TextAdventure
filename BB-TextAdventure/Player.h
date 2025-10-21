#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
  Header: PlayerRoomMovement
  Keeps track of the current room the player is in
  Uses a switch to notify player that they're input is processed
*/
class Player 
{

private:

    Room* currentRoom;

public:

    //Constructor
    Player();

    // Set the players current location
    void setCurrentRoom(Room* newRoom);

    // Get the players current location
    Room* getCurrentRoom();
};
#endif