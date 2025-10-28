/**
 * @file CommandParser.h
 * @brief Declares the CommandParser class used to interpret player text input.
 */
#pragma once

#include "Command.h"
#include "VerbLookup.h"
#include "NounLookup.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @class CommandParser
 * @brief Parses player input into structured Command objects.
 *
 * @details
 * The CommandParser processes text entered by the player, normalizes it
 * (trimming and converting to lowercase), and interprets it into a structured
 * Command object. It relies on the VerbLookup and NounLookup.
 *
 */
class CommandParser
{
private:

	/** @brief Table of recognized verbs used to interpret the first word of input. */
	VerbLookup verbs;


	/** @brief Table of recognized nouns used to interpret the second word of input. */
	NounLookup nouns;

	/**
	 * @brief Splits an input line into lowercase, whitespace delimited tokens.
	 * @param inputLine The full line of text entered by the player.
	 * @return A vector of individual lowercase tokens in the order they appeared.
	 *
	 * @details
	 * Consecutive whitespace is ignored. If the input is blank,
	 * an empty vector is returned.
	 */
	vector<string> splitLine(const string& inputLine);

public:

	/** @brief Default constructor that initializes the verb and noun lookup tables. */
	CommandParser();

	/**
	 * @brief Reads, parses, and returns a structured Command object.
	 *
	 * @details
	 *  - Reads one line from standard input.
	 *  - Normalizes and tokenizes the line.
	 *  - Maps the first token to a Verb and the second to a Noun.
	 *  - Returns (Verb::Quit, Noun::Unknown) if input reading fails.
	 *
	 * @return A Command object representing the player's input.
	 */
	Command getCommand();

	/**
	 * @brief Prints all available verbs to the console.
	 *
	 * @details
	 * Useful for displaying help menus or debugging available commands.
	 */
	void showAllVerbs();

	/**
	 * @brief Converts a string to lowercase.
	 * 
	 * @param input The input string to be converted.
	 * @return A new string with all characters converted to lowercase.
	 */
	string toLower(string& input);
};