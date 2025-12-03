/**
 * @file Item.h
 * @brief Defines the Item class used to represent objects in the game.
 *
 * @details
 * The Item class models individual objects that can exist within rooms or
 * be collected by the player. Each item has a name and description.
 */
#pragma once

#include <string>
using namespace std;

/**
 * @class Item
 * @brief Represents a single interactable or collectible object in the game.
 *
 * @details
 * Each Item contains a name and a description that describe what the item is
 * and how it can be interacted with. Items can be stored in rooms, inventories,
 * or used for interactions within gameplay logic.
 *
 * @note Extend this class as needed to support item types, stats, or effects.
 */
class Item
{
private:

	/** @brief The name of the item */
	string itemName;

	/** @brief The description details about the item. */
	string itemDescription;
	bool isQuestItem = false; 

	// If Item is visible to user or not
	bool itemIsVisible = false;

public:

	/** @brief Default constructor creating an empty item. */
	Item();

	/**
	 * @brief Constructs an item with a given name and description.
	 * @param newName The name of the item.
	 * @param newDescription A short description of the item.
	 */
	Item(string newName, string newDescription);


	string getItemName();

	/**
	 * @brief Sets the name of the item.
	 * @param newName The new name to assign to the item.
	 */
	void setItemName(string newName);

	/**
	 * @brief Retrieves the item's description.
	 * @return The item's description as a string.
	 */
	string getItemDescription();

	/**
	 * @brief Sets the description of the item.
	 * @param newDescription The new description to assign.
	 */
	void setItemDescription(string newDescription);

	// Gets and Sets item being visible or not as a bool
	bool getItemIsVisible() const;
	void setItemIsVisible(bool visible);

	/**
	 * @brief Prints the item's name and description to the console.
	 */
	void printItemInformation() const;

	bool getIsQuestItem() const; 
	void setIsQuestItem(bool q); 

};
