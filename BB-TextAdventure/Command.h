/**
 * @file Command.h
 * @brief Defines the Command class, representing a parsed player command.
 *
 * @details
 * A single player command consisting of a Verb (action)
 * and an optional Noun (target or direction). 
 * Unknown values represent invalid or incomplete input.
 */
#pragma once

#include "Verb.h"
#include "Noun.h"

 /**
  * @class Command
  * @brief Represents a single parsed player command.
  *
  * @details
  * The Command class stores:
  * - Verb: The player's intended action.
  * - Noun: The object, target, or direction related to that action.
  *
  */
class Command
{
private:

	/** @brief The verb representing the player's intended action. */
	Verb commandVerb;

	/** @brief The noun representing the target or direction of the action. */
	Noun commandNoun;

public:

	/**
	 * @brief Constructs a Command with a specified verb and noun.
	 * @param verb The action part of the command.
	 * @param noun The target or direction part of the command.
	 */
	Command(Verb verb, Noun noun);

	/**
	 * @brief Returns the command's verb.
	 * @return The Verb associated with this command.
	 */
	Verb getVerb();

	/**
	 * @brief Returns the command' noun.
	 * @return The Noun associated with this command.
	 */
	Noun getNoun();

	/**
	 * @brief Checks if the command verb is unknown.
	 * @return True if the verb is Verb::Unknown, otherwise false.
	 */
	bool isUnknown();

	/**
	 * @brief Checks if the noun represents a valid movement direction.
	 * @return True if the noun is a directional input (north, south, east, west).
	 */
	bool hasDirection();
};