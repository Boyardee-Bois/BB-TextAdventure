#include "Player.h"
#include "Room.h"

#include <iostream>
#include <limits>
#include <cstdio>
#include <string>
using namespace std;

class PlayerMove
{
public:
    int x = 0;
    int y = 0;
    //Creates directions of movement and adds +1 to a direction everytime it's entered
    char Movement_Counter() {
        char direction;
        bool h = false; //temp line for testing
        while (h == false) {
            cout << "Enter direction (w/a/s/d): ";
            cin >> direction;
            switch (direction) {
            case 'w':
                cout << "Going North..." << endl;
                h = true;
                y++;
                break;
            case 'a':
                cout << "Going West..." << endl;
                h = true;
                x--;
                break;
            case 's':
                cout << "Going South..." << endl;
                h = true;
                y--;
                break;
            case 'd':
                cout << "Going East..." << endl;
                h = true;
                x++;
                break;
            default:
                cout << "Not a correct input. Please enter w/a/s/d." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        return 0;
    }


    /*Uses Movement_Counter to get player X and Y position
    X and Y will initially be 0 and work like:
    For X: Add move_right, minus move_left
    For Y: Add move_up, minus move_down
    */
    void Reset_Coordinates(Room* newRoom) {
        Room* currentRoom;
        currentRoom = newRoom;
        x = 0;
        y = 0;
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