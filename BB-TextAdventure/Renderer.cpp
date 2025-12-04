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
#include "Windows.h"
#include "Zone.h"
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
	

	//Allow Renderer to access NPC using Zone's connection to NPC
	NPC* npc = zone.getNpcInZone();
	DrawHUD(player, npc);

	//Test to see if Renderer can call NPC using Zone
	/*
	if (npc != nullptr) {
		cout << "HI TEST NPC: " << npc->getName() << "\n";
	}
	*/
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
	system("chcp 65001 > nul");
	for (int y = 0; y < zone.getHeight(); ++y)
	{
		for (int x = 0; x < zone.getWidth(); ++x)
		{
			const Tile& tile = zone.getTileAt(x, y);

			UI::SetColor(tile.getColorCode());

			if (x == playerX && y == playerY)
			{
				UI::SetColor(static_cast<int>(ColorCode::Black));
				//std::cout << "P ";
				SetConsoleOutputCP(CP_UTF8);
				std::cout << u8"🧑‍🔬";

			}
			else if (zone.getItemsAt(x,y) != nullptr)
			{
				Item* item = zone.getItemsAt(x, y);
				// If statement that displays regular tile for dropped items if an enemy hasn't been defeated yet
				if (item->getItemIsVisible() || item->getItemName() != "Data Drive")
				{
					std::cout << u8"🔩";
				}
				else
				{
					tile.Display();
				}
			}
			else if (zone.getEnemyAt(x,y) != nullptr)
			{
				Enemy* enemy = zone.getEnemyAt(x, y);

				// Only show enemies that are visible (unlocked after quest)
				if (enemy->getIsVisible() && enemy->getIsAlive())
				{
					std::cout <<u8"🤺";
				}
				else
				{
					Item* item = zone.getItemsAt(x, y);
					if (item != nullptr)
					{
						std::cout << u8"🔩";
					}
					else
					{
						cout << "  ";
					}
				}
			}
			else if (zone.getNpcsAt(x,y) != nullptr)
			{
				std::cout << u8"🧌";
			}
			else if (zone.getPortalAt(x, y) != nullptr)
			{
				UI::SetColor(static_cast<int>(ColorCode::Pink));
				cout << "  ";
			}
			else
			{
				tile.Display();
			}

			UI::Reset();
		}
	
		cout << "    |    ";
		cout << displayCommand(y);
		cout << endl;
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
void Renderer::DrawHUD(const Player& player, NPC* npc)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::cout << healthBar.render(const_cast<Player&>(player)) << std::endl;

	SetConsoleTextAttribute(hConsole, 10); // Green text for HUD
	std::cout << "===============================" << std::endl;
	if (npc != nullptr)
	{
		std::cout << " Quest: " << npc->getName() << std::endl;
		std::cout << " Objective: " << npc->getQuestObject().GetCurrentObjective() << std::endl;
	}
	else {
		std::cout << " Objective: N/A " << std::endl;
	}
		std::cout << "===============================" << std::endl;
	SetConsoleTextAttribute(hConsole, 7); // Reset color
}

string Renderer::displayCommand(int lineNumber)
{
	switch (lineNumber)
	{
	case 1: return "COMMANDS:";
	case 2: return "---------";
	case 3: return "[W/A/S/D]: Move";
	case 4: return "Help: Display help menu";
	default:return "";
	}
}
