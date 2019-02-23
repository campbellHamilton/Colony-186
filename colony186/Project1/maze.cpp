//COLONY-186 (C186), BETA VERSION 5.4, CYBER-HIVE STUDIOS
#include "maze.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <Windows.h>
#include <iostream>
#include <fstream>

//░ floor
//█ walls

void dialogue(int x);

void mantisDrop();

void mongerDrop();

void crabDrop();

int boneCheck();

int resources = 0;
const char walls = char(219);
const char floors = ' ';
const char explored = char(177);

// for editing purposes dont touch setup, writen, write, write2, move.
// random is used to spawn the resources and eventually the merchants
// check is used to detect wether the player is on a resource/merchant
//combat chance is used to check when the player is going to enter combat
//rerandom is for testing purposes and it rerandomizes the maze currently it should be disabled(causes instability and bugs).

void researchCount(int x, int y);

mazes::mazes(int resources, int tempColour, int tempMax)
{
	max = tempMax;
	colour = tempColour;
	pos[0] = max / 8;
	pos[1] = max / 8;
	sizey = max / 2;
	sizex = max / 2;
	rSize = max - 1;
	for (int count = 0; count < max; count++)
	{
		for (int count2 = 0; count2 < max; count2++)
		{
			visit[count][count2] = false;
		}
	}

	for (int count = 0; count < sizey; count++)
	{
		for (int count2 = 0; count2 < sizex; count2++)
		{
			maze[count][count2] = true;
			wall[count][count2] = true;
			if (count < sizex - 1)
			{
				floor[count][count2] = true;
			}
		}
	}
	for (int count = 0; count < rSize; count++)
	{
		line.push_back("       ");

	}
	if (tempMax == 20)//this makes the cave levels
	{
			setup();//makes the maze
			writen("cave.txt");//saves it to textfile. both for bugtesting and for simplicity.
			Write("cave.txt");//???? i think it removes chunks of the maze
			random();//adds resources to maze
			cave(true);
	}
	else//this makes the normal levels
	{
		make("biome.txt");
	}
	
}

void mazes::setup()
{
	pos[0] = size / 4;
	pos[1] = size / 4;
	bool options = false;
	srand(time(0));
	int choice = 0;
	maze[size / 4][size / 4] = false;

	for (int count = 0; count < 47; count++)
	{
		for (int count2 = 0; count2 < 47; count2++)
		{
			visit[count][count2] = false;
		}
	}

	do
	{
		choice = rand() % 8 + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 10 });
		switch (choice)
		{
		case 1:


			if (pos[0] + 1 < sizex && maze[pos[0] + 1][pos[1]] == true)
			{
				pos[0]++;
				wall[pos[0]][pos[1]] = false;
				maze[pos[0]][pos[1]] = false;
				directions[place] = 1;
				place++;

			}
			break;

		case 2:

			if (pos[0] - 1 >= 0 && maze[pos[0] - 1][pos[1]] == true)
			{
				pos[0]--;
				wall[pos[0] + 1][pos[1]] = false;
				maze[pos[0]][pos[1]] = false;
				directions[place] = 2;
				place++;
			}
			break;

		case 3:
		case 7:
		case 8:
			if (pos[1] + 1 < sizey && maze[pos[0]][pos[1] + 1] == true)
			{
				pos[1]++;
				floor[pos[0]][pos[1]] = false;
				maze[pos[0]][pos[1]] = false;
				directions[place] = 3;
				place++;
			}
			break;

		case 4:
		case 5:
		case 6:

			if (pos[1] - 1 >= 0 && maze[pos[0]][pos[1] - 1] == true)
			{
				pos[1]--;
				floor[pos[0]][pos[1] + 1] = false;
				maze[pos[0]][pos[1]] = false;
				directions[place] = 4;
				place++;
			}
			break;
		}

		options = true;

		do
		{
			if (pos[1] + 1 < sizey)
			{
				if (maze[pos[0]][pos[1] + 1] == true)
				{
					options = false;
				}
			}
			if (pos[1] - 1 >= 0)
			{
				if (maze[pos[0]][pos[1] - 1] == true)
				{
					options = false;
				}
			}
			if (pos[0] + 1 < sizex)
			{
				if (maze[pos[0] + 1][pos[1]] == true)
				{
					options = false;
				}
			}
			if (pos[0] - 1 >= 0)
			{
				if (maze[pos[0] - 1][pos[1]] == true)
				{
					options = false;
				}
			}
			if (options == true)
			{
				switch (directions[place - 1])
				{
				case 1:
					pos[0]--;
					place--;
					break;

				case 2:
					pos[0]++;
					place--;
					break;

				case 3:
					pos[1]--;
					place--;
					break;
				case 4:
					pos[1]++;
					place--;
					break;

				}
			}
		} while (options == true && (pos[0] != size / 4 || pos[1] != size / 4));
	} while (pos[0] != size / 4 || pos[1] != size / 4);

}

