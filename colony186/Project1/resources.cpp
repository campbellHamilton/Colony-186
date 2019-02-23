#include "resources.h"
#include <string>
#include <iostream>
#include "merchant.h"
#include <Windows.h>

void resources::write()
{
	DWORD written;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 30 });
	std::string s = "you have ";
	s += std::to_string(re[0]);
	s += " Alloy";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 31 });
	s = "you have ";
	s += std::to_string(re[1]);
	s += " Bones";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 32 });
	s = "you have ";
	s += std::to_string(re[2]);
	s += " Gems";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 33 });
	s = "you have ";
	s += std::to_string(re[3]);
	s += " Nishati";
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 129, 34 });
	s = std::to_string(re[4]);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.length(), &written, NULL);
}
