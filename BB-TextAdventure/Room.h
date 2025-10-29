/**
 * @file Room.h
 * @brief Defines the Room class representing a location in the text adventure.
 *
 * @details
 * The Room class models an individual game location with a name,
 * description, and a set of exits leading to other rooms.
 * Each Room can track whether it has been visited and provides
 * accessor and mutator methods for its attributes.
 */
#pragma once
#include <iostream>
#include <string>
#include <map>
#include "NPC.h"
using namespace std;

/**
 * @class Room
 * @brief Represents a single location in the game world.
 *
 * @details
 * Each Room contains:
 * - A name and description.
 * - A visited flag indicating whether the player has entered before.
 * - A map of exits connecting it to neighboring rooms.
 *
 * The Room class provides methods to retrieve information, manage exits,
 * and print room details for player interaction.
 *
 * @note Rooms are typically created and linked during game initialization.
 */
class Room
{
private:

    /** @brief The name of the room. */
    string roomName;

    /** @brief The description displayed when the player enters. */
    string roomDescription;

    /** @brief Indicates whether the player has visited this room. */
    bool isVisited;

    /** @brief Maps exit directions to neighboring rooms. */
    map<string, Room*> exits;

    NPC* roomNPC;

public:

    /**
     * @brief Default constructor initializing an empty room.
     */
    Room();

    /**
     * @brief Constructs a room with a specified name and description.
     * @param newRoomName The display name of the room.
     * @param newRoomDescription The narrative text for the room.
     */
    Room(string newRoomName, string newRoomDescription);

    /**
     * @brief Marks the room as entered by the player.
     * @details Called when the player moves into this room.
     */
    void enterRoom();
    /**
     * @brief Retrieves the room's name.
     * @return The current room name.
     */
    string getRoomName();

    /**
     * @brief Updates the room's name.
     * @param newName The new name for the room.
     */
    void setRoomName(string newName);

    /**
     * @brief Retrieves the room's description.
     * @return The descriptive text associated with the room.
     */
    string getRoomDescription();

    /**
     * @brief Updates the room's description.
     * @param newDescription The new descriptive text.
     */
    void setRoomDescription(string newDescription);

    /**
     * @brief Checks whether the room has been visited.
     * @return True if the room was visited; otherwise false.
     */
    bool getIsVisited() const;

    /**
     * @brief Sets the visited flag for the room.
     * @param visited True if the room has been visited, false otherwise.
     */
    void setVisited(bool visited);

    /**
     * @brief Prints the room's name and description to the console.
     */
    void printRoomInformation();

    /**
    * @brief Adds an exit leading to a neighboring room.
    * @param direction The direction of the exit.
    * @param neighbor Pointer to the connected Room.
    */
    void addExit(const string& direction, Room* neighbor);

    /**
     * @brief Retrieves the neighboring room for a given direction.
     * @param direction The exit direction to follow.
     * @return Pointer to the corresponding Room, or nullptr if none exists.
     */
    Room* getExit(const string& direction);

    /*
    * Sets and Gets an NPC to be placed in a room
    */
    void setNPC(NPC* npc);
    NPC* getNPC() const;
};