#pragma once
#ifndef NPC_H
#define NPC_H

#include<iostream>
#include <string>
#include <map>
#include "Room.h"
using namespace std;

//string npcName;

//NPC class holding its name and coordinates

class NPC {	

public:
	int npc_xcoord, npc_ycoord;
	NPC(string npcName, int x_coord, int y_coord);
	//Checks if Player is same coordinates as NPC
	bool player_Coord_Check(int x_coord, int y_coord);
	void interact();
};

#endif