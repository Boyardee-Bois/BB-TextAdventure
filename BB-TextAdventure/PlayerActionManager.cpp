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
#include "TimeMachineLiquidQuest.h"

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

	int newXPos = player.getX();
	int newYPos = player.getY();

	char moveChar = 0;

	switch (command.getNoun())
	{
	case Noun::North: case::Noun::W:
		newYPos--;
		moveChar = 'w';
		break;
	case Noun::South: case::Noun::S:
		newYPos++;
		moveChar = 's';
		break;
	case Noun::East: case::Noun::D:
		newXPos++;
		moveChar = 'd';
		break;
	case Noun::West: case::Noun::A:
		newXPos--;
		moveChar = 'a';
		break;
	default:
		return;
	}

	// Check if the players movement will result in an out of bounds.
	if (newXPos < 0 || newXPos >= world.getWidth() || newYPos < 0 || newYPos >= world.getHeight())
	{
		cout << "You can't go that way!" << endl;
		UI::Pause();
		return;
	}

	// Reference to the tile the player is trying to walk on.
	const Tile& targetTile = world.getTileAt(newXPos, newYPos);
	
	// If the tile is not walkable return, otherwise allow the movement.
	if (!targetTile.isWalkable())
	{
		cout << "You cant walk on that." << endl;
		UI::Pause();
		return;
	}

	player.movePlayer(moveChar);
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
	NPC* npc = zone.getNpcInZone();

	//  Check if there's an item at current tile
	Item* itemToPickup = zone.getItemsAt(playerX, playerY);

	if (itemToPickup == nullptr)
	{
		cout << "There is nothing to pick up here!\n";
		UI::Pause();
		return;
	}

	//  Prevent picking up item before talking to NPC
	if (!npc->isQuestStarted())
	{
		cout << "You can't pick this up yet! Try talking to the NPC first!\n";
		UI::Pause();
		return;
	}

	if (npc->getName() == "TempNameBeachNPC")
	{
		TimeMachineLiquidQuest* questNPC = (TimeMachineLiquidQuest*) npc;

		string itemName = itemToPickup->getItemName();
		int vialNumber = 0;
		if (itemName == "Liquid Vial 1") {
			vialNumber = 1;
		}
		else if (itemName == "Liquid Vial 2") {
			vialNumber = 2;
		}
		else if (itemName == "Liquid Vial 3") {
			vialNumber = 3;
		}

		if (vialNumber > 0 && questNPC->isVialCollected(vialNumber))
		{
			cout << "You already picked up this vial!\n";
			UI::Pause();
			return;
		}

		if (vialNumber > 0)
		{
			questNPC->setVialCollected(vialNumber, true);
		}
		player.ItemPickUp(itemToPickup);
		zone.removeItemsAt(playerX, playerY);
		UI::Pause();
		return;
	}

	if (!npc->getQuestItemCollected()) {
		//  Pickup success
		player.ItemPickUp(itemToPickup);
		zone.removeItemsAt(playerX, playerY);
		// 
		// setItemPickedUp(true);  -- comment this out for now
		npc->setQuestItemCollected(true);

		UI::Pause();
	}

	//  Prevent double pickup
	else {
		cout << "You already picked up this item!\n";
		UI::Pause();
		return;
	}
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

void PlayerActionManager::processAttackCommand(Command command, Player& player, Zone& zone)
{
	// Get the player's current position
	int playerX = player.getX();
	int playerY = player.getY();

	// Try to find an enemy on the same tile
	Enemy* target = zone.getEnemyAt(playerX, playerY);

	// --- No enemy present ---
	if (target == nullptr || !target->getActive())
	{
		std::cout << "There's no enemy here to attack.\n";
		UI::Pause();
		return;
	}

	// --- Enemy already defeated ---
	if (!target->getIsAlive())
	{
		std::cout << "That enemy is already defeated.\n";
		UI::Pause();
		return;
	}

	// --- Player already in combat ---
	if (player.getInCombat())
	{
		std::cout << "You are already in combat!\n";
		UI::Pause();
		return;
	}

	// --- Begin turn-based combat ---
	std::cout << "  Combat initiated against " << target->getEnemyName() << "!\n";
	player.setInCombat(true);

	// Enter combat loop until one side dies
	while (player.isAlive() && target->getIsAlive())
	{
		// --- Player's turn ---
		player.attackEnemy(target);

		if (!target->getIsAlive())
		{
			std::cout << "You defeated " << target->getEnemyName() << "!\n";
			zone.removeEnemyAt(playerX, playerY);
			break;
		}

		UI::Pause();
		UI::Clear();

		// --- Enemy's turn ---
		target->attackPlayer(&player);

		if (!player.isAlive())
		{
			std::cout << "You were defeated by " << target->getEnemyName() << "...\n";
			break;
		}

		UI::Pause();
		UI::Clear();
	}

	// --- End of Combat ---
	player.setInCombat(false);
	std::cout << "Combat has ended.\n";
	UI::Pause();
}


void PlayerActionManager::startCombat(Player& player, Enemy* enemy, Zone& zone)
{
	UI::Clear();
	std::cout << " Combat begins with " << enemy->getEnemyName() << "!\n";
	player.setInCombat(true);

	while (player.isAlive() && enemy->getIsAlive())
	{
		// --- PLAYER TURN ---
		std::cout << "\nYour turn! Type 'attack enemy' to strike.\n";
		player.attackEnemy(enemy);

		if (!enemy->getIsAlive())
		{
			std::cout << "You defeated " << enemy->getEnemyName() << "!\n";
			zone.removeEnemyAt(player.getX(), player.getY());
			break;
		}

		UI::Pause();
		UI::Clear();

		// --- ENEMY TURN ---
		std::cout << enemy->getEnemyName() << "'s turn!\n";
		enemy->attackPlayer(&player);

		if (!player.isAlive())
		{
			std::cout << "You were defeated by " << enemy->getEnemyName() << "...\n";
			break;
		}

		UI::Pause();
		UI::Clear();
	}

	player.setInCombat(false);
	std::cout << "Combat has ended.\n";
	UI::Pause();
}
