/**
 * @file VerbLookup.cpp
 * @brief Implements the VerbLookup class for mapping input text to Verb values.
 *
 * @details
 * Populates a map of valid verbs from a list and
 * provides lookup, validation, and listing utilities for use by the parser.
 */
#include "VerbLookup.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * @brief Source list of recognized verbs and their enum values.
 * 
 * @details Extend this list to add new verbs to the game.
 *
 * @note The string in the pair {"word", Verb::Word} NEEDS TO BE LOWERCASE!
 */
static const vector<pair<string, Verb>> VERB_LIST = {

	// Movement
	{"go", Verb::Go},
	{"move", Verb::Go},
	{"walk", Verb::Go},

	{"interact", Verb::Interact},
	{"talk", Verb::Interact},
	{"speak", Verb::Interact},

	// Interaction
	{"pickup", Verb::Pickup},
	{"grab", Verb::Pickup},
	{"take", Verb::Pickup},
	{"collect", Verb::Pickup},
	{"take", Verb::Pickup},

	// Combat
	{"attack", Verb::Attack},
	{"fight", Verb::Attack},
	{"hit", Verb::Attack},
	{"strike", Verb::Attack},

	// Inventory
	{"open", Verb::Open},
	{"view", Verb::Open},
	{"show", Verb::Open},

	// System
	{"help", Verb::Help},
	{"quit", Verb::Quit},
	{"exit", Verb::Quit}
};

/**
* @brief Populates the verb map from the list of verbs.
* @details Ignores Verb::Unknown entries if present.
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

/**
 * @brief Returns the Verb corresponding to the input text.
 * @param input Player entered verb.
 * @return Matching Verb, or Verb::Unknown if not found.
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

/**
 * @brief Checks whether the input text is a recognized verb.
 * @param input Player entered verb.
 * @return True if recognized, false otherwise.
 */
bool VerbLookup::isVerb(string& input)
{
	return validVerb.find(input) != validVerb.end();
}

/**
 * @brief Prints all recognized verbs on one line.
 * @details Useful for help output or debugging.
 */
void VerbLookup::showAllVerbs()
{
	for (const auto& pair : validVerb)
	{
		cout << pair.first << " ";
	}

	cout << endl;
}