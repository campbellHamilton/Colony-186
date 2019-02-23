

#include <iostream>

#include <string>

#include <stdlib.h>

#include <time.h>

#include <Windows.h>


using namespace std;

int turnNumber = 1;

bool playAgain = true;

int resourceGained = 5;

class MineralExtraction

{

private:

	int speed;

	int force;

	int depth;

	int durability;

public:

	MineralExtraction(int speedValue, int forceValue, int depthValue, int durabilityValue);

	int checkSpeed();

	int checkForce();

	int checkDepth();

	int checkDurability();

	void reduceSpeed();

	void reduceForce();

	void reduceDepth();

	void reduceDurability();

};

MineralExtraction::MineralExtraction(int speedValue, int forceValue, int depthValue, int durabilityValue)

{

	speed = speedValue;

	force = forceValue;

	depth = depthValue;

	durability = durabilityValue;

}

//defines member functions for checking the three private variables

int MineralExtraction::checkSpeed()

{

	return speed;

}

int MineralExtraction::checkForce()

{

	return force;

}

int MineralExtraction::checkDepth()

{

	return depth;

}

int MineralExtraction::checkDurability()

{

	if (durability <= 0)

	{

		cout << "Your drill has broken." << endl;

		playAgain = false;

		return durability;

	}

	else

	{

		return durability;

	}

}

//defines the member functions for mutating the 4 private variables

void MineralExtraction::reduceSpeed()

{

	speed--;

	//random meter increase by 2

	int randomIncrease = rand() % 2 + 1;

	if (randomIncrease == 1)

	{

		force = force + (rand() % 2 + 1);

	}

	else if (randomIncrease == 2)

	{

		depth = depth + (rand() % 2 + 1);

	}

	reduceDurability();

}

void MineralExtraction::reduceForce()

{

	force--;

	//random meter increase by 2

	int randomIncrease = rand() % 2 + 1;

	if (randomIncrease == 1)

	{

		speed = speed + (rand() % 2 + 1);

	}

	else if (randomIncrease == 2)

	{

		depth = depth + (rand() % 2 + 1);

	}

	reduceDurability();

}

void MineralExtraction::reduceDepth()

{

	depth--;

	//random meter increasae by 2

	int randomIncrease = rand() % 2 + 1;

	if (randomIncrease == 1)

	{

		force = force + (rand() % 2 + 1);

	}

	else if (randomIncrease == 2)

	{

		speed = speed + (rand() % 2 + 1);

	}

	reduceDurability();

}

void MineralExtraction::reduceDurability()

{

	if ((speed == 7) || (force == 7) || (depth == 7))

	{

		durability = durability - 4;

		resourceGained--;

		//checkDurability();

	}

	else if ((speed == 8) || (force == 8) || (depth == 8))

	{

		durability = durability - 5;

		resourceGained--;

		//checkDurability();

	}

	else if ((speed == 9) || (force == 9) || (depth == 9))

	{

		durability = durability - 7;

		resourceGained--;

		//checkDurability();

	}

	else if ((speed == 10) || (force == 10) || (depth == 10))

	{

		durability = durability - 10;

		resourceGained--;

		//checkDurability();

	}

	else if ((speed <= 0) || (force <= 0) || (depth <= 0))

	{

		playAgain = false;

		resourceGained--;

		//checkDurability();

	}

}

void checkTurn()

{

	if (turnNumber == 10)

	{

		playAgain = false;

	}

}

int setStartingSpeed()

{

	int startingSpeed = rand() % 2 + 1;

	if (startingSpeed == 1)

	{

		startingSpeed = 4;

	}

	else

	{

		startingSpeed = 5;

	}

	return startingSpeed;

}

int setStartingForce()

{

	int startingForce = rand() % 2 + 1;

	if (startingForce == 1)

	{

		startingForce = 4;

	}

	else

	{

		startingForce = 5;

	}

	return startingForce;

}

int setStartingDepth()

{

	int startingDepth = rand() % 2 + 1;

	if (startingDepth == 1)

	{

		startingDepth = 4;

	}

	else

	{

		startingDepth = 5;

	}

	return startingDepth;

}

//has the actual game in it

int drillin()

{

	turnNumber = 1;

	playAgain = true;

	resourceGained = 5;

	srand(time(0));

	bool validInput = false;

	MineralExtraction vein(setStartingSpeed(), setStartingForce(), setStartingDepth(), 10);

	cout << "You are extracting a resource." << endl;

	cout << "Balance the 3 meters for 5 turns. Don't let them hit 10." << endl;

	cout << "Reducing one will randomly increase another by 2." << endl;

	cout << "Your drill will start taking damage around 7." << endl;

	cout << "You will lose if your drill's durability reaches 0." << endl << endl;

	do{

		cout << "Turn Number: " << turnNumber << endl << endl;

		cout << "Current drill speed: " << vein.checkSpeed() << endl;

		cout << "Current drill force: " << vein.checkForce() << endl;

		cout << "Current drill depth: " << vein.checkDepth() << endl;

		cout << "Current drill durability: " << vein.checkDurability() << endl;

		cout << "\nWhat would you like to do?" << endl;

		cout << "1. Slow drill (lower speed).\n2. Lighten up (lower force).\n3. Pull out (lower depth)." << endl;

		string input;

		do {

			checkTurn();
			bool answered = false;
			Sleep(300);
			while (answered == false)
			{
				if (GetAsyncKeyState('1') & 0x8000)
				{
					input = '1';
					answered = true;
				}
				else if (GetAsyncKeyState('2') & 0x8000)
				{
					input = '2';
					answered = true;
				}
				else if (GetAsyncKeyState('3') & 0x8000)
				{
					input = '3';
					answered = true;
				}
			}

			if ((input == "1") || (input == "2") || (input == "3"))

			{

				validInput = true;

				if (input == "1")

				{

					vein.reduceSpeed();

					turnNumber++;

					cout << "" << endl;

					//cout << "Current drill speed:: " << vein.checkSpeed() << endl;

					//cout << "Current drill force: " << vein.checkForce() << endl;

					//cout << "Current drill depth: " << vein.checkDepth() << endl;

					//cout << "Current drill durability: " << vein.checkDurability() << endl;

					//system("pause");

					system("CLS");

				}

				else if (input == "2")

				{

					vein.reduceForce();

					turnNumber++;

					cout << "" << endl;

					//cout << "Current drill speed:: " << vein.checkSpeed() << endl;

					//cout << "Current drill force: " << vein.checkForce() << endl;

					//cout << "Current drill depth: " << vein.checkDepth() << endl;

					//cout << "Current drill durability: " << vein.checkDurability() << endl;

					//system("pause");

					system("CLS");

				}

				else if (input == "3")

				{

					vein.reduceDepth();

					turnNumber++;

					cout << "" << endl;

					//cout << "Current drill speed:: " << vein.checkSpeed() << endl;

					//cout << "Current drill force: " << vein.checkForce() << endl;

					//cout << "Current drill depth: " << vein.checkDepth() << endl;

					//cout << "Current drill durability: " << vein.checkDurability() << endl;

					//system("pause");

					system("CLS");

				}

			}

			else

			{

				validInput = false;

				cout << "Sorry, didn't quite catch that." << endl;

				system("pause");

				system("CLS");

			}

		} while (validInput == false);

	} while (playAgain == true);
	Sleep(500);
	cout << "You gain " << resourceGained << " Resources";
	return resourceGained;
}

//why the fuck do I even have a main?

void drillMain()

{

	drillin();

	cout << "You have completed this extraction. You have gained " << resourceGained << " resources." << endl;

	system("pause");

}

