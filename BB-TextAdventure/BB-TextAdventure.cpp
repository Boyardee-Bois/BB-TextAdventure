#include <iostream>
#include "UI.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Tile.h"
#include <vector>
#include "Map.h"
#include "CommandParser.h" 
#include "Command.h"         
#include "Verb.h"            
#include "Noun.h"

using namespace std;


/*
* Sample command processing this will need to be moved into
* a seperate game manager when time permits.
*/void processGoCommand(Command command, Player& player, Map& world)
{
	if (!command.hasDirection()) {
		cout << "Go where? (Example: 'go north')" << endl;
		return;
	}

	char moveChar = 0;

	switch (command.getNoun())
	{
	case Noun::North:
	case Noun::W:
		moveChar = 'w';
		break;
	case Noun::South:
	case Noun::S:
		moveChar = 's';
		break;
	case Noun::East:
		moveChar = 'd';
		break;
	case Noun::West:
	case Noun::A:
		moveChar = 'a';
		break;
	default:
		cout << "Invalid direction.\n";
		return;
	}

	// Move the player (no redraw or cls here)
	player.movePlayer(moveChar);
}



/*
* Print the available commands for the player
* This also should be moved into the game manager
* once created
*
* Not all functionality is implemented
*/
void printHelp(CommandParser& parser)
{
	cout << "Your available command words are:" << endl;
	parser.showAllVerbs();
	cout << "Example: 'go north' or 'quit'" << endl;
}

int main()
{

	UI Interface;
	Map world; // Create our map


	Interface.GameIntro();
	Interface.EnableColor();
	world.Display();
	Interface.Reset();




	CommandParser parser;
	Player player;

	// Create rooms for the player to move through
	Room* lab = new Room("Crashed Lab", "The ruins of the lab. Wires spark and the air smells of ozone.");
	Room* jungle = new Room("Dense Jungle", "The air is thick and hot. Strange animals cry out.");
	Room* beach = new Room("Black Sand Beach", "A wide-open beach with dark, volcanic sand.");

	// Add exits to the room
	lab->addExit("north", jungle);
	jungle->addExit("south", lab);
	jungle->addExit("east", beach);
	beach->addExit("west", jungle);



	// Set the players current room
	player.setCurrentRoom(lab);
	player.setPosition(5, 8);
	system("cls");
	world.DisplayWithPlayer(player.getX(), player.getY());
	Interface.SectionSeperator();
	player.getCurrentRoom()->printRoomInformation();


	//adding for Testing purposes: putting an item in the starting area
	Item* testItem = new Item(); 
	testItem->setItemName("Arc Reactor"); 
	testItem->setIsQuestItem(true); 
	lab->setItem(testItem);

	// Sample statement to display game is starting
	cout << "\nGAME STARTING...\n";
	cout << "Type 'help' for commands or 'quit' to exit.\n";

	bool finished = false;

	
	// Sample main game loop: will be updated later
	while (!finished)
	{
		// clear screen *first*, so the map redraws at top
		system("cls");

		// draw the map and player position first
		world.DisplayWithPlayer(player.getX(), player.getY());

		// now draw the separator and current room info below the map
		Interface.SectionSeperator();
		Interface.DisplayObjective("Retrieve the Arc Reactor (@) near the water.");

		// now prompt for input (so it stays below everything)
		Command command = parser.getCommand();

		switch (command.getVerb())
		{
		case Verb::Go:
			processGoCommand(command, player, world);
			break;

		case Verb::Help:
			printHelp(parser);
			break;

		case Verb::Quit:
			finished = true;
			break;

		case Verb::Pickup:
		{
			int playerTilePosX = player.getX();
			int playerTilePosY = player.getY();

			Tile& tile = world.getTilePos(playerTilePosX, playerTilePosY);

			if (tile.getItem() != nullptr)
			{
				Item* item = tile.getItem();
				player.ItemPickUp(item);
				tile.removeItem();

				cout << "You picked up the " << item->getItemName() << "!\n";
				system("pause"); //  Waits for user input (press any key)
			}
			else
			{
				cout << "No item here.\n";
				system("pause");
			}

			system("cls");
			world.DisplayWithPlayer(player.getX(), player.getY());
			break;
		}
		case Verb::Open:
			player.displayInventory();
			system("pause");
			break;

		case Verb::Unknown:
			cout << "I don't know what you mean. (Type 'help' for commands)" << endl;
			break;
		}
	}


	cout << "\nGood-Bye" << endl;

	delete lab;
	delete jungle;
	delete beach;

	return 0;
};

//This is a change to test for jira, my initial commit message may not be connected :(
