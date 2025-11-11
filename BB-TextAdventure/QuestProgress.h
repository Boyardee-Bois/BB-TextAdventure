#pragma once
#include <string>

class QuestProgress
{
private:
    static bool questStarted;
    static bool questCompleted;
    static bool itemPickedUp;
    static bool enemyUnlocked;

public:
    // Constructors
    QuestProgress() = default;

    // Quest Control
    static void startQuest(const std::string& name = "Main Quest");
    static void completeQuest();

    // State Checks
    static bool isQuestStarted();
    static bool isQuestCompleted();

    // Item Tracking
    static void setItemPickedUp(bool value);
    static bool hasPickedUpItem();

    // Debug Info
    static void printStatus();

    // HUD Helper
    static std::string GetCurrentObjective();

    // Quest Name (public for HUD access)
    static std::string questName;

    static bool isEnemyUnlocked();
};
