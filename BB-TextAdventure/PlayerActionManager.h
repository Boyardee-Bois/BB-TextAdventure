#pragma once

#include "Verb.h"
#include "Noun.h"
#include "Room.h"
#include "Map.h"
#include "Command.h"
#include "CommandParser.h"
#include "Player.h"
#include <string>
#include <unordered_map>

class Player;

/*
* Scope: PlayerActionManager
* 
*/

class PlayerActionManager
{

public:

	void processGoCommand(Command command, Player& player, Map& world);

	void printHelp(CommandParser& parser);
};