void mazes::writen(std::string name)
{


	std::ofstream file;
	file.open(name);

	for (int count2 = 0; count2 < sizey; count2++)
	{
		for (int count = 0; count < sizex - 1; count++)
		{

			file << floors;
			if (wall[1 + count][count2] == false)
			{

				file << floors;

			}
			else
			{

				file << walls;

			}
		}

		file << floors;
		file << "\n";



		if (count2 < sizey - 1)
		{
			for (int count = 0; count < sizex; count++)
			{
				if (floor[count][count2 + 1] == false)
				{
					file << floors;
				}
				else
				{
					file << walls;

				}
				if (count < sizex - 1)
				{
					file << walls;

				}
			}
		}
		file << "\n";

	}
	file.close();
}

void mazes::Write(std::string name)
{
	DWORD written;
	std::ifstream file;
	file.open(name);
	for (int count = 0; count < rSize; count++)
	{
		getline(file, line[count]);
	}

	for (int count2 = 1; count2 < rSize / 2; count2++)
	{
		pos[0] = rand() % rSize;
		pos[1] = rand() % rSize;
		for (int count = 0; count < rSize; count++)
		{

			switch (rand() % 4 + 1)
			{
			case 1:
				if (pos[0] > 0)
				{
					pos[0]--;
					line[pos[1]].at(pos[0]) = floors;
				}
				break;

			case 2:
				if (pos[0] < rSize - 1)
				{
					pos[0]++;
					line[pos[1]].at(pos[0]) = floors;
				}
				break;

			case 3:
				if (pos[1] > 0)
				{
					pos[1]--;
					line[pos[1]].at(pos[0]) = floors;
				}
				break;
			case 4:
				if (pos[1] < rSize - 1)
				{
					pos[1]++;
					line[pos[1]].at(pos[0]) = floors;
				}
				break;

			}
		}
	}
	file.close();
	pos[1] = rSize - 1;
	pos[0] = rSize - 1;

}

void mazes::Write2()
{

	DWORD written;
	for (short count = 0; count < rSize; count++)
	{

		for (short count2 = 0; count2 < rSize; count2++)
		{
			if (line[count].at(count2) == explored)
			{
				std::string temps = "";
				temps += explored;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { count2, count });
				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temps.c_str(), temps.size(), &written, NULL);
				temps = walls;
				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temps.c_str(), temps.size(), &written, NULL);
			}
			else
			{
				std::string temps = "";
				temps += line[count].at(count2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { count2, count });
				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temps.c_str(), temps.size(), &written, NULL);
				temps = walls;
				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temps.c_str(), temps.size(), &written, NULL);
			}
		}
	}
	for (short count = 0; count < rSize + 1; count++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { count, rSize });
		std::string temps;
		temps = walls;
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temps.c_str(), temps.size(), &written, NULL);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { rSize / 2 - 2, rSize + 1 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "LEGEND", 6, &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 2 });
	std::string bType = "Biome: ";
	bType += (biome + "				");
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), bType.c_str(), bType.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 3 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "G: Gems", 7, &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 4 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "A: Alloy", 8, &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 5 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "N: Nishati", 10, &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 6 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "C: Cave", 7, &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 7 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "E: Cave Exit", 12, &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 8 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "B: Boss", 7, &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, rSize + 9 });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "*: Region Exit", 14, &written, NULL);

	//delete the below when write2 has been replaced with move write;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	short posx = pos[0];
	short posy = pos[1];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { posx, posy });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "@", 1, &written, NULL);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void mazes::moveWrite()
{
	DWORD written;
	std::string temps = "";
	temps += line[pos[1]].at(pos[0]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	short posx = pos[0];
	short posy = pos[1];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { posx, posy });
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temps.c_str(), 1, &written, NULL);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}

void mazes::moveWrite2()
{
	DWORD written;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	short posx = pos[0];
	short posy = pos[1];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { posx, posy });	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "@", 1, &written, NULL);

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 30 });
	//std::string s = "you have ";
	//s += std::to_string(temp[0]);
	//s += " Alloy";
	//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 31 });
	//s = "you have ";
	//s += std::to_string(temp[1]);
	//s += " Bones";
	//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 32 });
	//s = "you have ";
	//s += std::to_string(temp[2]);
	//s += " Gems";
	//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 33 });
	//s = "you have ";
	//s += std::to_string(temp[3]);
	//s += " Nishati";
	//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);
	//updateBattle(true);

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 129, 34 });
	//s = std::to_string(temp[4]);
	//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

}

