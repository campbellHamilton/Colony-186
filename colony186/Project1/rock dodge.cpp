#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>
#include "rock dodge.h"

void clearScreen(char(&screen)[9][10]){
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 9; x++) {
			screen[x][y] = ' ';
		}
	}
}

void rock(rocks(&invent)[10], char(&screen)[9][10]){
	for (int i = 0; i < 9; i++){
		invent[i].fall();
		screen[invent[i].getx()][invent[i].gety()] = 'O';
	}
}

void player(char(&screen)[9][10], int x){

	screen[x][9] = '^';
}

void printScreen2(char(&screen)[9][10], int &durability, int &resources){
	system("cls");
	std::cout << "Drill durability: " << durability;
	printf("\n");
	std::cout << "resources: " << resources;
	printf("\n");

	for (int i = 0; i < 11; i++){
		printf("%c", char(219));
	}
	printf("\n");


	for (int y = 0; y < 10; y++) {
		printf("%c", char(219));
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 1, (short)y + 3 });
		for (int x = 0; x < 9; x++) {

			printf("%c", screen[x][y]);
		}
		printf("%c", char(219));
		printf("\n");
	}

	for (int i = 0; i < 11; i++){
		printf("%c", char(219));
	}
}

void printScreen(char(&screen)[9][10], int &durability, int &resources){

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	std::cout << "Drill durability: " << durability;
	printf("\n");
	std::cout << "resources: " << resources;
	printf("\n");

	for (int y = 0; y < 10; y++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 1, (short)y + 3 });
		for (int x = 0; x < 9; x++) {

			printf("%c", screen[x][y]);
		}
		printf("\n");
	}
}

void drillCheck(rocks(&invent)[10], int playerx, int &durability, bool &breakTheLoop){
	if (durability <= 0){
		breakTheLoop = false;
	}
	else{
		for (int i = 0; i < 9; i++){
			if (invent[i].gety() == 9 && invent[i].getx() == playerx){
				durability -= 10;
			}
		}
	}
}



int rockMain(){
	bool breakTheLoop = true;
	srand(time(NULL));
	int initial;
	int playerx = 4;
	int durability = 30;
	int resources = 0;
	int count = 0;
	char screen[9][10];
	rocks invent[10];
	clearScreen(screen);

	for (int i = 0; i < 10; i++){
		initial = rand() % 9;
		invent[i].setInitial(initial);
	}

	for (int o = 15; o > 0; o--){

		system("cls");
		printf("use the left and right keys to move the drill");
		printf("\n");
		printf("hit 3 rocks and you lose the game!");
		printf("\n");
		printf("Avoid the rock to for 15 seconds to win!");
		printf("\n");
		printf("             STARTS IN:  ");
		printf("%i", o);
		printf("\n");
		printf("press space skip and start the game!");
		Sleep(1000);
		if (GetAsyncKeyState(VK_SPACE)){
			o = 0;
		}
	}
	printScreen2(screen, durability, resources);
	while (breakTheLoop){
		Sleep(150);
		count++;
		if (count == 30){
			resources++;
			count = 0;
		}
		if (resources == 5){
			breakTheLoop = false;
		}
		//%%%%%%%%%%%%%%%%%%%%%TEMPLATE FOR ALL MOVEMENTS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')){								//moving right
			clearScreen(screen);
			rock(invent, screen);
			if (playerx == 8){
				player(screen, 8);
			}
			else{
				playerx++;
				player(screen, playerx);
			}
			drillCheck(invent, playerx, durability, breakTheLoop);
			printScreen(screen, durability, resources);
		}
		//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')){
			clearScreen(screen);
			rock(invent, screen);
			if (playerx == 0){
				player(screen, 0);
			}
			else{
				playerx--;
				player(screen, playerx);
			}
			drillCheck(invent, playerx, durability, breakTheLoop);
			printScreen(screen, durability, resources);
		}
		else{
			clearScreen(screen);
			rock(invent, screen);
			player(screen, playerx);
			drillCheck(invent, playerx, durability, breakTheLoop);
			printScreen(screen, durability, resources);
		}
	}
	if (durability == 0){
		printf("\n");
		std::cout << "!!!!!!Drill Broke!!!!!!";
	}
	if (resources == 5){
		printf("\n");
		std::cout << "!!!!!!Resource Exhusted!!!!!!";
	}
	Sleep(2000);
	system("cls");
	return resources;
}
