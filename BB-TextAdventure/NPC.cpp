#include "NPC.h"
#include "Room.h"
#include "Player.h"
#include "Noun.h"
#include "Verb.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
//Create NPC name and coordinates
NPC::NPC(string npcName, int x_coord, int y_coord)
{
	//Assigns npcName to member variable
	this->npcName = npcName;

	// Initialize NPC coords
	npc_xcoord = x_coord;
	npc_ycoord = y_coord;
	
	//Player::playerX = player_xcoord;
	//Player::playerY = player_ycoord;
}
/*
int NPC::getY() const
{
	return npc_xcoord;
}
*/
//Checks if the player is standing where the NPC is standing to confirm if they can interact with the NPC or not
bool NPC::player_Coord_Check(int x_coord, int y_coord) {
	return (x_coord == npc_xcoord && y_coord == npc_ycoord);
}
//The code for when player interacts
void NPC::interact(Verb playerVerb, Noun playerNoun, int playerX, int playerY) {

	//Accepts enum parser "Interact NPC" only if Player and NPC same coords
	if (playerVerb == Verb::Interact && playerNoun == Noun::NPC && player_Coord_Check(playerX, playerY)) {
		cout << npcName << ": Help me X_X\n" << endl;
		bool helpNPC = false;

		while (!helpNPC) //Loop to let player try again after incorrect input
		{
			//Dialogue couts and choices
			cout << "1) With what?\n2) No, goodbye!\n";

			int choice;
			cin >> choice;

			if (choice == 1) {
				cout << npcName << " Please find me a specific rock!\n";
				helpNPC = true;
			}

			else if (choice == 2) {
				cout << npcName << " Wow okay...\n";
				helpNPC = true;
			}

			else { //Invalid input catcher
				cout << "Not a correct input. Please enter 1/2." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	else if (playerVerb == Verb::Interact && playerNoun == Noun::NPC) {
		cout << "You can't interact yet! Move closer.\n";
	}
	
	else {
		cout << "Not a correct input. Please enter Y/N." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}