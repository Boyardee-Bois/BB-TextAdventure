/**
 * @file CommandParser.cpp
 * @brief Implements the CommandParser for interpreting player input.
 *
 * @details
 * Reads a line from stdin, tokenizes to words, normalizes to lowercase,
 * and maps the first word to a Verb and the second (optional) word to a Noun.
 * Returns a Command reflecting the player’s intent.
 */
#include "CommandParser.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <conio.h>

using namespace std;

/**
 * @class CommandParser
 * @brief Converts player text input into Command objects.
 *
 * @details
 * Splits input on whitespace, lowercases tokens, and resolves them via
 * VerbLookup and NounLookup. Does not execute gameplay.
 */
CommandParser::CommandParser() {};

/**
 * @brief Read and parse one player command from stdin.
 * 
 * @return A Command with verb and noun, or (Verb::Quit, Noun::Unknown) on EOF.
 */
Command CommandParser::getCommand()
{
	// Get a single character without the buffer
	int inputCharacter = _getch();

	// If the input character is equal to a move character... instantly return a move command
	if (inputCharacter == 'w' || inputCharacter == 'W') return Command(Verb::Go, Noun::North);
	if (inputCharacter == 'a' || inputCharacter == 'A') return Command(Verb::Go, Noun::West);
	if (inputCharacter == 's' || inputCharacter == 'S') return Command(Verb::Go, Noun::South);
	if (inputCharacter == 'd' || inputCharacter == 'D') return Command(Verb::Go, Noun::East);

	// Print the command key pressed
	cout << (char)inputCharacter;

	/*
	* Read the command normally if the input character
	* is not one of the dedicated movement cases.
	*
	* Need to concatenate the input char into a string
	* to read the rest of the command
	*/
	string remainingInput;

	Verb inputVerb = Verb::Unknown;
	Noun inputNoun = Noun::Unknown;

	if (!getline(cin, remainingInput))
	{
		return Command(Verb::Quit, Noun::Unknown);
	}

	string fullInput = (char)inputCharacter + remainingInput;

	vector<string> inputWords = splitLine(fullInput);

	if (!inputWords.empty())
	{
		inputVerb = verbs.getVerb(inputWords[0]);
	}

	if (inputWords.size() > 1)
	{
		inputNoun = nouns.getNoun(inputWords[1]);
	}

	return Command(inputVerb, inputNoun);
}

/**
 * @brief Print all recognized verbs.
 */
void CommandParser::showAllVerbs()
{
	verbs.showAllVerbs();
}

/**
 * @brief Return a lowercase copy of the input string.
 *
 * Ensures input normalization before performing lookups in command maps.
 *
 * @param input Reference to the string to convert.
 * @return string Lowercase version of the provided string.
 */
string CommandParser::toLower(string& input)
{
	string lowerCase = input;

	transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), [](unsigned char c) { return tolower(c); });

	return lowerCase;
}

/**
 * @brief Split a line into lowercase tokens.
 * 
 * @param inputLine The input line.
 * 
 * @return Vector of tokens.
 */
vector<string> CommandParser::splitLine(const string& inputLine)
{
	stringstream ss(inputLine);

	istream_iterator<string> begin(ss);

	istream_iterator<string> end;

	vector<string> inputWords(begin, end);

	for (string& word : inputWords)
	{
		word = toLower(word);
	}

	return inputWords;
}