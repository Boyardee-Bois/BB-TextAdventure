#include "VerbLookup.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/*
*  A static command list that will populate the command word constructor.
*  This list can be expanded as needed for future updates.
* 
*/
static const vector<pair<string, Verb>> VERB_LIST = {
	
	{"go", Verb::Go},
	{"help", Verb::Help},
	{"quit", Verb::Quit}
};

/*
* Populate the command word list based on the defined valid commands
* in COMMAND_LIST (available commands to the player)
*/
VerbLookup::VerbLookup()
{
	for (auto& input : VERB_LIST)
	{
		const string& word = input.first;

		Verb verb = input.second;

		if (verb != Verb::Unknown)
		{
			validVerb[word] = verb;
		}
	}
}

/*
* Takes the players and checks if 
* it is in the validCommand map
* 
* If found returns the Verb value
* otherwise returns unknown command
*/
Verb VerbLookup::getVerb(string& input)
{
	auto iterator = validVerb.find(input);

	if (iterator != validVerb.end())
	{
		return iterator->second;
	}
	else
	{
		return Verb::Unknown;
	}
}

/*
* Returns true if the players input is
* a match in the valid command map
*/
bool VerbLookup::isVerb(string& input)
{
	return validVerb.find(input) != validVerb.end();
}

/*
* Prints all currently implemented commands to the console
* 
* This is used to display the commands for the player
*/
void VerbLookup::showAllVerbs()
{
	for (const auto& pair : validVerb)
	{
		cout << pair.first << " ";
	}

	cout << endl;
}