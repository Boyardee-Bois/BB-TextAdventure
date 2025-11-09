#include "NPC.h"
#include "Player.h"
#include "Noun.h"
#include "Verb.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
* @breif The default constuctor for and NPC
*/
NPC::NPC(){}

//Create NPC name and coordinates
NPC::NPC(string npcNamE)
{
	//Assigns npcName to member variable
	this->npcName = npcName;

	// Initialize NPC coords 
	// DO NOT NEED THIS ANY MORE ZONE
	// PLACES NPC'S ON THE GRID
	//npc_xcoord = x_coord;
	//npc_ycoord = y_coord;
	
	//Player::playerX = playerX;
	//Player::playerY = playerY;
}

/**
* DEPRECATED ZONE SETS THE LOCATION OF THE NPC
* 
 * @brief Sets the NPC's position on the map.
 * @param x The new X coordinate.
 * @param y The new Y coordinate.
void NPC::setNPC_Position(int npcX, int npcY)
{
	npc_xcoord = npcX;
	npc_ycoord = npcY;
}
 */

/**
* DEPRECATED ZONE SETS THE LOCATION OF THE NPC
* 
* 
 * @brief Returns the NPC's current X coordinate.
 * @return The NPC’s X position.
int NPC::getNPC_X() const
{
	return npc_xcoord;
}
 */

/**
* DEPRECATED ZONE SETS THE LOCATION OF THE NPC
* 
* 
 * @brief Returns the NPC's current Y coordinate.
 * @return The NPC’s Y position.
int NPC::getNPC_Y() const
{
	return npc_ycoord;
}
 */

//Checks if the player is standing where the NPC is standing to confirm if they can interact with the NPC or not
/*
* 
* DEPRECATED ZONE SETS & CHECKS THE LOCATION OF THE NPC
* 
* 
bool NPC::player_Coord_Check(int playerX, int playerY) {
	return (playerX == npc_xcoord && playerY == npc_ycoord);
}
*/

//The code for when player interacts
void NPC::interact(Verb playerVerb, Noun playerNoun, int playerX, int playerY) {

	//Accepts enum parser "Interact NPC" only if Player and NPC same coords
	if (playerVerb == Verb::Interact && playerNoun == Noun::NPC) 
	{
		cout << npcName << ": Help me X_X\n" << endl;
		bool helpNPC = false;

		while (!helpNPC) //Loop to let player try again after incorrect input
		{
			//Dialogue couts and choices
			cout << "1) With what?\n2) No, goodbye!\n";

			int choice;
			cin >> choice;

			if (choice == 1) {
				cout << npcName << " Ooga Booga! (There's a shiny thing by the water!)\n";
				system("pause");
				helpNPC = true;
			}
			else if (choice == 2) {
				cout << npcName << " Wow okay...\n";
				helpNPC = true;
			}
			else 
			{ //Invalid input catcher
				cout << "Not a correct input. Please enter 1/2." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	else if (playerVerb == Verb::Interact && playerNoun == Noun::NPC) {
		cout << "You can't interact yet!\n";
	}
	
	else {
		cout << "Not a correct input. Please enter Y/N." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}