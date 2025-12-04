// JungleNPC.h
#pragma once
#ifndef JUNGLE_NPC_H
#define JUNGLE_NPC_H

#include <iostream>
#include <string>
#include <map>
#include "Verb.h"
#include "Noun.h"
#include "QuestProgress.h"
#include "NPC.h"

class Zone;

using namespace std;

/**
 * @class JungleNPC
 * @brief NPC class for jungle zone hunt quest
 *
 * Requires player to kill specific enemy (Jungle Lurker) to complete
 * Tracks enemy kill status and provides quest progression
 */
class JungleNPC : public NPC
{
private:
    Zone* currentZone;
    bool enemyKilled;  // Tracks if quest enemy has been defeated

public:
    JungleNPC();
    JungleNPC(const string& npcName);

    // Quest tracking methods
    void setEnemyKilled(bool killed);
    bool isEnemyKilled() const;

    //Main interaction method
    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY) override;
    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug) override;
};

#endif
