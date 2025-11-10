/**
* @file World.h
* @breif Defines the main World calss that manages the game state.
* 
* @details
* The world class acts as the game state manager. It will control all
* game objects (Zone,Player, etc.) and services (Renderer, Parser, ActionManager, etc)
*/
#pragma once
#include "Zone.h"
#include "Player.h"
#include "Renderer.h"
#include "CommandParser.h"
#include "UI.h"
#include "PlayerActionManager.h"
#include <map>
#include <string>

/**
* @class World
* @breif Manages all game objects, services, and the main game loop.
* 
* @details
* Owns and controls the Player, Zones, Renderer, the Command Parser,
* and the PlayerActionManager (Will be expanded upon adding more systems).
* 
* The StartGame() function begins the game.
*/
class World
{
private:

	/** @brief Controls the main game loop*/
	bool isRunning;

	/** @brief A map storing all loaded zones, keyed by their string ID. */
	map<string, Zone*> allZones;

	/** @brief A pointer to the zone the player is currently in */
	Zone* currentZone;

	/** @brief The player object */
	Player player;

	/** @brief The renderer obj responsible for drawing */
	Renderer renderer;

	/** @brief The parser obj responsible for user iput */
	CommandParser parser;

	/** @brief The action manager for executing player game logic */
	PlayerActionManager actionManager;

	/** @brief The UI obj for intro screens and objectives */
	UI interface;

	/**
	 * @brief Loads all zone files (.txt) and populates the allZone map.
	 */
	void LoadWorld();

	/**
	 * @brief The main loop that calls Render() and Update() until the
	 * game ends.
	 */
	void GameLoop();

	/**
	 * @brief Handles all the game logic for a single frame (parsing, input, processing action, portal checking)
	 */
	void Update();

	/**
	 * @brief Handles all drawing to the console for a single frame of the game.
	 */
	void Render();

	/**
	 * @brief Check if the player is on a portal tile and handles the transition.
	 */
	void CheckForPortal();

public:
	
	/**
	 * @brief Constructor. Initializes the game world.
	 */
	World();

	/**
	 * @brief The main entry point of the game.
	 * @details Shows the intro, loads the world, and starts the game loop.
	 */
	void StartGame();
};