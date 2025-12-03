#pragma once
#ifndef GEARSQUEST_H
#define GEARSQUEST_H

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
 * @class GearsQuest
 * @brief NPC class for a quest that requires collecting 5 Gears in the lab basement zone
 *
 * Deals with multiple gear items for players to find and pick up in the lab basement zone
 * Return to the NPC once all 5 gears are collected, finishing the quest
 */
class GearsQuest : public NPC
{
private:
    Zone* currentZone;

    bool gear1Collected = false;
    bool gear2Collected = false;
    bool gear3Collected = false;
    bool gear4Collected = false;
    bool gear5Collected = false;

    // Checks if all gears are collected
    bool allGearsCollected() const;

public:
    GearsQuest();
    GearsQuest(const string& npcName);

    //Main NPC interaction method
    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY) override;
    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug) override;

    //Methods for tracking each individual gears
    void setGearCollected(int gearNumber, bool collected);
    bool isGearCollected(int gearNumber) const;
    int getCollectedGearCount() const;
};

#endif
