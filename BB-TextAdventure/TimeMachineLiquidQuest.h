#pragma once
#ifndef TIMEMACHINELIQUIDQUEST_H
#define TIMEMACHINELIQUIDQUEST_H

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
 * @class TimeMachineLiquidQuest
 * @brief NPC class for a quest that requires collecting 3 Liquid Vials in the beach zone
 *
 * Deals with multiple items for player to find and pick up in the beach zone
 * Return the NPC once all of them are collecting, finishing the quest O_O
 */
class TimeMachineLiquidQuest : public NPC
{
private:
    //string npcName;
    //QuestProgress questProgress_;  // Tracks overall quest state
    Zone* currentZone;

    bool vial1Collected = false;
    bool vial2Collected = false;
    bool vial3Collected = false;

    // Method to check if all vials are collected
    bool allVialsCollected() const;

public:
    TimeMachineLiquidQuest();
    TimeMachineLiquidQuest(const string& npcName);

    //Main interaction method
    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY) override;
    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug) override;

    //Methods for tracking individual vials
    void setVialCollected(int vialNumber, bool collected);
    bool isVialCollected(int vialNumber) const;
    int getCollectedVialCount() const;  //Amount of vials collected tracker
};

#endif
