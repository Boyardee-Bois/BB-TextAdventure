/**
 * @file Room.cpp
 * @brief Implements the Room class used to represent locations in the game world.
 *
 * @details
 * Each Room represents a single location in the game.
 * Rooms contain a name, a description, a visited flag, and exits that
 * connect to neighboring rooms. The class provides basic accessors,
 * mutators, and utility methods to display information and manage exits.
 */
#include "Room.h"
#include "Room.h"   
#include "Item.h"   
#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * @brief Default constructor.
 * @details Initializes an empty room marked as not visited.
 */
Room::Room() { isVisited = false; }


/**
 * @brief Constructs a Room with a specified name and description.
 * @param newRoomName The name of the room.
 * @param newRoomDescription The description of the room.
 */
Room::Room(string newRoomName, string newRoomDescription)
{
	roomName = newRoomName;
	roomDescription = newRoomDescription;
	isVisited = false;
}

/**
 * @brief Called when the player enters the room.
 * @details Placeholder for future logic such as events, messages, or interactions.
 */
void Room::enterRoom()
{
	/*
	* Need to implement
	*/
}

/**
 * @brief Gets the room's name.
 * @return The name of the room as a string.
 */
string Room::getRoomName()
{
	return roomName;
}

/**
 * @brief Sets the room's name.
 * @param newName The new name for the room.
 */
void Room::setRoomName(string newName)
{
	roomName = newName;
}

/**
 * @brief Gets the room's description.
 * @return The description of the room as a string.
 */
string Room::getRoomDescription()
{
	return roomDescription;
}

/**
 * @brief Sets the room's description.
 * @param newDescription The new description for the room.
 */
void Room::setRoomDescription(string newDescription)
{
	roomDescription = newDescription;
}

/**
 * @brief Checks whether the room has been visited.
 * @return True if the room has been visited; otherwise false.
 */
bool Room::getIsVisited() const
{
	return isVisited;
}

/**
 * @brief Sets the visited state of the room.
 * @param visited True if the room has been visited; otherwise false.
 */
void Room::setVisited(bool visited)
{
	isVisited = visited;
}

/**
 * @brief Prints the room's name, description, and available exits.
 * @details If the room has no exits, an appropriate message is shown.
 */
void Room::printRoomInformation()
{
	cout << roomName << ": " << roomDescription << endl;

	if (exits.empty())
	{
		cout << "There are no exits from here." << endl;
		return;
	}

	cout << "Exits: ";

	for (const auto& exitPair : exits)
	{
		cout << exitPair.first << " ";
	}

	cout << endl;
}

/**
 * @brief Adds an exit to this room.
 * @param direction The direction of the exit.
 * @param neighbor A pointer to the neighboring Room.
 */
void Room::addExit(const string& direction, Room* neighbor)
{
	exits[direction] = neighbor;
}

/**
 * @brief Retrieves the neighboring room in a given direction.
 * @param direction The direction to check.
 * @return A pointer to the connected Room, or nullptr if no exit exists.
 * @details Prints a message if the direction is invalid.
 */
Room* Room::getExit(const string& direction)
{
	auto iterator = exits.find(direction);

	if (iterator == exits.end())
	{
		cout << "You can't go " << direction << " from here!" << endl;
		return nullptr;
	}

	return iterator->second;
}

void Room::setNPC(NPC* npc)
{
  //Placeholder
}

NPC* Room::getNPC() const
{
	return nullptr;
}

Item* Room::getItem()
{
	return roomItem;
}

void Room::setItem(Item* i)
{
	roomItem = i;
}

void Room::removeItem()
{
	roomItem = nullptr;
}

bool Room::hasItem() const
{
	return roomItem != nullptr;
}
