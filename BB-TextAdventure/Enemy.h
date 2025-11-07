#pragma once

#include <string>
using namespace std; 


class Enemy
{
protected:
	string enemyName; 
	string enemyDescription;
	bool isVisible; 

public: 
	Enemy(); 
	Enemy(string name, string description);
	virtual ~Enemy() = default; 

	virtual string getEnemyName() const;
	virtual string getEnemyDescription() const;

	void setEnemyName(const string& name);
	void setEnemyDescription(const string& description);

	bool getIsVisible() const;
	void setIsVisible(bool visibility);

	virtual void printEnemyInfo() const;

	void takeDamage(int dmgAmount);
};
