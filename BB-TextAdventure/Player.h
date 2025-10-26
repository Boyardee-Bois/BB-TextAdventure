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
    int playerX;       // player's current X position on the map
    int playerY;       // player's current Y position on the map

public:

    //Constructor
    Player();

    // Set the players current location
    void setCurrentRoom(Room* newRoom);

    // Get the players current location
    Room* getCurrentRoom();
    void setPosition(int x, int y);        // sets player's position
    int getX() const;                      // returns player's x position
    int getY() const;                      // returns player's y position
    void movePlayer(char direction);       // moves player based on input
};
#endif