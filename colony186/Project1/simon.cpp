#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <windows.h>


void display(int colour){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//144blue, 160green, 192red, 224yellow
	int lineN = 0;

	if (colour == 1){
		lineN = 10;
	}
	else if (colour == 2){
		lineN = 20;
	}
	else if (colour == 3){
		lineN = 30;
	}

	for (int space = 0; space < lineN; space++){
		printf("\n");
	}


	for (int y = 0; y < 10; y++){
		for (int x = 0; x < 10; x++){
			//blue block
			if (colour == 0){
				SetConsoleTextAttribute(hConsole, 144);
				std::cout << "1";
			}
			//green block
			else if (colour == 1){
				SetConsoleTextAttribute(hConsole, 160);
				std::cout << "Q";
			}
			//red block
			else if (colour == 2){
				SetConsoleTextAttribute(hConsole, 192);
				std::cout << "A";
			}
			//yellow block
			else if (colour == 3){
				SetConsoleTextAttribute(hConsole, 224);
				std::cout << "Z";
			}
		}
		printf("\n");
	}
}

void control(int(&input)[5]){
	std::cout << "Input the Pattern?";
	Sleep(1000);

	bool breakTheLoop = true;
	int counter = 0;
	while (breakTheLoop){

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 7);
		system("cls");

		//%%%%%%%%%%%%%%%%%%%%%INPUT TEMPLATE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		if (GetAsyncKeyState(0x31)){	// 1 key						
			display(0);
			input[counter] = 0;
			counter++;
		}
		//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		else if (GetAsyncKeyState(0x51)){	// Q key						
			display(1);
			input[counter] = 1;
			counter++;
		}
		else if (GetAsyncKeyState(0x41)){	// A key						
			display(2);
			input[counter] = 2;
			counter++;
		}
		else if (GetAsyncKeyState(0x5A)){	// Z key						
			display(3);
			input[counter] = 3;
			counter++;
		}
		Sleep(300);

		if (counter == 5){
			breakTheLoop = false;
			SetConsoleTextAttribute(hConsole, 7);
			system("cls");
		}


	}
}
void instuct(){
	bool exit = true;
	std::cout << "SAME RULE AS SIMON SAYS"
		<< "\n" << "Using 1, Q, A, Z"
		<< "\n" << "Simon says you need to get the right pattern."
		<< "\n" << "For every one you get right he will give you one resource!"
		<< "\n" << "PRESS SPACE TO SKIP WHENEVER YOU ARE READY"
		<< "\n" << "PRESS SPACE TO SKIP ANYTIME NEXT TIME";
	while (exit){
		if (GetAsyncKeyState(VK_SPACE) & 0x8000){
			exit = false;
			system("cls");
		}
	}
}

int SimonMain(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int pattern[5];
	int input[5];
	int resource = 0;
	srand(time(NULL));

	instuct();

	for (int count = 5; count > 0; count--){
		std::cout << "STARTING IN : " << count;
		Sleep(1000);
		system("cls");
	}
	for (int down = 0; down < 5; down++){
		pattern[down] = rand() % 4;
	}
	//display the pattern
	for (int i = 0; i < 5; i++){
		display(pattern[i]);
		Sleep(1000);
		SetConsoleTextAttribute(hConsole, 7);
		system("cls");
		Sleep(500);
	}
	//user input
	control(input);

	//check how many user got right
	for (int checker = 0; checker < 5; checker++){
		if (pattern[checker] == input[checker]){
			resource++;
		}
	}
	std::cout << "YOU GOT " << resource << " RESOURCE(S)!";
	Sleep(3000);
	system("cls");
	return resource;
}