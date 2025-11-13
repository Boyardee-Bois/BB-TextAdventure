#include "QuestProgress.h"
#include <iostream>
using namespace std; 

// Define static variables (shared across entire game)
bool QuestProgress::questStarted = false;
bool QuestProgress::questCompleted = false;
bool QuestProgress::itemPickedUp = false;
bool QuestProgress::enemyUnlocked = false;
std::string QuestProgress::questName = "Main Quest";

// === Function Definitions ===

void QuestProgress::startQuest(const std::string& name)
{
    if (!questStarted)
    {
        questName = name;
        questStarted = true;
        std::cout << "\n[Quest Started] '" << questName
            << "'\nObjective: Find the shiny thing by the water.\n";
    }
    else
    {
        std::cout << "[Quest Info] Quest already started.\n";
    }
}

void QuestProgress::completeQuest()
{
    if (questStarted && itemPickedUp && !questCompleted)
    {
        questCompleted = true;
        enemyUnlocked = true; 
        std::cout << "\n[Quest Completed] '" << questName
            << "'\nWoah, someone showed up near your lab!\n";
    }
    else if (questCompleted)
    {
        std::cout << "[Quest Info] Quest already completed.\n";
    }
    else
    {
        std::cout << "[Quest Info] You can’t complete this quest yet.\n";
    }
}

bool QuestProgress::isQuestStarted()
{
    return questStarted;
}

bool QuestProgress::isQuestCompleted()
{
    return questCompleted;
}

void QuestProgress::setItemPickedUp(bool value)
{
    itemPickedUp = value;
}

bool QuestProgress::hasPickedUpItem()
{
    return itemPickedUp;
}

void QuestProgress::printStatus()
{
   
    cout << "Quest Name: " << questName << "\n";

    cout << "Started: ";
    if (questStarted)
        cout << "Yes (Quest has been started)\n";
    else
        cout << "No (Player has not spoken to the NPC yet)\n";

    cout << "Item Picked: ";
    if (itemPickedUp)
        cout << "Yes (Quest item has been collected)\n";
    else
        cout << "No (Item still available in the world)\n";

   cout << "Completed: ";
    if (questCompleted)
        cout << "Yes (Quest is finished)\n";
    else
        cout << "No (Quest still in progress)\n";

    cout << "=====================================\n";
}

string QuestProgress::GetCurrentObjective()
{
    if (!questStarted)
        return "Talk to the NPC to begin your quest.";
    else if (questStarted && !itemPickedUp)
        return "Find the shiny thing by the water.";
    else if (questStarted && itemPickedUp && !questCompleted)
        return "Return to the NPC to complete your quest.";
    else if (enemyUnlocked && questCompleted)
        return "A new threat has appeared! Survive!"; 
    else
        return "No active objectives.";
}

bool QuestProgress::isEnemyUnlocked()
{
    return enemyUnlocked;
}

//Automated Testing reset to set everything back to the default (False)
void QuestProgress::Reset()
{
    questStarted = false;
    questCompleted = false;
    itemPickedUp = false;
    enemyUnlocked = false;
    questName = "First Quest for Arc Reactor";
}
