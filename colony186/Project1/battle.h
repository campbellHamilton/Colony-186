#include <iostream>
#include "Combat.h"
#include <Windows.h>
#include <time.h>
#include "maze.h"
#include <cmath>
#include "merchant.h"
#include "resources.h"

const char walls = char(219);
const char floors = ' ';
const char explored = char(177);

int drillMain();
int drillin();
int rockMain();
int SimonMain();

class battle {
public:

	combatObject player;
	combatObject tempEnemy[3];
	mazes level;
	resources amnt;
	mazes cave;

	void updateBattle(bool move);
	void playerCommand();
	int enemyCommand(int order);
	mazes *p_mazes;

	battle() : player("Player", 50, 7, 12, 3, false, true, 0, 10, 10, 3, 7), level(0, 10, 16), cave(0, 8, 20)
	{
		p_mazes = &level;
		place[0] = 0; place[1] = 0; place[2] = 0; place[3] = 0;
		cost[0] = 0; cost[1] = 0; cost[2] = 0; cost[3] = 0; cost[4];
	}

	int energyAtkCost = 3;
	int energyGain = 2;
	bool isCrit = false;

	int death()
	{
		if (player.get_curHp() <= 0)
		{
			return 0;
		}
		else if (tempEnemy[0].get_isAlive() <= 0 && tempEnemy[1].get_isAlive() <= 0 && tempEnemy[2].get_isAlive() <= 0)
		{
			return 1;
		}
		else
		{
			return 2;
		}

	}

	void battleOver();

	bool fleeCheck = false;

	bool move(mazes *type);

	bool inCave = false;//this is used to control when a player exits and leaves a cave. false = outside, true = inside

	void merchant();

private:

	void weapons(int);
	void energy(int);
	void defense(int);
	void potion();
	void purchase(); //uses the cost array to see if you can actually purchase the item.
	int cost[4];//used to temporarily store the values of items you wish to purchase. 0 = alloy, 1 = gem, 2 = nishati/energy, 3 = bone,
	int buy(int);
	void print();
	void display(int, int);
	int place[5];
	int choice(int);

	void playerStats();

	int maxes = 216;

	bool radialBlind = false;
	const short cPPos = 50;//change player position
	const short cEPos = 100;//change enemy position
	const short y = 0;//used to offset the y coordinates of combat down.

	void mongerDrop();
	void crabDrop();
	void mantisDrop();

	void attack();

	int selects();

	int selects_1();

	void wait(int x);

	void clearCommands();

	void recover();

	int damageCalc(bool isPlayer, int target);

	void reduce_curHp(int val);

	void block();

	void items();

	void flee();

	int combatChance(int);

	bool check(mazes *type);

	void researchCount(int x, int y);

	void writeResource();

};

void battle::updateBattle(bool move) {
	std::string temp = "";
	DWORD written;

	clearCommands();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 3 + y });
	temp += player.get_Name();
	int numTemp;
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 4 + y });
	temp = "";
	temp += "HP: ";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
	if (player.get_curHp() < player.get_MaxHp() / 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	}
	std::string hpColour;
	hpColour = std::to_string(player.get_curHp());
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), hpColour.c_str(), hpColour.size(), &written, NULL);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	temp = "/";
	numTemp = player.get_MaxHp();
	temp += std::to_string(numTemp);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 5 + y });
	temp = "";
	temp += "Energy: ";

	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
	if (player.player_Tools[2] < player.player_Tools[1] / 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}
	std::string energyColour;
	energyColour = std::to_string(player.player_Tools[2]);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), energyColour.c_str(), energyColour.size(), &written, NULL);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	temp = "/";
	temp += std::to_string(player.player_Tools[1]);
	temp += "    ";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);

	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 6 + y });
	//temp = "";
	//temp += "Potions: ";
	//temp += std::to_string(player.player_Tools[3]);
	//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);

	if (move == false)
	{
		if (tempEnemy[0].get_isAlive() == true) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 0 + y });
			std::cout << tempEnemy[0].get_Name();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 1 + y });
			std::cout << "HP: " << tempEnemy[0].get_curHp() << " ";
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 0 + y });
			std::cout << "                       ";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 1 + y });
			std::cout << "                       ";
		}

		if (tempEnemy[1].get_isAlive() == true) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 3 + y });
			std::cout << tempEnemy[1].get_Name();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 4 + y });
			std::cout << "HP: " << tempEnemy[1].get_curHp() << " ";
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 3 + y });
			std::cout << "                      ";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 4 + y });
			std::cout << "                      ";
		}

		if (tempEnemy[2].get_isAlive() == true) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 6 + y });
			std::cout << tempEnemy[2].get_Name();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 7 + y });
			std::cout << "HP: " << tempEnemy[2].get_curHp() << " ";
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 6 + y });
			std::cout << "                      ";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 7 + y });
			std::cout << "                      ";
		}
	}
}

