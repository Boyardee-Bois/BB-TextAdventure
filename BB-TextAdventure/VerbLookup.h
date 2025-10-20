#pragma once

#include "Verb.h"
#include "Noun.h"
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

/*
* Scope: This class stores all valid command words
*		 and provides lookup fuctions to interpret
*		 the players input.
*
*/

class VerbLookup
{
private:

	unordered_map<string, Verb> validVerb;

public:

	// Constructor: Fills the map with known verbs.
	VerbLookup();

	// Look up a word and return a verb value
	Verb  getVerb(string& input);

	// Returns true if the word is a recognized verb
	bool isVerb(string& input);

	// Prints all available verbs
	void showAllVerbs();
};