void potions();




void mazes::random()
{
	srand(time(0));
	int size = rSize*rSize*0.01;//this controls the resource limit per zone eventaully will be paramter
	int resources = rSize / 2;//this controls how many resources are spawned eventaully will be paramter
	bool test = false;
	int ran[16];
	for (int count = 0; count < 15; count++){ ran[count] = 0; }
	int count = 0;

	while (count < resources)
	{
		test = false;
		switch (rand() % 16 + 1)
		{
		case 1:
			while (test == false && ran[0] < size)
			{
				int rand1 = rand() % rSize / 4;//rSize=47
				int rand2 = rand() % rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[0]++;
				}
			}
			break;

		case 2:
			while (test == false && ran[1] < size)
			{
				int rand1 = rand() % rSize / 4 + rSize / 4;
				int rand2 = rand() % rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[2]++;
				}
			}
			break;

		case 3:
			while (test == false && ran[2] < size)
			{
				int rand1 = rand() % rSize / 4 + rSize / 2;
				int rand2 = rand() % rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[2]++;
				}
			}
			break;

		case 4:
			while (test == false && ran[3] < size)
			{
				int rand1 = rand() % rSize / 4 + 3 * rSize / 4;
				int rand2 = rand() % rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[3]++;
				}
			}
			break;

		case 5:
			while (test == false && ran[4] < size)
			{
				int rand1 = rand() % rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[4]++;
				}
			}
			break;

		case 6:
			while (test == false && ran[5] < size)
			{
				int rand1 = rand() % rSize / 4 + rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[5]++;
				}
			}
			break;

		case 7:
			while (test == false && ran[6] < size)
			{
				int rand1 = rand() % rSize / 4 + rSize / 2;
				int rand2 = rand() % rSize / 4 + rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[6]++;
				}
			}
			break;

		case 8:
			while (test == false && ran[7] < size)
			{
				int rand1 = rand() % rSize / 4 + 3 * rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[7]++;
				}
			}
			break;
		case 9://here
			while (test == false && ran[8] < size)
			{
				int rand1 = rand() % rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize / 2;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[8]++;
				}
			}
			break;

		case 10:
			while (test == false && ran[9] < size)
			{
				int rand1 = rand() % rSize / 4 + rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize / 2;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[9]++;
				}
			}
			break;

		case 11:
			while (test == false && ran[10] < size)
			{
				int rand1 = rand() % rSize / 4 + rSize / 2;
				int rand2 = rand() % rSize / 4 + rSize / 2;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[10]++;
				}
			}
			break;

		case 12:
			while (test == false && ran[11] < size)
			{
				int rand1 = rand() % rSize / 4 + 3 * rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize / 2;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[11]++;
				}
			}
			break;
		case 13:
			while (test == false && ran[12] < size)
			{
				int rand1 = rand() % rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize * 3 / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[12]++;
				}
			}
			break;

		case 14:
			while (test == false && ran[13] < size)
			{
				int rand1 = rand() % rSize / 4 + rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize * 3 / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[13]++;
				}
			}
			break;

		case 15:
			while (test == false && ran[14] < size)
			{
				int rand1 = rand() % rSize / 2 + rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize * 3 / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[14]++;
				}
			}
			break;

		case 16:
			while (test == false && ran[15] < size)
			{
				int rand1 = rand() % rSize / 4 + 3 * rSize / 4;
				int rand2 = rand() % rSize / 4 + rSize * 3 / 4;
				if (line[rand1].at(rand2) == floors)
				{
					rType(rand2, rand1);
					test = true;
					count++;
					ran[15]++;
				}
			}
			break;
		}
	}


}


void mazes::cave(bool type)
{
	if (type == false)
	{
		int rand1 = rand() % rSize;
		int rand2 = rand() % rSize;

		if (rSize + 1 < 40)
		{
			line[rand1].at(rand2) = 'C';
		}

		line[(rSize - 3) / 2].at(0) = '*';

		rand1 = rand() % rSize;
		rand2 = rand() % rSize;
		line[rand1].at(rand2) = 'M';
	}
	else
	{
		line[pos[1]].at(pos[0]) = 'E';
	}
}

