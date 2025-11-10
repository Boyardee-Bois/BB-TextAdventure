#pragma once
#include <string>
#include <iostream>
using namespace std;

class QuestProgress {
private:
    bool questStarted;
    bool itemPickUp;
    bool questCompleted;
    string questName;

public:
    QuestProgress();
    QuestProgress(const string& name);

    void startedQuest();
    void pickUpItemBeforeQuest();
    bool canCompleteQuest() const;
    void completedQuest();

    bool isQuestStarted() const;
    bool isQuestCompleted() const;
};
