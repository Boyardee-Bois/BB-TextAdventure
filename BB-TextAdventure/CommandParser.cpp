#include "CommandParser.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;


CommandParser::CommandParser() {};

/*
* Get the players input and split the input line to a
* verb & noun, return the pair as a command.
*/
Command CommandParser::getCommand()
{
	string input;
	Verb inputVerb = Verb::Unknown;
	Noun inputNoun = Noun::Unknown;

	if (!getline(cin, input))
	{
		return Command(Verb::Quit, Noun::Unknown);
	}

	vector<string> inputWords = splitLine(input);

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

/*
* Displays all available verbs (actions)
*/
void CommandParser::showAllVerbs()
{
	verbs.showAllVerbs();
}

vector<string> CommandParser::splitLine(const string& inputLine) 
{
	stringstream ss(inputLine);

	istream_iterator<string> begin(ss);

	istream_iterator<string> end;

	vector<string> inputWords(begin, end);

	return inputWords;
}