/**
 * @file Item.cpp
 * @brief Implements the Item class used to represent interactable objects in the game.
 *
 * @details
 * The Item class defines objects that exist within rooms or inventories.
 * Each item has a name and description, which can be displayed or used by
 * the player. This class can be expanded to include more gameplay options
 * such as usability, weight, or interaction effects.
 */
#include "Item.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * @brief Default constructor.
 * 
 * @details Creates an empty item with no name or description.
 */
Item::Item() {}


/**
 * @brief Constructs an item with a name and description.
 * 
 * @param newName The name of the item.
 * 
 * @param newDescription A description of the item.
 */
Item::Item(string newName, string newDescription)
{
	itemName = newName;
	itemDescription = newDescription;
}

/**
 * @brief Returns the item's name.
 * 
 * @return The item's name as a string.
 */
string Item::getItemName()
{
	return itemName;
}

/**
 * @brief Sets the item's name.
 * 
 * @param newName The new name to assign.
 */
void Item::setItemName(string newName)
{
	itemName = newName;
}

/**
 * @brief Returns the item's description.
 * 
 * @return The item's description as a string.
 */
string Item::getItemDescription()
{
	return itemDescription;
}

/**
 * @brief Sets the item's description.
 * 
 * @param newDescription The new description to assign.
 */
void Item::setItemDescription(string newDescription)
{
	itemDescription = newDescription;
}

bool Item::getItemIsVisible() const
{
	return itemIsVisible;
}

void Item::setItemIsVisible(bool visible)
{
	itemIsVisible = visible;
}

/**
 * @brief Prints the item's name and description.
 * 
 * @details Used to display the item's information.
 */
void Item::printItemInformation() const
{
	cout << itemName << ": " << itemDescription << endl;
}


bool Item::getIsQuestItem() const
{
	return isQuestItem;
}

void Item::setIsQuestItem(bool q)
{
	isQuestItem = q;
}
