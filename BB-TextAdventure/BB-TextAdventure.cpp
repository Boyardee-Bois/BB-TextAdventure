#include <iostream>
#include "UI.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "CommandParser.h" 
#include "Command.h"         
#include "Verb.h"            
#include "Noun.h"

using namespace std;


/*
* Sample command processing this will need to be moved into
* a seperate game manager when time permits.
*/
void processGoCommand(Command command, Player& player)
{
	if (!command.hasDirection())
	{
		cout << "Go where? (Example: 'go north')" << endl;
		return;
	}

	string direction;
	switch (command.getNoun())
	{
	case Noun::North: direction = "north"; break;
	case Noun::South: direction = "south"; break;
	case Noun::East:  direction = "east";  break;
	case Noun::West:  direction = "west";  break;
	default:
		cout << "That's not a valid direction." << endl;
		return;
	}

	Room* current = player.getCurrentRoom();

	Room* nextRoom = current->getExit(direction);

	if (nextRoom != nullptr)
	{
		player.setCurrentRoom(nextRoom);
		cout << "You move " << direction << ".\n";
	}
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
	Interface.GameIntro();

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

	// Sample statement to display game is starting
	cout << "\nGAME STARTING...\n";
	cout << "Type 'help' for commands or 'quit' to exit.\n";

	bool finished = false;

	// Sample main game loop: will be updated later
	while (!finished)
	{
		cout << "\n======================================================\n";
		
		player.getCurrentRoom()->printRoomInformation();
		
		Command command = parser.getCommand();

		switch (command.getVerb())
		{
		case Verb::Go:
			processGoCommand(command, player);
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