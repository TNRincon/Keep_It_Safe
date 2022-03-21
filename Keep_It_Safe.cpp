//Tanis Rincon
// 
// KEEP IT SAFE: A console window math game ©
//
//SETUP: You are a lowly maintenance person in Area 51. All scientists and authorized perosnnel have 
//been annihilated while you were cleaning the bathroom on the ground level floor. Aliens have
//found where their stolen technology is hiddem and are trying to take it back.You must get to
//the control room to manually shut down all lab entrances before they get to it first!

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void PlotIntro();
void ElevatorScreen(int);
bool PlayGame(int);

int main()
{
	//to create a seeded random number
	srand(time(NULL));

	// initializing level difficultly
	const int MAX_LEVEL = 10;
	int CurrentLevel = 1;

	PlotIntro();

	//Loop to complete all 10 levels
	while (CurrentLevel <= MAX_LEVEL)
	{
		//cout << rand() % 10 << "\n";
		bool bLevelComplete = PlayGame(CurrentLevel);
		cin.clear(); // Clears errors
		cin.ignore(); // Discards the buffer

		//increase level difficulty
		if (bLevelComplete)
		{
			++CurrentLevel;
		}
	}

	cout << "Dr. Smith: Great work Alex *cough*, humanity owes you, but they will never know who you are.\n";
	cout << "You are the bravest silent hero in the world.\n\n";

	return 0;
}

void PlotIntro()
{
	// exlplaining the game plot and giving instruction
	cout << "You are Alex, you are a maintenance person who works on the Area 51 Base. You just finished a plumping job\n";
	cout << " on the ground level floor bathroom. ";
	cout << endl;
	cout << endl;
	cout << "You walk out of the bathroom, to discover an unsettling silence.\n";
	cout << "It has never been this quiet during working hours, you think to yourself.\n";
	cout << "You hear static and low mumbling on the portable radio coming from your utility\nbelt, followed by distant loud bangs and a faint shriek.";
	cout << endl;
	cout << endl;
	cout << "Dr. Smith: Alex is that you? *cough*\n";
	cout << "Alex(You): Dr. Smith?? You sound in pain! What's going on, there is an unexplainable sound coming from below the\n";
	cout << "\tground level! Where is everyone? \n";
	cout << "Dr. Smith: Alex *cough* I need you to calm down and listen to what I am about to tell you.\n";
	cout << "\tI don't know how they *cough* didn't find you, but you need to stay hidden and cautious!\n";
	cout << "\tThe labs are being invaded and I *cough* don't know how they are doing it but they are making people physically diappear or leaving\n";
	cout << "\tthem for dead after horrible injuries! *cough* Sadly that is the position I am currently in and I need you to stop them! The\n";
	cout << "extraterrestrials \"A1-13N5\" finally did it, *cough* they located where we have hidden our advanced technology! *cough* \n";
	cout << "\tI know you don't have clearance for any underground levels past 1. But there was a reason\n";
	cout << "\tyou had to pass a math test for a maintenance job.";
	cout << endl;
	cout << endl;
	cout << "Dr. Smith informs you there is an alternative way to bypass the security clearance systems via the main elevator!\n";
	cout << "Proceed to that elevator CAREFULLY and follow the prompts on the elevator screen. Each level will require a secret code to get in and\n";
	cout << "each level will increase in difficulty.\n";
	cout << "Answer the math problems presented and you will be able to proceed to the next floor. If you do not enter it correctly you will\n";
	cout << "surely die a horrible alien death. The fate of humanity relies on you Alex.....\n\n";
}
void ElevatorScreen(int Level)
{
	cout << "In the elevator you see \"Level " << Level << "\" on the screen....\n" << endl;
}

bool PlayGame(int Level)
{

	//declare 3 random number
	const int CodeA = rand() % Level + Level;
	const int CodeB = rand() % Level + Level;
	const int CodeC = rand() % Level + Level;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	//print sum and product to terminal
	ElevatorScreen(Level);
	cout << "There are 3 numbers in the code.";
	cout << "\n1. The sum of the numbers: " << CodeSum;
	cout << "\n2. The product of the same numbers: " << CodeProduct << endl;

	int GuessA, GuessB, GuessC;

	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;
	cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << endl;;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		cout << "\nCORRECT. Moving down to next level...\n" << endl;
		return true;
	}
	else
	{
		cout << "\nINCORRECT. Hurry and try again or";
		cout << "\nyou might die a horrible alien death...\n\n";
		cout << "\t    ##            *##\n";
		cout << "\t   #               **#\n";
		cout << "\t  #       %% %%    ***#\n";
		cout << "\t #       %%%%%%%   ****#\n";
		cout << "\t#         %%%%%    *****#\n";
		cout << "\t#   ###     %     ###***#\n";
		cout << "\t#  # ####       #### #**#\n";
		cout << "\t#  #     #     #     #**#\n";
		cout << "\t#   #####  # #  #####***#\n";
		cout << "\t#         #   #  *******#\n";
		cout << "\t ### #           **# ###\n";
		cout << "\t     # - - - - - - #\n";
		cout << "\t      | | | | | | | \n\n";

		return false;
	}
}