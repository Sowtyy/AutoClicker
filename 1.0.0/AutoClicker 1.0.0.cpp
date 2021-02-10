// AutoClicker
// Version 1.0.0
// Created by Sowtyy on 02.02.2021 @ 12:35 am

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleTitle(L"AutoClicker 1.0.0  by Sowtyy");

	std::cout << " Hi! To enable/disable AutoClicker press [F8] . . .\n";

	int ClickCheck = 0;
	int Clicked = 0;

	INPUT iLeftUp{};
	iLeftUp.type = INPUT_MOUSE;
	iLeftUp.mi.dwFlags = MOUSEEVENTF_LEFTUP;

	//ZeroMemory(&input, sizeof(input));
	INPUT iLeftDown{};
	iLeftDown.type = INPUT_MOUSE;
	iLeftDown.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	while (true)
	{
		while (GetKeyState(VK_F8))
		{
			SendInput(true, &iLeftUp, sizeof(iLeftUp));
			ClickCheck = SendInput(true, &iLeftDown, sizeof(iLeftDown));

			Sleep(30);

			if (ClickCheck != 0)
			{
				Clicked++;

				std::cout << "Times clicked: " << Clicked << std::endl;
			}
			else
				std::cout << "Something is wrong...\n";
		}

		Sleep(300);
	}
}