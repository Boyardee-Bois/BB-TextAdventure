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
#include "Enemy.h"
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
	inCombat = false; 
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
	if (enemy == nullptr || !enemy->getIsAlive())
	{
		std::cout << "There’s no living enemy to attack.\n";
		return;
	}

	int choice = 0;
	int damage = 0;

	std::cout << "\nChoose your attack:\n";
	std::cout << "1. Light Attack (10 damage)\n";
	std::cout << "2. Heavy Attack (20 damage)\n";
	std::cout << "Enter choice (1 or 2): ";

	while (!(std::cin >> choice) || (choice != 1 && choice != 2))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid choice! Please enter 1 (Light) or 2 (Heavy): ";
	}

	if (choice == 1)
	{
		damage = 10;
		std::cout << "You perform a light attack!\n";
	}
	else
	{
		damage = 20;
		std::cout << "You perform a heavy attack!\n";
	}

	enemy->takeDamage(damage);

}

bool Player::getInCombat() const
{
	return inCombat;
}

bool Player::isAlive() const
{
	return health > 0;
}

void Player::setInCombat(bool state)
{
	inCombat = state;
}
