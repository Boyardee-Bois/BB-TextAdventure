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

int main()
{

	UI Interface;
	Map world; // Create our map

	Interface.GameIntro();
	Interface.EnableColor();
	world.Display();
	Interface.Reset();

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
	beach->setNPC(&beachNPC);

	// Set the players current room
	player.setCurrentRoom(lab);
	player.setPosition(13, 13);
	system("cls");
	world.DisplayWithPlayer(player.getX(), player.getY());


	// Sample statement to display game is starting
	cout << "\nGAME STARTING...\n";
	cout << "Type 'help' for commands or 'quit' to exit.\n";

	bool finished = false;

	// Sample main game loop: will be updated later
	while (!finished)
	{
		Interface.SectionSeperator();
		
		player.getCurrentRoom()->printRoomInformation();
		
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
			break;

		case Verb::Quit:
			finished = true;
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
