#pragma once
#ifndef NPC_H
#define NPC_H

#include<iostream>
#include <string>
#include <map>
#include "Verb.h"
#include "Noun.h"
using namespace std;


//NPC class holding its name and coordinates

class NPC {
private:
    string npcName;
    int npc_xcoord;
    int npc_ycoord;
public:
    NPC(string npcName, int x_coord, int y_coord);
    bool player_Coord_Check(int x_coord, int y_coord);
    void interact(Verb playerVerb, Noun playerNoun, int playerX, int playerY);
};


#endif
