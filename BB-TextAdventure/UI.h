#pragma once
#ifndef UI_H
#define UI_H


#include <iostream>
using namespace std;

/*
Scope:
Implement files for OOP to allow Messages to be displayed in the game
Create a class called Messages which will handle all messages and pop-ups in game.
This will handle all output text for the game (UI stuff, messages, backstory, Map, and future dialog).
 */

//This class should hold every display message/Color for the UI and map

constexpr int Green = 34;   
constexpr int Blue = 27;   
constexpr int Brown = 94;  
constexpr int Gray = 240;   

class UI
{
public:

	static void GameIntro();
	static void HelpMenu();
	static void EnableColor();
	static void SetColor(int color);
	static void Reset();
	static void SectionSeperator();
	

	//Will have more room to add more messages ie. error messages and more


private:
	static void GameTitle();
	static bool GameIntroParser();

};



#endif 

