#include "MiniBoss.h"
#include <iostream>
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
	return 0;
}

void MiniBoss::setAttackPower(int attack)
{
	attackPower = attack;
}

void MiniBoss::printMiniBossInfo() const
{
	printEnemyInfo();
	cout << "Health: " << health << endl;
	cout << "Attack Power: " << attackPower << endl;
}
