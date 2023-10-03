#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include <iostream>
#include <fstream>
#include "engin.h"
//#include <vld.h>

void InitGameplay(void) {

}
INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	homer::Engin theEngine;
	if (theEngine.Init("TestGame", 800, 600)) {
		InitGameplay();
		std:: ofstream MyFile("filename.txt");

		// Write to the file
		MyFile << "Files can be tricky, but it is fun enough!";

		// Close the file
		MyFile.close();
		theEngine.Start();
	}
	return 0;
}

