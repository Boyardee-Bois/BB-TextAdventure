/**
 * @file PlayerActionManager.h
 * 
 * @brief Declares the PlayerActionManager class, which executes player-driven commands and 
 * interacts with the game world.
 */
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

/**
 * @class PlayerActionManager
 * @brief Handles and executes player-related actions in the game.
 *
 * Acts as the bridge between parsed Command objects and game state updates.
 * Interprets player intent (movement, help, etc.) and applies effects to
 * relevant game objects such as the Player and Map.
 *
 * @details
 * Current functionality includes movement and help display. Future expansions
 * may include item handling, combat, and NPC interaction.
 *
 * @note This class executes actions but does not parse player input.
 */
class PlayerActionManager
{

public:

	/**
	 * @brief Executes a movement command.
	 *
	 * Validates and performs player movement based on the parsed command's direction noun.
	 * Updates player position and triggers map redraw.
	 *
	 * @param command Parsed command containing a direction (e.g., "north", "west").
	 * @param player Reference to the active Player object.
	 * @param world Reference to the current Map for rendering updates.
	 */
	void processGoCommand(Command command, Player& player, Map& world);

	/**
	 * @brief Displays all available commands and usage examples.
	 *
	 * Provides the player with a list of recognized verbs and basic usage patterns.
	 *
	 * @param parser Reference to the CommandParser for accessing valid verbs.
	 */
	void printHelp(CommandParser& parser);
};