/**
* @file Renderer.h
* @brief Defines the Renderer class for drawing the game to the console.
* 
* @details
* The Renderer is a class that handles all of the drawing logic.
* It is the only class that should draw to the console.
*/
#pragma once
#include "Zone.h"
#include "Player.h"
#include "HealthUI.h"

/**
* @class Renderer.h
* @brief Manages all console drawing operationss for the game.
*
* @details
* This class seperated the game logic and drawing logic. The world
* class uses calls the Renderer and calls Draw for each frame. The 
* Renderer then reads the information from the Zone and Player.
*/
class Renderer
{

private:
	
	/**
	* @brief The HealthUI helper for displaying health bar.
	*/
	HealthUI healthBar;

	/**
	* @brief Draws the zone, including tiles, players, any other objects. 
	* @param zone A reference to the active zone.
	* @param player A reference to the player.
	*/
	void DrawZone(const Zone& zone, const Player& player);

	/**
	* @brief Draws the HUD for the player (Health, Objective)
	* @param player A reference to the player.
	*/
	void DrawHUD(const Player& player, NPC* npc);

public:
	/**
	* @breif Constructor that enables colors for use in the console.
	*/
	Renderer();

	/**
	* @brief The main draw function for the game.
	* @details Clears the screen, draws the zone, and draws the HUD.
	* @param zone A constant reference to the active zone.
	* @param player A constant reference to the Player.
	*/
	void Draw(const Zone& zone, const Player& player);

};