#pragma once
#include <iostream>
#include "UI.h"

enum class TileType { Grass, Water, Dirt, Stone };

class Tile {
private:
    TileType type;

public:
    Tile(TileType t = TileType::Grass);
    void Display() const;
};
