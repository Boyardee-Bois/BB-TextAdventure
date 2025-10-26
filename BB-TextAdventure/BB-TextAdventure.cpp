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
*/
void processGoCommand(Command command, Player& player, Map& world)
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
			processGoCommand(command, player, world);
			system("cls"); // clear console before redrawing
			world.DisplayWithPlayer(player.getX(), player.getY());
			break;

		case Verb::Help:
			printHelp(parser);
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
