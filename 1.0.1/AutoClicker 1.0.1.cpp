// AutoClicker
// Version 1.0.1
// Created by Sowtyy on 03.02.2021 @ 3:00 am

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleTitle(L"AutoClicker 1.0.1  by Sowtyy");

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
		if (GetAsyncKeyState(VK_F8) & 1)
		{
			Beep(600, 500);

			while (true)
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

				if (GetAsyncKeyState(VK_F8) & 1)
				{
					Beep(400, 500);
					break;
				}
			}
		}

		Sleep(300);
	}
}