#include "Item.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
* Class: Item
* --------------------------------------------
* Represents a single item in the text adventure game.
* Each Item has:
*    A name (itemName)
*    A description (itemDescription)
* 
*/

/*
* Default constructor
*/
Item::Item(){}


/*
* Creates an item with a name and description
*/
Item::Item(string newItemName, string newItemDescription)
{
	itemName = newItemName;
	itemDescription = newItemDescription;
}

/*
* Gets the name of the room
*/
string Item::getItemName()
{
	return itemName;
}

/*
* Sets the name of the room
*/
void Item::setItemName(string newName)
{
	itemName = newName;
}

/*
* Sets the name of the room
*/
void Item::setItemDescription(string newDescription)
{
	itemDescription = newDescription;
}

string Item::getItemDescription()
{
	return itemDescription;
}

/*
* Prints the name and description of a item
*/
void Item::printItemInformation()
{
	cout << itemName << ": " << itemDescription << endl;
}