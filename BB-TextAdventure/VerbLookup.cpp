#include "VerbLookup.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/*
*  A static verb list that will populate the verb word constructor.
*  This list can be expanded as needed for future updates.
*
*/
static const vector<pair<string, Verb>> VERB_LIST = {

	{"go", Verb::Go},
	{"help", Verb::Help},
	{"quit", Verb::Quit}
};
/*
* Populate the verb word list based on the defined valid verbs (actions)
* in VERB_LIST (available verbs (actions) to the player)
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
* it is in the validVerb map
*
* If found returns the Verb value
* otherwise returns unknown
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
* a match in the valid verb (actions) map
*/
bool VerbLookup::isVerb(string& input)
{
	return validVerb.find(input) != validVerb.end();
}

/*
* Prints all currently implemented verbs (actions) to the console
*
* This is used to display the verbs (actions) for the player
*/
void VerbLookup::showAllVerbs()
{
	for (const auto& pair : validVerb)
	{
		cout << pair.first << " ";
	}

	cout << endl;
}