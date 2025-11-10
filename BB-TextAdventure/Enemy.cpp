#include "Enemy.h"
#include <iostream>
using namespace std; 

Enemy::Enemy()
{
	enemyName = "Unknown Enemy";
	enemyDescription = "No description available.";
	health = 100;
	alive = true;
}

Enemy::Enemy(string name, string description, int newHealth)
{
	enemyName = name;
	enemyDescription = description;
	isVisible = true;
	health = newHealth; 
	alive = true; 
}

string Enemy::getEnemyName() const
{
	return string();
}

string Enemy::getEnemyDescription() const
{
	return string();
}

void Enemy::setEnemyName(const string& name)
{
	enemyName = name;
}

void Enemy::setEnemyDescription(const string& description)
{
	enemyDescription = description;
}

bool Enemy::getIsVisible() const
{
	return false;
}

void Enemy::setIsVisible(bool visibility)
{
	isVisible = visibility;
}

void Enemy::printEnemyInfo() const
{
	cout << "Enemy Name: " << enemyName << endl;
	cout << "Description: " << enemyDescription << endl;
	cout << "Visible: " << (isVisible ? "Yes" : "No") << endl;
}

int Enemy::getHealth() const
{ 
	return health; 
}
bool Enemy::getIsAlive() const
{ 
	return alive;
}
void Enemy::setIsAlive(bool healthState)
{
	alive = healthState;
}
//Removes X amount from player health
void Enemy::takeDamage(int dmgAmount)
{
	if (!alive) {
		std::cout << enemyName << " is already defeated!\n";
		return;
	}

	health -= dmgAmount;
	std::cout << "You hit " << enemyName << " for " << dmgAmount << " damage!\n";

	if (health <= 0)
	{
		alive = false;
		std::cout << enemyName << " has been defeated!\n";
	}
	else
	{
		std::cout << enemyName << " has " << health << " HP remaining.\n";
	}
}
 

void Enemy::setEnemy_Position(int enemyX, int enemyY)
{
	enemy_xcoord = enemyX;
	enemy_ycoord = enemyY;
}

/**
 * @brief Returns the NPC's current X coordinate.
 * @return The NPC’s X position.
 */
int Enemy::getEnemy_X() const
{
	return enemy_xcoord;
}

/**
 * @brief Returns the NPC's current Y coordinate.
 * @return The NPC’s Y position.
 */
int Enemy::getEnemy_Y() const
{
	return enemy_ycoord;
}
