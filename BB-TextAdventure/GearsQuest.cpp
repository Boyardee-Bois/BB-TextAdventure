#include "GearsQuest.h"
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
 * Initializes quest with no current zone and all gears uncollected
 */
GearsQuest::GearsQuest()
{
    this->currentZone = nullptr;

    //Set all gears to not collected
    this->gear1Collected = false;
    this->gear2Collected = false;
    this->gear3Collected = false;
    this->gear4Collected = false;
    this->gear5Collected = false;
}

/**
 * @brief Constructor with NPC name derivation
 * Sets NPC name and initializes all gears as uncollected
 */
GearsQuest::GearsQuest(const string& npcName) : NPC(npcName)
{
    currentZone = nullptr;
    gear1Collected = false;
    gear2Collected = false;
    gear3Collected = false;
    gear4Collected = false;
    gear5Collected = false;
}

/**
 * @brief Check if all five gears have been collected
 * @return True if all gears are collected, false otherwise
 */
bool GearsQuest::allGearsCollected() const
{
    return gear1Collected && gear2Collected && gear3Collected && gear4Collected && gear5Collected;
}

/**
 * @brief Sets a specific gear as collected
 * @param collected = True if collected, false otherwise
 */
void GearsQuest::setGearCollected(int gearNumber, bool collected)
{
    if (NPC::isQuestStarted())
    {
        switch (gearNumber)
        {
        case 1:
            gear1Collected = collected;
            break;
        case 2:
            gear2Collected = collected;
            break;
        case 3:
            gear3Collected = collected;
            break;
        case 4:
            gear4Collected = collected;
            break;
        case 5:
            gear5Collected = collected;
            break;
        default:
            return;
        }
    }
}

/**
 * @brief Checks if a specific gear has been collected
 * @return True if collected, false if not
 */
bool GearsQuest::isGearCollected(int gearNumber) const
{
    switch (gearNumber)
    {
    case 1:
        return gear1Collected;
    case 2:
        return gear2Collected;
    case 3:
        return gear3Collected;
    case 4:
        return gear4Collected;
    case 5:
        return gear5Collected;
    default:
        return false;
    }
}

/**
 * @brief Returns the count of gears collected so far
 * @return Number of gears collected (0-5)
 */
int GearsQuest::getCollectedGearCount() const
{
    int count = 0;
    if (gear1Collected) {
        count++;
    }
    if (gear2Collected) {
        count++;
    }
    if (gear3Collected) {
        count++;
    }
    if (gear4Collected) {
        count++;
    }
    if (gear5Collected) {
        count++;
    }
    return count;
}

/**
 * @brief Normal interact method - calls debug version with false
 */
void GearsQuest::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY)
{
    interact(playerVerb, playerNoun, activeZone, playerX, playerY, false);
}

/**
 * @brief Main interaction method handling quest dialogue based on progress
 * @param Ignores UI pausing if we're using debug (For automatic testing basically)
 */
void GearsQuest::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug)
{
    // --- STEP 1: Quest not started ---
    if (!NPC::isQuestStarted())
    {
        cout << NPC::getName() << ": Hey..I am looking for some gears. Help me find them..." << endl;
        UI::Pause();
        cout << NPC::getName() << ": They should be around here somewhere...I NEED IT" << endl;
        NPC::startedQuest();
        UI::Pause();
        return;
    }

    // --- STEP 2: Quest started but not all gears collected ---
    if (NPC::isQuestStarted() && !allGearsCollected())
    {
        int collected = getCollectedGearCount();
        cout << NPC::getName() << ": Good. You got " << collected << " gears. Get to it again." << endl;
        UI::Pause();
        return;
    }

    // --- STEP 3: All gears collected but quest not yet completed ---
    if (NPC::isQuestStarted() && allGearsCollected() && !NPC::isQuestComplete())
    {
        cout << NPC::getName() << ": FINALLY, you got them all.\n" << NPC::getName() << ": Give them to-WHOA, I DON'T HAVE THE GEARS SO GET THEM NOT ME!" << endl;
        setQuestItemCollected(true);
        NPC::completedQuest();
        activeZone->spawnEnemy();
        UI::Pause();
        return;
    }

    // --- STEP 4: Quest already completed ---
    if (NPC::isQuestComplete())
    {
        int counter = 0;
        if (counter == 0) {
            cout << NPC::getName() << ": YOU! Get away from me! You're on your own with that THING!" << endl;
            UI::Pause();
        }
        else {
            cout << NPC::getName() << ": I'M TAKING THOSE GEARS AND LEAVING IF YOU DIE!" << endl;
            UI::Pause();
        }
        return;
    }
}
