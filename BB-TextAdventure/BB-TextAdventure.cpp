#include <iostream>
#include "UI.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "Tile.h"
#include <vector>
#include "Map.h"

using namespace std; 


int main()
{

	UI Interface;
	Map world; // Create our map


	Interface.GameIntro();
	Interface.EnableColor();
	world.Display();
	Interface.Reset();
	return 0;



	/*
	Room startRoom("Lab", "You find yourself in a dimly lit lab with scattered papers.");
	Room hallwayRoom("Hallway", "You see a long hallway leading to the outdoors.");

	Item testItem("Flux Capacitor", "Used to for a time machine");
	testItem.printItemInformation();

	startRoom.addExit("North", &hallwayRoom);

	Player player(&startRoom);

	cout << "You being in:" << player.getCurrentRoom()->getRoomName() << endl;
	
	player.Movement_Counter();*/
}
