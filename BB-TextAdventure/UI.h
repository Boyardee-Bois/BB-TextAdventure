#pragma once
#ifndef UI_H
#define UI_H


#include <iostream>
using namespace std;

/*
Scope:
Implement files for OOP to allow Messages to be displayed in the game
Create a class called Messages which will handle all messages and pop-ups in game.
This will handle all output text for the game (UI stuff, messages, backstory, and future dialog).
 */

//This class should hold every display message for the UI
class UI
{
public:

	static void GameIntro();
	static void HelpMenu();
	static bool GameIntroParser();

	//Will have more room to add more messages ie. error messages and more


private:
	static void SectionSeperator();
	static void GameTitle();

};



#endif 

