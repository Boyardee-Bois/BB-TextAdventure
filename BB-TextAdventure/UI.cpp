#include "UI.h"
using namespace std; 

void UI::GameTitle()
{
    cout << "Welcome to Project Chronoscape\n\n\n"; 
}

void UI::SectionSeperator()
{
    cout << "\n======================================================\n";
}

//Outputs the introduction of the game, title and then allows user to press enter to get into the game
//I left the Rival's name as 'Insert Name' for now, but will change later once full story is complete. -JoshL
void UI::GameIntro()
{
   
    UI::GameTitle();

  cout << "In the distant future, you're tasked with working on humanity's most important Mission yet... Project Chronoscape. The breakthrough in time travel\n\n";

  cout << "Your primary obstacle isn't the science, rather it's the ego of your co-worker Dr. (Insert Name), your brilliant but reckless rival. He craves absolute control over the anomaly and views your measured approach as cowardice.\n\n";

  cout << "Behind your back, (Insert Name) overrides the safety protocols and initiates an unauthorized high-energy sequence. He was certain his calculations for the Tachyonic Cascade were flawless. They were not.\n\n";

  cout << "The Singularity explodes. The lab ruptures. A blinding, deafening shockwave tears through your reality, followed by the terrifying sensation of your molecular structure being stretched thin.\n\n";

  cout << "When the light fades, the air is thick, the humidity crushing, and the familiar scent of ozone is replaced by something ancient and savage.\n\n";


  cout << "You are alive. You are separated from (Insert Name). And you are catastrophically out of time.\n";
  UI::SectionSeperator();
  cout << "Press ENTER to begin your journey...\n";
   cin.get();
}

void UI::HelpMenu()
{
    cout << "HELP MENU\n";
    UI::SectionSeperator();
    cout << "The following controls will enable you to traverse this prehistoric land where danger lurks in every corner...\n";
    UI::SectionSeperator();
    cout << "W - Move Up/Forwards\n";
    cout << "A - Move Left\n";
    cout << "S - Move Down/Backwards\n";
    cout << "D - Move Right\n";
    UI::SectionSeperator();
    cout << "Utilize these to survive, locate friend or foe, and locate the missing pieces of the chronoscape to save the future as we know it...\n";
}


