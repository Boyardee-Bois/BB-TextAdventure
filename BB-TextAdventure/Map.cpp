#include "Map.h"
#include "UI.h"
#include "Item.h"
#include <iostream>

/*
* Class: Map
* --------------------------------------------
* Represents the grid system for player movement.
* Each tile in the map has a terrain type and color.
*/

Map::Map() {
    width = 25;
    height = 25;
    Item* questItem = new Item();
    questItem->setItemName("Arc Reactor"); 
    questItem->setIsQuestItem(true); 

    // Initialize full map with grass tiles
    grid = std::vector<std::vector<Tile>>(height, std::vector<Tile>(width, Tile(TileType::Grass)));

    // Build specific regions of the map
    Map::BuildStoneRegion();
    Map::BuildDirtPath();
    Map::BuildWaterArea();
    

   grid[12][12].setItem(questItem); 
    
}

   // Builds the stone region in the top left of the map
void Map::BuildStoneRegion() {
    // Row 2–4 contain stone tiles
    for (int x = 3; x < 7; x++) grid[1][x] = Tile(TileType::Stone);      // Row 2
    for (int x = 2; x < 8; x++) grid[2][x] = Tile(TileType::Stone);      // Row 3
    for (int x = 2; x < 9; x++) grid[3][x] = Tile(TileType::Stone);      // Row 4
}

/**
 * Builds our dirt path 
 */
void Map::BuildDirtPath() {
    // Top-left dirt cluster
    grid[3][12] = grid[3][13] = grid[3][15] = grid[3][18] = grid[3][22] = Tile(TileType::Dirt);

    // Path continues downward
    grid[4][13] = grid[4][19] = grid[4][20] = Tile(TileType::Dirt);
    grid[5][12] = Tile(TileType::Dirt);
    grid[6][13] = Tile(TileType::Dirt);
    grid[7][12] = Tile(TileType::Dirt);

    // Middle section weaving around water
    grid[8][13] = Tile(TileType::Dirt);
    grid[9][13] = grid[9][14] = Tile(TileType::Dirt);
    grid[10][13] = Tile(TileType::Dirt);
    grid[11][14] = Tile(TileType::Dirt);
    grid[12][13] = grid[12][14] = Tile(TileType::Dirt);
    grid[13][13] = Tile(TileType::Dirt);
    grid[14][14] = Tile(TileType::Dirt);
    grid[15][13] = grid[15][14] = Tile(TileType::Dirt);
    grid[16][13] = Tile(TileType::Dirt);

    // Lower vertical line of dirt
    grid[17][12] = Tile(TileType::Dirt);
    grid[18][13] = Tile(TileType::Dirt);
    grid[19][12] = Tile(TileType::Dirt);
    grid[20][13] = Tile(TileType::Dirt);
    grid[21][12] = Tile(TileType::Dirt);
    grid[22][13] = Tile(TileType::Dirt);
    grid[23][12] = Tile(TileType::Dirt);
    grid[24][13] = Tile(TileType::Dirt);
}

/**
 * Builds the lake on the left side of the map
 */
void Map::BuildWaterArea()
{
    // Top and bottom water rows
    for (int x = 3; x < 8; x++) grid[8][x] = Tile(TileType::Water);
    for (int x = 2; x < 10; x++) grid[9][x] = Tile(TileType::Water);

    // Mid-section water bands
    for (int x = 1; x < 11; x++) {
        grid[10][x] = Tile(TileType::Water);
        grid[11][x] = Tile(TileType::Water);
        grid[12][x] = Tile(TileType::Water);
        grid[13][x] = Tile(TileType::Water);
        grid[14][x] = Tile(TileType::Water);
    }

    // Bottom curve of the lake
    for (int x = 2; x < 10; x++) grid[15][x] = Tile(TileType::Water);
    for (int x = 3; x < 8; x++) grid[16][x] = Tile(TileType::Water);
}


   // Displays the entire map grid to the console.
void Map::Display() const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x].Display();
        }
        std::cout << std::endl;
    }
}

void Map::DisplayWithPlayer(int playerX, int playerY) const
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            const Tile& tile = grid[y][x];
            UI::Reset();
            UI::SetColor(tile.getColorCode()); // use tile color (grass, dirt, etc.)

            if (x == playerX && y == playerY) {
                std::cout << "P"; // player
            }
            else if (tile.getItem() != nullptr) {
                std::cout << "I"; // item
            }
            else {
                tile.Display(); // normal terrain
            }

            UI::Reset();
        }
        std::cout << std::endl;
    }

    UI::Reset(); // safeguard after all rendering
}

Tile& Map::getTilePos(int x, int y)
{
    if (y < 0) y = 0;
    if (x < 0) x = 0;
    if (y >= height) y = height - 1;
    if (x >= width)  x = width - 1;

    return grid[y][x];
}
