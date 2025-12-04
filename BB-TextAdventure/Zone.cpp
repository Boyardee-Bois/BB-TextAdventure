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
#include "TimeMachineLiquidQuest.h"
#include "GearsQuest.h"
#include "JungleNPC.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Default constructor. Creates the hardcoded Lab zone (fallback).
 */
Zone::Zone(ZoneLocation name)
{
	switch (name)
	{
	case ZoneLocation::DefaultLab:
			CreateDefaultZone();
			break;

	case ZoneLocation::InteriorLab:
			CreateLabInteriorZone();
			break;

	case ZoneLocation::BasementLab:
			CreateLabBasementZone();
			break;
	case ZoneLocation::Beach:
			CreateBeachZone();
			break;
	case ZoneLocation::Jungle:
			CreateJungleZone();
			break;
	default:
		CreateDefaultZone();
			break;
	}
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
 * @brief Checks if a portal exists at a given coordinate (xPos,yPos).
 * @param xPos The x position of a portal.
 * @param yPos The y position of a protal.
 * @return A pointer to a portal if it exits. Otherwise nullptr.
 * @note READ ONLY
 */
const Portal* Zone::getPortalAt(int xPos, int yPos) const
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
 * LV
 * @brief Returns the first NPC in a zone - don't ask ..
 *   if no NPCs exist in the zone - return the nullptr
 */
NPC* Zone::getNpcInZone() const
{
	if (!npcs.empty()) {
		auto iterator = npcs.begin();
		return iterator->second;
	}
	else {
		return nullptr;
	}
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

// This needs comments
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
// This needs comments
void Zone::spawnEnemy()
{
	//if (getNpcInZone()->isQuestComplete())
	//{
	
		for (auto& pair : enemies)
		{
			Enemy* enemy = pair.second;
			if (enemy != nullptr && !enemy->getIsVisible())
			{
				
				enemy->setIsVisible(true);
				enemy->setActive(true);
				if (enemy != nullptr && !enemy->getIsAlive())
				{
					Item* item = getItemsAt(enemy->getEnemy_X(), enemy->getEnemy_Y());
					if (item != nullptr && !item->getItemIsVisible())
					{
						item->setItemIsVisible(true);
						cout << "Looks like the enemy dropped something!\n";
					}
				}
		
			}
		//}
	}
}
// This needs comments
void Zone::spawnEnemyAt(int xPos, int yPos, const Enemy& enemy)
{
	Enemy* newEnemy = new Enemy(enemy);
	enemies[{xPos, yPos}] = newEnemy;
}

/*
* @breif The initial zone players load into
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
	Enemy* testEnemy = new Enemy("Bob", "bob", 100);
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
	//staticNPC = testNPC;

	/*
	*
	* Add a portal to the Lab Zone
	*
	* (5,5) Location of the portal
	* -> lab
	* (5,8) arrival tile in the lab zone
	*
	*/
	portals.push_back(Portal{ 0,7, "beach", 23, 5 });

	/*
	*
	* Add a portal to the Lab interior Zone
	*
	* (5,5) Location of the portal in the current room
	* -> lab
	* (5,8) arrival tile in the lab interior zone
	*
	*/
	grid[0][12] = Tile(TileType::Dirt);
	portals.push_back(Portal{ doorX, doorY, "lab_interior", 7, 8 });

	/*
	*
	* Add a portal to the Jungle Zone
	*
	* (5,5) Location of the portal in the current room
	* -> lab
	* (5,8) arrival tile in the Jungle zone
	*
	*/
	portals.push_back(Portal{ 24, 18, "jungle", 1, 18 });
}

/*
* @breif The beach zone west of the load zone
*/
void Zone::CreateBeachZone()
{
	width = 25;
	height = 20;

	// Creat a zone filled with sand.
	grid = vector<vector<Tile>>(height, vector<Tile>(width, Tile(TileType::Sand)));

	// Create the water area
	for (int vertical = 0; vertical < height; ++vertical)
	{
		// Left most columns are water
		grid[vertical][0] = Tile(TileType::Water);
		grid[vertical][1] = Tile(TileType::Water);
		grid[vertical][2] = Tile(TileType::Water);
		grid[vertical][3] = Tile(TileType::Water);
	}

	// Create the NPC
	TimeMachineLiquidQuest* reach_beachNPC = new TimeMachineLiquidQuest("Beachkeeper Cole");

	// Set the zone for the NPC to this beach
	reach_beachNPC->setZone(this);

	// Add NPC to beach map
	npcs[{10, 10}] = reach_beachNPC;

	Item* vial1 = new Item("Liquid Vial 1", "whoa");
	vial1->setIsQuestItem(true);
	items[{13, 19}] = vial1;

	Item* vial2 = new Item("Liquid Vial 2", "Whoaaaaa");
	vial2->setIsQuestItem(true);
	items[{7, 7}] = vial2;

	Item* vial3 = new Item("Liquid Vial 3", "WHOAAAAAAAAAAA");
	vial3->setIsQuestItem(true);
	items[{19, 2}] = vial3;

	Enemy* sandEnemy = new Enemy("Sand-Dweller", "Sand-Dweller!", 100);
	sandEnemy->setIsVisible(false);
	sandEnemy->setEnemy_Position(10, 15);
	enemies[{10, 15}] = sandEnemy;

	Item* dataDrive = new Item("Data Drive", "It has all the time periods!");
	dataDrive->setItemIsVisible(false);
	//dataDrive->setIsQuestItem(true);
	items[{10, 15}] = dataDrive;
	//grid[4][2] = Tile(TileType::Water);
	//grid[5][2] = Tile(TileType::Water);

	/*
	* 
	* Add a portal to the Lab Zone
	* 
	* (5,5) Location of the portal in the current room
	* -> lab
	* (5,8) arrival tile in the lab zone
	* 
	*/ 
	portals.push_back(Portal{ 24,5, "lab", 1, 7 });
}

/*
* @breif The interior of the lab located in the inital zone
*/
void Zone::CreateLabInteriorZone()
{
	width = 15;
	height = 10;

	// Creat a zone filled with stone (walls)
	grid = vector<vector<Tile>>(height, vector<Tile>(width, Tile(TileType::Stone)));

	// Fill the interior of the zone with a walkable tile ie., flooring
	for (int y = 1; y < height - 1; ++y)
	{
		for (int x = 1; x < width - 1; x++)
		{
			grid[y][x] = Tile(TileType::Flooring);
		}
	}

	/*
	*
	* Add a portal to the Lab exterior Zone
	*
	* (7,9) Location of the portal in the current room
	* -> lab
	* (12,23) arrival tile in the lab interior zone
	*
	*/
	portals.push_back(Portal{ 7,9, "lab", 5, 6 });

	grid[9][7] = Tile(TileType::Dirt);

	/*
	*
	* Add a portal to the Lab basement Zone
	*
	* (1,1) Location of the portal in the current room
	* -> lab
	* (5,1) arrival tile in the lab interior zone
	*
	*/
	portals.push_back(Portal{ 1,1, "lab_basement", 2, 1 });
}

/*
* @breif The lower level of the interior of the interior lab zone
*/
void Zone::CreateLabBasementZone()
{
	width = 10;
	height = 10;

	// Creat a zone filled with stone (walls)
	grid = vector<vector<Tile>>(height, vector<Tile>(width, Tile(TileType::BasementWall)));

	// Fill the interior of the zone with a walkable tile ie., flooring
	for (int y = 1; y < height - 1; ++y)
	{
		for (int x = 1; x < width - 1; x++)
		{
			grid[y][x] = Tile(TileType::Dirt);
		}
	}

	// Create the Gear Quest NPC
	GearsQuest* gearsNPC = new GearsQuest("Hoarder Riley");
	gearsNPC->setZone(this);
	npcs[{6, 1}] = gearsNPC;

	// Creates the 5 Different Gear quest items
	Item* gear1 = new Item("Gear 1", "A shiny gear");
	gear1->setIsQuestItem(true);
	items[{8, 4}] = gear1;

	Item* gear2 = new Item("Gear 2", "A medium sized gear");
	gear2->setIsQuestItem(true);
	items[{8, 5}] = gear2;

	Item* gear3 = new Item("Gear 3", "A large sized gear");
	gear3->setIsQuestItem(true);
	items[{8, 6}] = gear3;

	Item* gear4 = new Item("Gear 4", "A small sized gear");
	gear4->setIsQuestItem(true);
	items[{8, 7}] = gear4;

	Item* gear5 = new Item("Gear 5", "The master gear!");
	gear5->setIsQuestItem(true);
	items[{8, 8}] = gear5;

	// Spawns the enemy but sets it to invisible
	Enemy* gearEnemy = new Enemy("Gear Guardian", "Gear Guardian!", 120);
	gearEnemy->setIsVisible(false);
	enemies[{5, 5}] = gearEnemy;

	/*
	*
	* Add a portal to the Lab interior Zone
	*
	* (1,1) Location of the portal in the current room
	* -> lab_basement
	* (2,1) arrival tile in the lab interior zone
	*
	*/
	portals.push_back(Portal{ 1,1, "lab_interior", 2, 1 });

}

/*
* @breif Additional biome zone for future quests
*/
void Zone::CreateJungleZone()
{
	width = 20;
	height = 20;

	grid = vector<vector<Tile>>(height, vector<Tile>(width, Tile(TileType::Grass)));

	for (int x = 0; x < width; ++x)
	{
		grid[9][x] = Tile(TileType::Water);
		grid[8][x] = Tile(TileType::Water);
	}

	JungleNPC* jungleNPC = new JungleNPC("Hunter Darwin");
	jungleNPC->setZone(this);
	npcs[{6, 1}] = jungleNPC;

	Enemy* jungleEnemy1 = new Enemy("Jungle Lurker", "Jungle Lurker!", 140);
	jungleEnemy1->setIsVisible(true);
	jungleEnemy1->setActive(true);
	enemies[{15, 5}] = jungleEnemy1;

	// Bridge to cross water
	grid[8][10] = Tile(TileType::Dirt);
	grid[9][10] = Tile(TileType::Dirt);

	/*
	*
	* Add a portal to the Default Zone
	*
	* (1,1) Location of the portal in the current room
	* -> lab_basement
	* (2,1) arrival tile in the default zone
	*/
	portals.push_back(Portal{ 0,18, "lab", 23,18 });
	
}
