#include "NPC.h"
#include "Room.h"

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
}
//Checks if the player is standing where the NPC is standing to confirm if they can interact with the NPC or not
bool NPC::player_Coord_Check(int x_coord, int y_coord) {
	return (x_coord == npc_xcoord && y_coord == npc_ycoord);
}
//The code for when player interacts
void NPC::interact() {
	cout << "[NPC Quick Backstory/Explain what they're doing]\n" << "Interact with NPC? (Y/N): " << endl;

	string response;
	cin >> response;

	//If responds with Y/y, give more details
	if (response == "Y" || response == "y") {
		cout << "[NPC Name]: Help me X_X\n" << endl;
		bool helpNPC = false;

		while (!helpNPC) //Loop to let player try again after incorrect input
		{
			//Dialogue couts and choices
			cout << "1) With what?\n2) No, goodbye!\n";
			int choice;
			cin >> choice;
			if (choice == 1) {
				cout << npcName << "Please find me a specific rock!\n";
				helpNPC = true;
			}
			else if (choice == 2) {
				cout << npcName << "Wow okay...\n";
				helpNPC = true;
			}
			else { //Invalid input catcher
				cout << "Not a correct input. Please enter Y/N." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}

	//If responds with N/n, cout an exit line
	else if (response == "N" || response == "n") {
		cout << "[NPC Name]: Wow okay...\n" << endl;
	}
	else {
		cout << "Not a correct input. Please enter Y/N." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}