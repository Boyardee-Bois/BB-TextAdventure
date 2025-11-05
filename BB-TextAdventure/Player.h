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
#include <vector>
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

    /** @brief Players x coordinate on the map */
    int playerX;

    /** @brief Players y coordinate on the map. */
    int playerY;

    /** @brief Players current health */
    int currentHealth;

    /** @brief Players max health */
    int maxHealth = 100;

    /** @brief Pointer to the current Room where the player is located. */
    Room* currentRoom;

    /** @brief List of items in the players inventory. */
    std::vector<Item*> inventory; 

public:
    
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
    void setPosition(int x, int y);        // sets player's position
    int getX() const;                      // returns player's x position
    int getY() const;                      // returns player's y position
    void movePlayer(char direction);       // moves player based on input

    void ItemPickUp(Item* item); 
    void displayInventory(); 
    bool hasItemName(const string& n) const; 

    /**
     * @brief Gets the player's current health.
     * @return The players current health as an integer.
     */
    int getCurrentHealth();

    /**
     * @brief Gets the player's max health.
     * @return The players max health as an integer.
     */
    int getMaxHealth();

    /**
     * @brief Take damage from sources in the game.
     * @param ammount The amount of damage applied to the player.
     */
    void takeDamage(int amount);

    /**
     * @brief Checks if the player is dead.
     * @return True if the player is dead, otherwise false.
     */
    bool isDead();
};