#include "Tile.h"
#include "UI.h"
#include <iostream>
using namespace std; 


/*
* Class: Tile
* --------------------------------------------
* Represents the individual square that the player will walk on (if allowed)
* Each Tile has:
*    A type (TileType)
*    A color (SetColor)
*    The ability to be reset if need be (ie entering a new 
*/



Tile::Tile(TileType t) : type(t) {}

void Tile::Display() const {
    switch (type) {
    case TileType::Grass:
        UI::SetColor(Green); // green
        std::cout << "  ";
        UI::Reset();
        break;
    case TileType::Water:
        UI::SetColor(Blue); // blue
        std::cout << "  ";
        UI::Reset();
        break;
    case TileType::Dirt:
        UI::SetColor(Brown); // brownish
        std::cout << "  ";
        UI::Reset();
        break;
    case TileType::Stone:
        UI::SetColor(Gray); // gray
        std::cout << "  ";
        UI::Reset();
        break;
    }
}

