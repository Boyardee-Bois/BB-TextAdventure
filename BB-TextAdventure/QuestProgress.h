#pragma once
#include <string>

class QuestProgress
{
private:
    bool questStarted;
    bool questCompleted;
    bool itemPickedUp;
    bool enemyUnlocked;

public:
    // Constructors
    QuestProgress();

    // Quest Control
    void startQuest(std::string name);
    void completeQuest();

    // State Checks
    bool isQuestStarted();
    bool isQuestCompleted();

    // Item Tracking
    void setItemPickedUp(bool value);
    bool hasPickedUpItem();

    // Debug Info
    void printStatus();

    // HUD Helper
    std::string GetCurrentObjective();

    // Quest Name (public for HUD access)
    std::string questName;

    bool isEnemyUnlocked();

    //Automated Testing Reset Method
    void Reset();
};
