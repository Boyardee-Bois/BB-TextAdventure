/**
 * @file Tile.cpp
 * @brief Implements the Tile class responsible for rendering terrain and holding items.
 *
 * @details
 * Each Tile represents a single position on the map grid. It stores its type
 * (ex. grass, dirt, water) and an optional pointer to an Item.
 */
#include "Tile.h"
#include "UI.h"
#include "ColorCodes.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructs a Tile with a specified type.
 * @param t The TileType assigned at creation.
 */
Tile::Tile(TileType t) : type(t)
{
   gameItem = nullptr;
   gameEnemy = nullptr;
 
}

/**
 * @brief Retrieves the color code associated with this tile's terrain type.
 * @return The 8 bit ANSI color code representing the tile’s color.
 */
int Tile::getColorCode() const 
{
    switch (type)
    {
    case TileType::Grass:    return static_cast<int>(ColorCode::Green);
    case TileType::Water:    return static_cast<int>(ColorCode::Blue);
    case TileType::Dirt:     return static_cast<int>(ColorCode::Brown);
    case TileType::Stone:    return static_cast<int>(ColorCode::Gray);
    case TileType::RedLight: return static_cast<int>(ColorCode::Red);
    case TileType::Sand:     return static_cast<int>(ColorCode::Tan);
    default:                 return static_cast<int>(ColorCode::Green);
    }
}

/**
 * @brief Renders the tile to the console.
 *
 * @details
 * - Sets the color according to terrain type.
 * - Displays a space "  " to visually represent the tile.
 * - Resets color afterward.
 */
void Tile::Display() const
{
    int colorCode = getColorCode();
    UI::SetColor(colorCode);
    cout << "  ";
    UI::Reset();
}

/**
 * @brief Retrieves the current tile type.
 * @return The tile's TileType.
 */
TileType Tile::GetType() const
{
    return type;
}

/**
 * @brief Updates the terrain type of the tile.
 * @param t The new TileType.
 */
void Tile::SetType(TileType t)
{
    type = t;
}

/**
* @brief Determines if a tile is walkable
* @return True if the player can walk on a tile, False otherwise.
*/
bool Tile::isWalkable() const
{

}