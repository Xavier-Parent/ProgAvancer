#include "TitleScene.h"
#include "engin.h"
using namespace homer;
void TitleScene::Load()
{
	Entity* pacMan = Engin::Get()->World().Create("PacMan");
	//pacMan->AddComponent<PlayerController>
}