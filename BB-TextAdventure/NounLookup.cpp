/**
 * @file NounLookup.cpp
 * @brief Implements the NounLookup class used for mapping player input to Noun values.
 *
 * @details
 * Populates a map of valid nouns from a list and
 * provides lookup, validation, and listing utilities for use by the parser.
 */
#include "NounLookup.h"
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * @brief  List of valid nouns used to populate the lookup table.
 * @details
 * Extend this list to include new directions or interactive targets.
 */
static const vector<pair<string, Noun>> NOUN_LIST =
{
    {"north", Noun::North},
    {"south", Noun::South},
    {"east", Noun::East},
    {"west", Noun::West},
    {"W", Noun::North},
    {"S", Noun::South},
    {"A", Noun::West},
    {"NPC", Noun::NPC}
};

/**
 * @brief Constructs NounLookup and initializes its map.
 * 
 * @details
 * Populates the validNouns map using predefined values from NOUN_LIST.
 * Ignores Noun::Unknown entries if present.
 */
NounLookup::NounLookup()
{
    for (auto& input : NOUN_LIST)
    {
        const string& word = input.first;

        Noun noun = input.second;

        if (noun != Noun::Unknown)
        {
            validNouns[word] = noun;
        }
    }
}

/**
 * @brief Retrieves a Noun corresponding to the provided input string.
 * 
 * @param input The text input from the player.
 * 
 * @return The matching Noun, or Noun::Unknown if no match is found.
 */
Noun NounLookup::getNoun(string input)
{
    auto iterator = validNouns.find(input);

    if (iterator != validNouns.end())
    {
        return iterator->second;
    }
    else
    {
        return Noun::Unknown;
    }
}

/**
 * @brief Checks if the provided input is a valid noun.
 * 
 * @param input The input from the player.
 * 
 * @return True if the word is recognized, otherwise false.
 */
bool NounLookup::isNoun(string input)
{
    return validNouns.find(input) != validNouns.end();
}