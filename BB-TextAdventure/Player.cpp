#include "Player.h"
#include "Room.h"

#include <iostream>
#include <limits>
#include <cstdio>
#include <string>
using namespace std;


int x_coord = 0;
int y_coord = 0;

//Creates directions of movement and adds +1 to a direction everytime it's entered
void Player::Movement_Counter() 
{
	char direction;

	bool h = false;

	while (h == false) {
		cout << "Enter direction (w/a/s/d): ";
		cin >> direction;
		switch (direction) {
		case 'w':
			cout << "Going North..." << endl;
			h = true;
			y_coord++;
			cout << "Coordinates (x,y): " << x_coord << ", " << y_coord << endl;
			break;
		case 'a':
			cout << "Going West..." << endl;
			h = true;
			x_coord--;
			cout << "Coordinates (x,y): " << x_coord << ", " << y_coord << endl;
			break;
		case 's':
			cout << "Going South..." << endl;
			h = true;
			y_coord--;
			cout << "Coordinates (x,y): " << x_coord << ", " << y_coord << endl;
			break;
		case 'd':
			cout << "Going East..." << endl;
			h = true;
			x_coord++;
			cout << "Coordinates (x,y): " << x_coord << ", " << y_coord << endl;
			break;
		default:
			cout << "Not a correct input. Please enter w/a/s/d." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}


/*Uses Movement_Counter to get player X and Y position
X and Y will initially be 0 and work like:
For X: Add move_right, minus move_left
For Y: Add move_up, minus move_down
*/

//Previous room coordinates are reset
void Player::Reset_Coordinates(Room* newRoom) 
{
	Room* currentRoom;
	currentRoom = newRoom;
	x_coord = 0;
	y_coord = 0;
}