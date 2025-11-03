#pragma once
#include "Enemy.h"
#include <string>

class MiniBoss : public Enemy
{
	private:
		int health;
		int attackPower;
public: 
	MiniBoss(std::string name, std::string description, int hp, int attack);
	
	int getHealth() const;
	void setHealth(int hp);
	
	int getAttackPower() const;
	void setAttackPower(int attack);
	
	void printMiniBossInfo() const;
};