void battle::playerCommand()
{
	std::string temp;
	DWORD written;
	int tempSelect;
	int select;
	int target = 0;
	int dmg;
	int cur;
	int max;

	clearCommands();
	player.set_isBlocking(false);

	Sleep(100);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
	printf("                                                                               "); //10
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
	printf("It is your turn!							                               	   ");// 10

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
	temp = "1. Attack. Cost: " + std::to_string(energyAtkCost) + " Energy. Damage: " + std::to_string(player.get_atkMin()) + " - " + std::to_string(player.get_atkMax());
	temp += "							";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
	printf("2. Block. Cost: 2 Energy. Take half damage during next attack							");//12

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
	printf("3. Use Item Cost: 2 Energy.								"); //13

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
	std::cout << "4. Wait. Gain " << energyGain << " Energy.								"; //14

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
	printf("5. Flee:									"); //15

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
	printf("Enter a Command:									"); //15

	select = selects_1();
	switch (select)
	{
	case 1:
		attack();
		break;

	case 2:
		block();
		break;

	case 3:
		items();
		break;

	case 4:
		recover();
		break;

	case 5:
		flee();
		break;
	}
}

void battle::attack()
{
	std::string temp;
	DWORD written;
	int tempSelect;
	int select;
	int target = 0;
	int dmg;
	int cur;
	int max;

	clearCommands();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
	printf("You are attacking! Select a Target.                                            "); //10
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
	printf("1. Top Enemy                                                                   "); //11
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
	printf("2. Middle Enemy                                                                "); //12
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
	printf("3. Bottom Enemy                                                                "); //13
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
	printf("0. Go Back.                                                                    "); //14
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
	printf("Enter a Command:                                                               "); //15
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
	printf("                                                                               "); //16
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
	printf("                                                                               "); //17
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 18 + y });
	printf("                                                                               "); //18
	Sleep(100);
	tempSelect = selects();

	if ((tempSelect == 1 || tempSelect == 2 || tempSelect == 3) && player.get_curEnergy() > 2)
	{
		target = tempSelect;

		if (tempEnemy[target - 1].get_isAlive() == false) {
			clearCommands();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("INVALID COMMAND												");
			wait(500);
			playerCommand();
			target = 0;
		}
		else
		{
			target -= 1;

			player.reduce_curEnergy(energyAtkCost);
			clearCommands();

			if (player.get_Acc() == true)
			{
				clearCommands();
				dmg = damageCalc(true, target);
				tempEnemy[target].set_curHp(tempEnemy[target].get_curHp() - dmg);

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
				printf("                                                                               "); //10
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
				temp = "You attack " + tempEnemy[target].get_Name() + "							";
				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//10

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
				if (isCrit == true) {
					temp = "Critical Strike! " + tempEnemy[target].get_Name() + " takes " + std::to_string(dmg) + " damage!						";
					WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
				}
				else {
					temp = tempEnemy[target].get_Name() + " takes " + std::to_string(dmg) + " damage!								";
					WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
				}

				if (tempEnemy[target].get_curHp() <= 0) {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
					temp = "You have killed " + tempEnemy[target].get_Name() + "							";
					WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
					tempEnemy[target].set_isAlive(false);
				}
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
				temp = "Your attack misses the " + tempEnemy[target].get_Name() + "							";
				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//10
			}
			wait(500);
			clearCommands();
		}
	}
	else if (tempSelect == 0)
	{
		clearCommands();
		playerCommand();
	}
	else if (player.get_curEnergy() < energyAtkCost)
	{
		clearCommands();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
		printf("INSUFFICIENT ENERGY												");
		target = 0;
		wait(500);
		playerCommand();
	}
	else
	{
		clearCommands();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
		printf("INVALID COMMAND													");
		wait(500);
		playerCommand();
	}
}

int battle::enemyCommand(int order) {
	int choice;
	int dmg;
	if (tempEnemy[order].get_isAlive() == true) {
		std::string eneName = tempEnemy[order].get_Name();

		tempEnemy[order].set_isBlocking(false);

		clearCommands();
		std::cout << "It is " << eneName << "'s turn." << std::endl;
		clearCommands();

		srand(time(NULL));
		choice = 1 + (rand() % (int)(10));

		if (choice >= 1 && choice < 8) {
			dmg = damageCalc(false, order);

			if (radialBlind == true) {
				int radial = 1 + (rand() % (int)(5));
				if (radial == 3) {
					dmg = 0;
				}
			}

			if (tempEnemy[order].get_Acc() == true)
			{
				reduce_curHp(dmg);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
				std::cout << eneName << " attacks the player. " << std::endl; //10

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });

				if (isCrit == true) {
					std::cout << "Critical Strike! " + player.get_Name() << " takes " << dmg << " damage!" << std::endl; //11
				}
				else if (dmg == 0) {
					std::cout << "RADIAL BLIND! #SPOOKY!" << player.get_Name() << " takes " << dmg << " damage!" << std::endl;
				}
				else {
					std::cout << player.get_Name() << " takes " << dmg << " damage!" << std::endl; //11
				}
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
				std::cout << eneName << " attacks the player and misses" << std::endl; //10
			}
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
			std::cout << eneName << " is blocking and will take half damage if it is attacked. " << std::endl; //10
			tempEnemy[order].set_isBlocking(true);
		}
		for (int count = 0; count < 50; count++)
		{
			Sleep(1);
		}
		for (int count = 0; count < 1000; count++)
		{
			Sleep(1);
			if (GetAsyncKeyState(VK_SPACE))
			{
				count = 1005;
			}
		}
		return order;
	}
	return ++order;
}

void battle::block()
{
	player.increase_curEnergy(1);
	clearCommands();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
	printf("You are blocking! You take half damage.									"); //10
	wait(500);
}

