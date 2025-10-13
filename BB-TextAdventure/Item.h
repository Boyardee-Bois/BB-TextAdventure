#pragma once
#ifndef ITEM.H
#define ITEM.H

#include <string>
using namespace std;

class Item
{
private:

	string itemName;
	string itemDescription;

public:

	Item();

	Item(string newName, string newDescription) {};

	string getItemName();
	void setItemName(string newName);

	string getItemDescription();
	void setItemDescription(string newDescription);

	void printItemInformation();
};

#endif
