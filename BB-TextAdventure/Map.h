#pragma once
#include <vector>
#include "Tile.h"
#include "Chunk.h"


//Shows the entire grid with each individual tile
class Map {
private:
    int width;   // should be constant & possible all in upper case
    int height;  //    same
    std::vector<std::vector<Tile>> grid; //2D grid of all tiles in said map
    void BuildStoneRegion();  // Creates the upper stone area
    void BuildDirtPath();     // Lays out the dirt trail/path
    void BuildWaterArea();    // Fills in the central water zone

public:
    Map(); //builds said map
    void Display() const; //Display map function to actually see everything
    void DisplayWithPlayer(int playerX, int playerY) const;

    // for unit testing
    Tile returnTile(int row, int column);

};
