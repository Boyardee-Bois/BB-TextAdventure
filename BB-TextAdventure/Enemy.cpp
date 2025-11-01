#include "Enemy.h"

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
