#include "MiniBoss.h"
#include <iostream>
#include "Player.h"
using namespace std;

MiniBoss::MiniBoss(std::string name, std::string description, int hp, int attack)
{
	setEnemyName(name);
	setEnemyDescription(description);
	health = hp;
	attackPower = attack;
}

void MiniBoss::setHealth(int hp)
{
	health = hp;
}

int MiniBoss::getAttackPower() const
{
	return attackPower;
}

void MiniBoss::setAttackPower(int attack)
{
	attackPower = attack;
}

void Player::attackEnemy(Enemy* enemy)
{
	if (enemy == nullptr)
	{
		cout << "There is no enemy to attack!" << endl;
		return; 
	}
	if(!enemy->getIsAlive())
	{
		cout << "There is no enemy to attack!" << endl;
	}
}

void MiniBoss::printMiniBossInfo() const
{
	printEnemyInfo();
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
}
