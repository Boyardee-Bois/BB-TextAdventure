/**
 * @file HealthUI.cpp
 * @brief Defines the health UI for the player class.
 *
 * @details
 * HealthUI converts the Player's current and maximum health values into a
 * formatted health string such as "[#######---] : 70/100".
 *
 */
#include "HealthUI.h"
#include "Player.h"

#include <string>
#include <sstream>
#include <cmath>

HealthUI::HealthUI()
{
	healthBarWidth = 10;
}

/**
 * @brief String builds the bracketed health bar, ex., "[#######---]".
 * @param currentHealth Player's current health.
 * @param maxHealth Player's maximum health.
 * @return The health bar string.
 */
std::string HealthUI::buildBar(int currentHealth, int maxHealth)
{
	if (maxHealth <= 0)
	{
		return "[" + std::string(healthBarWidth, '-') + "]";
	}

	if (currentHealth < 0)
	{
		currentHealth = 0;
	}

	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}

	double ratio = static_cast<double>(currentHealth) / static_cast<double>(maxHealth);

	int filledAmount = static_cast<int>(std::floor(ratio * healthBarWidth));

	int emptyAmount = healthBarWidth - filledAmount;

	std::string healthBar = "[";

	healthBar += std::string(filledAmount, '#');

	healthBar += std::string(emptyAmount, '-');

	healthBar += "]";

	return healthBar;
}

/**
 * @brief Generates the health bar for the player.
 * @param player Reference to the Player.
 * @return String formatted as "[#######---] : 70/100".
 */
std::string HealthUI::render(Player& player)
{
	// Gets players current healtg
	int current = player.getCurrentHealth();

	// Hets players max health
	int max = player.getMaxHealth();

	// Creates the health bar visual
	std::string healthBar = buildBar(current, max);

	std::ostringstream output;

	output << healthBar << " : " << current << "/" << max;

	return output.str();
}