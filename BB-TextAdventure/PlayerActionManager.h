/**
 * @file PlayerActionManager.h
 * 
 * @brief Declares the PlayerActionManager class, which executes player-driven commands and 
 * interacts with the game world.
 */
#pragma once

#include "UI.h"
#include "Zone.h"
#include "Verb.h"
#include "Noun.h"
#include "NPC.h"
#include "Command.h"
#include "CommandParser.h"
#include "Player.h"
#include "Item.h"
#include <string>
#include <unordered_map>

class Player;

/**
 * @class PlayerActionManager
 * @brief Handles and executes player-related actions in the game.
 *
 * @details
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
	 * @details
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
	 * @details
	 * Provides the player with a list of recognized verbs and basic usage patterns.
	 *
	 * @param parser Reference to the CommandParser for accessing valid verbs.
	 */
	void printHelp(CommandParser& parser);

	/**
	 * @brief Executes a interact command.
	 *
	 * @details
	 * Validates and performs player interaction based on the parsed command.
	 * Interacts with an entity if one exists where the player is standing
	 *
	 * @param command Parsed command containing a interactable (ex., "NPC").
	 * @param player Reference to the active Player object.
	 * @param zone Reference to the current Zone for rendering updates.
	*/
	void processInteractCommand(Command command, Player& player, Zone& zone);

	/**
	 * @brief Executes a Pickup command.
	 *
	 * @details
	 * Validates and performs player pickup based on the parsed command.
	 * Pickup an item if one exists where the player is standing
	 *
	 * @param command Parsed command containing an item (ex., "NPC").
	 * @param player Reference to the active Player object.
	 * @param zone Reference to the current Zone for rendering updates.
	*/
	void processPickupCommand(Command command, Player& player, Zone& zone);

	/**
	 * @brief Opens the players inventory.
	 *
	 * @details
	 * Opens the players inventory and displays what the player has
	 * picked up from the world
	 *
	 * @param command Parsed command containing an open.
	 * @param player Reference to the active Player object.
	 */
	void processOpenCommand(Command command, Player& player);

	/**
	* @brief Asks the user if the want to quit
	* 
	* @details
	* This function handles a prompt confirming if the 
	* user would like to quit the game.  "Are you sure (y/n)"
	* @return True if the user confirms, otherwise false.
	*/
	bool processQuitCommand();
	void processAttackCommand(Command command, Player& player, Zone& zone);
};