void battle::items()
{
	std::string temp;
	int tempSelect;
	DWORD written;

	clearCommands();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
	printf("Choose a potion														"); //10
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
	temp = "1. Restoration Potion:" + std::to_string(player.player_Tools[3]) + "							";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
	temp = "2. Greater Restoration Potion:" + std::to_string(player.player_Tools[4]) + "							";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
	temp = "3. Awali Ale: " + std::to_string(player.player_Tools[5]);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
	temp = "4. Distilled Monster Blood: " + std::to_string(player.player_Tools[6]);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
	printf("0. Go Back .								");

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
	printf("Enter a Command:									");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });

	Sleep(200);
	tempSelect = selects();
	switch (tempSelect)
	{
	case 1:

		if (player.get_curHp() < player.get_MaxHp() && player.get_curEnergy() >= 2 && player.player_Tools[3] > 0)
		{
			clearCommands();
			player.reduce_curEnergy(2);
			int restored = player.use_Potion();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
			printf("You use a Potion.														");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
			temp = "You have restored " + std::to_string(restored) + "HP												";
			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
			wait(500);

		}
		else if (player.get_curEnergy() < 2)
		{
			clearCommands();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("INSUFFICIENT ENERGY															");
			wait(500);
			playerCommand();
		}
		else if (player.player_Tools[3] <= 0)
		{
			clearCommands();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("You have no more Potions.														");
			wait(500);
			playerCommand();
		}
		else
		{
			clearCommands();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
			printf("You are at Max HP.																");
			wait(500);
			playerCommand();
		}
		break;
	case 2:

		if (player.get_curHp() <= player.get_MaxHp() && player.get_curEnergy() >= 2 && player.player_Tools[4] > 0)
		{
			clearCommands();
			player.reduce_curEnergy(2);
			int restored = player.use_GPotion();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
			printf("You use a Greater Potion.													");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
			temp = "You have restored " + std::to_string(restored) + "HP							";
			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
			wait(500);
		}
		else if (player.get_curEnergy() < 2)
		{
			clearCommands();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("INSUFFICIENT ENERGY																");
			wait(500);
			playerCommand();
		}
		else if (player.player_Tools[3] <= 0)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("You have no more Greater Potions.												");
			wait(500);
			playerCommand();
		}
		else
		{
			clearCommands();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
			printf("You are at Max HP.																");
			wait(500);
			playerCommand();
		}
		break;
	case 3:
		if (player.buffs[0] == true)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("You already have this buff														");
			wait(500);
			playerCommand();
		}
		else if (player.player_Tools[5] > 0)
		{
			player.awali_buff(true);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
			printf("You drink some Awali ale.													");
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("You have no more Awali Ale.														");
			wait(500);
			playerCommand();
		}
		break;
	case 4:
		if (player.buffs[1] == true)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("You already have this buff														");
			wait(500);
			playerCommand();
		}
		else if (player.player_Tools[6] > 0)
		{
			player.blood_buff(true);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
			printf("You inject yourself with distilled monster blood .													");
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
			printf("You have no more Distilled Blood.														");
			wait(500);
			playerCommand();
		}

		break;
	}
	playerCommand();
}

void battle::recover()
{
	std::string temp;
	DWORD written;

	int	cur = player.get_curEnergy();
	int	max = player.get_maxEnergy();

	clearCommands();

	if (cur < max)
	{
		int restore = player.increase_curEnergy(energyGain);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
		temp = "You restored " + std::to_string(restore) + " energy!										";
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
		wait(500);

	}

	else {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
		printf("You already have maximum energy!											");
		wait(500);
		playerCommand();
	}
}

void battle::flee()
{
	if (rand() % 100 + 1 < 1000 && fleeCheck == false)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
		printf("You succesfully fled from combat.");
		tempEnemy[0].set_isAlive(false);
		tempEnemy[1].set_isAlive(false);
		tempEnemy[2].set_isAlive(false);
		wait(500);
		clearCommands();
		updateBattle(false);
	}
	else if (fleeCheck == true)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
		printf("You've already tried to flee from combat");
		wait(500);
		playerCommand();
	}
	else
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
		fleeCheck = true;
		printf("You failed to flee from combat.");
		wait(500);
	}
}

int battle::selects()
{
	while (1)
	{
		if (GetAsyncKeyState('0') & 0x8000)
		{
			return 0;
		}
		else if (GetAsyncKeyState('1') & 0x8000)
		{
			return 1;
		}
		else if (GetAsyncKeyState('2') & 0x8000)
		{
			return 2;
		}
		else if (GetAsyncKeyState('3') & 0x8000)
		{
			return 3;
		}
		else if (GetAsyncKeyState('4') & 0x8000)
		{
			return 4;
		}
	}
}

int battle::selects_1()
{
	while (1)
	{
		if (GetAsyncKeyState('1') & 0x8000)
		{
			return 1;
		}
		else if (GetAsyncKeyState('2') & 0x8000)
		{
			return 2;
		}
		else if (GetAsyncKeyState('3') & 0x8000)
		{
			return 3;
		}
		else if (GetAsyncKeyState('4') & 0x8000)
		{
			return 4;
		}
		else if (GetAsyncKeyState('5') & 0x8000)
		{
			return 5;
		}
	}
}

void battle::wait(int x)
{
	for (int count = 0; count < x; count++)
	{
		Sleep(1);
		if (GetAsyncKeyState(VK_SPACE))
		{
			count = 1005;
		}
	}
}

