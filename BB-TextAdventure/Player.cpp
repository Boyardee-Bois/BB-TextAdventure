/**
 * @file Player.cpp
 * @brief Implements the Player class responsible for tracking position and movement.
 *
 * @details
 * The Player class keeps track of the player's current location in the world
 * and provides basic movement functionality.
 * Movement is controlled using character-based input (W, A, S, D),
 */
#include "Player.h"
#include "NPC.h"
#include <iostream>
#include <limits>
#include <cstdio>
#include <string>
using namespace std;


/**
 * @brief Default constructor initializing player position and room.
 * @details The player starts with coordinates (0, 0) and no assigned room.
 */
Player::Player()
{
	playerX = 0;
	playerY = 0;
	currentHealth = maxHealth;
	health = 100; 
	inCombat = true; 
}

/**
 * @brief Sets the player's current room.
 * @param newRoom Pointer to the next Room.
 */




/**
 * @brief Sets the player's position on the map.
 * @param x The new X coordinate.
 * @param y The new Y coordinate.
 */
void Player::setPosition(int x, int y)
{
	playerX = x;
	playerY = y;
}

/**
 * @brief Returns the player's current X coordinate.
 * @return The player’s X position.
 */
int Player::getX() const
{
	return playerX;
}

/**
 * @brief Returns the player's current Y coordinate.
 * @return The player’s Y position.
 */
int Player::getY() const
{
	return playerY;
}

/**
 * @brief Moves the player in a specified direction.
 * @param direction Character representing movement: 'w' (up), 's' (down), 'a' (left), 'd' (right).
 *
 * @details
 * Updates the player's coordinates based on the given direction.
 */
void Player::movePlayer(char direction)
{
	switch (direction)
	{
	case 'w': // up / north
		playerY--;
		break;
	case 's': // down / south
		playerY++;
		break;
	case 'a': // left / west
		playerX--;
		break;
	case 'd': // right / east
		playerX++;
		break;
	}


	// Keep player inside map boundaries (25x25 for example)
	if (playerX < 0) playerX = 0;
	if (playerY < 0) playerY = 0;
	if (playerX >= 25) playerX = 24;
	if (playerY >= 25) playerY = 24;
}

/*
* Picking up an item from a zone
* 1.Check if
* 
*/
void Player::ItemPickUp(Item* item)
{
	if (item != nullptr)
	{
		inventory.push_back(item);

		cout << "You picked up: " << item->getItemName();
		//if (item->getIsQuestItem())

		cout << "\n";
	}
}


void Player::displayInventory()
{
	// If the inventory is empty
	if (inventory.empty()) {
		cout << "[Inventory] (empty)\n";
		return;
	}
	cout << "[Inventory]\n";

	// Go through each item in the player's inventory
	for (auto* item : inventory) {
		if (item) {
			cout << " - " << item->getItemName();

			// If the item is a quest item, show that label
			if (item->getIsQuestItem()) {
				cout << " (Quest Item)";
			}

			cout << "\n";
		}
	}
}


bool Player::hasItemName(const string& n) const
{
	for (auto* it : inventory) {
		if (it && it->getItemName() == n) return true;
	}
	return false;
}

/**
* @brief Gets the player's current health.
* @return The players current health as an integer.
*/
int Player::getCurrentHealth()
{
	return currentHealth;
}

/**
 * @brief Gets the player's max health.
 * @return The players max health as an integer.
 */
int Player::getMaxHealth()
{
	return maxHealth;
}

/**
 * @brief Take damage from sources in the game.
 * 
 * @details Subtracts the specified amount from the player's current health.
 *			Ensures health does not drop below zero.
 * 
 * @param ammount The amount of damage applied to the player.
 */
void Player::takeDamage(int amount)
{
	health -= amount;
	if (health < 0) health = 0;

	cout << "You take " << amount << " damage! (HP: "
		<< health << "/" << maxHealth << ")\n";
}

void Player::resetHealth()
{
	health = maxHealth;
}

/**
 * @brief Checks if the player is dead.
 * @return True if the player health is 0, otherwise false.
 */
bool Player::isDead()
{
	return (currentHealth <= 0);
}


int Player::getAttackPower() const
{
	return attackPower;
}
void Player::setAttackPower(int newPower)
{
	attackPower = newPower;
}

void Player::attackEnemy(Enemy* enemy)
{
	if (enemy == nullptr)
		return;

	if (!enemy->getIsAlive()) {
		std::cout << "That enemy is already defeated.\n";
		return;
	}

	enemy->takeDamage(attackPower);
}

bool Player::getInCombat(bool state)
{
	return inCombat;
}

bool Player::isAlive() const
{
	return health > 0;
}
