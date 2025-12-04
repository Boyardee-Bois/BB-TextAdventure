#include "TimeMachineLiquidQuest.h"
#include "Player.h"
#include "NPC.h"
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
 * @brief Default constructor
 */
TimeMachineLiquidQuest::TimeMachineLiquidQuest()
{
    this->currentZone = nullptr;

    //Set all vials to not collected
    this->vial1Collected = false;
    this->vial2Collected = false;
    this->vial3Collected = false;
}

/**
 * @brief Constructor with NPC name derivation
 */
TimeMachineLiquidQuest::TimeMachineLiquidQuest(const string& npcName) : NPC(npcName)
{
    currentZone = nullptr;
    vial1Collected = false;
    vial2Collected = false;
    vial3Collected = false;
}

/**
 * Check if all three vials have been collected
 * @return True if all vials are collected, false otherwise
 */
bool TimeMachineLiquidQuest::allVialsCollected() const
{
    return vial1Collected && vial2Collected && vial3Collected;
}

/**
 * Sets a specific vial as collected
 * @param collected = True if collected, false otherwise
 */
void TimeMachineLiquidQuest::setVialCollected(int vialNumber, bool collected)
{
    if (NPC::isQuestStarted())
    {
        switch (vialNumber)
        {
        case 1:
            vial1Collected = collected;
            break;
        case 2:
            vial2Collected = collected;
            break;
        case 3:
            vial3Collected = collected;
            break;
        default:
            return;
        }
    }
}

/**
 * Checks if a specific one has been collected
 * @return True if collected, false if not
 */
bool TimeMachineLiquidQuest::isVialCollected(int vialNumber) const
{
    switch (vialNumber)
    {
    case 1:
        return vial1Collected;
    case 2:
        return vial2Collected;
    case 3:
        return vial3Collected;
    default:
        return false;
    }
}

/**
 * Returns the count of vials collected so far
 * @return Number of vials collected (0-3)
 */
int TimeMachineLiquidQuest::getCollectedVialCount() const
{
    int count = 0;
    if (vial1Collected) {
        count++;
    }
    if (vial2Collected) {
        count++;
    }
    if (vial3Collected) {
        count++;
    }
    return count;
}

/**
 * @brief Normal interact method
 */
void TimeMachineLiquidQuest::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY)
{
    interact(playerVerb, playerNoun, activeZone, playerX, playerY, false);
}

/**
 * @brief Main interaction method handling quest dialogue based on progress
 * @param Ignores UI pausing if we're using debug (For automatic testing basically)
 */
void TimeMachineLiquidQuest::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug)
{

    // --- STEP 1: Quest not started ---
    if (!NPC::isQuestStarted())
    {
        cout << NPC::getName() << ": You looking for something?" << endl;
        if (!debug) {
            UI::Pause();
        }
        cout << NPC::getName() << ": Uh, yeah...I think I saw something like that over there..." << endl;
        NPC::startedQuest();
        if (!debug) {
            UI::Pause();
        }
        return;
    }

    // --- STEP 2: Quest started but not all vials collected ---
    if (NPC::isQuestStarted() && !allVialsCollected())
    {
        int collected = getCollectedVialCount();
        cout << NPC::getName() << ": Whoa! You got " << collected << " vials. There should be more out there!" << endl;

        if (!debug) {
            UI::Pause();
        }
        return;
    }

    // --- STEP 3: All vials collected but quest not yet completed ---
    if (NPC::isQuestStarted() && allVialsCollected() && !NPC::isQuestComplete())
    {
        cout << NPC::getName() << ": Whoa, you got them all!\n" << NPC::getName() << ": An enemy appeared and it looks like it's holding something! If you kill it, maybe they'll drop it and you can pick it up!" << endl;
        setQuestItemCollected(true);
        activeZone->spawnEnemy();
        NPC::completedQuest();
        if (!debug) {
            UI::Pause();
        }
        return;
    }

    // --- STEP 4: Quest already completed ---
    if (NPC::isQuestComplete())
    {
        cout << NPC::getName() << ": Good job O_O" << endl;
        if (!debug) {
            UI::Pause();
        }
        return;
    }
}
