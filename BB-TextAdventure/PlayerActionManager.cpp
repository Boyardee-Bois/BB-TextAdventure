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

/**
* @brief Executes a interact command.
*
* Validates and performs player interaction based on the parsed command.
* Interacts with an entity if one exists where the player is standing
 *
* @param command Parsed command containing a direction (ex., "NPC").
* @param player Reference to the active Player object.
* @param zone Reference to the current Zone for rendering updates.
* @note If there is nothing to interact with a message will be displayed
* that there are no interactables.
*/
void processInteractCommand(Command command, Player& player, Zone& zone)
{
	// Get the players position
	int playerX = player.getX();
	int playerY = player.getY();

	// Check what the player wants to interact with
	Noun targetNoun = command.getNoun();

	if (targetNoun == Noun::NPC || targetNoun == Noun::Unknown)
	{
		// Check if there is a NPC at the players location
		NPC* npc = zone.getNpcsAt(playerX, playerY);

		// If the NPC exists... Interact with them
		if (npc != nullptr)
		{
			npc->interact(Verb::Interact, Noun::NPC, playerX, playerY);
		}
		else
		{
			cout << "There is no one here to interact with!" << endl;
			UI::Pause();
		}
	}
	else
	{
		cout << "You can not interact with that." << endl;
		UI::Pause();
	}
}