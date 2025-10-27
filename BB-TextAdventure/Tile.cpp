#include "Tile.h"
#include "UI.h"
#include <iostream>
using namespace std;



Tile::Tile(TileType t) : type(t) {} //Default constructor

//Displays the color of each assigned tile
void Tile::Display() const {
    switch (type) {
    case TileType::Grass:
        UI::SetColor(Green); 
        std::cout << "  ";
        UI::Reset();
        break;
    case TileType::Water:
        UI::SetColor(Blue); 
        std::cout << "  ";
        UI::Reset();
        break;
    case TileType::Dirt:
        UI::SetColor(Brown);
        std::cout << "  ";
        UI::Reset();
        break;
    case TileType::Stone:
        UI::SetColor(Gray); 
        std::cout << "  ";
        UI::Reset();
        break;
    }
}

//Returns current type of tile terrain
TileType Tile::GetType() const
{
    return type;
}

//Updates that tile terrain
void Tile::SetType(TileType t)
{
    type = t; 
}

// For test purposes - return a character map for each Tile type
//Displays the color of each assigned tile
char Tile::mapTileToChar() const {
    char characterMapping;
    switch (type) {
    case TileType::Grass:
        characterMapping = 'G';
        break;
    case TileType::Water:
        characterMapping = 'W';
        break;
    case TileType::Dirt:
        characterMapping = 'D';
        break;
    case TileType::Stone:
        characterMapping = 'S';
        break;
    default:
        characterMapping = '?';
    }
    return characterMapping;
}


