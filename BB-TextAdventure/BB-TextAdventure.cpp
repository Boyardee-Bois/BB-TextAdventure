#include "Room.h"
#include "Player.h"
#include "Player.cpp"
#include <iostream>
#include <limits>
#include <cstdio>
#include <string>
using namespace std;

/* To do
* Scope:
Requirements: Define the command for movement
Design: Design the text output for a successful move and for an invalid/blocked move.
Implementation:  Accept movement commands and update the player's location.
Validation: Test that the player can successfully move from the starting area to the lab and that attempting to move to an invalid location yields a clear error message.
Acceptance Criteria:
The game accepts a defined command (W,A,S,D) to move from the starting area to the lab.
After a successful move, the screen updates with the new position of the player on the map.
Attempting an invalid movement command results in a helpful error message (Ex. "You can't go that way.")
*/



int main()
{   
    //Test line for room and adding an exit
    Room labRoom("Lab", "A quiet research area filled with strange equipment.");
    Room wildernessRoom("Wilderness", "The great outdoors! There is a loud screech in the distance....");

    //Adding an exit in the north direction
    labRoom.addExit("North", &wildernessRoom);

    //Print the room information
    labRoom.printRoomInformation();

    PlayerMove move;
    move.Movement_Counter();
    move.Reset_Coordinates(nullptr);
    return 0;

}
