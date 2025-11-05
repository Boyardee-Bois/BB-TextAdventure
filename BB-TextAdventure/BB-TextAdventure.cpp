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
#include "Enemy.h"
#include "HealthUI.h"

using namespace std;

int main()
{

	UI Interface;
	Map world; // Create our map

	Interface.GameIntro();
	

	// Tokenize user input
	CommandParser parser;

	// Create the player
	Player player;

	// To test player UI
	HealthUI ui;
	
	// Process the players input
	PlayerActionManager actionManager;


	/*
	* 
	* We need to move all of this stuff rooms, npc, etc 
	* into a sepereat init() function outside of main
	* 
	*/
	// Create rooms for the player to move through
	Room* lab = new Room("Crashed Lab", "The ruins of the lab. Wires spark and the air smells of ozone.");
	Room* jungle = new Room("Dense Jungle", "The air is thick and hot. Strange animals cry out.");
	Room* beach = new Room("Black Sand Beach", "A wide-open beach with dark, volcanic sand.");

	//Declaring enemies and types
	Enemy* raptor = new Enemy("Raptor", "A swift and deadly predator.");
	Enemy* miniBoss = new Enemy("MiniBoss", "A larger, more dangerous foe.");

	// Add exits to the room
	lab->addExit("north", jungle);
	jungle->addExit("south", lab);
	jungle->addExit("east", beach);
	beach->addExit("west", jungle);

	//Place an enemy in the map
	lab->setEnemy(raptor);
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

	// Game loop controller
	bool finished = false;

	
	// Sample main game loop: will be updated later
	while (!finished)
	{
		if (player.isDead())
		{
			break;
		}
		
		// clear screen *first*, so the map redraws at top
		system("cls");
		// draw the map and player position first
		world.DisplayWithPlayer(player.getX(), player.getY());

		// now draw the separator and current room info below the map
		Interface.SectionSeperator();
		Interface.DisplayObjective("Retrieve the Arc Reactor (@) near the water.");

		//Display the health bar
		cout << ui.render(player) << endl;

		// now prompt for input (so it stays below everything)
		Command command = parser.getCommand();

		switch (command.getVerb())
		{
		case Verb::Go:
			actionManager.processGoCommand(command, player, world);
			system("cls"); // clear console before redrawing
			world.DisplayWithPlayer(player.getX(), player.getY());

			//Testing player health = 0
			player.takeDamage(100);
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
		case Verb::Attack:
			//Will fill in during next story BB-49
			break;

		case Verb::Unknown:
			cout << "I don't know what you mean. (Type 'help' for commands)" << endl;
			system("pause");
			break;
		}
	}


	cout << "\nGame Over!" << endl;

	delete lab;
	delete jungle;
	delete beach;

	return 0;
};
