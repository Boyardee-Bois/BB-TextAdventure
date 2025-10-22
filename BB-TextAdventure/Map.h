#pragma once
#include <vector>
#include "Tile.h"

class Map
{
private:
    int width;
    int height;
    std::vector<std::vector<Tile>> grid; // 2D grid of tiles

public:
    Map();         // Default constructor
    void Display() const;  // Prints the map to console
};