void battle::clearCommands() {

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 18 });
	printf("                                                            ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 });

}

int battle::damageCalc(bool isPlayer, int target) {
	int dmgDealt;
	int unitDmg;
	int crit;
	int playerCrit;

	isCrit = false;

	if (isPlayer == true)
	{
		int max = player.get_atkMax();
		int min = player.get_atkMin();
		int armor = tempEnemy[target].get_armor();

		bool blockCheck = tempEnemy[target].get_isBlocking();

		if (blockCheck == true)
		{
			srand(time(NULL));
			unitDmg = min + (rand() % (int)(max - min + 1));

			dmgDealt = (unitDmg - armor) / 2;
		}
		else
		{
			srand(time(NULL));
			unitDmg = min + (rand() % (int)(max - min + 1));
			dmgDealt = (unitDmg - armor);
		}

		if (dmgDealt <= 0) {
			dmgDealt = 1;
		}

		playerCrit = player.get_critChance();
		srand(time(NULL));
		crit = 100 + (rand() % (int)(1));
		if (crit >= 1 && crit <= playerCrit) {
			dmgDealt = dmgDealt * 2;
			isCrit = true;
		}

		return dmgDealt;
	}
	else
	{
		int max = tempEnemy[target].get_atkMax();
		int min = tempEnemy[target].get_atkMin();
		int armor = player.get_armor();


		bool blockCheck = player.get_isBlocking();

		if (blockCheck == true)
		{
			srand(time(NULL));
			unitDmg = rand() % max + min;

			dmgDealt = (unitDmg - armor) / 2;
		}
		else
		{
			srand(time(NULL));
			unitDmg = rand() % max + min;
			int tempN = tempEnemy[target].get_atkMax();
			if (unitDmg > tempN) {
				unitDmg = tempN;
			}
			dmgDealt = (unitDmg - armor);
		}

		if (dmgDealt <= 0) {
			dmgDealt = 1;
		}

		srand(time(NULL));
		crit = 1 + (rand() % (int)(100));
		if (crit >= 1 && crit <= 7) {
			dmgDealt = dmgDealt * 2;
			isCrit = true;
		}

		return dmgDealt;
	}
}

void battle::reduce_curHp(int val) {
	int current = player.get_curHp();
	int newHp = current - val;

	if (newHp > 0)
	{
		player.set_curHp(newHp);
	}
	else
	{
		player.set_curHp(0);
	}
}

