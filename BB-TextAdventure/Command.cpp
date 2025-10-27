/**
 * @file Command.cpp
 * @brief Implements the Command class used to represent a parsed player command.
 *
 * @details
 * Stores a Verb (the player's action) and a Noun (the object or direction of that action).
 * Created by the CommandParser after reading player input.
 * Used by other systems (like PlayerActionManager) to decide what action to perform.
 */
#include "Verb.h"
#include "Noun.h"
#include "Command.h"

using namespace std;

/**
 * @brief Constructs a Command object with a specified verb and noun.
 * 
 * @param verb The action part of the command.
 * 
 * @param noun The target or direction part of the command.
 */
Command::Command(Verb verb, Noun noun)
{
    commandVerb = verb;
    commandNoun = noun;

}

/**
 * @brief Returns the noun of this command.
 * 
 * @return The Noun representing the target or direction of the action.
 */
Verb Command::getVerb()
{
    return commandVerb;
}

/**
 * @brief Checks if the command verb is unknown.
 * 
 * @details
 * Used to detect unrecognized or incomplete commands entered by the player.
 *
 * @return True if the verb equals Verb::Unknown, otherwise false.
 */
Noun Command::getNoun()
{
    return commandNoun;
}

/**
 * @brief Checks if the command's verb is unknown.
 * 
 * @details Used to detect unrecognized or invalid input from the player.
 * 
 * @return True if the verb equals Verb::Unknown, otherwise false.
 */
bool Command::isUnknown()
{
    return commandVerb == Verb::Unknown;
}

/**
 * @brief Checks if the noun represents a valid movement direction.
 * 
 * @details
 * Used by the PlayerActionManager to validate movement commands before performing an action.
 * 
 * @return True if the noun corresponds to a direction (North, South, East, or West).
 */
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