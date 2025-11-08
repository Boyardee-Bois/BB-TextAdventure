/**
 * @file PlayerActionManager.cpp
 * 
 * @brief Routes parsed player commands to in-game actions (movement, help).
 * 
 * @details
 *  Acts as a layer between parsed input (Command) and game state
 *  (Player, Map). Validates intent, triggers Player updates, and refreshes the Map.
 */
#include "PlayerActionManager.h"

 /**
  * @brief Execute a movement command (e.g., "go north", "go w").
  *
  * Maps the command's noun to a movement direction and corresponding key,
  * updates the player's position, and redraws the map.
  *
  * @param command Parsed player command.
  * @param player Reference to the player.
  * @param world  Reference to the map for re-rendering after movement.
  *
  * @note If the command has no direction (e.g just "go"), prints a prompt and returns.
  */
void PlayerActionManager::processGoCommand(Command command, Player& player, Zone& world)
{
	if (!command.hasDirection())
	{
		cout << "Go where? (Example: 'go north')" << endl;
		return;
	}

	string direction;
	char moveChar = 0; // for controlling player movement

	switch (command.getNoun())
	{
	case Noun::North:
		direction = "north";
		moveChar = 'w';
		break;
	case Noun::South:
		direction = "south";
		moveChar = 's';
		break;
	case Noun::East:
		direction = "east";
		moveChar = 'd';
		break;
	case Noun::West:
		direction = "west";
		moveChar = 'a';
		break;
	case Noun::W:
		direction = "north";
		moveChar = 'w';
		break;
	case Noun::S:
		direction = "south";
		moveChar = 's';
		break;
	case Noun::D:  
		 direction = "east"; 
		 moveChar = 'd'; 
		 break;
	case Noun::A:
		direction = "west";
		moveChar = 'a';
		break;
	default:
		break;
	}

	/*
	*  TODO: Add collision detection
	* 
	*  int newX = player.getX()
	*  int newY = player.getY()
	* 
	*  calculate new X & Y
	* 
	* if (zone.getTileAt(newX, newY).isWalkable())
	*	 player.movePlayer(moveChar)
	* 
	*/

	player.movePlayer(moveChar); // This is temporary need to implement collision check for type of tile
}


/**
 * @brief Print available command words and basic help.
 *
 * @param parser Reference to the command parser displaying known verbs.
 */
void PlayerActionManager::printHelp(CommandParser& parser)
{
	cout << "Your available command words are:" << endl;
	parser.showAllVerbs();
	cout << "Example: 'go north' or 'quit'" << endl;
}