bool battle::move(mazes *type)
{
	int health = 0;//controls when the play health go's up from movement
	int energy = 0;//controls when the play energy go's up from movement
	int combat = 0;//controls when the player encounters combat.

	while (1)
	{
		Sleep(75);
		if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState('W') & 0x8000)
		{

			if (type->pos[1] > 0)
			{
				if (type->line[type->pos[1] - 1].at(type->pos[0]) != walls)
				{

					combat++;
					health++;
					energy++;
					type->moveWrite();
					type->pos[1]--;
					type->moveWrite2();


					writeResource();

					if (type->visit[type->pos[0]][type->pos[1]] == false)
					{
						if (type->line[type->pos[1]].at(type->pos[0]) == floors)
						{
							type->line[type->pos[1]].at(type->pos[0]) = explored;
						}

						type->visit[type->pos[0]][type->pos[1]] = true;
						if (amnt.get(4) + 3 >= maxes)
						{
							amnt.set(4, maxes);
						}
						else
						{
							amnt.add(4, 3);
						}//static? or should i scale it? rSize/4
					}

					if (combatChance(combat) == 1)
					{
						return 1;
					}


				}
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState('S') & 0x8000)
		{

			if (type->pos[1] < type->rSize - 1)
			{
				if (type->line[type->pos[1] + 1].at(type->pos[0]) != walls)
				{
					combat++;
					health++;
					energy++;
					type->moveWrite();
					type->pos[1]++;
					type->moveWrite2();
					writeResource();

					if (type->visit[type->pos[0]][type->pos[1]] == false)
					{
						if (type->line[type->pos[1]].at(type->pos[0]) == floors)
						{
							type->line[type->pos[1]].at(type->pos[0]) = explored;
						}

						type->visit[type->pos[0]][type->pos[1]] = true;
						if (amnt.get(4) + 3 >= maxes)
						{
							amnt.set(4, maxes);
						}
						else
						{
							amnt.add(4, 3);
						}//static? or should i scale it? rSize/4
					}
					if (combatChance(combat) == 1)
					{
						return 1;
					}
				}
			}
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000)
		{

			if (type->pos[0] > 0)
			{
				if (type->line[type->pos[1]].at(type->pos[0] - 1) != walls)
				{
					combat++;
					health++;
					energy++;
					type->moveWrite();
					type->pos[0]--;
					type->moveWrite2();
					writeResource();

					if (type->visit[type->pos[0]][type->pos[1]] == false)
					{
						if (type->line[type->pos[1]].at(type->pos[0]) == floors)
						{
							type->line[type->pos[1]].at(type->pos[0]) = explored;
						}

						type->visit[type->pos[0]][type->pos[1]] = true;
						if (amnt.get(4) + 3 >= maxes)
						{
							amnt.set(4, maxes);
						}
						else
						{
							amnt.add(4, 3);
						}//static? or should i scale it? rSize/4
					}
					if (combatChance(combat) == 1)
					{
						return 1;
					}
				}
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000)
		{

			if (type->pos[0] < type->rSize - 1)
			{
				if (type->line[type->pos[1]].at(type->pos[0] + 1) != walls)
				{
					combat++;
					health++;
					energy++;
					type->moveWrite();
					type->pos[0]++;
					type->moveWrite2();

					writeResource();

					if (type->visit[type->pos[0]][type->pos[1]] == false)
					{
						if (type->line[type->pos[1]].at(type->pos[0]) == floors)
						{
							type->line[type->pos[1]].at(type->pos[0]) = explored;
						}

						type->visit[type->pos[0]][type->pos[1]] = true;
						if (amnt.get(4) + 3 >= maxes)
						{
							amnt.set(4, maxes);
						}
						else
						{
							amnt.add(4, 3);
						}//static? or should i scale it? rSize/4
					}
					if (combatChance(combat) == 1)
					{
						return 1;
					}
				}
			}
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			if (check(p_mazes) == true)
			{
				return false;
			}

		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			//will exit the game
			level.setMax(41);
			return false;
		}
		if (health == 5)
		{
			if (player.get_curHp() < player.get_MaxHp())
			{
				player.set_curHp(player.get_curHp() + 1);
				clearCommands();
				updateBattle(false);
			}
			health = 0;
		}
		if (energy == 2)
		{
			if (player.player_Tools[2] < player.player_Tools[1])
			{
				player.player_Tools[2] += 1;
				clearCommands();
				updateBattle(false);
			}
			energy = 0;
		}

	}

}

int battle::combatChance(int combat)//this controls the chance for combat
{
	if (combat <= 15)
	{
		if (rand() % 100 == 1)
		{
			return 1;
		}
	}
	else if (combat >= 16 && combat <= 20)
	{
		if (rand() % 100 <= 2)
		{
			return 1;
		}
	}
	else if (combat >= 21 && combat <= 26)
	{
		if (rand() % 100 <= 5)
		{
			return 1;
		}
	}
	else if (combat >= 27 && combat <= 29)
	{
		if (rand() % 100 <= 10)
		{
			return 1;
		}
	}
	else if (combat >= 30 && combat <= 32)
	{
		if (rand() % 100 <= 25)
		{
			return 1;
		}
	}
	else
	{
		if (rand() % 100 <= 50)//you have a 50% chance of combat
		{
			return 1;
		}
	}
	return 0;
}

bool battle::check(mazes *type)	//controls all the checks for wether the player is standing on a special spot
{
	//int maxes = level.max*max*0.8;
	//controls the amount of research needed to advance  these are temp values while i get the base function set up.
	//controls the amount of research needed to advance     these are temp values while i get the base function set up.

	if (type->line[type->pos[1]].at(type->pos[0]) != floors)
	{
		if (type->line[type->pos[1]].at(type->pos[0]) == 'A')//controls resource collection
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 30 });

			system("cls");
			std::cin.clear();
			int rand1 = rand() % 75 + 1;
			if (rand1 <= 25)
			{
				amnt.add(0, drillMain());
			}
			else if (rand1 > 25 && rand1 <= 50)
			{
				amnt.add(0, drillin());
			}
			else if (rand1 > 50 && rand1 <= 75)
			{
				amnt.add(0, rockMain());
			}


			std::string s = "you have ";
			s += std::to_string(amnt.get(0));
			s += " Alloy";
			if (amnt.get(4) + 10 >= maxes)
			{
				amnt.set(4, maxes);
			}
			else
			{
				amnt.add(4, 10);
			}
			type->line[type->pos[1]].at(type->pos[0]) = 'D';
			type->Write2();
			amnt.write();
			researchCount(maxes, amnt.get(4));
		}
		else if (type->line[type->pos[1]].at(type->pos[0]) == 'G')//controls resource collection
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 30 });

			system("cls");
			std::cin.clear();
			int rand1 = rand() % 75 + 1;
			if (rand1 <= 25)
			{
				amnt.add(1, drillMain());
			}
			else if (rand1 > 25 && rand1 <= 50)
			{
				amnt.add(1, drillin());
			}
			else if (rand1 > 50 && rand1 <= 75)
			{
				amnt.add(1, SimonMain());
			}


			std::string s = "you have ";
			s += std::to_string(amnt.get(1));
			s += " Gems";
			if (amnt.get(4) + 10 >= maxes)
			{
				amnt.set(4, maxes);
			}
			else
			{
				amnt.add(4, 10);
			}
			type->Write2();
			amnt.write();
			type->line[type->pos[1]].at(type->pos[0]) = 'D';
			researchCount(maxes, amnt.get(4));
		}
		else if (type->line[type->pos[1]].at(type->pos[0]) == 'N')//controls resource collection
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 30 });

			system("cls");
			std::cin.clear();
			int rand1 = rand() % 50 + 1;
			if (rand1 <= 25)
			{
				amnt.add(2, SimonMain());
			}
			else if (rand1 > 25 && rand1 <= 50)
			{
				amnt.add(2, drillin());
			}

			std::string s = "you have ";
			s += std::to_string(amnt.get(2));
			s += " Nishati";
			if (amnt.get(4) + 10 >= maxes)
			{
				amnt.set(4, maxes);
			}
			else
			{
				amnt.add(4, 10);
			}
			type->Write2();
			amnt.write();
			type->line[type->pos[1]].at(type->pos[0]) = 'D';
			researchCount(maxes, amnt.get(4));
		}
		else if (type->line[type->pos[1]].at(type->pos[0]) == 'C')//Cave
		{
			system("cls");
			cave.Write2();
			inCave = true;
			return true;

		}
		else if (type->line[type->pos[1]].at(type->pos[0]) == 'E')//Cave
		{
			system("cls");
			level.Write2();
			inCave = false;
			return true;

		}
		else if (type->line[type->pos[1]].at(type->pos[0]) == 'M')
		{
			merchant();
			type->Write2();
		}
		else if (type->line[type->pos[1]].at(type->pos[0]) == '*')//controls resource collection
		{
			if (amnt.get(4) == maxes)
			{
				type->nextBiome(8);
				std::cout << type->getMax();
				maxes *= 2;
				return true;
			}
			else
			{
				type->make("biome.txt");
			}
		}
	}
	return false;
}


