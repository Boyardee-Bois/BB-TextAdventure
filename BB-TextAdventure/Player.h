/**
 * @file Player.h
 * @brief Defines the Player class, which represents the player in the game world.
 *
 * @details
 * The Player class tracks the player's current location and position.
 * It is designed to be expanded later with additional gameplay features
 * such as inventory, health, or stats. Currently, it provides basic
 * functionality for movement and location tracking.
 */
#pragma once

#include "Room.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * @class Player
 * @brief Represents the player and manages their current location and position.
 *
 * @details
 * The Player class stores a pointer to the current room the player is in,
 * along with X and Y coordinates for map tracking. It provides methods to
 * get and set these values, as well as move the player based on direction input.
 *
 * @note This class will be expanded to include features such as inventory,
 * player stats, and combat.
 */
class Player 
{

private:

    /** @brief Pointer to the current Room where the player is located. */
    Room* currentRoom;

    /** @brief The player’s current X coordinate on the map. */
    //int playerX;

    /** @brief The player’s current Y coordinate on the map. */
    //int playerY;

public:
    int playerX;
    int playerY;
    /** @brief Default constructor initializing position and room. */
    Player();

    /**
     * @brief Sets the player's current room.
     * @param newRoom Pointer to the Room object to set as current.
     */
    void setCurrentRoom(Room* newRoom);

    /**
     * @brief Gets the player's current room.
     * @return Pointer to the current Room object.
     */
    Room* getCurrentRoom();

    /**
     * @brief Sets the player's position.
     * @param x The X coordinate.
     * @param y The Y coordinate.
     */
    void setPosition(int x, int y);
    
    /**
     * @brief Gets the player's current X coordinate.
     * @return The X position as an integer.
     */
    int getX() const;
    
    /**
     * @brief Gets the player's current Y coordinate.
     * @return The Y position as an integer.
     */
    int getY() const; 
    
    /**
     * @brief Moves the player based on direction input.
     * @param direction A character representing the movement direction.
     *
     * @details
     * This method updates the player's position and current room based on
     * valid movement directions and available exits.
     */
    void movePlayer(char direction);
};