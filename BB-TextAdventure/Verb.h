/**
 * @file Verb.h
 * @brief Defines all player verbs recognized by the parser.
 *
 * @details
 * Verbs are the action component of a player command.
 * Unknown inputs map to Verb::Unknown.
 */
#pragma once

 /**
  * @enum Verb
  * @brief Action keywords accepted by the command system.
  *
  * @details
  * Extend this list when adding new player actions. Preserve Unknown as the fallback.
  */
enum class Verb
{
	Go,
	Help,
	Quit,
	Unknown
};