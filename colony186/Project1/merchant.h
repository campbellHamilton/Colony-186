//#include <iostream>
//#include <string>
//#include <Windows.h>
//
//// PROTOTYPES
//void merchant(int &alloy, int &bones, int &gems, int &nishati);
//
//// Function called to displays user's current resources
//void getResources(int &alloy, int &bones, int &gems, int &nishati)
//{
//	std::cout
//		<< std::endl
//		<< "Your Resources:" << std::endl
//		<< " " << alloy << " Alloy" << std::endl
//		<< " " << gems << " Gems" << std::endl
//		<< " " << nishati << " Nishati" << std::endl
//		<< " " << bones << " Bones" << std::endl;
//}
//
//// Function called when user chooses to buy an upgrade
//void buy(std::string name, int &counter, int itemLvl, bool &weapon, bool &requirements, int &alloy, int &bones, int &gems, int&nishati, int &alloyReq, int &bonesReq, int &gemsReq, int&nishatiReq);
//
//// Called when user chooses to buy a consumable
//void buy(std::string name, int  &potion, bool &requirements, int &alloy, int &bones, int &gems, int&nishati, int &alloyReq, int &bonesReq, int &gemsReq, int&nishatiReq)
//{
//	getResources(alloy, bones, gems, nishati);
//	std::cout
//		<< std::endl
//		<< "Merchant: Do you wish to buy this item?" << std::endl
//		<< " 1. Buy" << std::endl
//		<< " 0. Back" << std::endl;
//	//<< "Enter Command: ";
//	bool browse = true;
//	while (browse)
//	{
//		if (GetAsyncKeyState('1') & 0x8000)
//		{
//			if (requirements == true)
//			{
//				potion += 1;
//				alloy -= alloyReq;
//				bones -= bonesReq;
//				gems -= gemsReq;
//				nishati -= nishatiReq;
//				browse = false;
//				system("cls");
//				std::cout << "Merchant: You have purchased a \"" << name << "\"" << std::endl << std::endl;
//				system("pause");
//				Sleep(300);
//				system("cls");
//			}
//			else
//			{
//				browse = false;
//				system("cls");
//				std::cout << "Merchant: Apologies stranger, you do not meet the requirements to purchase this item." << std::endl << std::endl;
//				system("pause");
//			}
//		}
//		if (GetAsyncKeyState('0') & 0x8000)
//		{
//			browse = false;
//			system("cls");
//		}
//	}
//	merchant(alloy, bones, gems, nishati);
//}
//
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//// ATTACK UPGRADES
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//
//int counterAU = 1;
//bool musket = false;
//bool pulsator = false;
//bool scope = false;
//bool capacitor = false;
//bool bayonet = false;
//bool rifle = false;
//bool splitter = false;
//bool focuser = false;
//
//// Displays attack upgrades available for purchase
//void AUlist()
//{
//	system("cls");
//	std::cout
//		<< "Merchant: Attack Upgrades" << std::endl
//		<< " 1. Nishati Musket" << std::endl
//		<< " 2. Rifle Pulsator" << std::endl
//		<< " 3. Reflex Scope" << std::endl
//		<< " 4. Nishati-Flux Capacitor" << std::endl
//		<< " 5. Bayonet" << std::endl
//		<< " 6. Nishati Rifle" << std::endl
//		<< " 7. Nishati Beam Splitter" << std::endl
//		<< " 0. Back" << std::endl
//		<< "Enter Command: ";
//}
//
//// " "Info Displays the attributes of items
//void musketInfo()
//{
//	std::cout
//		<< "Nishati Musket (Weapon)" << std::endl
//		<< " Range Damage 9 - 13" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 10 Alloy" << std::endl
//		<< " 8 Nishati" << std::endl;
//}
//void pulsatorInfo()
//{
//	std::cout
//		<< "Rifle Pulsator (Weapon Mod)" << std::endl
//		<< " +2 Damage" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Nishati Musket" << std::endl
//		<< " 2 Gems" << std::endl
//		<< " 20 Nishati" << std::endl;
//}
//void scopeInfo()
//{
//	std::cout
//		<< "Reflex Scope (Weapon Mod)" << std::endl
//		<< " +1 Damge" << std::endl
//		<< " +5% Accuracy" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Rifle Pulsator" << std::endl
//		<< " 3 Alloy" << std::endl
//		<< " 5 Gems" << std::endl;
//}
//void capacitorInfo()
//{
//	std::cout
//		<< "Nishati-Flux Capacitor (Weapon Mod)" << std::endl
//		<< " Range Damage 10 - 15" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Reflex Scope" << std::endl
//		<< " 4 Alloy" << std::endl
//		<< " 5 Gems" << std::endl
//		<< " 15 Nishati" << std::endl
//		<< " 5 Bones" << std::endl;
//}
//void bayonetInfo()
//{
//	std::cout
//		<< "Bayonet (Weapon Mod)" << std::endl
//		<< " +2 Melee Damage" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Nishati-Flux Capacitor" << std::endl
//		<< " 15 Alloy" << std::endl
//		<< " 7 Bones" << std::endl;
//}
//void rifleInfo()
//{
//	std::cout
//		<< "Nishati Rifle (Weapon)" << std::endl
//		<< " Range Damage 15 - 20" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Bayonet" << std::endl
//		<< " 15 Alloy" << std::endl
//		<< " 3 Gems" << std::endl
//		<< " 10 Nishati" << std::endl
//		<< " 10 Bones" << std::endl;
//}
//void splitterInfo()
//{
//	std::cout
//		<< "Nishati Beam Splitter" << std::endl
//		<< " +3 Damage" << std::endl
//		<< " -15% Accuracy" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Nishati Rifle" << std::endl
//		<< " 10 Alloy" << std::endl
//		<< " 10 Gems" << std::endl
//		<< " 10 Nishati" << std::endl
//		<< " 10 Bones" << std::endl;
//}
//void focuserInfo()
//{
//	std::cout
//		<< "Nishati Beam Splitter" << std::endl
//		<< " +1 Damage" << std::endl
//		<< " Critical Chance +5%" << std::endl;
//}
//
//// Function called when choosing Attack Upgrades
//// Displays to user what items they can choose which would then prompt them to buy it by calling the buy function
//void AUInfo(int &alloy, int &bones, int &gems, int&nishati)
//{
//	Sleep(300);
//	AUlist();
//	bool browse = true;
//	while (browse)
//	{
//		bool req = false; // Variable used to check whether user has the required materials to buy/create item	
//		// Variables used to determine amount of materials are required to buy/create item
//		// Initialiazed to 0 to ensure values from previously chosen item does not add up to current item
//		int alloyReq = 0;
//		int bonesReq = 0;
//		int gemsReq = 0;
//		int nishatiReq = 0;
//		// Entering a command prompts user to buy chosen item
//		if (GetAsyncKeyState('1') & 0x8000)
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 10 && nishati >= 8)
//			{
//				req = true;
//				alloyReq = 10;
//				nishatiReq = 8;
//			}
//			musketInfo();
//			buy("Nishati Musket", counterAU, 1, musket, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			AUlist();
//		}
//		else if (GetAsyncKeyState('2') & 0x8000)
//		{
//			Sleep(300);
//			system("cls");
//			if (gems >= 2 && nishati >= 20)
//			{
//				req = true;
//				gemsReq = 2;
//				nishatiReq = 20;
//			}
//			pulsatorInfo();
//			buy("Rifle Pulsator", counterAU, 2, pulsator, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			AUlist();
//		}
//		else if (GetAsyncKeyState('3') & 0x8000)
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 3 && gems >= 5)
//			{
//				req = true;
//				alloyReq = 3;
//				gemsReq = 3;
//			}
//			scopeInfo();
//			buy("Reflex Scope", counterAU, 3, scope, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			AUlist();
//		}
//		else if (GetAsyncKeyState('4') & 0x8000)
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 4 && bones >= 5 && gems >= 5 && nishati >= 15)
//			{
//				req = true;
//				alloyReq = 4;
//				bonesReq = 5;
//				gemsReq = 5;
//				nishatiReq = 15;
//			}
//			capacitorInfo();
//			buy("Nishati-Flux Capacitor", counterAU, 4, capacitor, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			AUlist();
//		}
//		else if (GetAsyncKeyState('5') & 0x8000)
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 15 && bones >= 7)
//			{
//				req = true;
//				alloyReq = 15;
//				bonesReq = 7;
//			}
//			bayonetInfo();
//			buy("Bayonet", counterAU, 5, bayonet, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			AUlist();
//		}
//		else if (GetAsyncKeyState('6') & 0x8000)
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 15 && bones >= 10 && gems >= 3 && nishati >= 10)
//			{
//				req = true;
//				alloyReq = 15;
//				bonesReq = 10;
//				gemsReq = 3;
//				nishatiReq = 10;
//			}
//			rifleInfo();
//			buy("Nishati Rifle", counterAU, 6, rifle, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			AUlist();
//		}
//		else if (GetAsyncKeyState('7') & 0x8000)
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 10 && bones >= 10 && gems >= 10 && nishati >= 10)
//			{
//				req = true;
//				alloyReq = 10;
//				bonesReq = 10;
//				gemsReq = 10;
//				nishatiReq = 10;
//			}
//			splitterInfo();
//			buy("Nishati Beam Splitter", counterAU, 7, splitter, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			AUlist();
//		}
//		else if (GetAsyncKeyState('0') & 0x8000)
//		{
//			browse = false;
//			merchant(alloy, bones, gems, nishati);
//		}
//	}
//	system("cls");
//}
//
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//// DEFENSE UPGRADES
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//int counterDU = 1;
//bool plate = false;
//bool awaliCharm = false;
//bool detection = false;
//bool gemPlate = false;
//bool bonePlate = false;
//bool shield = false;
//bool spikes = false;
//
//// Displays defense upgrades available for purchase
//void DUlist()
//{
//	system("cls");
//	std::cout
//		<< "Merchant: Defense Upgrades" << std::endl
//		<< " 1. Kepler Alloy Plate" << std::endl
//		<< " 2. Awali Charm" << std::endl
//		<< " 3. Detection System" << std::endl
//		<< " 4. Gem Infused Plating" << std::endl
//		<< " 5. Kepler Bone Plate" << std::endl
//		<< " 6. Nishati Shield System" << std::endl
//		<< " 0. Back" << std::endl
//		<< "Enter Command: ";
//}
//void plateInfo()
//{
//	std::cout
//		<< "Kepler Alloy Plate" << std::endl
//		<< " +1 Armour" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 10 Alloy" << std::endl
//		<< " 3 Nishati" << std::endl;
//}
//void awaliCharmInfo()
//{
//	std::cout
//		<< "Awali Charm" << std::endl
//		<< " +10 HP" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Kepler Alloy Plate" << std::endl
//		<< " 2 Alloy" << std::endl
//		<< " 5 Gems" << std::endl
//		<< " 3 Nishati" << std::endl
//		<< " 1 Bone" << std::endl;
//}
//void detectionInfo()
//{
//	std::cout
//		<< "Kepler Alloy Plate" << std::endl
//		<< " +5% Flee Chance" << std::endl
//		<< " Take 1 Less 'Escape Damage'" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Awali Charm" << std::endl
//		<< " 5 Alloy" << std::endl
//		<< " 3 Nishati" << std::endl
//		<< " 1 Bone" << std::endl;
//}
//void gemPlateInfo()
//{
//	std::cout
//		<< "Gem Infused Plating" << std::endl
//		<< " +1 Armour" << std::endl
//		<< " +10 HP" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Kepler Alloy Plate" << std::endl
//		<< " 5 Alloy" << std::endl
//		<< " 7 Gems" << std::endl;
//}
//void bonePlateInfo()
//{
//	std::cout
//		<< "Kepler Bone Plate" << std::endl
//		<< " +1 Armour" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Gem Infused Plating" << std::endl
//		<< " 25 Bones" << std::endl;
//}
//void shieldInfo()
//{
//	std::cout
//		<< "Nishati Shielding System" << std::endl
//		<< " +1 Armour" << std::endl
//		<< " Restore Energy Every 4 steps" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Kepler Bone Plate" << std::endl
//		<< " 10 Alloy" << std::endl
//		<< " 10 Gems" << std::endl
//		<< " 10 Nishati" << std::endl
//		<< " 10 Bones" << std::endl;
//}
//void spikesInfo()
//{
//	std::cout
//		<< "Kepler Alloy Plate" << std::endl
//		<< " +1 Armour" << std::endl
//		<< " Melee enemies have a 15% chance to take 3 damage when attacking you";
//}
//
//// Function called when choosing Defense Uprades
//// Displays to user what items they can choose which would then prompt them to buy it by calling the buy function
//void DUInfo(int &alloy, int &bones, int &gems, int&nishati)
//{
//	Sleep(300);
//	DUlist();
//	bool browse = true;
//	while (browse)
//	{
//		bool req = false; // Variable used to check whether user has the required materials to buy/create item	
//		// Variables used to determine amount of materials are required to buy/create item
//		// Initialiazed to 0 to ensure values from previously chosen item does not add up to current item
//		int alloyReq = 0;
//		int bonesReq = 0;
//		int gemsReq = 0;
//		int nishatiReq = 0;
//
//		// Entering a command prompts user to buy chosen item
//		if (GetAsyncKeyState('1') & 0x8000)
//		{
//			system("cls");
//			Sleep(300);
//			if (alloy >= 10 && nishati >= 3)
//			{
//				req = true;
//				alloyReq = 10;
//				nishatiReq = 3;
//			}
//			plateInfo();
//			buy("Kepler Alloy Plate", counterDU, 1, plate, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			DUlist();
//		}
//		else if (GetAsyncKeyState('2') & 0x8000)
//		{
//			system("cls");
//			Sleep(300);
//			if (alloy >= 2 && bones >= 1 && gems >= 5 && nishati >= 3)
//			{
//				req = true;
//				alloyReq = 2;
//				bonesReq = 1;
//				gemsReq = 5;
//				nishatiReq = 3;
//			}
//			awaliCharmInfo();
//			buy("Awali Charm", counterDU, 2, awaliCharm, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			DUlist();
//		}
//		else 	if (GetAsyncKeyState('3') & 0x8000)
//		{
//			system("cls");
//			Sleep(300);
//			if (alloy >= 5 && gems >= 7)
//			{
//
//				req = true;
//				alloyReq = 5;
//				gemsReq = 7;
//			}
//			detectionInfo();
//			buy("Detection System", counterDU, 3, detection, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			DUlist();
//		}
//		else if (GetAsyncKeyState('4') & 0x8000)
//		{
//			system("cls");
//			Sleep(300);
//			if (alloy >= 5 && gems >= 7)
//			{
//				req = true;
//				alloyReq = 5;
//				gemsReq = 7;
//			}
//			gemPlateInfo();
//			buy("Gem Infused Plating", counterDU, 4, gemPlate, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			DUlist();
//		}
//		else 	if (GetAsyncKeyState('5') & 0x8000)
//		{
//			system("cls");
//			Sleep(300);
//			if (bones >= 25)
//			{
//				req = true;
//				bonesReq = 25;
//			}
//			bonePlateInfo();
//			buy("Kepler Bone Plate", counterDU, 5, bonePlate, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			DUlist();
//		}
//		else if (GetAsyncKeyState('6') & 0x8000)
//		{
//			system("cls");
//			Sleep(300);
//			if (alloy >= 10 && bones >= 10 && gems >= 10 && nishati >= 10)
//			{
//				req = true;
//				alloyReq = 10;
//				bonesReq = 10;
//				gemsReq = 10;
//				nishatiReq = 10;
//			}
//			shieldInfo();
//			buy("Nishati Shield System", counterDU, 6, shield, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			browse = false;
//			DUlist();
//		}
//		else if (GetAsyncKeyState('0') & 0x8000)
//		{
//			browse = false;
//			merchant(alloy, bones, gems, nishati);
//		}
//	}
//	system("cls");
//}
//
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//// ENERGY UPGRADES
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//
//int counterEU = 1;
//bool lightAlloy = false;
//bool nishatiCharm = false;
//bool overclockSystem = false;
//bool radialBlind = false;
//
//void EUlist()
//{
//	system("cls");
//	std::cout
//		<< "Merchant: Energy Upgrades" << std::endl
//		<< " 1. Lighter Alloy" << std::endl
//		<< " 2. Nishati Charm" << std::endl
//		<< " 3. Nishati Overclocking System" << std::endl
//		<< " 0. Back" << std::endl
//		<< "Enter Command: ";
//}
//// " "Info Displays the attributes of items
//void lightAlloyInfo()
//{
//	std::cout
//		<< "Lighter Alloy" << std::endl
//		<< " +5 Energy" << std::endl
//		<< "Requirements:" << std::endl
//		<< " 5 Alloy" << std::endl
//		<< " 3 Gems" << std::endl;
//}
//void nishatiCharmInfo()
//{
//	std::cout
//		<< "Nishati Charm" << std::endl
//		<< " Attacking costs 1 less energy" << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Lighter Alloy" << std::endl
//		<< " 5 Gems" << std::endl
//		<< " 10 Nishati" << std::endl;
//}
//void overclockSystemInfo()
//{
//	std::cout
//		<< "Nishati Overclocking System" << std::endl
//		<< " +2 Energy when waiting" << std::endl
//		<< "Requirements:" << std::endl
//		<< " 1 Nishati Charm" << std::endl
//		<< " 3 Alloy" << std::endl
//		<< " 3 Gems" << std::endl
//		<< " 5 Nishati" << std::endl
//		<< " 3 Bones" << std::endl;
//}
//void radialBlindInfo()
//{
//	std::cout
//		<< "Radial Blind" << std::endl
//		<< " 1 Nishati Overclocking System" << std::endl
//		<< " 20% Chance for all damage to be negated while blocking" << std::endl;
//}
//
//// Function called when choosing Energy Uprades
//// Displays to user what items they can choose which would then prompt them to buy it by calling the buy function
//void EUInfo(int &alloy, int &bones, int &gems, int&nishati)
//{
//	Sleep(300);
//	EUlist();
//	bool browse = true;
//	while (browse)
//	{
//		bool req = false;
//		int alloyReq = 0;
//		int bonesReq = 0;
//		int gemsReq = 0;
//		int nishatiReq = 0;
//		if (GetAsyncKeyState('1'))
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 5 && gems >= 3)//5 3
//			{
//				req = true;
//				alloyReq = 5;
//				gemsReq = 3;
//			}
//			lightAlloyInfo();
//			browse = false;
//			buy("Lighter Alloy", counterEU, 1, lightAlloy, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			EUlist();
//		}
//		else if (GetAsyncKeyState('2'))
//		{
//			Sleep(300);
//			system("cls");
//			if (gems >= 2 && nishati >= 10)//2 10
//			{
//				req = true;
//				gemsReq = 5;
//				nishatiReq = 10;
//			}
//			nishatiCharmInfo();
//			browse = false;
//			buy("Nishati Charm", counterEU, 2, nishatiCharm, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			EUlist();
//		}
//		else if (GetAsyncKeyState('3'))
//		{
//			Sleep(300);
//			system("cls");
//			if (alloy >= 3 && gems >= 3 && nishati >= 5 && bones >= 3)//3 3 5 3
//			{
//				req = true;
//				alloyReq = 3;
//				gemsReq = 3;
//				nishatiReq = 5;
//				bonesReq = 3;
//			}
//			overclockSystemInfo();
//			browse = false;
//			buy("Nishati Overclocking System", counterEU, 3, overclockSystem, req, alloy, bones, gems, nishati, alloyReq, bonesReq, gemsReq, nishatiReq);
//			EUlist();
//		}
//		else if (GetAsyncKeyState('0'))
//		{
//			browse = false;
//			merchant(alloy, bones, gems, nishati);
//		}
//	}
//	system("cls");
//}
//
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//// CONSUMABLES
//// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//
//// Displays energy upgrades available for purchase
//void Clist()
//{
//	system("cls");
//	std::cout
//		<< "Merchant: Consumables" << std::endl
//		<< " 1. Restoration Potion" << std::endl
//		<< " 2. Greater Restoration Potion" << std::endl
//		<< " 3. Awali Ale" << std::endl
//		<< " 0. Back" << std::endl
//		<< "Enter Command: ";
//}
//void restorationInfo()
//{
//	std::cout
//		<< "Restoration Potion" << std::endl
//		<< " Restores 20 HP" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 3 Gems" << std::endl
//		<< " 5 Nishati" << std::endl;
//}
//void greatRestorationInfo()
//{
//	std::cout
//		<< "Greater Restoration Potion" << std::endl
//		<< " Restores 50 HP" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 5 Gems" << std::endl
//		<< " 7 Nishati" << std::endl
//		<< " 3 Bones" << std::endl;
//}
//void awaliAleInfo()
//{
//	std::cout
//		<< "Awali Ale" << std::endl
//		<< " +2 Armour" << std::endl
//		<< " +1 Attack" << std::endl
//		<< " -3 Total Energy" << std::endl << std::endl
//		<< "Requirements:" << std::endl
//		<< " 5 Gems" << std::endl
//		<< " 7 Nishati" << std::endl
//		<< " 3 Bones" << std::endl;
//}
//void monsterBloodInfo()
//{
//	std::cout
//		<< "Monster Blood" << std::endl
//		<< " +1 Armour" << std::endl
//		<< " +1 Attack" << std::endl
//		<< " +5% Critical Strike Chance" << std::endl;
//}
//
//void resetMerchant()
//{
//	int counterAU = 1;
//	bool musket = false;
//	bool pulsator = false;
//	bool scope = false;
//	bool capacitor = false;
//	bool bayonet = false;
//	bool rifle = false;
//	bool splitter = false;
//	bool focuser = false;
//
//	int counterDU = 1;
//	bool plate = false;
//	bool awaliCharm = false;
//	bool detection = false;
//	bool gemPlate = false;
//	bool bonePlate = false;
//	bool shield = false;
//	bool spikes = false;
//
//	int counterEU = 1;
//	bool lightAlloy = false;
//	bool nishatiCharm = false;
//	bool overclockSystem = false;
//	bool radialBlind = false;
//}