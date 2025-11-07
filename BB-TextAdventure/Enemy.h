#pragma once

#include <string>
using namespace std; 


class Enemy
{
protected:
	string enemyName; 
	string enemyDescription;
	bool isVisible; 
	int health;
	bool alive = true;

public: 
	Enemy(); 
	Enemy(string name, string description, int newHealth);

	virtual ~Enemy() = default; 

	virtual string getEnemyName() const;
	virtual string getEnemyDescription() const;

	void setEnemyName(const string& name);
	void setEnemyDescription(const string& description);

	bool getIsVisible() const;
	void setIsVisible(bool visibility);

	virtual void printEnemyInfo() const;

	void takeDamage(int dmgAmount);

	int getHealth() const;
	bool getIsAlive() const;
	void setIsAlive(bool state);
};
