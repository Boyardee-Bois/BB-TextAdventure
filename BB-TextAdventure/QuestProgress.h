#pragma once
#include <string>

class QuestProgress
{
private:
    bool questStarted;
    bool questCompleted;
    bool itemPickedUp;
    bool enemyUnlocked;
    std::string questName;

public:
    // Constructors
    QuestProgress();

    // Quest Control
    void startQuest(std::string name);
    void completeQuest();

    // returns the name given to the quest, when the quest was started
    std::string getQuestName();

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

    bool isEnemyUnlocked();

    //Automated Testing Reset Method
    void Reset();
};
