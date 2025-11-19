#pragma once
#ifndef NPC_H
#define NPC_H

#include<iostream>
#include <string>
#include <map>
#include "Verb.h"
#include "Noun.h"
#include "QuestProgress.h"
//#include "Zone.h"
class Zone;
using namespace std;


//NPC class holding its name and coordinates

class NPC 
{
private:
    string npcName;
    bool questItemCollected;
    QuestProgress questProgress_;  // LV - already created, not used since all methods static - changing this behavior
    Zone* currentZone;
public:

    NPC();

    NPC(const string& npcName);

    QuestProgress getQuestObject();

    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY);
    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY, bool debug);  // support debug flag, false uses pauses, true - don't pause

    // LV - deleted deprecated methods



    /**void DisplayWithNPC(int npc_xcoord, int npc_ycoord) const;
     * @brief Sets Quest item as collected
    */
    bool setQuestItemCollected(bool collected);
    /**
     * @brief Gets Quest item as collected
     */
    bool getQuestItemCollected();

    void setZone(Zone* zone);
    Zone* getZone() const;

    string getName() const;

    void startedQuest();
    void completedQuest();
    void pickUpItemBeforeQuest();
    bool canCompleteQuest();
    bool isQuestStarted();
    bool isQuestComplete();
};


#endif
