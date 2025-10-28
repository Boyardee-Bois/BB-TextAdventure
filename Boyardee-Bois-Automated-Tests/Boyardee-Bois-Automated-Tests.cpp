#include "pch.h"
#include "CppUnitTest.h"
#include "../BB-TextAdventure/Map.cpp"
#include "../BB-TextAdventure/Tile.cpp"
#include "../BB-TextAdventure/UI.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BoyardeeBoisAutomatedTests
{
	TEST_CLASS(BoyardeeBoisAutomatedTests)
	{
	public:
		
		// test method to demonstrate the test project is correctly linked and can be run from test explorer
		TEST_METHOD(Hello_BB_AutoTest)
		{
			Logger::WriteMessage("Hello from Boyardee Bois AutomatedTestProject\n");
		}

		// Get_Grid test case reads the specified section of the grid and prints it to the test output
		//    it doesn't do any validation of expected results
		//    the MAX_ROWS and MAX_COLUMNS is configurable here (actual in game is 25x25)
		//      ideally should add methods to the Map class to return the actual grid size & use those
		TEST_METHOD(Get_Grid) 
		{
			const int MAX_ROWS = 10;   // for now just pull first 10 rows & columns, rather than all 25
			const int MAX_COLUMNS = 10;
			Map gridMap;              // initializes the grid
			Tile returnedTile;
			char gridCharArray[MAX_ROWS][MAX_COLUMNS];

			for (int rowIterator = 0; rowIterator < MAX_ROWS; rowIterator++) {
				string outputString = "";
				for (int columnIterator = 0; columnIterator < MAX_COLUMNS; columnIterator++) {
					returnedTile = gridMap.returnTile(rowIterator, columnIterator);
					gridCharArray[rowIterator][columnIterator] = returnedTile.mapTileToChar();
					outputString = outputString + gridCharArray[rowIterator][columnIterator] + " ";
				}
				outputString += "row" + to_string(rowIterator) + "\n";
				Logger::WriteMessage(outputString.c_str());
			}
		}
		// Validate_Grid - reads the grid from the map & validates against an expected grid
		//   for example - tile [0,0] is grass, ....
		//   can move much of the duplicate test code to a helper function, but 
		TEST_METHOD(Validate_Grid) {
			const int MAX_ROWS = 2;   // for now just pull first 10 rows & columns, rather than all 25
			const int MAX_COLUMNS = 10;
			Map gridMap;              // initializes the grid
			Tile returnedTile;
			char gridCharArray[MAX_ROWS][MAX_COLUMNS];         // for downloading the initialized grid from the Map class
			char expectedGridCharArray[MAX_ROWS][MAX_COLUMNS] = {     // this is the expected grid, with tiles aliased to characters - e.g. Grass = 'G'
				{'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
				{'G', 'G', 'G', 'S', 'S', 'S', 'S', 'G', 'G', 'W'} };

			// loop through the Map grid - for each row, retrieve all of the column tiles
			//   store the received grid (no specific reason to do so, but ...)
			//   compare each tile to the expected tile, if not equal, fail the test case (ie Assert)
			// prints each successfully compared row on the test output
			//    Note: for demonstration purposes switched cell[1][9] from Grass to Water to intentionallly fail the test case
			for (int rowIterator = 0; rowIterator < MAX_ROWS; rowIterator++) {
				string outputString = "";
				for (int columnIterator = 0; columnIterator < MAX_COLUMNS; columnIterator++) {
					// get the tile, store it and add to print string
					returnedTile = gridMap.returnTile(rowIterator, columnIterator);
					gridCharArray[rowIterator][columnIterator] = returnedTile.mapTileToChar();
					outputString = outputString + gridCharArray[rowIterator][columnIterator] + " ";

					// verify the tile matches the expected tile
					Assert::AreEqual(expectedGridCharArray[rowIterator][columnIterator],
						             gridCharArray[rowIterator][columnIterator],
						L"Tile did not match!");
				}  // end of row
				outputString += "row" + to_string(rowIterator) + "\n";
				Logger::WriteMessage(outputString.c_str());
			}  // end of all rows
		}
	};
}


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





