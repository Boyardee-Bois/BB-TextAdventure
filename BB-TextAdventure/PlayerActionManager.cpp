/**
 * @file PlayerActionManager.cpp
 *
 * @brief Routes parsed player commands to in-game actions.
 *
 * @details
 *  Acts as a layer between parsed input (Command) and game state
 *  (Player, Map). Validates intent, triggers Player updates, and refreshes the Map.
 * 1. Movement
 * 2. Interaction
 * 3. Pick up
 * 4. Attack
 * 5. Inventory
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
void PlayerActionManager::processInteractCommand(Command command, Player& player, Zone& zone)
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
			npc->interact(Verb::Interact, Noun::NPC, &zone, playerX, playerY);
		}
		else
		{
			cout << "There is no one here to interact with!\n";
			UI::Pause();
		}
	}
	else
	{
		cout << "You can not interact with that.\n";
		UI::Pause();
	}
}

/**
* @brief Executes a Pickup command.
*
* Validates and performs player pickup based on the parsed command.
* Pickup an item if one exists where the player is standing
*
* @param command Parsed command containing an item (ex., "NPC").
* @param player Reference to the active Player object.
* @param zone Reference to the current Zone for rendering updates.
*/
void PlayerActionManager::processPickupCommand(Command command, Player& player, Zone& zone)
{
	int playerX = player.getX();
	int playerY = player.getY();

	//  Check if there's an item at current tile
	Item* itemToPickup = zone.getItemsAt(playerX, playerY);
	if (itemToPickup == nullptr)
	{
		cout << "There is nothing to pick up here!\n";
		UI::Pause();
		return;
	}

	//  Prevent picking up item before talking to NPC
	if (!QuestProgress::isQuestStarted())
	{
		cout << "You can’t pick this up yet! Try talking to the NPC first!\n";
		UI::Pause();
		return;
	}

	//  Prevent double pickup
	if (QuestProgress::hasPickedUpItem())
	{
		cout << "You already picked up this item!\n";
		UI::Pause();
		return;
	}

	//  Pickup success
	player.ItemPickUp(itemToPickup);
	zone.removeItemsAt(playerX, playerY);
	QuestProgress::setItemPickedUp(true);

	UI::Pause();
}
	/*
	// Check if the item exits
	if (itemToPickup != nullptr)
	{
		// Pick up the item if it exists
		player.ItemPickUp(itemToPickup);

		UI::Pause();
	}
	*/


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
void PlayerActionManager::processOpenCommand(Command command, Player& player)
{
	UI::Clear();
	player.displayInventory();
	UI::Pause();
}

/**
	* @brief Asks the user if the want to quit
	*
	* @details
	* This function handles a prompt confirming if the
	* user would like to quit the game.  "Are you sure (y/n)"
	* @return True if the user confirms, otherwise false.
	*/
bool PlayerActionManager::processQuitCommand()
{
	cout << "Are you sure you want to quit? (y/n): ";

	string choice;

	if (!getline(cin, choice))
	{
		// In the case of ctrl + z the game will exit
		cin.clear();
		return true;
	}

	if (choice == "y" || choice == "Y")
	{
		return true;
	}

	cout << "Resuming Game..." << endl;
	UI::Pause();
	return false;
}