//bool mazes::combatChance(int &combat)
//{
//	int bones = 0;
//	bool test = true;
//	bool life;
//	//to disable and enable combat simply change the parameter to 0 and combat respectively
//
//	switch (combat)
//	{
//	case 1:
//
//		if (rand() % 300 == 1)
//		{
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50, 11 });
//
//			bones = buildBattle(colour);
//			life = combatDriver();
//
//
//
//			combat = 0;
//			temp[1] += boneCheck();
//
//
//			moveWrite2();
//
//			return life;
//		}
//
//		break;
//
//	case 2:
//		if (rand() % 160 == 1)
//		{
//			bones = buildBattle(colour);
//			life = combatDriver();
//
//			combat = 0;
//			temp[1] += boneCheck();
//
//			moveWrite2();
//			return life;
//		}
//
//		break;
//
//
//	case 3:
//
//		if (rand() % 80 == 1)
//		{
//			bones = buildBattle(colour);
//			life = combatDriver();
//
//			combat = 0;
//			temp[1] += boneCheck();
//			moveWrite2();
//			return life;
//		}
//		else
//
//			break;
//	case 4:
//		if (rand() % 60 == 1)
//		{
//			bones = buildBattle(colour);
//			life = combatDriver();
//
//			combat = 0;
//			temp[1] += boneCheck();
//			moveWrite2();
//			return life;
//		}
//
//
//		break;
//	case 5:
//
//		if (rand() % 40 == 1)
//		{
//			bones = buildBattle(colour);
//			life = combatDriver();
//
//			combat = 0;
//			temp[1] += boneCheck();
//			moveWrite2();
//			return life;
//		}
//
//		break;
//	case 6:
//		if (rand() % 20 == 1)
//		{
//			bones = buildBattle(colour);
//			life = combatDriver();
//
//			combat = 0;
//			temp[1] += boneCheck();
//			moveWrite2();
//			return life;
//		}
//
//
//
//	}
//
//	return test;
//}

void mazes::setCave(int x, int y)
{
	pos[0] = x;
	pos[1] = y;
	line[pos[1]].at(pos[0]) = 'E';
	line[7].at(0) = 'B';
}


void mazes::rType(int x, int y)
{
	int temporary = rand() % 20;
	switch (colour)
	{
	case 10:
		if (temporary <= 7)
		{
			line[y].at(x) = 'N';
		}
		else if (temporary >= 8 && temporary <= 17)
		{
			line[y].at(x) = 'A';
		}
		else if (temporary >= 18)
		{
			line[y].at(x) = 'G';
		}
		break;
	case 6:
		if (temporary <= 9)
		{
			line[y].at(x) = 'N';
		}
		else if (temporary >= 10 && temporary <= 18)
		{
			line[y].at(x) = 'A';
		}
		else if (temporary >= 19)
		{
			line[y].at(x) = 'G';
		}
		break;
	case 7:
		if (temporary <= 5)
		{
			line[y].at(x) = 'N';
		}
		else if (temporary >= 6 && temporary <= 13)
		{
			line[y].at(x) = 'A';
		}
		else if (temporary >= 14)
		{
			line[y].at(x) = 'G';
		}
		break;
	case 11:
		if (temporary <= 7)
		{
			line[y].at(x) = 'N';
		}
		else if (temporary >= 8 && temporary <= 15)
		{
			line[y].at(x) = 'A';
		}
		else if (temporary >= 16)
		{
			line[y].at(x) = 'G';
		}
		break;
	case 8:
		if (temporary <= 1)
		{
			line[y].at(x) = 'N';
		}
		else if (temporary >= 2 && temporary <= 9)
		{
			line[y].at(x) = 'A';
		}
		else if (temporary >= 10)
		{
			line[y].at(x) = 'G';
		}
		break;
	}

}


void mazes::make(std::string file)
{
	setup();//makes the maze
	writen(file);//saves it to textfile. both for bugtesting and for simplicity.
	Write(file);//???? i think it removes chunks of the maze
	random();//adds resources to maze
	cave(false);//adds several points to maze, including cave exit
	Write2();//prints the resultant maze to the screen
}


void mazes::nextBiome(int tempColour)
{
	max += 8;
	switch (max)
	{
	case 24:
		colour = 6;
		break;
	case 32:
		colour = 7;
		break;
	case 40:
		colour = 11;
		break;
	}
	pos[0] = max / 8;
	pos[1] = max / 8;
	sizey = max / 2;
	sizex = max / 2;
	rSize = max - 1;
	for (int count = 0; count < max; count++)
	{
		for (int count2 = 0; count2 < max; count2++)
		{
			visit[count][count2] = false;
		}
	}

	for (int count = 0; count < sizey; count++)
	{
		for (int count2 = 0; count2 < sizex; count2++)
		{
			maze[count][count2] = true;
			wall[count][count2] = true;
			if (count < sizex - 1)
			{
				floor[count][count2] = true;
			}
		}
	}

	for (int count = 0; count < rSize; count++)
	{
		line.push_back("       ");

	}
	if (max < 48)
	{
		make("biome.txt");
	}
}