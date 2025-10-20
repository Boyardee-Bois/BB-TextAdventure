#pragma once

#include "Noun.h"
#include <unordered_map>
#include <string>

using namespace std;

/*
* Scope: This class stores all valid nouns
*        and provides lookup fuctions to interpret
*        the second word of the player's input.
*/

class NounLookup 
{
private:

    unordered_map<string, Noun> validNouns;

public:

    // Constructor: Fills the map with known nouns.
    NounLookup();

    // Look up a word and return a noun value
    Noun getNoun(string input);

    // Returns true if the word is a recognized noun
    bool isNoun(string input);
};