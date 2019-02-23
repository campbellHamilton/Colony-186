#include <Windows.h>

void fllscren()
{
	system("mode 650");

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD Coord;
	SetConsoleDisplayMode(hConsole, 1, &Coord);


	CONSOLE_SCREEN_BUFFER_INFO sizing;
	GetConsoleScreenBufferInfo(hConsole, &sizing);

	COORD  size =
	{
		sizing.srWindow.Right - sizing.srWindow.Left + 1,
		sizing.srWindow.Bottom - sizing.srWindow.Top + 1
	};

	SetConsoleScreenBufferSize(hConsole, size);

	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(hConsole, &info);
}