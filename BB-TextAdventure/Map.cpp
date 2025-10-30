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
    

   grid[13][20].setItem(questItem); 
    
}

   // Builds the stone region in the top left of the map
void Map::BuildStoneRegion() {
    // Smaller rectangular lab near top-left of map
    int startX = 2;   // left edge
    int startY = 2;   // top edge
    int labWidth = 7;
    int labHeight = 4;

    // --- Outer lab structure (Stone walls) ---
    for (int y = startY; y < startY + labHeight; y++) {
        for (int x = startX; x < startX + labWidth; x++) {
            grid[y][x] = Tile(TileType::Stone);
        }
    }

    // --- Roof lights: blue and red accents ---
    grid[startY][startX + 2] = Tile(TileType::Water);  // blue light
    grid[startY][startX + 3] = Tile(TileType::Water);
    grid[startY][startX + 5] = Tile(TileType::RedLight);   // red light

    // --- Doorway at bottom center ---
    int doorX = startX + labWidth / 2;
    int doorY = startY + labHeight - 1;
    grid[doorY][doorX] = Tile(TileType::Grass); // entrance (door)
}



/**
 * Builds our dirt path 
 */void Map::BuildDirtPath() {
 // Top-left dirt cluster (shifted left)
     grid[3][10] = grid[3][11] = grid[3][13] = grid[3][15] = grid[3][17] = Tile(TileType::Dirt);

     // Path continues downward
     grid[4][11] = grid[4][13] = grid[4][15] = Tile(TileType::Dirt);
     grid[5][10] = Tile(TileType::Dirt);
     grid[6][11] = Tile(TileType::Dirt);
     grid[7][10] = Tile(TileType::Dirt);

     // Middle section weaving down
     grid[8][11] = Tile(TileType::Dirt);
     grid[9][11] = grid[9][12] = Tile(TileType::Dirt);
     grid[10][11] = Tile(TileType::Dirt);
     grid[11][12] = Tile(TileType::Dirt);
     grid[12][11] = grid[12][12] = Tile(TileType::Dirt);
     grid[13][11] = Tile(TileType::Dirt);
     grid[14][12] = Tile(TileType::Dirt);
     grid[15][11] = grid[15][12] = Tile(TileType::Dirt);
     grid[16][11] = Tile(TileType::Dirt);

     // Lower vertical stretch
     grid[17][10] = Tile(TileType::Dirt);
     grid[18][11] = Tile(TileType::Dirt);
     grid[19][10] = Tile(TileType::Dirt);
     grid[20][11] = Tile(TileType::Dirt);
     grid[21][10] = Tile(TileType::Dirt);
     grid[22][11] = Tile(TileType::Dirt);
     grid[23][10] = Tile(TileType::Dirt);
     grid[24][11] = Tile(TileType::Dirt);
 }

/**
 * Builds the lake on the left side of the map
 */
 void Map::BuildWaterArea()
 {
     int startX = 14;  // right side
     int startY = 15;  // lower area

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
            int colorCode = tile.getColorCode();

            // Set tile color first (background color)
            UI::SetColor(colorCode);

            if (x == playerX && y == playerY) {
                // Draw player icon ON TOP of tile color
                std::cout << "P ";
            }
            else if (tile.getItem() != nullptr) {
                // Item sits on its tile color too
                std::cout << "@ ";
            }
            /**
            * @brief Displays NPC on map
            */
            else if (x == 10 && y == 7) {
                x = npc_xcoord;
                y = npc_ycoord;
                cout << "N";
                x = 10;
                y = 7;
                UI::Reset();
            }
            else {
                // Default tile display (terrain)
                tile.Display();
               
            }

            // Reset AFTER each tile
            UI::Reset();
        }
        std::cout << std::endl;
    }

    UI::Reset(); // safety reset
}


Tile& Map::getTilePos(int x, int y)
{
    if (y < 0) y = 0;
    if (x < 0) x = 0;
    if (y >= height) y = height - 1;
    if (x >= width)  x = width - 1;

    return grid[y][x];
}
/*
void Map::DisplayWithNPC(int npc_xcoord, int npc_ycoord) const
{
    return;
}
*/