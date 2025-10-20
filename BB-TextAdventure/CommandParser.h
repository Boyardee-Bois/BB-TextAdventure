#pragma once

#include "Command.h"
#include "VerbLookup.h"
#include "NounLookup.h"
#include <string>
#include <vector>

using namespace std;

/*
* Scope: This class reads player input, tokenizes it,
*		 and uses the lookup tables to create a valid command
*/

class CommandParser
{
private:

	VerbLookup verbs;
	NounLookup nouns;

	// Helper fuction to split a line into a vector of individual words
	vector<string> splitLine(const string& inputLine);

public:

	// Constructor (Initialize the verb/noun lookups)
	CommandParser();

	// Get a command from the player
	Command getCommand();

	// Display all available verbs (from VerbLookup)
	void showAllVerbs();
};