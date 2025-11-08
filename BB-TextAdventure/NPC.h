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

class NPC 
{
private:
    string npcName;
    int npc_xcoord;
    int npc_ycoord;

public:

    NPC();

    NPC(string npcName, int x_coord, int y_coord);
    bool player_Coord_Check(int playerX, int playerY);
    void interact(Verb playerVerb, Noun playerNoun, int playerX, int playerY);

    /**
     * @brief Sets the NPC's position.
     * @param x The X coordinate.
     * @param y The Y coordinate.
     */
    void setNPC_Position(int npcX, int npcY);

    /**
     * @brief Gets the NPC's current X coordinate.
     * @return The X position as an integer.
     */
    int getNPC_X() const;

    /**
     * @brief Gets the NPC's current Y coordinate.
     * @return The Y position as an integer.
     */
    int getNPC_Y() const;
    /**
    * @brief Displays NPC on map
    */
    //void DisplayWithNPC(int npc_xcoord, int npc_ycoord) const;
};


#endif
