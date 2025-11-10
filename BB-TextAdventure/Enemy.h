#pragma once
#include <string>
#include <iostream>
using namespace std; 

class Player; 

class Enemy
{
protected:
	string enemyName; 
	string enemyDescription;
	bool isVisible; 
	int health;
	bool alive = true;
	int enemy_xcoord;
	int enemy_ycoord;
	int attackPower; 

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


	void setEnemy_Position(int enemyX, int enemyY);

	int getEnemy_X() const;

	int getEnemy_Y() const;

	int getHealth() const;
	bool getIsAlive() const;
	void setIsAlive(bool state);

	
	int getAttackPower() const;
	void attackPlayer(Player* player) const;
	bool isAlive() const;
	void takeDamage(int amount);
};
