/**
* @file Zone.cpp
* @breif Defines the Zone class, which represents a single grid based level.
*
* @details
* The zone class holds the grid of Tiles, a list of portals (exits to another zones),
* and a collection of entities (NPC's, Enemies, Items), withing that a zone.
*
*/
#include "Zone.h"
#include "UI.h"
#include "Item.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Default constructor. Creates the hardcoded Lab zone (fallback).
 */
Zone::Zone()
{
	CreateDefaultZone();
}

/**
 * @brief File-Loading constructor. Creates a zone based on a parsed file.
 * @param fileName The path to the zone's .txt file.
 */
Zone::Zone(const string& fileName)
{
	LoadZoneFromFile(fileName);
}

/**
 * @breif Loads the zone's grid and entities from a text file.
 * @param fileName The path to the .txt file to load.
 */
void Zone::LoadZoneFromFile(const string& fileName)
{
	/*
		TODO: Read from a file and map chars to enum types

		1.) Open 'fileName'
		2.) Read width & height
		3.) Loop Y for height, X for width
				- Read char 'c'
				- if (c == 'G') grid[x][y] = TileType::Green
				- if (c == 'S') grid[x][y] = TileType::Stone
				- if (c == 'W') grid[x][y] = TileType::Water
		4.) After building the map read lines in the file for:
				- Portal Location
				- Enemy Location
				- Item Location
				- NPC Location

			^ This may be moved into the the actual classes of the
			respective object then placed on a tile after the map
			is built.
	*/

}

/**
 * @brief Gets a reference to the tile at a specific (x,y).
 * @param x The x position.
 * @param y The y position.
 * @return A reference to the tile obj.
 */
Tile& Zone::getTileAt(int xPos, int yPos)
{
	if (yPos < 0) yPos = 0;
	if (xPos < 0) xPos = 0;
	if (yPos >= height) yPos = height - 1;
	if (xPos >= width) xPos = width - 1;

	return grid[yPos][xPos];
}

/**
 * @brief Gets a READ ONLY reference to the tile at a specific (x,y).
 * @param x The x position.
 * @param y The y position.
 * @return A READ ONLY reference to the tile obj.
 * @note This Read Only version is used for rendering the level
 */
const Tile& Zone::getTileAt(int xPos, int yPos) const
{
	if (yPos < 0) yPos = 0;
	if (xPos < 0) xPos = 0;
	if (yPos >= height) yPos = height - 1;
	if (xPos >= width) xPos = width - 1;

	return grid[yPos][xPos];
}

/**
 * @brief Checks if a portal exists at a given coordinate (xPos,yPos).
 * @param xPos The x position of a portal.
 * @param yPos The y position of a protal.
 * @return A pointer to a portal if it exits. Otherwise nullptr.
 */
Portal* Zone::getPortalAt(int xPos, int yPos)
{
	for (auto& portal : portals)
	{
		if (portal.xPosition == xPos && portal.yPosition == yPos)
		{
			return &portal;
		}
	}

	return nullptr;
}

/**
 * @brief Gets an enemy exists at a given coordinate (xPos,yPos).
 * @param xPos The x position of a enemy.
 * @param yPos The y position of a enemy.
 * @return A pointer to a enemy if it exits. Otherwise nullptr.
 */
Enemy* Zone::getEnemyAt(int xPos, int yPos) const
{
	auto iterator = enemies.find({ xPos,yPos });

	if (iterator != enemies.end())
	{
		return iterator->second;
	}

	return nullptr;
}

/**
 * @brief Gets an NPC exists at a given coordinate (xPos,yPos).
 * @param xPos The x position of a NPC.
 * @param yPos The y position of a NPC.
 * @return A pointer to a NPC if it exits. Otherwise nullptr.
 */
NPC* Zone::getNpcsAt(int xPos, int yPos) const
{
	auto iterator = npcs.find({ xPos,yPos });

	if (iterator != npcs.end())
	{
		return iterator->second;
	}

	return nullptr;
}

/**
 * @brief Gets an Item exists at a given coordinate (xPos,yPos).
 * @param xPos The x position of a Item.
 * @param yPos The y position of a Item.
 * @return A pointer to a Item if it exits. Otherwise nullptr.
 */
Item* Zone::getItemsAt(int xPos, int yPos) const
{
	auto iterator = items.find({ xPos,yPos });

	if (iterator != items.end())
	{
		return iterator->second;
	}

	return nullptr;
}

/**
 * @brief Gets an Item exists at a given coordinate (xPos,yPos).
 * @param xPos The x position of a Item.
 * @param yPos The y position of a Item.
 * @return True if there was an item to remove, false otherwise.
 */
Item* Zone::removeItemsAt(int xPos, int yPos)
{
	auto iterator = items.find({ xPos,yPos });

	if (iterator != items.end())
	{
		Item* itemToReturn = iterator->second;

		items.erase(iterator);

		return itemToReturn;
	}

	return nullptr;
}

/**
* @brief The width of the grid.
* @return The width of the level.
*/
int Zone::getWidth() const
{
	return width;
}

/**
* @brief The height of the grid.
* @return The height of the level.
*/
int Zone::getHeight() const
{
	return height;
}

Enemy* Zone::removeEnemyAt(int xEnPos, int yEnPos)
{
	auto it = enemies.find({ xEnPos, yEnPos });

	// Check if there’s an enemy at that coordinate
	if (it != enemies.end())
	{
		Enemy* enemyToRemove = it->second; // store pointer before erasing
		enemies.erase(it);                 // remove from the map
		return enemyToRemove;              // return the pointer if you need it
	}

	return nullptr; // no enemy found
}

