#include "Tile.h"
#include "UI.h"
#include <iostream>
using namespace std;


Tile::Tile(TileType t) : type(t)
{
   gameItem = nullptr;
 
}


int Tile::getColorCode() const 
{
    switch (type) {
    case TileType::Grass: return Green;
    case TileType::Water: return Blue;
    case TileType::Dirt:  return Brown;
    case TileType::Stone: return Gray;
    case TileType::RedLight: return Red; 

    default: return Green;
    }
}




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
    case TileType::RedLight:
        UI::SetColor(Red);
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

void Tile::Display()
{
    UI::SetColor(static_cast<int>(Gray));

    if (gameItem != nullptr)
    {
        cout << "I"; 
    }
    else
    {
         UI::SetColor(Green); 
    }

}

void Tile::setItem(Item* item)
{
    gameItem = item; 
}

Item* Tile::getItem() const
{
    return gameItem;
}

void Tile::removeItem()
{
    gameItem = nullptr; 
}

