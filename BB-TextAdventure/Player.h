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

public:

    void Movement_Counter();

    Player(Room* startRoom) :currentRoom(startRoom) {}

    Room* getCurrentRoom() const { return currentRoom; }

    void setCurrentRoom(Room* room) { currentRoom = room; }

    Room* currentRoom;

    void Reset_Coordinates(Room* room);
};
#endif