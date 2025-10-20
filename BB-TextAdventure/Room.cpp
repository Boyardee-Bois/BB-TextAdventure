#include "Room.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
* Class: Room
* --------------------------------------------
* Represents a single location in the text adventure game.
* Each Room has:
*    A name (roomName)
*    A description (roomDescription)
*    A visited flag (isVisited)
*    A collection of exits (connections to other rooms)
*/

/*
* Default constructor
*/
Room::Room() { isVisited = false; }


/*
* Creates a room with a name and description
*/
Room::Room(string newRoomName, string newRoomDescription)
{
	roomName = newRoomName;
	roomDescription = newRoomDescription;
	isVisited = false;
}

/*
* Placeholder for logic when the player enters this room.
* This function will later be expanded to handle interactions,
* events, or special messages upon entering.
*/
void Room::enterRoom()
{
	/*
	* Need to implement
	*/
}

/*
* Gets the name of the room
*/
string Room::getRoomName()
{
	return roomName;
}

/*
* Sets the name of the room
*/
void Room::setRoomName(string newName)
{
	roomName = newName;
}

/*
* Gets the name of the room
*/
string Room::getRoomDescription()
{
	return roomDescription;
}

/*
* Sets the name of the room
*/
void Room::setRoomDescription(string newDescription)
{
	roomDescription = newDescription;
}

/*
* Checks if a room has been visited
*/
bool Room::getIsVisited()
{
	return isVisited;
}

/*
* Sets if a room has been visited
*/
void Room::setVisited(bool visited)
{
	isVisited = visited;
}

/*
* Prints the name and description of a room
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

/*
* Adds an exit to this room.
* Each exit connects a direction (string) to another room (Room*).
* 
* Updates for duplicate exits
*/
void Room::addExit(const string& direction, Room* neighbor)
{
	exits[direction] = neighbor;
}

/*
* Gets the exit (Room*) for a specific direction.
* If no exit is found, prints an error message and returns nullptr.
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