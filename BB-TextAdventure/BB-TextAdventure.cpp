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
#include "PlayerActionManager.h"
#include "NPC.h"

using namespace std;


/*
* Sample command processing this will need to be moved into
* a seperate game manager when time permits.
*/void processGoCommand(Command command, Player& player, Map& world)
{
	if (!command.hasDirection()) {
		cout << "Go where? (Example: 'go north')" << endl;
		system("pause");
		
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
	

	// Tokenize user input
	CommandParser parser;
	// Create the player
	Player player;
	// Process the players input
	PlayerActionManager actionManager;

	// Create rooms for the player to move through
	Room* lab = new Room("Crashed Lab", "The ruins of the lab. Wires spark and the air smells of ozone.");
	Room* jungle = new Room("Dense Jungle", "The air is thick and hot. Strange animals cry out.");
	Room* beach = new Room("Black Sand Beach", "A wide-open beach with dark, volcanic sand.");

	// Add exits to the room
	lab->addExit("north", jungle);
	jungle->addExit("south", lab);
	jungle->addExit("east", beach);
	beach->addExit("west", jungle);

	//Create an NPC named BeachNPC (for now) and place it in the Beach room
	NPC beachNPC("BeachNPC", 10, 7);
	lab->setNPC(&beachNPC);
	beachNPC.setNPC_Position(10, 7);
	//world.DisplayWithNPC(beachNPC.getNPC_X(), beachNPC.getNPC_Y());

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
			actionManager.processGoCommand(command, player, world);
			system("cls"); // clear console before redrawing
			world.DisplayWithPlayer(player.getX(), player.getY());
			break;

		case Verb::Help:
			actionManager.printHelp(parser);
			system("pause");
			break;

		case Verb::Quit:
			finished = true;
			break;

		case Verb::Interact:
		{
			int npcX = beachNPC.getNPC_X();
			int npcY = beachNPC.getNPC_Y();
			int playerX = player.getX();
			int playerY = player.getY();
			cout << npcX << " " << npcY << " " << playerX << " " << playerY << endl;
			//Tile& tile = world.getTilePos(npcX, npcY);
			beachNPC.player_Coord_Check(playerX, playerY);
			if (playerX == npcX && playerY == npcY) {
				beachNPC.interact(command.getVerb(), command.getNoun(), playerX, playerY);
			}
			break;
		}
		case Verb::Pickup:
		{
			int playerTilePosX = player.getX();
			int playerTilePosY = player.getY();

			Tile& tile = world.getTilePos(playerTilePosX, playerTilePosY);

			if (tile.getItem() != nullptr)
			{
				Item* item = tile.getItem();
				player.ItemPickUp(item);
				beachNPC.setQuestItemCollected(true);
				tile.removeItem();
				system("pause"); 
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
			system("pause");
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
