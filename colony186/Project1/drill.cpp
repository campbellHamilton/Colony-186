#include <iostream>
#include <ctime>
#include <stdio.h>
#include <Windows.h>
#include <thread>


// FUNCTION PROTOYPES
void countdown();
void howToPlay();
void spinDrill(int &resource, int &durability);
void status(int &resource, int&durability);
void up(int color, int sleep);
void down(int color, int sleep);
void right(int color, int sleep);
void left(int color, int sleep);

int drillMain()
{
	int durability = 10;
	int resource = 0;
	int input;

	srand(time(0));


	switch (1)
	{
	case 1: //Choice: Yes
		system("cls");
		countdown();
		system("cls");

		do {							     //Players spins the drill until 
			spinDrill(resource, durability);	//the durability reaches below 0
		} while (durability > 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("\nYou've collected ["); //Displays the amount of resources
		printf("%i", resource);				//the players has collected
		printf("] resources.\n\n");
		break;
	case 3: //Choice: How to play
		howToPlay();
		break;
	default:
		system("cls");
		break;
	}
	Sleep(500);
	system("cls");
	return resource;
}

// Timer that countsdown from 5
void countdown()
{
	for (int i = 3; i > 0; i--)
	{
		printf("Press the corresponding arrow key to spin the drill.\n\n");
		printf("Extraction starts in...\n");
		printf("\t");
		printf("%i", i);
		Sleep(750);
		system("cls");
	}
}

// Instructions on how to play
void howToPlay()
{
	system("cls");
	printf("Press the corresponding arrow key to spin the drill.\n\n");
	printf("You lose 1 durability each time you spin the drill.\n");
	printf("Spinning the wrong way causes you to lose 5.\n");
	printf("You're drill will no longer work when your durablity reaches below 0.\n\n");
	system("pause");
	system("cls");
	drillMain();
}

void spinDrill(int &resource, int &durability)
{
	int spin;
	int t = 650;
	spin = rand() % 4 + 1; //Generates a random number between 1 and 4
	switch (spin)			//and bases output to be randomly generated
	{
	case 1: //Output: Up
		status(resource, durability);
		up(15, t);
		system("cls");
		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D') ||
			GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S') ||
			GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))//Player is wrong
		{
			status(resource, durability);
			up(12, 50);
			durability -= 2;
		}
		else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) //Player is correct
		{
			status(resource, durability);
			up(10, 50);
			resource += 1;
			durability -= 1;
		}
		else
		{
			status(resource, durability);
			up(12, 50);
			durability -= 2;
		}
		system("cls");
		break;
	case 2: //Output: Down
		status(resource, durability);
		down(15, t);
		system("cls");
		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A') ||
			GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W') ||
			GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))//Player is wrong
		{
			status(resource, durability);
			down(12, 50);
			durability -= 2;
		}
		else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) //Player is correct
		{
			status(resource, durability);
			down(10, 50);
			resource += 1;
			durability -= 1;
		}
		else
		{
			status(resource, durability);
			down(12, 50);
			durability -= 2;
		}
		system("cls");
		break;
	case 3: //Output: Right
		status(resource, durability);
		right(15, t);
		system("cls");
		if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S') ||
			GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A') ||
			GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))//Player is wrong
		{
			status(resource, durability);
			right(12, 50);
			durability -= 2;
		}
		else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) //Player is correct
		{
			status(resource, durability);
			right(10, 50);
			resource += 1;
			durability -= 1;
		}
		else
		{
			status(resource, durability);
			left(12, 50);
			durability -= 2;
		}
		system("cls");
	case 4: //Output: Left
		status(resource, durability);
		left(15, t);
		system("cls");
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W') ||
			GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D') ||
			GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))//Player is wrong
		{
			status(resource, durability);
			left(12, 50);
			durability -= 2;
		}
		else	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) //Player is correct
		{
			status(resource, durability);
			left(10, 50);
			resource += 1;
			durability -= 1;
		}
		else
		{
			status(resource, durability);
			right(12, 50);
			durability -= 2;
		}
		system("cls");
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("cls");
}

void status(int &resource, int &durability)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n Resources: \t"); //Prints the amount of resources
	printf("%i", resource);			//the player has collected
	printf("\n durability: \t"); //Prints the durability
	printf("%i", durability);		//of the drill
	printf("\n\n");
}

void up(int color, int sleep)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	printf("+ - - - - - - - - - +\n");
	printf("|         .         |\n");
	printf("|      .:::::.      |\n");
	printf("|    .:::::::::.    |\n");
	printf("|       ::::: 	    |\n");
	printf("|       :::::       |\n");
	printf("|       :::::       |\n");
	printf("|       :::::       |\n");
	printf("+ - - - - - - - - - +\n");
	Sleep(sleep);
}

void down(int color, int sleep)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	printf("+ - - - - - - - - - +\n");
	printf("|       :::::       |\n");
	printf("|       :::::  	    |\n");
	printf("|       :::::       |\n");
	printf("|       :::::       |\n");
	printf("|    ...:::::...    |\n");
	printf("|      ':::::'      |\n");
	printf("|        ':'        |\n");
	printf("+ - - - - - - - - - +\n");
	Sleep(sleep);
}

void right(int color, int sleep)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	printf("+ - - - - - - - - - +\n");
	printf("|                   |\n");
	printf("|             .     |\n");
	printf("| ............:.    |\n");
	printf("| ::::::::::::::::. |\n");
	printf("| :::::::::::::::'  |\n");
	printf("|             :'    |\n");
	printf("|                   |\n");
	printf("+ - - - - - - - - - +\n");
	Sleep(sleep);
}

void left(int color, int sleep)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	printf("+ - - - - - - - - - +\n");
	printf("|                   |\n");
	printf("|    .              |\n");
	printf("|   .:............. |\n");
	printf("| .:::::::::::::::: |\n");
	printf("|  '::::::::::::::: |\n");
	printf("|    ':             |\n");
	printf("|                   |\n");
	printf("+ - - - - - - - - - +\n");
	Sleep(sleep);
}