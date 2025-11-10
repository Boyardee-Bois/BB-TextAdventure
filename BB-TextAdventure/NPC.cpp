#include "NPC.h"
#include "Room.h"
#include "Player.h"
#include "QuestProgress.h"
#include "Zone.h"
#include "Noun.h"
#include "Verb.h"
#include "UI.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
* @breif The default constuctor for and NPC
*/
NPC::NPC() {}

//Create NPC name and coordinates
NPC::NPC(const string& npcName) {
	this->npcName = npcName;
	this->questItemCollected = false;
	this->currentZone = nullptr;
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

void NPC::setQuestItemCollected(bool collected)
{
	questItemCollected = collected;
}

bool NPC::getQuestItemCollected() const
{
	return questItemCollected;
}

//Checks if the player is standing where the NPC is standing to confirm if they can interact with the NPC or not
/*
*
* DEPRECATED ZONE SETS & CHECKS THE LOCATION OF THE NPC
*

bool NPC::player_Coord_Check(int playerX, int playerY) {
	return (playerX == npc_xcoord && playerY == npc_ycoord);
}
*/
void NPC::setZone(Zone* zone) {
	currentZone = zone;
}

Zone* NPC::getZone() const {
	return currentZone;
}

string NPC::getName() const {
	return npcName;
}

// Quest progress methods (delegate directly to the local QuestProgress object)
void NPC::startedQuest() {
	questProgress.startedQuest();
}

void NPC::completedQuest() {
	questProgress.completedQuest();
}

void NPC::pickUpItemBeforeQuest() {
	questProgress.pickUpItemBeforeQuest();
}

bool NPC::canCompleteQuest() const {
	return questProgress.canCompleteQuest();
}

bool NPC::isQuestStarted() const {
	return questProgress.isQuestStarted();
}

bool NPC::isQuestComplete() const {
	return questProgress.isQuestCompleted();
}

void NPC::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY) {
	if (!(playerVerb == Verb::Interact && playerNoun == Noun::NPC)) {
		cout << "Try again.\n";
		UI::Pause();
		return;
	}
	//Tells user they need to be closer to NPC to interact
	NPC* startingAreaNPC = activeZone->getNpcsAt(playerX, playerY);
	if (!startingAreaNPC) {
		cout << "oog wha- (Hey, I can't hear you! Come closer!\n";
		UI::Pause();
		return;
	}
	//Prevents user from picking up an item to early
	if (startingAreaNPC->getQuestItemCollected() && !startingAreaNPC->isQuestStarted()) {
		cout << startingAreaNPC->getName() << "Start a quest before picking up this item!\n";
		UI::Pause();
		return;
	}

	if (!startingAreaNPC->isQuestStarted()) {
		cout << npcName << ": Ooga Booga! (There's a shiny thing by the water!)\n";
		startingAreaNPC->startedQuest();
		UI::Pause();
		return;
	}

	if (startingAreaNPC->isQuestStarted() && !startingAreaNPC->canCompleteQuest()) {
		cout << npcName << ": FIND?!?\n";
		UI::Pause();
		return;
	}

	if (startingAreaNPC->canCompleteQuest()) {
		if (!startingAreaNPC->getQuestItemCollected()) {
			cout << npcName << ": WHERE?!?\n";
			UI::Pause();
			return;
		}
		cout << npcName << ": yes.\n";
		startingAreaNPC->completedQuest();
		UI::Pause();
		return;
	}

	if (startingAreaNPC->isQuestComplete()) {
		cout << npcName << ": yes!?\n";
		UI::Pause();
		return;
	}
	/*
		if (firstQuest->isQuestStarted())
		{
			firstQuest->pickUpItemBeforeQuest();
		}
		else
		{
			beachNPC.setQuestItemCollected(false);
			system("pause");
		}
	}
	*/
	/*
	//Accepts enum parser "Interact NPC" only if Player and NPC same coords
	if (playerVerb == Verb::Interact && playerNoun == Noun::NPC) {

		if (questItemCollected)
		{
			cout << npcName << ": yes.\nQuest Completed!\n";
			system("pause");
			return;
		}

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
	*/
}