void battle::researchCount(int x, int y)
{
	DWORD written;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 34 });
	std::string s = "you have ";
	s += "    /";
	int temp = x;
	s += std::to_string(temp);
	s += " research";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 129, 34 });
	s = std::to_string(y);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

}

void battle::writeResource()
{

	DWORD written;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 30 });
	std::string s = "you have ";
	s += std::to_string(amnt.get(0));
	s += " Alloy";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 31 });
	s = "you have ";
	s += std::to_string(amnt.get(3));
	s += " Bones";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 32 });
	s = "you have ";
	s += std::to_string(amnt.get(1));
	s += " Gems";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 33 });
	s = "you have ";
	s += std::to_string(amnt.get(2));
	s += " Nishati";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 34 });

	s = "you have ";
	s += std::to_string(amnt.get(4));
	s += " /";
	s += std::to_string(maxes);
	s += " research";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

}


void battle::merchant()
{
	system("cls");
	print();
	bool browse = true;
	while (browse)
	{
		Sleep(100);
		// Calls appropiate 'info' function allowing user to purchase items
		if (GetAsyncKeyState('1') & 0x8000)
		{
			if (place[0] <= 6)
			{
				display(place[0], 0);
			}
			else
			{
				std::cout << "You have already bought all the attack upgrades.";
				Sleep(300);
			}
			print();
		}
		else if (GetAsyncKeyState('2') & 0x8000)
		{
			if (place[1] <= 5)
			{
				display(place[1], 1);
			}
			else
			{
				std::cout << "You have already bought all the defense upgrades.";
				Sleep(300);
			}
			print();
		}
		else if (GetAsyncKeyState('3') & 0x8000)
		{
			if (place[2] <= 2)
			{
				display(place[2], 2);
			}
			else
			{
				std::cout << "You have already bought all the energy upgrades.";
				Sleep(300);
			}
			print();
		}
		else if (GetAsyncKeyState('4') & 0x8000)
		{
			potion();
			print();
		}
		else if (GetAsyncKeyState('0') & 0x8000)
		{
			browse = false;
			Sleep(300);
			system("cls");
		}
	}
}

void battle::print()
{
	system("CLS");
	std::cout
		<< "Merchant: Please, feel free to browse my wares." << std::endl
		<< " 1. Attack Upgrade:" << std::endl
		<< " 2. Defense Upgrade:" << std::endl
		<< " 3. Energy Upgrade:" << std::endl
		<< " 4. Consumables" << std::endl
		<< " 0. Back" << std::endl
		<< "Enter Command:";
}

void battle::potion()
{
	system("cls");
	std::cout
		<< "Merchant: Consumables" << std::endl
		<< "1. Restoration Potion" << std::endl
		<< "2. Greater Restoration Potion" << std::endl
		<< "3. Awali Ale" << std::endl
		<< "0. Back" << std::endl
		<< "Enter Command" << std::endl;
	bool exit = false;
	while (exit == false)
	{
		Sleep(100);
		if (GetAsyncKeyState('0') & 0x8000)
		{
			system("CLS");
			exit = true;
		}
		else if (GetAsyncKeyState('1') & 0x8000)
		{
			system("cls");
			std::cout
				<< "Restoration Potion (Item)" << std::endl
				<< "Restores 20 Hp" << std::endl << std::endl
				<< "Requirements:" << std::endl
				<< " 3 Gems" << std::endl
				<< " 5 Nishati" << std::endl;
			cost[1] = 3;
			cost[2] = 5;
			if (choice(4) == true)
			{
				player.player_Tools[3]++;
			}
			exit = true;

		}
		else if (GetAsyncKeyState('2') & 0x8000)
		{
			system("cls");
			std::cout
				<< "Greater Restoration Potion (Item)" << std::endl
				<< "Restores 40 Hp" << std::endl << std::endl
				<< "Requirements:" << std::endl
				<< " 5 Gems" << std::endl
				<< " 7 Nishati" << std::endl
				<< " 3 Bones" << std::endl;
			cost[1] = 5;
			cost[2] = 7;
			cost[3] = 3;
			if (choice(4) == true)
			{
				player.player_Tools[4]++;
			}
			exit = true;
		}
		else if (GetAsyncKeyState('3') & 0x8000)
		{
			system("cls");
			std::cout
				<< "Awali Ale (Item) - Temporary buff" << std::endl
				<< "+2 Armor" << std::endl << std::endl
				<< "+1 Attack" << std::endl << std::endl
				<< "-3 Total Energy" << std::endl << std::endl
				<< "-10% Accuracy" << std::endl << std::endl
				<< "Requirements:" << std::endl
				<< " 1 Gems" << std::endl
				<< " 3 Nishati" << std::endl
				<< " 5 Bones" << std::endl;
			cost[1] = 1;
			cost[2] = 3;
			cost[3] = 5;
			if (choice(4) == true)
			{
				player.player_Tools[5]++;
			}
			exit = true;
		}
	}
}