void Zone::spawnEnemy()
{
	if (QuestProgress::isQuestCompleted())
	{
		for (auto& pair : enemies)
		{
			Enemy* enemy = pair.second;
			if (enemy != nullptr && !enemy->getIsVisible())
			{
				enemy->setIsVisible(true);
			}
		}
	}
}

void Zone::spawnEnemyAt(int xPos, int yPos, const Enemy& enemy)
{
	Enemy* newEnemy = new Enemy(enemy);
	enemies[{xPos, yPos}] = newEnemy;
}

/*
* This will get replaced when reading from a file
* is functioning this is the original Map creation.
*/
void Zone::CreateDefaultZone()
{
	width = 25;
	height = 25;

	// Initialize full map with grass tiles
	grid = std::vector<std::vector<Tile>>(height, std::vector<Tile>(width, Tile(TileType::Grass)));

	// --- BuildStoneRegion ---
	// (Logic from Map::BuildStoneRegion)
	int startX = 2;   // left edge
	int startY = 2;   // top edge
	int labWidth = 7;
	int labHeight = 4;

	// Outer lab structure (Stone walls)
	for (int y = startY; y < startY + labHeight; y++) {
		for (int x = startX; x < startX + labWidth; x++) {
			grid[y][x] = Tile(TileType::Stone);
		}
	}

	grid[startY][startX + 2] = Tile(TileType::Water);  // blue light
	grid[startY][startX + 3] = Tile(TileType::Water);
	grid[startY][startX + 5] = Tile(TileType::RedLight);   // red light

	// Doorway at bottom center
	int doorX = startX + labWidth / 2;
	int doorY = startY + labHeight - 1;
	grid[doorY][doorX] = Tile(TileType::Grass); // entrance (door)


	// --- BuildDirtPath ---
	// (Logic from Map::BuildDirtPath)
	grid[3][10] = grid[3][11] = grid[3][13] = grid[3][15] = grid[3][17] = Tile(TileType::Dirt);
	grid[4][11] = grid[4][13] = grid[4][15] = Tile(TileType::Dirt);
	grid[5][10] = Tile(TileType::Dirt);
	grid[6][11] = Tile(TileType::Dirt);
	grid[7][10] = Tile(TileType::Dirt);
	grid[8][11] = Tile(TileType::Dirt);
	grid[9][11] = grid[9][12] = Tile(TileType::Dirt);
	grid[10][11] = Tile(TileType::Dirt);
	grid[11][12] = Tile(TileType::Dirt);
	grid[12][11] = grid[12][12] = Tile(TileType::Dirt);
	grid[13][11] = Tile(TileType::Dirt);
	grid[14][12] = Tile(TileType::Dirt);
	grid[15][11] = grid[15][12] = Tile(TileType::Dirt);
	grid[16][11] = Tile(TileType::Dirt);
	grid[17][10] = Tile(TileType::Dirt);
	grid[18][11] = Tile(TileType::Dirt);
	grid[19][10] = Tile(TileType::Dirt);
	grid[20][11] = Tile(TileType::Dirt);
	grid[21][10] = Tile(TileType::Dirt);
	grid[22][11] = Tile(TileType::Dirt);
	grid[23][10] = Tile(TileType::Dirt);
	grid[24][11] = Tile(TileType::Dirt);


	// --- BuildWaterArea ---
	// (Logic from Map::BuildWaterArea)
	startX = 14;  // right side
	startY = 15;  // lower area

	// Top and bottom edges of the lake
	for (int x = startX + 1; x < startX + 6; x++) grid[startY][x] = Tile(TileType::Water);
	for (int x = startX; x < startX + 7; x++) grid[startY + 1][x] = Tile(TileType::Water);

	// Middle bulge
	for (int x = startX - 1; x < startX + 8; x++) {
		grid[startY + 2][x] = Tile(TileType::Water);
		grid[startY + 3][x] = Tile(TileType::Water);
		grid[startY + 4][x] = Tile(TileType::Water);
	}

	// Bottom taper
	for (int x = startX; x < startX + 7; x++) grid[startY + 5][x] = Tile(TileType::Water);
	for (int x = startX + 1; x < startX + 6; x++) grid[startY + 6][x] = Tile(TileType::Water);


	// --- Add Items/Enemies/NPCs ---
	// (Logic from Map::Map() constructor)

	/*
	* Steps for Item Creation & Placement
	* 
	* 1. Create the item
	* 2. Set is quest item
	* 3. Place at a location inside of the items map
	*	 renderer will reference zones map to place the 
	*	 item on the map.
	*/
	Item* questItem = new Item("Arc Reactor", "It's glowing.");
	questItem->setIsQuestItem(true);
	items[{13, 20}] = questItem;


	/*
	* Steps for Item Creation & Placement
	* 
	* 1. Create the enemy
	* 2. Place at a location inside of the items map
	*	 renderer will reference zones map to place the
	*	 item on the map.
	*/
	Enemy* testEnemy = new Enemy();
	testEnemy->setIsVisible(false);  // Hide until quest completion
	enemies[{7, 7}] = testEnemy;


	/*
	* Steps for Item Creation & Placement
	* 
	* 1. Create the NPC
	* 2. Place at a location inside of the items map
	*	 renderer will reference zones map to place the
	*	 item on the map.
	*/
	NPC* testNPC = new NPC("BOB");
	npcs[{9, 10}] = testNPC;
}