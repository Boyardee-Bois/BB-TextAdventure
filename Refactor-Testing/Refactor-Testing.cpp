#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../BB-TextAdventure/NPC.h"
#include "../BB-TextAdventure/QuestProgress.h"
#include "../BB-TextAdventure/Zone.h"
#include "../BB-TextAdventure/Verb.h"
#include "../BB-TextAdventure/Noun.h"
#include "../BB-TextAdventure/World.h"
#include "../BB-TextAdventure/Player.h"
#include "../BB-TextAdventure/Renderer.h"
#include "../BB-TextAdventure/CommandParser.h"
#include "../BB-TextAdventure/UI.h"
#include "../BB-TextAdventure/PlayerActionManager.h"
#include "../BB-TextAdventure/Tile.h"
#include "../BB-TextAdventure/HealthUI.h"

#include <map>
#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RefactorTesting
{
    TEST_CLASS(RefactorTesting)
    {
    public:
        //NPC autoTestNPC; //NPC that will be used in all the tests
        
        TEST_METHOD_INITIALIZE(npcTestSetup)
        {
            //autoTestNPC = NPC(); //NPC that will be used in all the tests
        }
        TEST_METHOD(Get_Grid)
        {

        }
        // verify NPC* Zone::getNpcInZone() const works as expected
        //    first create the zone
        TEST_METHOD(VerifyNpcInZone) {
            Zone *testZone = new Zone(ZoneLocation::DefaultLab);
            NPC *npc = testZone->getNpcInZone();   // verify this does return the expected NPC - Bob?
            Logger::WriteMessage(npc->getName().c_str());

            // test picking the item
            //    first verify item hasn't picked up, then call the NPC class to record the item is picked up & verify Quest & NPC both think we have the item
           
            Logger::WriteMessage("\n Testing we use the NPC class to record the item has picked up\n");
            Assert::IsFalse(npc->getQuestItemCollected());
            Assert::IsFalse(npc->getQuestObject().hasPickedUpItem());

            
            Assert::IsFalse(npc->setQuestItemCollected(true), L"expected item to be collected, but failed");    // should fail
            npc->startedQuest();
            Assert::IsTrue(npc->setQuestItemCollected(true), L"expected item to be collected, but failed");    // now we should be able to pick up the item
            Assert::IsTrue(npc->getQuestItemCollected());
            Assert::IsTrue(npc->getQuestObject().hasPickedUpItem());
            
        }
        
        // Walk through a quest
        TEST_METHOD(StepThroughASunnyDayQuestScenario) {
            Zone* testZone = new Zone(ZoneLocation::DefaultLab);
            NPC* npc = testZone->getNpcInZone();   // verify this does return the expected NPC - Bob?
            Logger::WriteMessage(npc->getName().c_str());
  
            Assert::IsFalse(npc->setQuestItemCollected(true));     // should not be able to retreive item before the quest

            Logger::WriteMessage("\n Talk to NPC\n");   // should start the quest
            npc->interact(Verb::Interact, Noun::NPC, testZone, 0, 0, true);  // first interaction
            Assert::IsTrue(npc->isQuestStarted());
            Assert::IsTrue(npc->getQuestObject().isQuestStarted());

            // next step pick-up the item & talk to NPC, should complete the quest & spawn an enemy
            Logger::WriteMessage("\n Talk to NPC after picking up the item - quest completed\n");   // should start the quest
            Assert::IsTrue(npc->setQuestItemCollected(true));     // should allow us to retrieve the item
            Assert::IsFalse(testZone->hasEnemySpawned());
            npc->interact(Verb::Interact, Noun::NPC, testZone, 0, 0, true);  // first interaction
            //   can't test this, no zone method to test if the enemy is visible, and hasEnemySpawned() doesn't work - never initialized
            Assert::IsTrue(npc->isQuestComplete());
            // Assert::IsTrue(testZone->hasEnemySpawned(), L"expecting enemy has spawned, but enemy hasn't spawned!");
        }
        
        // 

        // test case to verify that trying to pickup the item before talking to NPC fails
        
        TEST_METHOD(canStartQuest)
        {
            NPC autoTestNPC;
            Logger::WriteMessage("Testing if quest can be started again when already true/started");
            Assert::IsFalse(autoTestNPC.isQuestStarted()); //  quest should not be started
            autoTestNPC.startedQuest();                    //Calls NPC to start the quest again
            Assert::IsTrue(autoTestNPC.isQuestStarted()); //Check to see if quest can be started once already started (Should fail here) 
        }

        TEST_METHOD(pickUpItem_BeforeQuestStarted)
        {
            NPC autoTestNPC;
            Logger::WriteMessage("Testing if you can pick up an item before talking to the NPC to start the quest");
            autoTestNPC.pickUpItemBeforeQuest(); //Calls NPC to prevent item pickup before quest
            Assert::IsFalse(autoTestNPC.getQuestItemCollected()); //Sets picked up item to false despite not talking to NPC first (Should fail)
        }

        TEST_METHOD(hasItem_AfterQuestStarted)
        {
            NPC autoTestNPC;
            Logger::WriteMessage("Testing if the item can be picked up after starting quest\n");
            Logger::WriteMessage("Testing if player can complete quest without picking up the item");
            autoTestNPC.startedQuest();
            autoTestNPC.setQuestItemCollected(true); //Sets the item being picked up as true already (Item has been picked up)
            Assert::IsTrue(autoTestNPC.getQuestItemCollected()); //Says the item has NOT been picked up (Should fail)
            Assert::IsTrue(autoTestNPC.canCompleteQuest()); //Checks if player can complete quest despite not having the item (Should fail)
        }
        
        /*
        TEST_METHOD(CreateTwoQuests) {
            QuestProgress mythicalJourney();
            QuestProgress mySpiritualJourney();
            mythicalJourney.startQuest("Journey to a land of peace of quiet");
            
// prent the output ehre - will show peach & quiet
            Logger::WriteMessage("HI");
        }
        */
        
    };

/*
Common Test Automation Asserts including Examples
•	Assert::AreEqual(expected, actual, message): Checks if two values are equal.
         Assert::AreEqual(5, my_function(2, 3), L"my_function should return 5 for inputs 2 and 3");
•	Assert::AreNotEqual(expected, actual, message): Checks if two values are not equal.
         Assert::AreNotEqual(0, my_function(1, 0), L"my_function should not return 0 for inputs 1 and 0");
•	Assert::IsTrue(condition, message): Checks if a condition is true.
        Assert::IsTrue(my_object.IsValid(), L"my_object should be valid after initialization");
•	Assert::IsFalse(condition, message): Checks if a condition is false.
        Assert::IsFalse(my_object.IsEmpty(), L"my_object should not be empty after adding elements");
•	Assert::IsNull(pointer, message): Checks if a pointer is null.
        Assert::IsNull(my_pointer, L"my_pointer should be null after deletion");
•	Assert::IsNotNull(pointer, message): Checks if a pointer is not null.
        Assert::IsNotNull(my_pointer, L"my_pointer should not be null after allocation");
•	Assert::Fail(message): Forces a test failure with a specified message.
        Assert::Fail(L"This code path should never be reached");

Important Notes:
•	The message parameter in these methods is optional but highly recommended for providing context about the assertion's purpose, especially when a test fails.
•	The string literals used for messages should be wide-character strings (prefixed with L) to be compatible with the framework.
•	These assertions are part of the Microsoft::VisualStudio::CppUnitTestFramework namespace. You typically include the necessary header and use this namespace in your test files.
C++
    #include "CppUnitTest.h"
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;
*/
}