/**
 * @file HealthUI.h
 * @brief Defines the health UI for the player class.
 *
 * @details
 * HealthUI converts the Player's current and maximum health values into a
 * formatted health string such as "[#######---] : 70/100".
 *
 */
#pragma once
#include <string>

class Player;

/**
 * @class HealthUI
 * @brief Formatting helper for player health.
 *
 * @details
 * - Reads health from Player.
 * - Builds a fixed width bar using '#' for filled and '-' for empty.
 * - Returns a final string in the form "[#######---] : 70/100".
 */
class HealthUI
{
private:

	/** @brief Total number of slots inside the health bar (e.g., 10). */
	int healthBarWidth;

	/**
	 * @brief Builds the health bar string, ex., "[#######---]".
	 * @param currentHealth Current player health.
	 * @param maxHealth Maximum player health.
	 * @return The constructed health bar string.
	 */
	std::string buildBar(int currentHealth, int maxHealth);

public:

	HealthUI();

	/**
	 * @brief Produces the full health display for the given player.
	 * @param player Reference to the Player (read-only).
	 * @return String formatted as "[#######---] : 70/100".
	 */
	std::string render(Player& player);
};