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
    QuestProgress questProgress;
    Zone* currentZone;
public:

    NPC();

    NPC(const string& npcName);

    void interact(Verb playerVerb, Noun playerNoun, Zone* activeZone, int playerX, int playerY);

    /**
    * 
    * DEPRECATED ZONE SETS THE LOCATION OF THE NPC 
    *
    *
    void setNPC_Position(int npcX, int npcY);

    /**
     * 
     * DEPRECATED ZONE SETS THE LOCATION OF THE NPC
* 
     *
    int getNPC_X() const;

    /**
     * 
     DEPRECATED ZONE SETS THE LOCATION OF THE NPC
     *
    int getNPC_Y() const;
    /**
    * DEPRECATED ZONE CHECKS THE LOCATION OF THE NPC
    * 
    bool player_Coord_Check(int playerX, int playerY);
    */



    /*void DisplayWithNPC(int npc_xcoord, int npc_ycoord) const;
     * @brief Sets Quest item as collected
     */
    void setQuestItemCollected(bool collected);
    /**
     * @brief Gets Quest item as collected
     */
    bool getQuestItemCollected() const;

    void setZone(Zone* zone);
    Zone* getZone() const;

    string getName() const;

    void startedQuest();
    void completedQuest();
    void pickUpItemBeforeQuest();
    bool canCompleteQuest() const;
    bool isQuestStarted() const;
    bool isQuestComplete() const;

};


#endif
