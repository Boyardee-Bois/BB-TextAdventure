#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
private:

	string itemName;
	string itemDescription;
	bool isQuestItem = false; 

public:

	Item();

	Item(string newName, string newDescription);


	string getItemName();
	void setItemName(string newName);

	string getItemDescription();
	void setItemDescription(string newDescription);

	void printItemInformation() const;

	bool getIsQuestItem() const; 
	void setIsQuestItem(bool q); 

};

#endif
