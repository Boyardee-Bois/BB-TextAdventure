/*
* @file UI.h
* @breif Console UI utilities for rendering, prompts, and styling.
* 
* @details
* Responsibilities:
*	- Printing Static Screens
*	- Console formatting
*	- Terminal helpers like clear, pause, reset.
* 
* Do not include 
*	- Gamestate
*	- Map related jobs
*	- Tiling
*/
#pragma once


#include <iostream>
using namespace std;

/**
 * @class UI
 * @brief Presentation helper for console output.
 *
 * @details
 * Provides static methods for common UI tasks without owning game state.
 * Callers decide *what* to render; UI decides *how* to print/format.
 */
class UI
{
public:

	/** @brief Print the title screen banner. */
	static void TitleScreen();

	/** @brief Print the narrative intro and handle basic start/help prompt. */
	static bool GameIntro();

	/** @brief Print the help menu. */
	static void HelpMenu();

	/** @brief Enable Windows console virtual terminal sequences (ANSI colors). */
	static void EnableColor();

	/**
	 * @brief Set background color using 0–255 ANSI 8-bit color code.
	 * @param color 8-bit color code.
	 */
	static void SetColor(int color);

	/** @brief Reset console styles (color, attributes). */
	static void Reset();

	/**
	 * @brief Print the current objective line.
	 * @param objective Text of the current objective.
	 */
	void DisplayObjective(const string& objective);

	/** @brief Print a visible section separator line. */
	static void SectionSeperator();
	
	/** @brief Pause until user input (Windows-friendly). */
	static void Pause();

	/** @brief Clear the console screen. */
	static void Clear();


private:

	/** @brief Print a small title header used within other screens. */
	static void GameTitle();

	/** @brief Handle intro menu input loop; returns true when user starts. */
	static bool GameIntroParser();

};
