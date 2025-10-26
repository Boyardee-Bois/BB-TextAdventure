#pragma once
#include <iostream>
#include "UI.h"

enum class TileType { Grass, Stone, Dirt, Water };

class Tile {
private:
    TileType type; // Stores the type of tile (ie terrain).

public:
    Tile(TileType t = TileType::Grass);
    void Display() const;
    TileType GetType() const;
    void SetType(TileType t);
};
