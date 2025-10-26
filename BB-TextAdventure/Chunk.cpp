#include "Chunk.h"
#include <iostream>


//Default constructor
Chunk::Chunk() {
    tiles = std::vector<std::vector<Tile>>(ROW_SIZE, std::vector<Tile>(COLUMN_SIZE, Tile(TileType::Grass)));
}

//Updates the tile position to a new value
void Chunk::SetTileAt(int x, int y, Tile tile) {
    tiles[y][x] = tile;
}

//Returns a that tile position 
Tile& Chunk::GetTileAt(int x, int y) {
    return tiles[y][x];
}

//Displays all tiles within a given chunk with the correct color (because of .Display())
void Chunk::DisplayChunk() const {
    for (int y = 0; y < ROW_SIZE; y++) {
        for (int x = 0; x < COLUMN_SIZE; x++) {
            tiles[y][x].Display();
        }
        std::cout << std::endl;
    }
}
