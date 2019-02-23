//
//bool combatDriver();
//bool fleeCheck;
//int buildBattle(int biome);
//int numEnemy;
//bool isCrit;
//bool playerTurn;
//int enemyOrder;
//void wait(int);
//
//void playerCommand();
//
//
//bool radialBlind = false;
//
//combatObject tempEnemy[3];
//
//
//
//
//void set_potions(int x, int y)
//{
//	player.player_Tools[x] += y;
//}
//
//int get_Resources(){
//	return player.player_Tools[0];
//}
//
//
//

//void increase_Potions(int val){
//	player.player_Tools[3] += val;
//}

//
//
//
//
//void increase_maxHp(int val){
//	int newMax = player.get_MaxHp() + val;
//
//	player.set_MaxHp(newMax);
//}
//
//
////0 = Resources, 1 = Max Energy, 2 = Cur Energy 3 = Potions, 4 greater potion, 5, awali ale, 6, monster blood
////awali ale, 1 = monster blood
////enemy status effects.
//
//
//void unbuff()
//{
//	if (player.buffs[0] == true)
//	{
//		player.awali_buff(false);
//	}
//	if (player.buffs[1] == true)
//	{
//		player.blood_buff(false);
//	}
//}
//
//bool pDeath()
//{
//	if (player.get_curHp() <= 0)
//	{
//		player.set_isAlive(false);
//		return false;
//	}
//	return true;
//}
//
//bool death()
//{
//	if (tempEnemy[0].get_isAlive() == false && tempEnemy[1].get_isAlive() == false && tempEnemy[2].get_isAlive() == false)
//	{
//		return true;
//	}
//	return false;
//}
//
//int selects()
//{
//	while (1)
//	{
//		if (GetAsyncKeyState('0') & 0x8000)
//		{
//			return 0;
//		}
//		else if (GetAsyncKeyState('1') & 0x8000)
//		{
//			return 1;
//		}
//		else if (GetAsyncKeyState('2') & 0x8000)
//		{
//			return 2;
//		}
//		else if (GetAsyncKeyState('3') & 0x8000)
//		{
//			return 3;
//		}
//		else if (GetAsyncKeyState('4') & 0x8000)
//		{
//			return 4;
//		}
//	}
//}
//
//int selects_1()
//{
//	while (1)
//	{
//		if (GetAsyncKeyState('1') & 0x8000)
//		{
//			return 1;
//		}
//		else if (GetAsyncKeyState('2') & 0x8000)
//		{
//			return 2;
//		}
//		else if (GetAsyncKeyState('3') & 0x8000)
//		{
//			return 3;
//		}
//		else if (GetAsyncKeyState('4') & 0x8000)
//		{
//			return 4;
//		}
//		else if (GetAsyncKeyState('5') & 0x8000)
//		{
//			return 5;
//		}
//	}
//}
//
//bool check()
//{
//	if ((tempEnemy[0].get_isAlive() == false && tempEnemy[1].get_isAlive() == false && tempEnemy[2].get_isAlive() == false))
//	{
//		return false;
//	}
//	return true;
//}
//
//
//
//void updateBattle(bool move){
//	std::string temp = "";
//	DWORD written;
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 3 + y });
//	printf("                       ");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 4 + y });
//	printf("                       ");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 5 + y });
//	printf("                       ");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 6 + y });
//	printf("                       ");
//
//
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 3 + y });
//	temp += player.get_Name();
//	int numTemp;
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 4 + y });
//	temp = "";
//	temp += "HP: ";
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//	if (player.get_curHp() < player.get_MaxHp() / 2)
//	{
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//	}
//	std::string hpColour;
//	hpColour = std::to_string(player.get_curHp());
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), hpColour.c_str(), hpColour.size(), &written, NULL);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//
//	temp = "/";
//	numTemp = player.get_MaxHp();
//	temp += std::to_string(numTemp);
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 5 + y });
//	temp = "";
//	temp += "Energy: ";
//
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//	if (player.player_Tools[2] < player.player_Tools[1] / 2)
//	{
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//	}
//	std::string energyColour;
//	energyColour = std::to_string(player.player_Tools[2]);
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), energyColour.c_str(), hpColour.size(), &written, NULL);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//
//
//	temp = "/";
//	temp += std::to_string(player.player_Tools[1]);
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//
//	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 6 + y });
//	//temp = "";
//	//temp += "Potions: ";
//	//temp += std::to_string(player.player_Tools[3]);
//	//WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//
//	if (move == false)
//	{
//		if (tempEnemy[0].get_isAlive() == true){
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 0 + y });
//			std::cout << tempEnemy[0].get_Name();
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 1 + y });
//			std::cout << "HP: " << tempEnemy[0].get_curHp() << " ";
//		}
//		else
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 0 + y });
//			std::cout << "                       ";
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 1 + y });
//			std::cout << "                       ";
//		}
//
//		if (tempEnemy[1].get_isAlive() == true){
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 3 + y });
//			std::cout << tempEnemy[1].get_Name();
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 4 + y });
//			std::cout << "HP: " << tempEnemy[1].get_curHp() << " ";
//		}
//		else
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 3 + y });
//			std::cout << "                      ";
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 4 + y });
//			std::cout << "                      ";
//		}
//
//		if (tempEnemy[2].get_isAlive() == true){
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 6 + y });
//			std::cout << tempEnemy[2].get_Name();
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 7 + y });
//			std::cout << "HP: " << tempEnemy[2].get_curHp() << " ";
//		}
//		else
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 6 + y });
//			std::cout << "                      ";
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cEPos, 7 + y });
//			std::cout << "                      ";
//		}
//	}
//}
//
//void clearCommands(){
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 });
//	printf("														");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 });
//	printf("														");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 });
//	printf("										                ");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 });
//	printf("														");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 });
//	printf("														");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 });
//	printf("										                ");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 });
//	printf("										                ");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 });
//	printf("										                ");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 18 });
//	printf("													   ");
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 });
//}
//
//void wait(int x)
//{
//	for (int count = 0; count < x; count++)
//	{
//		Sleep(1);
//		if (GetAsyncKeyState(VK_SPACE))
//		{
//			count = 1005;
//		}
//	}
//}
//
//
//
//void playerCommand()
//{
//	std::string temp;
//	DWORD written;
//	int tempSelect;
//	int select;
//	int target = 0;
//	int dmg;
//	int cur;
//	int max;
//
//	player.set_isBlocking(false);
//
//	if (death() == false)
//	{
//
//		Sleep(100);
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//		printf("It is your turn!								");// 10
//
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//		temp = "1. Attack. Cost: " + std::to_string(energyAtkCost) + " Energy. Damage: " + std::to_string(player.get_atkMin()) + " - " + std::to_string(player.get_atkMax());
//		temp += "							";
//		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//		printf("2. Block. Cost: 2 Energy. Take half damage during next attack							");//12
//
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
//		printf("3. Use Item Cost: 2 Energy.								"); //13
//
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
//		std::cout << "4. Wait. Gain " << energyGain << " Energy.								"; //14
//
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
//		printf("5. Flee:									"); //15
//
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//		printf("Enter a Command:									"); //15
//
//		select = selects_1();
//
//		switch (select){
//		case 1:
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			printf("You are attacking! Select a Target.									"); //10
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//			printf("1. Top Enemy								"); //11
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//			printf("2. Middle Enemy								"); //12
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
//			printf("3. Bottom Enemy										"); //13
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
//			printf("0. Go Back.													"); //14
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
//			printf("Enter a Command:											"); //15
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//			printf("											"); //15
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
//			Sleep(200);
//			tempSelect = selects();
//
//			if ((tempSelect == 1 || tempSelect == 2 || tempSelect == 3) && get_curEnergy() > 2)
//			{
//				target = tempSelect;
//			}
//			else if (tempSelect == 0)
//			{
//				playerCommand();
//
//			}
//			else if (get_curEnergy() < energyAtkCost)
//			{
//				clearCommands();
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//				printf("INSUFFICIENT ENERGY												");
//				target = 0;
//				wait(500);
//				playerCommand();
//			}
//			else
//			{
//				clearCommands();
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//				printf("INVALID COMMAND													");
//				wait(500);
//				playerCommand();
//			}
//
//			if (tempEnemy[target - 1].get_isAlive() == false){
//				clearCommands();
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//				printf("INVALID COMMAND												");
//				wait(500);
//				playerCommand();
//				target = 0;
//			}
//			break;
//
//		case 2:
//			if (get_curEnergy() >= 2)
//			{
//				reduce_curEnergy(2);
//				clearCommands();
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//				printf("You are blocking! You take half damage.									"); //10
//				playerTurn = false;
//				wait(500);
//				combatDriver();
//			}
//			else
//			{
//				clearCommands();
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//				printf("INSUFFICIENT ENERGY															");
//				wait(500);
//				playerCommand();
//			}
//
//			break;
//
//		case 3:
//
//			clearCommands();
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			printf("Choose a potion														"); //10
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//			temp = "1. Restoration Potion:" + std::to_string(player.player_Tools[3]) + "							";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//			temp = "2. Greater Restoration Potion:" + std::to_string(player.player_Tools[4]) + "							";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//
//			//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
//			//printf("											"); //13
//			//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });			
//			//printf("											"); //14
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
//			temp = "3. Awali Ale: " + std::to_string(player.player_Tools[5]);
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
//			temp = "4. Distilled Monster Blood: " + std::to_string(player.player_Tools[6]);
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
//			printf("0. Go Back .								");
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//			printf("Enter a Command:									");
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
//
//			Sleep(200);
//			tempSelect = selects();
//			switch (tempSelect)
//			{
//			case 1:
//
//				if (player.get_curHp() < player.get_MaxHp() && get_curEnergy() >= 2 && player.player_Tools[3]>0)
//				{
//					clearCommands();
//					reduce_curEnergy(2);
//					int restored = use_Potion();
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//					printf("You use a Potion.														");
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//					temp = "You have restored " + std::to_string(restored) + "HP												";
//					WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//					playerTurn = false;
//					wait(500);
//					combatDriver();
//				}
//				else if (get_curEnergy() < 2)
//				{
//					clearCommands();
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//					printf("INSUFFICIENT ENERGY															");
//					wait(500);
//					playerCommand();
//				}
//				else if (player.player_Tools[3] <= 0)
//				{
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//					printf("You have no more Potions.														");
//					wait(500);
//					playerCommand();
//				}
//				else
//				{
//					clearCommands();
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//					printf("You are at Max HP.																");
//					wait(500);
//					playerCommand();
//				}
//				break;
//			case 2:
//
//				if (player.get_curHp() < player.get_MaxHp() && get_curEnergy() >= 2 && player.player_Tools[4] > 0)
//				{
//					clearCommands();
//					reduce_curEnergy(2);
//					int restored = use_GPotion();
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//					printf("You use a Greater Potion.													");
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//					temp = "You have restored " + std::to_string(restored) + "HP							";
//					WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//					playerTurn = false;
//					wait(500);
//					combatDriver();
//				}
//				else if (get_curEnergy() < 2)
//				{
//					clearCommands();
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//					printf("INSUFFICIENT ENERGY																");
//					wait(500);
//					playerCommand();
//				}
//				else if (player.player_Tools[3] <= 0)
//				{
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//					printf("You have no more Greater Potions.												");
//					wait(500);
//					playerCommand();
//				}
//				else
//				{
//					clearCommands();
//
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//					printf("You are at Max HP.																");
//					wait(500);
//					playerCommand();
//				}
//				break;
//			case 3:
//				if (player.player_Tools[5] > 0)
//				{
//					player.awali_buff(true);
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//					printf("You drink some Awali ale.													");
//					playerTurn = false;
//					combatDriver();
//				}
//				else
//				{
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//					printf("You have no more Awali Ale.														");
//					wait(500);
//					playerCommand();
//				}
//				break;
//			case 4:
//				if (player.player_Tools[6] > 0)
//				{
//					player.blood_buff(true);
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//					printf("You inject yourself with distilled monster blood .													");
//					playerTurn = false;
//					combatDriver();
//				}
//				else
//				{
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//					printf("You have no more Distilled Blood.														");
//					wait(500);
//					playerCommand();
//				}
//
//				break;
//			}
//			playerCommand();
//			break;
//		case 4:
//			cur = get_curEnergy();
//			max = get_maxEnergy();
//
//			clearCommands();
//
//			if (cur < max)
//			{
//				int restore = increase_curEnergy(energyGain);
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//				temp = "You restored " + std::to_string(restore) + " energy!										";
//				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//				playerTurn = false;
//				wait(500);
//
//				combatDriver();
//			}
//
//			else {
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//				printf("You already have maximum energy!											");
//				wait(500);
//				combatDriver();
//			}
//			break;
//		case 5:
//			if (fleeCheck == false){
//				if (rand() % 100 + 1 < 33)
//				{
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
//					printf("You succesfully fled from combat.");
//					tempEnemy[0].set_isAlive(false);
//					tempEnemy[1].set_isAlive(false);
//					tempEnemy[2].set_isAlive(false);
//					wait(500);
//					clearCommands();
//					updateBattle(false);
//				}
//				else
//				{
//					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
//					fleeCheck = true;
//					printf("You failed to flee from combat.");
//
//
//					playerTurn = false;
//					wait(500);
//					combatDriver();
//				}
//			}
//			else
//			{
//				clearCommands();
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//				fleeCheck = true;
//				printf("You've already attempted to flee! The enemy suspsects you!");
//				wait(500);
//				playerTurn = true;
//				playerCommand();
//			}
//			break;
//		}
//	}
//	if (target > 0)
//	{
//		target -= 1;
//		reduce_curEnergy(energyAtkCost);
//		clearCommands();
//		if (player.get_Acc() == true)
//		{
//
//			dmg = damageCalc(true, target);
//			tempEnemy[target].set_curHp(tempEnemy[target].get_curHp() - dmg);
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			temp = "You attack " + tempEnemy[target].get_Name() + "							";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//10
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//			if (isCrit == true){
//				temp = "Critical Strike! " + tempEnemy[target].get_Name() + " takes " + std::to_string(dmg) + " damage!						";
//				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
//			}
//			else {
//				temp = tempEnemy[target].get_Name() + " takes " + std::to_string(dmg) + " damage!								";
//				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
//			}
//
//			if (tempEnemy[target].get_curHp() <= 0){
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//				temp = "You have killed " + tempEnemy[target].get_Name() + "							";
//				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//				tempEnemy[target].set_isAlive(false);
//			}
//		}
//		else
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			temp = "Your attack misses the " + tempEnemy[target].get_Name() + "							";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//10
//		}
//
//		playerTurn = false;
//		wait(500);
//		combatDriver();
//	}
//}
//
//void enemyCommand(){
//	int choice;
//	int dmg;
//	if (tempEnemy[enemyOrder].get_isAlive() == true){
//		std::string eneName = tempEnemy[enemyOrder].get_Name();
//
//		tempEnemy[enemyOrder].set_isBlocking(false);
//
//		clearCommands();
//		std::cout << "It is " << eneName << "'s turn." << std::endl;
//
//		srand(time(NULL));
//		choice = 1 + (rand() % (int)(10));
//
//		if (choice >= 1 && choice < 8){
//			dmg = damageCalc(false, enemyOrder);
//
//			if (radialBlind == true){
//				int radial = 1 + (rand() % (int)(5));
//				if (radial == 3){
//					dmg = 0;
//				}
//			}
//
//			if (tempEnemy[enemyOrder].get_Acc() == true)
//			{
//				reduce_curHp(dmg);
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//				std::cout << eneName << " attacks the player. " << std::endl; //10
//
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//
//				if (isCrit == true){
//					std::cout << "Critical Strike! " + player.get_Name() << " takes " << dmg << " damage!" << std::endl; //11
//					playerTurn = true;
//				}
//				else if (dmg == 0){
//					std::cout << "RADIAL BLIND! #SPOOKY!" << player.get_Name() << " takes " << dmg << " damage!" << std::endl;
//					playerTurn = true;
//				}
//				else {
//					std::cout << player.get_Name() << " takes " << dmg << " damage!" << std::endl; //11
//					playerTurn = true;
//				}
//				pDeath();
//			}
//			else
//			{
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//				std::cout << eneName << " attacks the player and misses" << std::endl; //10
//			}
//
//			enemyOrder++;
//			if (enemyOrder > 2){
//				enemyOrder = 0;
//			}
//			for (int count = 0; count < 50; count++)
//			{
//				Sleep(1);
//			}
//			for (int count = 0; count < 1000; count++)
//			{
//				Sleep(1);
//				if (GetAsyncKeyState(VK_SPACE))
//				{
//					count = 1005;
//				}
//			}
//		}
//		else
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//			std::cout << eneName << " is blocking and will take half damage if it is attacked. " << std::endl; //10
//			tempEnemy[enemyOrder].set_isBlocking(true);
//			for (int count = 0; count < 50; count++)
//			{
//				Sleep(1);
//			}
//			for (int count = 0; count < 1000; count++)
//			{
//				Sleep(1);
//				if (GetAsyncKeyState(VK_SPACE))
//				{
//					count = 1005;
//				}
//			}
//			playerTurn = true;
//		}
//		playerTurn = true;
//		combatDriver();
//	}
//	else {
//		enemyOrder++;
//		if (enemyOrder > 2){
//			enemyOrder = 0;
//		}
//		combatDriver();
//	}
//}
//
//int boneCheck(){
//
//	if (rand() % 100 < 35 && fleeCheck == false)
//	{
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50, 12 });
//		std::cout << "You aquire some bones";
//		return numEnemy;
//	}
//	return 0;
//}
//
//bool combatDriver(){
//
//	updateBattle(false);
//	if (player.get_isAlive() == true && check() == true)
//	{
//		if (playerTurn == true)
//		{
//			increase_curEnergy(1);
//			updateBattle(false);
//			playerCommand();
//		}
//		else
//		{
//			updateBattle(false);
//			enemyCommand();
//		}
//	}
//
//	clearCommands();
//
//	if (pDeath() == false)
//	{
//		Sleep(50);
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 });
//		return false;
//	}
//	else
//	{
//		if (check() == true){
//			if (rand() % 100 + 1 < 5)
//			{
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50, 11 });
//				std::cout << "You aquire some monster blood";
//				set_potions(6, 1);
//
//			}
//		}
//		unbuff();
//		return true;
//	}
//}
//
//
//
//void steps(bool types)
//{
//	player.steps(types);
//}
//
//void buildBoss(int area)
//{
//	playerTurn = true;
//	buildEnemyLibrary();
//	switch (area)
//	{
//	case 1:
//		tempEnemy[0] = edgeEnemies[0];
//		tempEnemy[1] = bosses[0];
//		tempEnemy[2] = edgeEnemies[0];
//		break;
//	case 2:
//		tempEnemy[1] = bosses[1];
//		break;
//	case 3:
//		tempEnemy[1] = bosses[2];
//		break;
//	case 4:
//		tempEnemy[1] = bosses[3];
//		break;
//	}
//}
//
//
//void atack()
//{
//	int dmg;
//	std::string temp;
//	int target = 0;
//	int tempSelect;
//	DWORD written;
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//	printf("You are attacking! Select a Target.									"); //10
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//	printf("1. Top Enemy								"); //11
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//	printf("2. Middle Enemy								"); //12
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
//	printf("3. Bottom Enemy										"); //13
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
//	printf("0. Go Back.													"); //14
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
//	printf("Enter a Command:											"); //15
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//	printf("											"); //15
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
//	Sleep(200);
//	tempSelect = selects();
//
//	if ((tempSelect == 1 || tempSelect == 2 || tempSelect == 3) && get_curEnergy() > 2)
//	{
//		target = tempSelect;
//	}
//	else if (tempSelect == 0)
//	{
//		playerCommand();
//
//	}
//	else if (get_curEnergy() < 3)
//	{
//		clearCommands();
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//		printf("INSUFFICIENT ENERGY												");
//		target = 0;
//		wait(500);
//		playerCommand();
//	}
//	else
//	{
//		clearCommands();
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//		printf("INVALID COMMAND													");
//		wait(500);
//		playerCommand();
//	}
//
//	if (tempEnemy[target - 1].get_isAlive() == false){
//		clearCommands();
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//		printf("INVALID COMMAND												");
//		wait(500);
//		playerCommand();
//		target = 0;
//	}
//	if (target > 0)
//	{
//		target -= 1;
//		reduce_curEnergy(3);
//		clearCommands();
//		if (player.get_Acc() == true)
//		{
//
//			dmg = damageCalc(true, target);
//			tempEnemy[target].set_curHp(tempEnemy[target].get_curHp() - dmg);
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			temp = "You attack " + tempEnemy[target].get_Name() + "							";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//10
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//			if (isCrit == true){
//				temp = "Critical Strike! " + tempEnemy[target].get_Name() + " takes " + std::to_string(dmg) + " damage!						";
//				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
//			}
//			else {
//				temp = tempEnemy[target].get_Name() + " takes " + std::to_string(dmg) + " damage!								";
//				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
//			}
//
//			if (tempEnemy[target].get_curHp() <= 0){
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//				temp = "You have killed " + tempEnemy[target].get_Name() + "							";
//				WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//				tempEnemy[target].set_isAlive(false);
//			}
//		}
//		else
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			temp = "Your attack misses the " + tempEnemy[target].get_Name() + "							";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//10
//		}
//
//		playerTurn = false;
//		wait(500);
//		combatDriver();
//	}
//
//}
//
//void energy()
//{
//	if (get_curEnergy() >= 2)
//	{
//		reduce_curEnergy(2);
//		clearCommands();
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//		printf("You are blocking! You take half damage.									"); //10
//		playerTurn = false;
//		wait(500);
//		combatDriver();
//	}
//	else
//	{
//		clearCommands();
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//		printf("INSUFFICIENT ENERGY															");
//		wait(500);
//		playerCommand();
//	}
//}
//
//void potions()
//{
//	DWORD written;
//	int tempSelect;
//	std::string temp;
//
//	clearCommands();
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//	printf("Choose a potion														"); //10
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//	temp = "1. Restoration Potion:" + std::to_string(player.player_Tools[3]) + "							";
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//11
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//	temp = "2. Greater Restoration Potion:" + std::to_string(player.player_Tools[4]) + "							";
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
//	printf("0. Go Back .								");
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
//	printf("Enter a Command:									");
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
//
//	int choice = 0;
//	bool potions = true;
//	while (potions == true)
//	{
//		if (GetAsyncKeyState('0') & 0x8000)
//		{
//			potions = false;
//			choice = 0;
//		}
//		else if (GetAsyncKeyState('1') & 0x8000)
//		{
//			choice = 1;
//			potions = false;
//		}
//		else if (GetAsyncKeyState('2') & 0x8000)
//		{
//			choice = 2;
//			potions = false;
//		}
//
//	}
//	switch (choice)
//	{
//	case 1:
//
//		if (player.get_curHp() < player.get_MaxHp() && player.player_Tools[3]>0)
//		{
//			clearCommands();
//			int restored = use_Potion();
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			printf("You use a Potion.														");
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//			temp = "You have restored " + std::to_string(restored) + "HP												";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//			playerTurn = false;
//			wait(500);
//			combatDriver();
//		}
//		else if (player.player_Tools[3] <= 0)
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//			printf("You have no more Potions.														");
//			wait(500);
//			playerCommand();
//		}
//		else
//		{
//			clearCommands();
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			printf("You are at Max HP.																");
//			wait(500);
//		}
//		break;
//	case 2:
//
//		if (player.get_curHp() && player.player_Tools[4] > 0)
//		{
//			clearCommands();
//			int restored = use_GPotion();
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			printf("You use a Greater Potion.													");
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//			temp = "You have restored " + std::to_string(restored) + "HP							";
//			WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);//12
//			playerTurn = false;
//			wait(500);
//		}
//		else if (player.player_Tools[3] <= 0)
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//			printf("You have no more Greater Potions.												");
//			wait(500);
//		}
//		else
//		{
//			clearCommands();
//
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//			printf("You are at Max HP.																");
//			wait(500);
//		}
//
//	}
//}
//
//void options()
//{
//	std::string temp;
//	DWORD written;
//	//int tempSelect;
//	int cur;
//	int max;
//	int select;
//
//
//	//int cur;
//	//int max;
//
//	Sleep(100);
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 10 + y });
//	printf("It is your turn!								");// 10
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 11 + y });
//	temp = "1. Attack. Cost: 3 Energy. Damage: " + std::to_string(player.get_atkMin()) + " - " + std::to_string(player.get_atkMax());
//
//	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), temp.c_str(), temp.size(), &written, NULL);
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 12 + y });
//	printf("2. Block. Cost: 2 Energy. Take half damage during next attack							");//12
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 13 + y });
//	printf("3. Use Item Cost: 2 Energy.								"); //13
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 14 + y });
//	printf("4. Wait. Gain 2 Energy.								"); //14
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 15 + y });
//	printf("5. Flee:									"); //15
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 16 + y });
//	printf("Enter a Command:									"); //15
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 17 + y });
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { cPPos, 18 + y });
//}