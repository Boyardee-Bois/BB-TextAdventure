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

    /** @brief Pointer to the current Room where the player is located. */
    Room* currentRoom;
    int playerX;       // player's current X position on the map
    int playerY;       // player's current Y position on the map
    std::vector<Item*> inventory; 

    /** @brief The player�s current X coordinate on the map. */
    //int playerX;

    /** @brief The player�s current Y coordinate on the map. */
    //int playerY;

    int attackPower;

    /** @brief Players current health */
    int currentHealth;

    /** @brief Players max health */
    int maxHealth = 100;

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

	int getAttackPower() const;
	void setAttackPower(int power);

	void attackEnemy(Enemy* enemy) const;
    void attackEnemy(Enemy* enemy);

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