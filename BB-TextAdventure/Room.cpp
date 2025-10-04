#include "Room.h"

#include <string>
using namespace std;

/*
* Class: Room
* --------------------------------------------
* Scope:
*   Represents one location in the text adventure.
*   Stores a room name, description, and a visited flag.
*   Will later connect to other rooms through exits.
*
* Current Implementation:
*   - Member variables declared for name, description, and visited state.
*   - Basic constructor placeholder.
*   - Getter and setter stubs for all member variables.
*   - enterRoom() placeholder for entry logic.
*
* To Do:
*   - Implement constructor to initialize name and description.
*   - Implement enterRoom() to print or return the room description.
*   - Complete getters/setters to return and modify private data members.
*   - Add exits once movement between rooms is ready.
*/

class Room
{
private:

	string roomName;
	string roomDescription;

	bool isVisited = false;

public:

	/*
	* Creates a room with a name and description
	*/
	Room(string newRoomName, string newRoomDescription) {}

	/*
	* TODO: Enter room
	*/
	void enterRoom()
	{

	}

	/*
	* Gets the name of the room
	*/
	string getRoomName()
	{
		//returns false until implemented
		return "false";
	}

	/*
	* Sets the name of the room
	*/
	void setRoomName(string newName)
	{

	}

	/*
	* Gets the name of the room
	*/
	string getRoomDescription()
	{
		//returns false until implemented
		return "false";
	}

	/*
	* Sets the name of the room
	*/
	void setRoomDesciption(string newDescription)
	{

	}

	/*
	* Checks if a room has been visited
	*/
	bool isVisited()
	{
		//returns false until implemented
		return false;
	}

	/*
	* Sets if a room has been visited
	*/
	void setVisited(bool visted)
	{

	}
};