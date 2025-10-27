/**
 * @file NounLookup.h
 * @brief Defines the NounLookup class used for mapping text input to noun enums.
 *
 * @details
 * The NounLookup class maintains a dictionary of valid nouns and provides
 * lookup and validation methods to interpret the second word of player input.
 * Unknown or invalid nouns return Noun::Unknown.
 */
#pragma once

#include "Noun.h"
#include <unordered_map>
#include <string>

using namespace std;

/**
 * @class NounLookup
 * @brief Handles lookup and validation for all recognized nouns.
 *
 * @details
 * NounLookup stores a list of valid nouns used in player commands.
 * It allows the command parser to convert input into
 * the appropriate Noun enum value.
 *
 */
class NounLookup
{
private:

    /** @brief A map storing valid noun strings and their corresponding enum values. */
    unordered_map<string, Noun> validNouns;

public:

    /** @brief Constructs a NounLookup and initializes known nouns. */
    NounLookup();

    /**
     * @brief Retrieves the Noun corresponding to the given string input.
     * @param input The text input provided by the player.
     * @return The matching Noun, or Noun::Unknown if not found.
     */
    Noun getNoun(string input);

    /**
     * @brief Determines whether the given input matches a valid noun.
     * @param input The text input provided by the player.
     * @return True if the word is recognized as a noun, otherwise false.
     */
    bool isNoun(string input);
};