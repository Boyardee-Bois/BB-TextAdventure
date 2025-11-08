/**
 * @file PlayerActionManager.h
 * 
 * @brief Declares the PlayerActionManager class, which executes player-driven commands and 
 * interacts with the game world.
 */
#pragma once

#include "Zone.h"
#include "Verb.h"
#include "Noun.h"
#include "NPC.h"
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
	 * @param zone Reference to the current Map for rendering updates.
	 */
	void processGoCommand(Command command, Player& player, Zone& zone);

	/**
	 * @brief Displays all available commands and usage examples.
	 *
	 * Provides the player with a list of recognized verbs and basic usage patterns.
	 *
	 * @param parser Reference to the CommandParser for accessing valid verbs.
	 */
	void printHelp(CommandParser& parser);

	/**
	 * @brief Executes a interact command.
	 *
	 * Validates and performs player interaction based on the parsed command.
	 * Interacts with an entity if one exists where the player is standing
	 *
	 * @param command Parsed command containing a direction (ex., "NPC").
	 * @param player Reference to the active Player object.
	 * @param zone Reference to the current Zone for rendering updates.
	*/
	void processInteractCommand(Command command, Player& player, Zone& zone);
};