void battle::display(int what, int type)
{
	system("CLS");
	switch (type)
	{
	case 0:
		weapons(what);
		break;
	case 1:
		defense(what);
		break;
	case 2:
		energy(what);
		break;
	}
}

int battle::choice(int type)
{
	std::cout
		<< "Your resources:" << std::endl
		<< amnt.get(0) << " Alloy" << std::endl
		<< amnt.get(1) << " Gems" << std::endl
		<< amnt.get(2) << " Nishati" << std::endl
		<< amnt.get(3) << " Bones" << std::endl
		<< "\nMerchant: Do you wish to buy this item?" << std::endl
		<< " 1. buy" << std::endl
		<< " 0. back" << std::endl
		<< " Enter Command" << std::endl;
	while (1)
	{
		Sleep(100);
		if (GetAsyncKeyState('1') & 0x8000)
		{
			return buy(type);
		}
		else if (GetAsyncKeyState('0') & 0x8000)
		{
			return false;
		}
	}

}

int battle::buy(int type)
{
	if (amnt.get(0) > cost[0], amnt.get(1) > cost[1], amnt.get(2) > cost[2], amnt.get(3) > cost[3])
	{
		amnt.subtract(0, cost[0]);
		amnt.subtract(1, cost[1]);
		amnt.subtract(2, cost[2]);
		amnt.subtract(3, cost[3]);
		system("cls");
		cost[0] = 0;
		cost[1] = 0;
		cost[2] = 0;
		cost[3] = 0;
		place[type]++;
		std::cout << "You bought the item";
		return true;
	}
	else
	{
		cost[0] = 0;
		cost[1] = 0;
		cost[2] = 0;
		cost[3] = 0;
		std::cout << "You do not have enough resources";
		return false;
	}
}

// " "Info Displays the attributes of items
void battle::weapons(int what)
{
	switch (what)
	{
	case 0:
		std::cout
			<< "Nishati Musket (Weapon)" << std::endl
			<< " Range Damage 9 - 13" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 10 Alloy" << std::endl
			<< " 8 Nishati" << std::endl;
		cost[0] = 10;
		cost[2] = 8;
		if (choice(0) == true)
		{
			player.set_atkRange(9, 13);
		}

		break;
	case 1:
		std::cout
			<< "Rifle Pulsator (Weapon Mod)" << std::endl
			<< " +2 Damage" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Nishati Musket" << std::endl
			<< " 2 Gems" << std::endl
			<< " 20 Nishati" << std::endl;
		cost[1] = 2;
		cost[2] = 20;
		if (choice(0) == true)
		{
			player.set_atkRange(11, 15);
		}
		break;
	case 2:
		std::cout
			<< "Reflex Scope (Weapon Mod)" << std::endl
			<< " +1 Damge" << std::endl
			<< " +5% Accuracy" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Rifle Pulsator" << std::endl
			<< " 3 Alloy" << std::endl
			<< " 5 Gems" << std::endl;
		cost[0] = 3;
		cost[1] = 5;
		if (choice(0) == true)
		{
			player.set_atkRange(12, 16);

			player.set_acc(5);
		}
		break;
	case 3:
		std::cout
			<< "Nishati-Flux Capacitor (Weapon Mod)" << std::endl
			<< " Range Damage 10 - 15" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Reflex Scope" << std::endl
			<< " 4 Alloy" << std::endl
			<< " 5 Gems" << std::endl
			<< " 15 Nishati" << std::endl
			<< " 5 Bones" << std::endl;
		cost[0] = 4;
		cost[1] = 5;
		cost[2] = 15;
		cost[3] = 5;
		if (choice(0) == true)
		{
			player.set_atkRange(13, 18);
		}
		break;
	case 4:
		std::cout
			<< "Bayonet (Weapon Mod)" << std::endl
			<< " +2 Melee Damage" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Nishati-Flux Capacitor" << std::endl
			<< " 15 Alloy" << std::endl
			<< " 7 Bones" << std::endl;
		cost[0] = 15;
		cost[3] = 7;
		if (choice(0) == true)
		{
			player.set_atkRange(15, 20);
		}
		break;
	case 5:
		std::cout
			<< "Nishati Rifle (Weapon)" << std::endl
			<< " Range Damage 15 - 20" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Bayonet" << std::endl
			<< " 15 Alloy" << std::endl
			<< " 3 Gems" << std::endl
			<< " 10 Nishati" << std::endl
			<< " 10 Bones" << std::endl;
		cost[0] = 15;
		cost[1] = 3;
		cost[2] = 10;
		cost[3] = 10;
		if (choice(0) == true)
		{
			player.set_atkRange(20, 25);
		}
		break;
	case 6:
		std::cout
			<< "Nishati Beam Splitter" << std::endl
			<< " +3 Damage" << std::endl
			<< " -15% Accuracy" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Nishati Rifle" << std::endl
			<< " 10 Alloy" << std::endl
			<< " 10 Gems" << std::endl
			<< " 10 Nishati" << std::endl
			<< " 10 Bones" << std::endl;
		cost[0] = 10;
		cost[1] = 10;
		cost[2] = 10;
		cost[3] = 10;
		break;
		if (choice(0) == true)
		{
			player.set_atkRange(18, 23);
			player.set_acc(-5);
		}
	}
}

