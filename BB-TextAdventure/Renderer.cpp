/**
* @file Renderer.cpp
* @brief Defines the Renderer class for drawing the game to the console.
*
* @details
* The Renderer is a class that handles all of the drawing logic.
* It is the only class that should draw to the console.
*/
#include "Renderer.h"
#include "UI.h"
#include "Tile.h"
#include "ColorCodes.h"
#include <iostream>

/**
* @breif Constructor that enables colors for use in the console.
* @details Enables color support for the console.
*/
Renderer::Renderer()
{
	UI::EnableColor();
}

/**
* @brief The main draw function for the game.
* @details Clears the screen, draws the zone, and draws the HUD.
* 1.Clear the screen
* 2.Draw the zone (map, npc, etc)
* 3.Draw the UI seperator
* 4.Draw the HUD (health and objective)
* @param zone A constant reference to the active zone.
* @param player A constant reference to the Player.
*/
void Renderer::Draw(const Zone& zone, const Player& player)
{
	UI::Clear();
	DrawZone(zone, player);
	UI::SectionSeperator();
	DrawHUD(player);
}

/**
* @brief Draws the zone, including tiles, players, any other objects.
* @details
* A private helper function the loops through every tile in the Zone's grid
* and draws the appropriate character (Player, Item, Enemy or Tile)
* @param zone A reference to the active zone.
* @param player A reference to the player.
*/
void Renderer::DrawZone(const Zone& zone, const Player& player)
{
	int playerX = player.getX();
	int playerY = player.getY();

	for (int y = 0; y < zone.getHeight(); ++y)
	{
		for (int x = 0; x < zone.getWidth(); ++x)
		{
			const Tile& tile = zone.getTileAt(x, y);

			UI::SetColor(tile.getColorCode());

			if (x == playerX && y == playerY)
			{
				std::cout << "P ";
			}
			else if (zone.getItemsAt(x,y) != nullptr)
			{
				std::cout << "@ ";
			}
			else if (zone.getEnemyAt(x,y) != nullptr)
			{
				std::cout << "E ";
			}
			else if (zone.getNpcsAt(x,y) != nullptr)
			{
				std::cout << "N ";
			}
			else if (zone.getPortalAt(x, y) != nullptr)
			{
				UI::SetColor(static_cast<int>(ColorCode::Pink));
				cout << "O ";
			}
			else
			{
				tile.Display();
			}

			UI::Reset();
		}
	
		std::cout << endl;
	}
}

/**
* @brief Draws the HUD for the player (Health, Objective)
* @details
* Draw all of the UI elements that appear below the map, such
* as the players health bar and their current objective.
* This should be expanded when more UI elements need to be displayed.
* @param player A reference to the player.
*/
void Renderer::DrawHUD(const Player& player)
{
	std::cout << healthBar.render(const_cast<Player&>(player)) << endl;
	std::cout << "This is where an objective will be" << endl;
	//TODO: Display Objective here!
}