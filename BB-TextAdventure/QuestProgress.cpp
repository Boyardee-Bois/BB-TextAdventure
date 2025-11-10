/**
 * @file QuestProgress.cpp
 * @brief
 *
 * @details
 *
 */
#include <iostream>
#include <string>
#include <map>
#include "QuestProgress.h"

using namespace std;

QuestProgress::QuestProgress() {
	questStarted = false;
	questCompleted = false;
	itemPickUp = false;
	questName = "";
}

QuestProgress::QuestProgress(const string& name) {
    questStarted = false;
    questCompleted = false;
    itemPickUp = false;
    questName = name;
}

void QuestProgress::startedQuest() {
	if (!questStarted) {
		cout << "Quest '" << questName << "' started!\n Objective:\n";
		questStarted = true;
		system("pause");
		return;
	}
}

void QuestProgress::pickUpItemBeforeQuest() {
	if (!questStarted) {
		cout << "This item can't be picked up yet! Try starting a quest!\n";
		system("pause");
		return;
	}
	if (!itemPickUp) {
		itemPickUp = true;
	}
}
bool QuestProgress::canCompleteQuest() const {
	return questStarted && itemPickUp && !questCompleted;
}
void QuestProgress::completedQuest() {
	if (canCompleteQuest()) {
		cout << "Quest '" << questName << "' completed!\nRewards:\n";
		questCompleted = true;
		system("pause");
	}
}
bool QuestProgress::isQuestStarted() const {
	return questStarted;
}

bool QuestProgress::isQuestCompleted() const {
	return questCompleted;
}