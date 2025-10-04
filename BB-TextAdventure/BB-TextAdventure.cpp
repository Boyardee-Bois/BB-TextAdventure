#include "Room.h"

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

class Movement {
public:
    //Creates directions of movement and adds +1 to a direction everytime it's entered
    char Movement_Counter(char move_count) {
        int move_up = 0, move_down = 0, move_left = 0, move_right = 0;
        char direction;
        bool h = true; //temp line for testing
        while (h = true)
        {
            cout << "Enter a direction: \n";
            cin >> direction;
            if (direction == 'W' || direction == 'w') {
                move_up++;
                return direction;
            }
            if (direction == 'S' || direction == 's') {
                move_down++;
                return direction;
            }
            if (direction == 'A' || direction == 'a') {
                move_left++;
                return direction;
            }
            if (direction == 'D' || direction == 'd') {
                move_right++;
                return direction;
            }
            else {
                cout << "Invalid input. Please enter a proper direction.\n";
            }
            h = false; //temp
        }
        return move_count;
    }


    /*Uses Movement_Counter to get player X and Y position
    X and Y will initially be 0 and work like:
    For X: Add move_right, minus move_left
    For Y: Add move_up, minus move_down
    */
    char Player_Position(char pos) {
        return pos;
    }
    /*
    char CtrlZ_avoid() {
        while (true) {
            cout << "Invalid input.Please enter a proper direction.\n";
            if (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    */
};

int main()
{
    Movement m;
    char move = m.Movement_Counter('x'); //temp line for test
    
    //Test line for room
    Room testRoom("Lab", "A quiet research area filled with strange equipment.");
    testRoom.printRoomInformation();

}
