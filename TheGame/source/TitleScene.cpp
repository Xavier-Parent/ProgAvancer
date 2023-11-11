#include "TitleScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "Atlas.h"
#include "SpriteRenderer.h"

using namespace homer;
void TitleScene::Load()
{
	//Engin::Get()->Graphics().DrawString("Allo", 0 , 50, 50 , Color::red)
	Entity* pacMan = Engin::Get()->World().Create("pacMan");
	pacMan->AddComponent<SpriteRenderer>()->Init("assets/sprite/pacman1.png", 500, 500);
    //pacMan->AddComponent<PlayerController>();
	//Atlas* atlas = pacMan->AddComponent<Atlas>();
	//atlas->Init("assets/sprite/pacman1.png");
	//atlas->AddFrame("1", 0, 0, 16, 16);
	//atlas->AddFrame("2", 0, 16, 16, 16);
	//atlas->AddFrame("3", 0, 32, 16, 16);
	//atlas->AddFrame("4", 0, 48, 16, 16);
}