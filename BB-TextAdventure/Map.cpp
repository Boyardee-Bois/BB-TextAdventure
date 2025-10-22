#include "Map.h"
#include "UI.h"
#include <iostream>

/*
* Class: Map
* --------------------------------------------
* Represents athe grid system in order for player to move around
* In this case will just need to print out a functioning grid/map
* Each Map object has:
*    A column
*	 A row
*    A Display feature (to actually see the map come together)
*
*/

//The entire map drawn out with characters representing each tile/block placed
//Currently set as a 25x25 but can scale 
Map::Map() {
    width = 25;
    height = 25;

    // Fill the grid with grass by default
    grid = std::vector<std::vector<Tile>>(height, std::vector<Tile>(width, Tile(TileType::Grass)));

    //For each row I need to output something other than grass, This calls those individual grid spaces with the color needed
   
    // Row 1
    for (int x = 0; x < width; x++) grid[0][x] = Tile(TileType::Grass);

    // Row 2
    for (int x = 3; x < 7; x++) grid[1][x] = Tile(TileType::Stone);

    // Row 3
    for (int x = 2; x < 8; x++) grid[2][x] = Tile(TileType::Stone);

    // Row 4
    for (int x = 2; x < 9; x++) grid[3][x] = Tile(TileType::Stone);
    grid[3][12] = Tile(TileType::Dirt);
    grid[3][13] = Tile(TileType::Dirt);
    grid[3][15] = Tile(TileType::Dirt);
    grid[3][18] = Tile(TileType::Dirt);
    grid[3][22] = Tile(TileType::Dirt);

    // Row 5
    grid[4][13] = Tile(TileType::Dirt);
    grid[4][19] = Tile(TileType::Dirt);
    grid[4][20] = Tile(TileType::Dirt);

    // Row 6
    grid[5][12] = Tile(TileType::Dirt);

    // Row 7
    grid[6][13] = Tile(TileType::Dirt);

    // Row 8
    grid[7][12] = Tile(TileType::Dirt);

    // Row 9
    for (int x = 3; x < 8; x++) grid[8][x] = Tile(TileType::Water);
    grid[8][13] = Tile(TileType::Dirt);

    // Row 10
    for (int x = 2; x < 10; x++) grid[9][x] = Tile(TileType::Water);
    grid[9][13] = Tile(TileType::Dirt);
    grid[9][14] = Tile(TileType::Dirt);

    // Row 11
    for (int x = 1; x < 11; x++) grid[10][x] = Tile(TileType::Water);
    grid[10][13] = Tile(TileType::Dirt);

    // Row 12
    for (int x = 1; x < 11; x++) grid[11][x] = Tile(TileType::Water);
    grid[11][14] = Tile(TileType::Dirt);

    // Row 13
    for (int x = 1; x < 11; x++) grid[12][x] = Tile(TileType::Water);
    grid[12][13] = Tile(TileType::Dirt);
    grid[12][14] = Tile(TileType::Dirt);

    // Row 14
    for (int x = 1; x < 11; x++) grid[13][x] = Tile(TileType::Water);
    grid[13][13] = Tile(TileType::Dirt);

    // Row 15
    for (int x = 1; x < 11; x++) grid[14][x] = Tile(TileType::Water);
    grid[14][14] = Tile(TileType::Dirt);

    // Row 16
    for (int x = 2; x < 10; x++) grid[15][x] = Tile(TileType::Water);
    grid[15][13] = Tile(TileType::Dirt);
    grid[15][14] = Tile(TileType::Dirt);

    // Row 17
    for (int x = 3; x < 8; x++) grid[16][x] = Tile(TileType::Water);
    grid[16][13] = Tile(TileType::Dirt);

    // Row 18
    grid[17][12] = Tile(TileType::Dirt);

    // Row 19
    grid[18][13] = Tile(TileType::Dirt);

    // Row 20
    grid[19][12] = Tile(TileType::Dirt);

    // Row 21
    grid[20][13] = Tile(TileType::Dirt);

    // Row 22
    grid[21][12] = Tile(TileType::Dirt);
    
    // Row 23
    grid[22][13] = Tile(TileType::Dirt);

    // Row 24
    grid[23][12] = Tile(TileType::Dirt);

    // Row 25
    grid[24][13] = Tile(TileType::Dirt);
}



// Displays the entire map in the console
void Map::Display() const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x].Display();
        }
        std::cout << std::endl;
    }
}
