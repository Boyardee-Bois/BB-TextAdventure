/**
 * @file Noun.h
 * @brief Defines all nouns recognized by the command parser.
 *
 * @details
 * The Noun enum represents the target or object portion
 * of a player’s command. Each value corresponds to a recognized
 * direction or interactable target in the game world.
 * Unrecognized inputs default to Noun::Unknown.
 */
#pragma once

 /**
  * @enum Noun
  * @brief Represents valid target or directional terms in player commands.
  *
  * @details
  * Extend this enum as the game expands to include new objects,
  * locations, or entities. The Unknown value is used when input cannot
  * be matched to any known noun.
  */
enum class Noun
{
	North,
	South,
	West,
	East,
	W,
	A,
	S,
	Unknown
};