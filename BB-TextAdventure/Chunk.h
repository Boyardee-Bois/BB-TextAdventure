#pragma once
#pragma once
#include "Tile.h"
#include <vector>

//Chunks will represent the areas of our map that contain smaller tiles
class Chunk {
private:
    static const int ROW_SIZE = 5;
    static const int COLUMN_SIZE = 5;
    std::vector<std::vector<Tile>> tiles;

public:
    Chunk();
    void SetTileAt(int x, int y, Tile tile);
    Tile& GetTileAt(int x, int y);
    void DisplayChunk() const;
};

