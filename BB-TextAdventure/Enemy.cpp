#include "Enemy.h"
#include <iostream>
#include "Player.h"
using namespace std; 

Enemy::Enemy()
{
	srand((unsigned)time(0));
	enemyName = "Unknown Enemy";
	enemyDescription = "No description available.";
	health = 100;
	alive = true;
	attackPower = 10;
	isActive = false; 
	isVisible = false;
	enemy_xcoord = 0;
	enemy_ycoord = 0;
}

Enemy::Enemy(string name, string description, int newHealth)
{
	enemyName = name;
	enemyDescription = description;
	isVisible = true;
	health = newHealth; 
	alive = true; 
	attackPower = 10; 
	isActive = false; 
	enemy_xcoord = 0;
	enemy_ycoord = 0;
}

string Enemy::getEnemyName() const
{
	return enemyName;
}

string Enemy::getEnemyDescription() const
{
	return enemyDescription;
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
	return isVisible;
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
int Enemy::getAttackPower() const
{
	return attackPower;
}
void Enemy::attackPlayer(Player* player) const
{
	if (!alive) {
		player->resetHealth();
		return;
	}
	// Randomize choice: 0 = Light, 1 = Heavy
	int choice = rand() % 2;
	int damage = 0;
	std::string attackName;

	if (choice == 0)
	{
		attackName = "light";
		damage = 10;
	}
	else
	{
		attackName = "heavy";
		damage = 20;
	}

	cout << enemyName << " uses a " << attackName
		<< " attack and deals " << damage << " damage!\n";

	player->takeDamage(damage);
}
bool Enemy::isAlive() const
{
	return health > 0 && alive;
}
//Removes X amount from player health
void Enemy::takeDamage(int amount)
{
	if (!alive) return;

	health -= amount;
	if (health <= 0) {
		health = 0;
		alive = false;
		std::cout << enemyName << " has been defeated!\n";
		std::cout << "Defeating the enemy recovered your HP X_X!\n";
	}
	else {
		std::cout << "You hit " << enemyName
			<< " for " << amount
			<< " damage! (" << health << " HP remaining)\n";
	}
}

void Enemy::setActive(bool value)
{
	isActive = value; 
}

bool Enemy::getActive() const
{
	return isActive; 
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
