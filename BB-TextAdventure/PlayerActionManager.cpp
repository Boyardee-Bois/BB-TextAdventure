#include "PlayerActionManager.h"

/*
* Sample command processing this will need to be moved into
* a seperate game manager when time permits.
*/
void PlayerActionManager::processGoCommand(Command command, Player& player, Map& world)
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
		player.movePlayer(moveChar);
		break;
	case Noun::South:
		direction = "south";
		moveChar = 's';
		player.movePlayer(moveChar);
		break;
	case Noun::East:
		direction = "east";
		moveChar = 'd';
		player.movePlayer(moveChar);
		break;
	case Noun::West:
		direction = "west";
		moveChar = 'a';
		player.movePlayer(moveChar);
		break;
	case Noun::W:
		direction = "north";
		moveChar = 'w';
		player.movePlayer(moveChar);
		break;
	case Noun::S:
		direction = "south";
		moveChar = 's';
		player.movePlayer(moveChar);
		break;
		//case Noun::East:  
		// direction = "east"; 
		// moveChar = 'd'; 
		// break;
	case Noun::A:
		direction = "west";
		moveChar = 'a';
		player.movePlayer(moveChar);
		break;
	default:
		break;
	}


	// --- CLEAR AND REDRAW MAP ---
	system("cls");
	world.DisplayWithPlayer(player.getX(), player.getY());
}


/*
* Print the available commands for the player
* This also should be moved into the game manager
* once created
*
* Not all functionality is implemented
*/
void PlayerActionManager::printHelp(CommandParser& parser)
{
	cout << "Your available command words are:" << endl;
	parser.showAllVerbs();
	cout << "Example: 'go north' or 'quit'" << endl;
}