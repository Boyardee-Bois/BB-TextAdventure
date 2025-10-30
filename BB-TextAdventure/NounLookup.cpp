#include "NounLookup.h"
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

/*
* A static noun list that will populate the noun lookup constructor.
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
    {"Item", Noun::Item},
    { "Inventory", Noun::Inventory }
};

/*
* Populate the noun lookup map
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

/*
* Takes the player's input word
* and checks if it is in the validNouns map.
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

/*
* Returns true if the player's input is
* a match in the valid noun map
*/
bool NounLookup::isNoun(string input)
{
    return validNouns.find(input) != validNouns.end();
}