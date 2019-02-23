#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include "battle.h"



enum biomeType
{
	edgej = 1,
	deepj = 2,
	cliff = 3,
	plateau = 4,
	cave = 5,
	boss = 6
};

combatObject edgeEnemies[4];
combatObject deepEnemies[5];
combatObject cliffEnemies[3];
combatObject plateauEnemies[3];
combatObject caveEnemies[3];
combatObject bosses[4];

void buildEnemyLibrary();

int selects();

combatObject buildBattle(int biome);

void combatMain()
{
	battle players;
	players.updateBattle(false);
	buildEnemyLibrary();
	int enemies;
	int order = 0;
	int temp = 0;
	int turn = 0;

	int size = sizeof(combatObject);
	std::cout << "size is=" << size << std::endl;

 	while (players.level.getMax() <= 40)
	{

		if (players.move(players.p_mazes) == true)
		{
			
			enemies = rand() % 3;
 			for (int count = 0; count <= enemies; count++)
			{
				players.tempEnemy[count] = buildBattle(edgej);
			}
			while (players.death() == 2)
			{
				players.updateBattle(false);
				players.playerCommand();
				if (players.death() == 2)
				{
					players.updateBattle(false);
					temp = players.enemyCommand(order);
					while (temp != order)
					{
						if (order >= 2)
						{
							order = 0;
						}
						else
						{
							order++;
						}
						temp = players.enemyCommand(order);
					}
					if (temp + 1 >= 3)
					{
						order = 0;
					}
					else
					{
						order = temp + 1;
					}
					players.player.increase_curEnergy(1);

				}
				players.updateBattle(false);
			}
			players.battleOver();
		}
		else if (players.inCave == true)
		{
			players.p_mazes = &players.cave;
		}
		else
		{
			players.p_mazes = &players.level;
		}
	}
}


void buildEnemyLibrary()
{
	//Jungle Edge
	edgeEnemies[0] = combatObject("Monger", 20, 3, 6, 0, false, true, 80);
	edgeEnemies[1] = combatObject("Bird", 15, 3, 6, 0, false, true, 90);
	edgeEnemies[2] = combatObject("Mushroom", 30, 2, 3, 1, false, true, 80);
	edgeEnemies[3] = combatObject("Spiky", 20, 4, 4, 1, false, true, 80);

	//Deep Jungle 
	//hp, max, min, def, acc
	deepEnemies[0] = combatObject("Slug", 25, 8, 10, 1, false, true, 40);
	deepEnemies[1] = combatObject("Cougar", 15, 5, 8, 1, false, true, 90);
	deepEnemies[2] = combatObject("Pack-Monkey", 20, 5, 7, 1, false, true, 80);
	deepEnemies[3] = combatObject("Solitude", 50, 3, 6, 2, false, true, 100);
	deepEnemies[4] = combatObject("Mantis", 15, 10, 12, 0, false, true, 90);

	//Cliffs
	cliffEnemies[0] = combatObject("Dactyl", 40, 7, 9, 3, false, true, 100);
	cliffEnemies[1] = combatObject("Cougar", 50, 5, 7, 3, false, true, 80);
	cliffEnemies[2] = combatObject("Boxy", 70, 3, 3, 1, false, true, 100);

	//Pleateu 
	plateauEnemies[0] = combatObject("Symbiote", 50, 10, 12, 1, false, true, 100);
	plateauEnemies[1] = combatObject("Sloth", 50, 8, 10, 3, false, true, 80);
	plateauEnemies[2] = combatObject("Lizard", 30, 12, 15, 1, false, true, 50);

	//Caves
	caveEnemies[0] = combatObject("Rock-Crab", 20, 3, 3, 3, false, true, 80);
	caveEnemies[1] = combatObject("Bat", 10, 3, 3, 0, false, true, 50);
	caveEnemies[2] = combatObject("Stalacthing", 5, 7, 7, 10, false, true, 80);

	//Bosses
	bosses[0] = combatObject("King Monger", 60, 7, 10, 3, false, true, 80);
	bosses[1] = combatObject("Queen Mantis", 40, 15, 20, 1, false, true, 75);
	bosses[2] = combatObject("Big Crab", 120, 3, 3, 7, false, true, 100);
	bosses[3] = combatObject("Drake Mk II", 100, 20, 25, 10, false, true, 100);
}

int selects()
{

	while (1)
	{
		switch (1)
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
		else if (GetAsyncKeyState('5') & 0x8000)
		{
			return 5;
		}
	}
}

combatObject buildBattle(int biome){

	int ranEn;
	switch (biome)
	{
	case edgej:
		ranEn = 0 + (rand() % (int)(4));
		return edgeEnemies[ranEn];
		break;

	case deepj:
		ranEn = 0 + (rand() % (int)(5));
		return edgeEnemies[ranEn];
		break;

	case cliff:
		ranEn = 0 + (rand() % (int)(3));
		return edgeEnemies[ranEn];
		break;

	case plateau:
		ranEn = 0 + (rand() % (int)(3));
		return edgeEnemies[ranEn];
		break;

	case cave:
		ranEn = 0 + (rand() % (int)(3));
		return edgeEnemies[ranEn];
		break;
	case boss:
		ranEn = 0 + (rand() % (int)(4));
		return edgeEnemies[ranEn];
		break;
	}


}