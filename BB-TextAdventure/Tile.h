/**
* @file Tile.h
* @breif Declares the Tile class used to represent terrain and items on the map.
*
* @details
* Each Tile defines a single position within the game world. It contains:
*   - A TileType representing its terrain (grass, stone, etc).
*   - An optional pointer to an Item located at a specific tile.
*
* The Tile is responsible for determining its own color and rendering
*/
#pragma once
#include <iostream>
#include "UI.h"
#include "Item.h"
#include "Enemy.h"
#include "ColorCodes.h"

/**
 * @class Tile
 * @brief Represents one map cell containing terrain and possibly an item.
 *
 * @details
 * Tiles handle their own rendering and color determination, while map classes
 * arrange them. Each tile can also hold one item (pointer).
 */
enum class TileType
{
	Grass,
	Stone,
	Water,
	Dirt,
	RedLight
};


class Tile
{
private:

	/** @brief The terrain type of the tile. */
	TileType type;

	/** @brief Pointer to an item placed on this tile, or nullptr if none. */
	Item* gameItem;

	/** @brief Pointer to an enemy placed on this tile, or nullptr if none. */
	Enemy* gameEnemy;

public:

	/**
	 * @brief Constructs a tile with an initial type.
	 * @param t The terrain type to assign (default is Grass).
	 */
	Tile(TileType t = TileType::Grass);

	/**
	 * @brief Retrieves the color code representing this tile's terrain.
	 * @return An integer corresponding to an 8 bit ANSI color code.
	 */
	int getColorCode() const;

	/**
	 * @brief Renders the tile's terrain color to the console.
	 *
	 * @details
	 * Uses UI::SetColor() and UI::Reset() to colorize output.
	 */
	void Display() const;

	/**
	 * @brief Returns the tile's current terrain type.
	 * @return The TileType of the tile.
	 */
	TileType GetType() const;

	/**
	 * @brief Updates the tile's terrain type.
	 * @param t The new terrain type to assign.
	 */
	void SetType(TileType t);
};
