/**
* @file World.cpp
* @breif Defines the main World calss that manages the game state.
*
* @details
* The world class acts as the game state manager. It will control all
* game objects (Zone,Player, etc.) and services (Renderer, Parser, ActionManager, etc)
*/
#include "World.h"

using namespace std;

/**
* @brief Constructor. Initializes the game world.
*/
World::World()
{
	// Most of the setup occurs during StartGame()

	currentZone = nullptr;
}

/**
* @brief The main entry point of the game.
* @details Shows the intro, loads the world, and starts the game loop.
* 1. Show the intro 
* 2. Load the zones
* 3. Set players starting POS
* 4. Begin the main loop
* 5. Print GameOver when loop is broken (Should make a UI screen for this)
*/
void World::StartGame()
{
	if (!interface.GameIntro())
	{
		return;
	}

	LoadWorld();

	// Default Zone
	currentZone = allZones["lab"];

	player.setPosition(6, 7);

	// Set the game to running
	isRunning = true;

	GameLoop();

	cout << "Game Over!" << endl;
}

/**
* @brief Loads all zone files (.txt) and populates the allZone map.
* @details Currently loads the default zone. This will be expanded to
* load several .txt files containing all of the maps
*/
void World::LoadWorld()
{
	// Load the default room for now
	allZones["lab"] = new Zone();

	// TODO: Read from file
	// allZones["beach"] = new Zone("beach.txt");
}

/**
* @brief The main loop that calls Render() and Update() until the
* game ends.
* @details
* Continuously call Render() and Update() while the game is running.
* Checks for a death condition.
*/
void World::GameLoop()
{
	while (isRunning)
	{
		if (player.isDead())
		{
			cout << "You have died" << endl;

			isRunning = false;

			break;
		}

		Render();

		Update();

		// TODO: Put quit logic here (:
	}
}

/**
* @brief Handles all drawing to the console for a single frame of the game.
* @details
* This function is a wrapper the defers to the Renderer object to draw on
* the console.
*/
void World::Render()
{
	renderer.Draw(*currentZone, player);
}

/**
* @brief Handles all the game logic for a single frame (parsing, input, processing action, portal checking)
* @details
* 1. Gets a command from the CommandParser 
* 2. Process the command (ex., movement help, interact, etc)
* 3. Check the game state for changes. (Portals for now)
*/
void World::Update()
{
	Command command = parser.getCommand();

	switch (command.getVerb())
	{
	case Verb::Go:

		actionManager.processGoCommand(command, player, *currentZone);
		break;

	case Verb::Help:

		actionManager.printHelp(parser);
		break;

	case Verb::Attack:

		// TODO: Do something
		break;

	case Verb::Interact:

		actionManager.processInteractCommand(command, player, *currentZone);
		break;

	case Verb::Pickup:

		actionManager.processPickupCommand(command, player, *currentZone);
		break;

	case Verb::Open:

		actionManager.processOpenCommand(command, player);
		break;

	case Verb::Quit:

		if (actionManager.processQuitCommand())
		{
			isRunning = false;
		}
		break;

	case Verb::Unknown:

		cout << "I dont know what you mean. (Type: 'help')" << endl;
		break;
	}

	CheckForPortal();
}

/**
* @brief Check if the player is on a portal tile and handles the transition.
* @details
* If a portal is found at the players (x,y), the update the players
* current zone and position. This moves the player to the next zone and
* places them at the target position in the new zone.
*/
void World::CheckForPortal()
{
	int playerX = player.getX();
	int playerY = player.getY();

	Portal* portal = currentZone->getPortalAt(playerX, playerY);

	if (portal != nullptr)
	{
		string nextZoneID = portal->targetZoneID;

		if (allZones.count(nextZoneID))
		{
			currentZone = allZones[nextZoneID];

			player.setPosition(portal->targetX, portal->targetY);
		}
	}
}