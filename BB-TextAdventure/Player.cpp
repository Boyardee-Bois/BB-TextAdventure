#include "Player.h"
#include "Room.h"

#include <iostream>
#include <limits>
#include <cstdio>
#include <string>
using namespace std;


// Contructor: Start the player in "NULL" room
Player::Player()
{
	currentRoom = NULL;
	playerX = 0; 
	playerY = 0; 
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

void Player::setPosition(int x, int y)
{
	playerX = x; 
	playerY = y; 
}

int Player::getX() const
{
	return playerX;
}

int Player::getY() const
{
	return playerY;
}
void Player::movePlayer(char direction)
{
    switch (direction)
    {
    case 'w': // up / north
        playerY--;
        break;
    case 's': // down / south
        playerY++;
        break;
    case 'a': // left / west
        playerX--;
        break;
    case 'd': // right / east
        playerX++;
        break;
    }

    // Keep player inside map boundaries (25x25 for example)
    if (playerX < 0) playerX = 0;
    if (playerY < 0) playerY = 0;
    if (playerX >= 25) playerX = 24;
    if (playerY >= 25) playerY = 24;
}

void Player::ItemPickUp(Item* item)
{
    if (item == nullptr) return;

    // prevent duplicates by name
    for (auto* it : inventory) {
        if (it && it->getItemName() == item->getItemName()) {
            std::cout << "You already have " << item->getItemName() << ".\n";
            return;
        }
    }

    inventory.push_back(item);
    std::cout << "You picked up " << item->getItemName() << ".\n";
}

void Player::displayInventory()
{
    if (inventory.empty()) {
        std::cout << "[Inventory] (empty)\n";
        return;
    }
    std::cout << "[Inventory]\n";
    for (auto* it : inventory) {
        if (it) std::cout << " - " << it->getItemName()
            << (it->getIsQuestItem() ? " (Quest Item)" : "")
            << "\n";
    }
}

bool Player::hasItemName(const string& n) const
{
    for (auto* it : inventory) {
        if (it && it->getItemName() == n) return true;
    }
    return false;
}

