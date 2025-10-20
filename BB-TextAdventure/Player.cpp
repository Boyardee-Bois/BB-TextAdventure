#include "Player.h"

using namespace std;

// Contructor: Start the player in "NULL" room
Player::Player()
{
	currentRoom = NULL;
}

// Set the players current room
void Player::setCurrentRoom(Room* newRoom)
{
	currentRoom = newRoom;
}

// Get the players current room
Room* Player::getCurrentRoom()
{
	return currentRoom;
}
