#include "GameScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "SpriteRenderer.h"
#include "Animation.h"
using namespace homer;
void GameScene::Load()
{
	Entity* BackGround = Engin::Get()->World().Create("BackGround");
	BackGround->AddComponent<SpriteRenderer>()->Init("assets/sprite/pacman9.png",600, 800);
	//BackGround->AddComponent<Animation>()->InitAnimation("assets/sprite/pacman9.png", 1, 18,18);

}