void battle::defense(int what)
{
	switch (what)
	{
	case 0:
		std::cout
			<< "Kepler Alloy Plate" << std::endl
			<< " +1 Armour" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 10 Alloy" << std::endl
			<< " 3 Nishati" << std::endl;
		cost[0] = 10;
		cost[2] = 3;
		if (choice(1) == true)
		{
			player.set_armor(player.get_armor() + 1);
		}
		break;
	case 1:
		std::cout
			<< "Awali Charm" << std::endl
			<< " +10 HP" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Kepler Alloy Plate" << std::endl
			<< " 2 Alloy" << std::endl
			<< " 5 Gems" << std::endl
			<< " 3 Nishati" << std::endl
			<< " 1 Bone" << std::endl;
		cost[0] = 2;
		cost[1] = 5;
		cost[2] = 3;
		cost[3] = 1;
		if (choice(1) == true)
		{
			player.set_MaxHp(player.get_MaxHp() + 10);
		}
		break;
	case 2:
		std::cout
			<< "Kepler Alloy Plate" << std::endl
			<< "+5 Hp" << std::endl
			<< "+ 1 Armor" << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Awali Charm" << std::endl
			<< " 5 Alloy" << std::endl
			<< " 3 Nishati" << std::endl
			<< " 1 Bone" << std::endl;
		cost[0] = 5;
		cost[2] = 3;
		cost[3] = 1;
		if (choice(1) == true)
		{
			player.set_MaxHp(player.get_MaxHp() + 5);
			player.set_armor(player.get_armor() + 1);
		}
		break;
	case 3:
		std::cout
			<< "Gem Infused Plating" << std::endl
			<< " +1 Armour" << std::endl
			<< " +10 HP" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Kepler Alloy Plate" << std::endl
			<< " 5 Alloy" << std::endl
			<< " 7 Gems" << std::endl;
		cost[0] = 5;
		cost[1] = 7;
		if (choice(1) == true)
		{
			player.set_MaxHp(player.get_MaxHp() + 10);
			player.set_armor(player.get_armor() + 1);
		}
		break;
	case 4:
		std::cout
			<< "Kepler Bone Plate" << std::endl
			<< " +1 Armour" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Gem Infused Plating" << std::endl
			<< " 25 Bones" << std::endl;
		cost[3] = 25;
		if (choice(1) == true)
		{
			player.set_armor(player.get_armor() + 1);
		}
		break;
	case 5:
		std::cout
			<< "Nishati Shielding System" << std::endl
			<< " +1 Armour" << std::endl
			<< " Restore Energy Every 4 steps" << std::endl << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Kepler Bone Plate" << std::endl
			<< " 10 Alloy" << std::endl
			<< " 10 Gems" << std::endl
			<< " 10 Nishati" << std::endl
			<< " 10 Bones" << std::endl;
		cost[0] = 10;
		cost[1] = 10;
		cost[2] = 10;
		cost[3] = 10;
		if (choice(1) == true)
		{
			player.set_armor(player.get_armor() + 1);
		}
		break;
	}

}

void battle::energy(int what)
{
	switch (what)
	{
	case 0:

		std::cout
			<< "Lighter Alloy" << std::endl
			<< " +5 Energy" << std::endl
			<< "Requirements:" << std::endl
			<< " 5 Alloy" << std::endl
			<< " 3 Gems" << std::endl;
		cost[0] = 5;
		cost[1] = 3;
		if (choice(2) == true)
		{
			player.increase_maxEnergy(5);
		}
		break;
	case 1:
		std::cout
			<< "Nishati Charm" << std::endl
			<< " Attacking costs 1 less energy" << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Lighter Alloy" << std::endl
			<< " 5 Gems" << std::endl
			<< " 10 Nishati" << std::endl;
		cost[1] = 5;
		cost[2] = 10;
		if (choice(2) == true)
		{
			player.set_atkCost(-1);
		}
		break;
	case 2:
		std::cout
			<< "Nishati Overclocking System" << std::endl
			<< " +2 Energy when waiting" << std::endl
			<< "Requirements:" << std::endl
			<< " 1 Nishati Charm" << std::endl
			<< " 3 Alloy" << std::endl
			<< " 3 Gems" << std::endl
			<< " 5 Nishati" << std::endl
			<< " 3 Bones" << std::endl;
		cost[0] = 3;
		cost[1] = 3;
		cost[2] = 5;
		cost[3] = 3;
		if (choice(2) == true)
		{
			player.set_recover(2);
		}
		break;
	}
}

void battle::battleOver()
{
	player.awali_buff(false);
	player.blood_buff(false);

	//Collect monster blood with an 20% chance
	if (rand() % 100 > 80)
	{
		player.player_Tools[6] += 1;
	}
}