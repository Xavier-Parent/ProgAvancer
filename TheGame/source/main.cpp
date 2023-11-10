#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include <iostream>
#include "engin.h"
#include "TitleScene.h"
#include "GameScene.h"
//#include <vld.h>
using namespace homer;
void InitGameplay(void) {
	Engin::Get()->World().Register("Title Scene",new TitleScene);
	Engin::Get()->World().Register("Game Scene", new GameScene);
	Engin::Get()->World().Load("Title Scene");
}
INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	Engin* theEngine = Engin::Get();
	if (theEngine->Init("TestGame", 800, 800)) {
		InitGameplay();
		theEngine->Start();
	}
	return 0;
}

