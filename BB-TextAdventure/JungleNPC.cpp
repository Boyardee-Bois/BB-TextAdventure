// JungleNPC.cpp
#include "JungleNPC.h"
#include "Player.h"
#include "NPC.h"
#include "QuestProgress.h"
#include "Enemy.h"
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
 * Initializes NPC with no current zone and enemy not killed
 */
JungleNPC::JungleNPC()
{
    this->currentZone = nullptr;
    enemyKilled = false;
}

/**
 * @brief Constructor with NPC name derivation
 * Sets NPC name and initializes quest state
 */
JungleNPC::JungleNPC(const string& npcName) : NPC(npcName)
{
    currentZone = nullptr;
    enemyKilled = false;
}

/**
 * @brief Checks if the quest enemy has been killed
 * @return True if enemy killed, false otherwise
 */
bool JungleNPC::isEnemyKilled() const
{
    return enemyKilled;
}

/**
 * @brief Sets enemy killed status
 * @param killed True if enemy defeated, false otherwise
 */
void JungleNPC::setEnemyKilled(bool killed)
{
    enemyKilled = killed;
}

/**
 * @brief Normal interact method
 * Calls debug version with false parameter
 */
void JungleNPC::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY)
{
    interact(playerVerb, playerNoun, activeZone, playerX, playerY, false);
}

/**
 * @brief Main interaction method handling jungle hunt quest
 * @param Ignores UI pausing if we're using debug (For automatic testing)
 */
void JungleNPC::interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug)
{
    // --- STEP 1: Quest not started ---
    if (!NPC::isQuestStarted())
    {
        cout << NPC::getName() << ": Welcome to the jungle, stranger!" << endl;
        UI::Pause();
        cout << NPC::getName() << ": I was going to hunt these monsters, but I forgot my tools!" << endl;
        UI::Pause();
        cout << NPC::getName() << ": Can you hunt the Jungle Lurker for me? You may get a prize!" << endl;
        NPC::startedQuest();
        UI::Pause();
        return;
    }

    // --- STEP 2: Quest started but enemy not killed ---
    if (NPC::isQuestStarted() && !isEnemyKilled())
    {
        cout << NPC::getName() << ": Hey! An alive jungle lurker means no prize from me!" << endl;
        UI::Pause();
        return;
    }

    // --- STEP 3: Enemy killed but quest not completed ---
    if (NPC::isQuestStarted() && isEnemyKilled() && !NPC::isQuestComplete())
    {
        cout << NPC::getName() << ": You killed the Jungle Lurker! YESSSSSSSSSSSSSSSSSSSSSS!" << endl;
        UI::Pause();
        cout << NPC::getName() << ": Here's your reward-!" << endl;
        UI::Pause();
        cout << NPC::getName() << ": A 'Good Job' from me!" << endl;
        setQuestItemCollected(true);
        NPC::completedQuest();
        UI::Pause();
        return;
    }

    // --- STEP 4: Quest completed ---
    if (NPC::isQuestComplete())
    {
        cout << NPC::getName() << ": What did you think of my prize?!?" << endl;
        UI::Pause();
        return;
    }
}