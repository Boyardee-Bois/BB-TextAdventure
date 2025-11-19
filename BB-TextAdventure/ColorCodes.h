/**
 * @file ColorCodes.h
 * @brief Defines 8 bit ANSI color constants for terrain and UI elements.
 *
 * @details
 * Intended for map and tile rendering.
 */
#pragma once

 /** @enum ColorCode
  *  @brief ANSI 8 bit color codes used for map tiles.
  */
enum class ColorCode : int
{
    Green = 34,   /**< Grass terrain */
    Blue = 27,   /**< Water terrain */
    Brown = 94,   /**< Dirt path */
    Gray = 240,  /**< Stone surface */
    Red = 196,   /**< Lights, warning indicators */
    Tan =  180,     /**< Sand terrain*/
    Pink = 201,  /**< Portal Color (Pink for testing) */
    Black = 0, /**< Black to contrast the player */
    DarkGray = 235 /**< Flooring color in lab */
};