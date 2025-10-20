#include "Verb.h"
#include "Noun.h"
#include "Command.h"

using namespace std;

Command::Command(Verb verb, Noun noun)
{
	commandVerb = verb;
	commandNoun = noun;

}

// Returns the stored verb
Verb Command::getVerb()
{
	return commandVerb;
}

// Returns the stored noun
Noun Command::getNoun()
{
	return commandNoun;
}

// Return true if the verb is unknown
bool Command::isUnknown()
{
	return commandVerb == Verb::Unknown;
}

// Return true if the noun is a valid direction
bool Command::hasDirection()
{
    switch (commandNoun) 
    {
    case Noun::North:
    case Noun::South:
    case Noun::East:
    case Noun::West:
        return true;
    default:
        return false;
    }
}