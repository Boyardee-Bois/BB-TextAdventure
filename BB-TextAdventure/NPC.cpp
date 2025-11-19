#include "NPC.h"
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
	// LV note: questProgress_ object created in the .h file when this object is created
}

QuestProgress NPC::getQuestObject() {
	return questProgress_;
}

/* deleted deprecated methods */

// Return true if the quest has started, so it is okay to pick up the item
//   false, otherwise

bool NPC::setQuestItemCollected(bool collected)
{
	if (questProgress_.isQuestStarted()) {
		questItemCollected = collected;   // LV - now redundant - can be replaced with the status in the questProgress
		questProgress_.setItemPickedUp(true);
		return(true);
	}
	else
		return(false);
}

bool NPC::getQuestItemCollected()
{
	return questProgress_.hasPickedUpItem();
}

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
void NPC::startedQuest()
{
	//  Use the new static global quest system
	questProgress_.startQuest("Find the Shiny Thing");
}

void NPC::completedQuest()
{
	questProgress_.completeQuest();
}

void NPC::pickUpItemBeforeQuest()
{
	// Optional — can print warning or perform pre-checks
	if (!questProgress_.isQuestStarted())
	{
		std::cout << "This item can't be picked up yet! Talk to the NPC first!\n";
	}
}

bool NPC::canCompleteQuest()
{
	// Quest can be completed if it's started, item picked up, and not completed yet
	return questProgress_.isQuestStarted() && questProgress_.hasPickedUpItem() && !questProgress_.isQuestCompleted();
}

bool NPC::isQuestStarted()
{
	return questProgress_.isQuestStarted();
}

bool NPC::isQuestComplete()
{
	return questProgress_.isQuestCompleted();
}

void NPC::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY)
{
	interact(playerVerb, playerNoun, activeZone, playerX, playerY, false);
}

void NPC::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug)
{
	// --- STEP 1: Quest not started ---
	if (!isQuestStarted())
	{
		cout << " Hey there! Could you find the shiny thing by the water?" << endl;
		questProgress_.startQuest("Find the Shiny Thing");
		if (!debug) UI::Pause();   // if in debug mode - don't pause - hangs the test harness
		return;
	}

	// --- STEP 2: Quest started but item not yet picked up ---
	if (questProgress_.isQuestStarted() && !questProgress_.hasPickedUpItem())
	{
		cout << " WHERE?!? It's by the water — keep looking!" << endl;
		if (!debug) UI::Pause();
		return;
	}

	// --- STEP 3: Item picked up but quest not yet completed ---
	if (questProgress_.isQuestStarted() && questProgress_.hasPickedUpItem() && !questProgress_.isQuestCompleted())
	{
		cout << " You found it?! Amazing work!" << endl;
		questProgress_.completeQuest();  // marks quest complete + unlocks enemy
		activeZone->spawnEnemy();        // now reactivates or shows the enemy
		if (!debug) UI::Pause();
		return;
	}

	// --- STEP 4: Quest already completed ---
	if (questProgress_.isQuestCompleted())
	{
		cout << " You’ve already helped me, hero. Be careful... something’s out there now." << endl;
		if (!debug) UI::Pause();
		return;
	}
}
