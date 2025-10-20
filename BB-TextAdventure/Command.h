#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include "Verb.h"
#include "Noun.h"

/*
* Scope: Represents a single command entered by the player.
*		 Stores the verb (action), and noun (target).
*
*/

class Command
{
private:

	// The action the player wants to perform
	Verb commandVerb;

	// The target of the action
	Noun commandNoun;

public:

	// Initializes the command with a verb & noun
	Command(Verb verb, Noun noun);

	// Returns the stored verb
	Verb getVerb();

	// Returns the stored noun
	Noun getNoun();

	// Return true if the verb is unknown
	bool isUnknown();

	// Return true if the noun is a valid direction
	bool hasDirection();

};

#endif 