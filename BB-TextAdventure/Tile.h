#pragma once
#include <iostream>
#include "UI.h"
#include "Item.h"

enum class TileType { Grass, Stone, Dirt, Water };

class Tile {
private:
    TileType type; // Stores the type of tile (ie terrain).

public:
    Tile(TileType t = TileType::Grass);
    int getColorCode() const;
    void Display() const;
    TileType GetType() const;
    void SetType(TileType t);
    void Display();
    Item* gameItem; 
    void setItem(Item* item); 
    Item* getItem() const; 
    void removeItem(); 
    
};
