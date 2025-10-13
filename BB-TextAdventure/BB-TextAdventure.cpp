#include <iostream>
#include "UI.h"
#include "Player.h"
#include "Room.h"
#include "Item.h"

using namespace std; 


int main()
{
	UI Interface;
	Interface.GameIntro();

	Room startRoom("Lab", "You find yourself in a dimly lit lab with scattered papers.");
	Room hallwayRoom("Hallway", "You see a long hallway leading to the outdoors.");

	startRoom.addExit("North", &hallwayRoom);

	Player player(&startRoom);

	cout << "You being in:" << player.getCurrentRoom()->getRoomName() << endl;
	
	player.Movement_Counter();
}
