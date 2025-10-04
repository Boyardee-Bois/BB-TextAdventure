#include "Room.h"

#include <iostream>
#include <string>
using namespace std;

/*
* Class: Room
* --------------------------------------------
* Scope:
*   Represents one location in the text adventure.
*   Stores a room name, description, and a visited flag.
*   Will later connect to other rooms through exits.
*/

/*
* Default constructor
*/
Room::Room(){}


/*
* Creates a room with a name and description
*/
Room::Room(string newRoomName, string newRoomDescription)
{
	roomName = newRoomName;
	roomDescription = newRoomDescription;
}

/*
* TODO: Enter room
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
}