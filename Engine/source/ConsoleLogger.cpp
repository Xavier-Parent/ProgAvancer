#include "ConsoleLogger.h"
#include <Windows.h>
#include <stdio.h>
#include <iostream>


homer::ConsoleLogger::ConsoleLogger()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "ERROR: " << "" << std::endl;
}

homer::ConsoleLogger::~ConsoleLogger()
{
	FreeConsole();
}

void homer::ConsoleLogger::Log(const char* message)
{

	std::cout << "ERROR: " << message << std::endl;
}
