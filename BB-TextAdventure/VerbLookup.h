/**
 * @file VerbLookup.h
 * @brief Defines the VerbLookup class used for mapping text input to verb enums.
 *
 * @details
 * The VerbLookup class maintains a dictionary of valid player verbs and
 * provides lookup, validation, and display functionality. It converts
 * normalized player input strings into corresponding Verb enum values.
 * Unknown or invalid inputs are handled gracefully as Verb::Unknown.
 */
#pragma once

#include "Verb.h"
#include "Noun.h"
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

/**
 * @class VerbLookup
 * @brief Provides lookup and validation for recognized command verbs.
 *
 * @details
 * Stores all valid command verbs in an unordered map.
 * Used by the CommandParser for player input mapping into
 * corresponding Verb enumeration values.
 * 
 */
class VerbLookup
{
private:

	/** @brief A hash map storing string:Verb key value pairs of valid commands. */
	unordered_map<string, Verb> validVerb;

public:

	/**
	 * @brief Constructs a VerbLookup instance and populates the valid verb map.
	 * @details Initializes the lookup table with all recognized verbs.
	 */
	VerbLookup();

	/**
	 * @brief Retrieves the Verb that corresponds to the given input string.
	 * @param input Reference to the player's entered command word.
	 * @return The matching Verb value, or Verb::Unknown if unrecognized.
	 */
	Verb  getVerb(string& input);

	/**
	* @brief Determines whether the given input is a valid verb.
	* @param input Reference to the player's entered command word.
	* @return True if the word is a recognized verb, otherwise false.
	*/
	bool isVerb(string& input);

	/**
	 * @brief Displays all available verbs to the console.
	 * @details Useful for listing valid command options.
	 */
	void showAllVerbs();
};