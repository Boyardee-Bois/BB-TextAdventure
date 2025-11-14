/**
* @file Zone.h
* @breif Defines the Zone class, which represents a single grid based level.
* 
* @details
* The zone class holds the grid of Tiles, a list of portals (exits to another zones), 
* and a collection of entities (NPC's, Enemies, Items), withing that a zone.
* 
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include "Tile.h"
#include "Enemy.h"
#include "NPC.h"
#include "Item.h"
using namespace std;

/**
* @brief Defines possible zones players may travel to.
*/
enum class ZoneLocation
{
    DefaultLab,
    Beach
};

/**
* @struct Portal
* @brief Defines a connection (teleport/load) between two Zone objects.
* 
* @details
* The portal stores the location on the current zone (xPosition, yPosition), and the 
* destination ZoneID (name of the .txt to load) and its cordinates.
*   - xPosition: The x coordinate of the current zones portal.
*   - yPosition: The y coordinate of the current zones portal.
*   - targetX: The x coordinate of the target zones portal (this is the tile you'll load on) .
*   - targetY: The y coordinate of the target zones portal (this is the tile you'll load on).
*   - targetZoneID: The name of the zone to load (.txt).
*/
struct Portal
{
    // Location of the portal in a room
    int xPosition, yPosition;

    // Name of the zone to load
    string targetZoneID;

    // The target tile to load on in the new zone
    int targetX, targetY;
};

/**
* @class Zone
* @breif A container for a single game level.
* 
* @details
* This class replaces the old Map class. It holds a tile grid and data about interactables in the world.
* This does not draw the map it only interprets the data then passes data to the Renderer.
* All level building will be done in a text file and referenced against ColorCode.h 
*/
class Zone 
{
private:

    int width; /**< The width of the zone grid (in tiles). */
    int height; /**< The height of the zone grid (in tiles). */
    
    /**@breif A list of all tiles in this zone */
    vector<vector<Tile>> grid;
    
    /**@breif A list of all portals in this zone */
    vector<Portal> portals;

    /**@breif A map pairing enemies to coordinates (x,y).*/
    map<pair<int, int>, Enemy*> enemies;

    /**@breif A map pairing enemies to coordinates (x,y).*/
    map<pair<int, int>, NPC*> npcs;

    /**@breif A map pairing items to coordinates (x,y).*/
    map<pair<int, int>, Item*> items;

    /**
    * @breif Loads the zone's grid and entities from a text file.
    * @param fileName The path to the .txt file to load.
    */
    void LoadZoneFromFile(const string& fileName);
    
    /**
    * @breif Creates a hardcoded default map.
    * @details Used as the fallback map.
    */
    void CreateDefaultZone();

	bool enemySpawned = false;

    /**
    * @breif Creates a hardcoded beach map.
    * @details Used as the fallback map.
    */
    void CreateBeachZone();

public:

    /**
    * @brief Default constructor. Creates the hardcoded Lab zone
    */
    Zone(ZoneLocation name);

    /**
    * @brief File-Loading constructor. Creates a zone based on a parsed file.
    * @param fileName The path to the zone's .txt file.
    */
    Zone(const string& filename);

    /**
    * @brief Gets a reference to the tile at a specific (x,y).
    * @param x The x position.
    * @param y The y position.
    * @return A reference to the tile obj.
    */
    Tile& getTileAt(int x, int y);
    
    /**
    * @brief Gets a READ ONLY reference to the tile at a specific (x,y).
    * @param x The x position.
    * @param y The y position.
    * @return A READ ONLY reference to the tile obj.
    * @note This Read Only version is used for rendering the level
    */
    const Tile& getTileAt(int xPos, int yPos) const;

    /**
    * @brief Checks if a portal exists at a given coordinate (xPos,yPos).
    * @param xPos The x position of a portal.
    * @param yPos The y position of a protal.
    * @return A pointer to a portal if it exits. Otherwise nullptr.
    */
    Portal* getPortalAt(int xPos, int yPos);

    /**
    * @brief Checks if a portal exists at a given coordinate (xPos,yPos).
    * @param xPos The x position of a portal.
    * @param yPos The y position of a protal.
    * @return A pointer to a portal if it exits. Otherwise nullptr.
    * @note READ ONLY
    */
    const Portal* getPortalAt(int xPos, int yPos) const;

    /**
    * @brief Gets an enemy exists at a given coordinate (xPos,yPos).
    * @param xPos The x position of a enemy.
    * @param yPos The y position of a enemy.
    * @return A pointer to a enemy if it exits. Otherwise nullptr.
    */
    Enemy* getEnemyAt(int xPos, int yPos) const;

    /**
    * @brief Gets an NPC exists at a given coordinate (xPos,yPos).
    * @param xPos The x position of a NPC.
    * @param yPos The y position of a NPC.
    * @return A pointer to a NPC if it exits. Otherwise nullptr.
    */
    NPC* getNpcsAt(int xPos, int yPos) const;
    NPC* getNpcInZone() const;

    /**
    * @brief Gets an Item exists at a given coordinate (xPos,yPos).
    * @param xPos The x position of a Item.
    * @param yPos The y position of a Item.
    * @return A pointer to a Item if it exits. Otherwise nullptr.
    */
    Item* getItemsAt(int xPos, int yPos) const;

    /**
    * @brief Removes an Item exists at a given coordinate (xPos,yPos).
    * @param xPos The x position of a Item.
    * @param yPos The y position of a Item.
    * @return A pointer to a Item to remove if it exits. Otherwise nullptr.
    */
    Item* removeItemsAt(int xPos, int yPos);

    /**
    * @brief The width of the grid.
    * @return The width of the level.
    */
    int getWidth() const;

    /**
    * @brief The height of the grid.
    * @return The height of the level.
    */
    int getHeight() const;

    Enemy* removeEnemyAt(int xEnPos, int yEnPos);

	void spawnEnemy();
	bool hasEnemySpawned() const { return enemySpawned; }
	void setEnemySpawned(bool spawned) { enemySpawned = spawned; }
	void spawnEnemyAt(int xPos, int yPos, const Enemy& enemy);
};
