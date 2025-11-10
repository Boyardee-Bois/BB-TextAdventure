/**
 * @file UI.cpp
 * @brief Implements all console UI functions for Project:Chronoscape.
 *
 * @details
 * Provides output formatting, title screen, intro text, help menus,
 * and utility functions for pausing and clearing the terminal.
 *
 * @note
 * The UI class should not directly access or manipulate game logic.
 */
#include "UI.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

/**
 * @brief Prints the main project title banner.
 *
 * @details
 * Used within other UI functions like TitleScreen() and GameIntro().
 */
void UI::GameTitle()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10); // greenish


	cout << R"(              ________________________________________________
            /                                                 \
           |    _________________________________________      |
           |   |                                          |    |
           |   |             PROJECT CHRONOSCAPE          |    |
           |   |                                          |    |
           |   |      C:\> Initializing time systems...   |    |
           |   |      Loading assets...                   |    |
           |   |      Establishing chrono-link...         |    |
           |   |      Ready.                              |    |
           |   |                                          |    |
           |   |__________________________________________|    |
           |                                                   |
            \_________________________________________________/
                   \___________________________________/
                ___________________________________________
             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_
          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_
       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_
    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_
 _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_
:-------------------------------------------------------------------------:
`---._.-------------------------------------------------------------._.---'
)" << endl;

	SetConsoleTextAttribute(hConsole, 7); // reset to white

	Pause();
}

/**
 * @brief Displays the title screen.
 *
 * @details
 * Clears the screen, prints the title banner, and shows available options.
 * Called at the beginning of the game or when returning from help.
 */
void UI::TitleScreen()
{
	Clear();

	EnableColor();

	GameTitle();

	cout << "A time-split text adventure.\n";

	SectionSeperator();

	//cout << "[P] Play    [H] Help    [Q] Quit\n";

	Reset();
}

/**
 * @brief Prints a line separator to the console.
 */
void UI::SectionSeperator()
{
	cout << "\n======================================================\n";
}

/**
 * @brief Displays the story introduction and prompts the player.
 *
 * @return True if player chooses to start the game; false if they quit.
 */
bool UI::GameIntro()
{
	Clear();

	GameTitle();

	cout << "\nIn the distant future, you're tasked with working on humanity's most important Mission yet..."
		 << + "Project Chronoscape.The breakthrough in time travel\n\n";

	cout << "Your primary obstacle isn't the science, rather it's the ego of your co-worker Dr. Jay Maximoff, your brilliant but reckless rival."  
		 << + "He craves absolute control over the anomaly and views your measured approach as cowardice.\n\n";

	cout << "Behind your back, Jay overrides the safety protocols and initiates an unauthorized high-energy sequence."
		 << + "He was certain his calculations for the Tachyonic Cascade were flawless.They were not.\n\n";

	cout << "The Singularity explodes. The lab ruptures."
		 << + "A blinding, deafening shockwave tears through your reality, followed by the terrifying sensation of your molecular structure being stretched thin.\n\n";

	cout << "When the light fades, the air is thick, the humidity crushing, and the familiar scent of ozone is replaced by something ancient and savage.\n\n";

	cout << "You are alive. You are separated from Jay. And you are catastrophically out of time.\n";

	SectionSeperator();

	return GameIntroParser();
}

/**
 * @brief Displays the help menu with command instructions.
 *
 * @details
 * Lists available commands and their use. Waits for user input
 * before returning to the caller.
 */
void UI::HelpMenu()
{
	Clear();

	cout << "HELP MENU\n";

	SectionSeperator();

	cout << "Use command verbs + nouns, e.g. 'go north', 'open inventory'.\n";

	SectionSeperator();

	cout << "Movement:'go north/south/east/west' or 'go W/A/S/D'\n";

	cout << "Open inventory: 'open inventory'\n";

	cout << "Interact: 'interact npc' or 'pickup item'\n";

	cout << "Attack: 'attack enemy' Use  '1 or 2' for light/heavy attack\n";

	cout << "Quit: 'quit'\n";

	SectionSeperator();

	Pause();
}


/**
 * @brief Parses and processes player input during intro.
 *
 * @return True if the user selects Play; false if they select Quit.
 */
bool UI::GameIntroParser()
{
	while (true)
	{
		cout << "\n[P] Play  [H] Help  [Q] Quit > ";
		string response;

		if (!getline(cin >> ws, response))
		{
			cin.clear();
			cout << "\nInvalid input.\n";
			continue;
		}

		if (response.size() == 1)
		{
			char c = response[0];

			if (c == 'P' || c == 'p')
				return true;  // start game

			if (c == 'H' || c == 'h')
			{
				HelpMenu();
				TitleScreen();
				continue;
			}

			if (c == 'Q' || c == 'q')
				return false; // quit game
		}

		cout << "Enter P, H, or Q.\n";
	}
}


/**
 * @brief Enables ANSI color codes on Windows terminals.
 *
 * @details
 * Uses WinAPI functions to activate virtual terminal processing
 * which allows escape sequences for colored output.
 */
void UI::EnableColor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	if (GetConsoleMode(hOut, &mode))
	{
		mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, mode);
	}
}

/**
 * @brief Sets console background color using ANSI 8 bit code.
 * @param color 8 bit color code value.
 */
void UI::SetColor(int color)
{
	cout << "\033[48;5;" << color << "m" << flush;
}

/**
 * @brief Resets all console color and text attributes to defaults.
 */
void UI::Reset()
{
	cout << "\033[0m";
}

/**
 * @brief Displays the player's current objective.
 * @param objective String description of the active objective.
 */
void UI::DisplayObjective(const string& objective)
{
	cout << "Objective: " << objective << "\n";
}

/**
 * @brief Pauses execution until user presses a key.
 *
 * @details
 * Wrapper for system("pause") to maintain consistent UI behavior.
 */
void UI::Pause()
{
	system("pause");
}

/**
 * @brief Clears the console screen.
 *
 * @details
 * Wrapper for system("cls") on Windows.
 */
void UI::Clear()
{
	system("cls");
}