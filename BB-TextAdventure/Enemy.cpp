#include "Enemy.h"
#include <iostream>
using namespace std; 

Enemy::Enemy()
{
	enemyName = "Unknown Enemy";
	enemyDescription = "No description available.";
	isVisible = true;
}

Enemy::Enemy(string name, string description)
{
	enemyName = name;
	enemyDescription = description;
	isVisible = true;
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


//Removes X amount from player health
void Enemy::takeDamage(int dmgAmount)
{
	if (!isAlive) return; 

	health -= amount; 
	cout << "You attacked " << name << "for " << amount << " damage!\n"; 

	if (health <= 0)
	{
		health = 0; 
		isAlive = false; 
		cout << name << " has been defeated!\n";
	}
	else
	{
		cout << name << " has " << health << " HP remaining.\n";
	}
	
}
