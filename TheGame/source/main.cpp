#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "engin.h"

void InitGameplay(void) {

}
INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	homer::Engin theEngine;
	if (theEngine.Init("TestGame", 800, 600)) {
		InitGameplay();
		theEngine.Start();
	}
	return 0;
}

