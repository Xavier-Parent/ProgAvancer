#include "GameScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "SpriteRenderer.h"
#include "Animation.h"
using namespace homer;
void GameScene::Load()
{
	Entity* BackGround = Engin::Get()->World().Create("BackGround");
	Animation* animation;
	animation = BackGround->AddComponent<Animation>();
	animation->InitAnimation("assets/sprite/pacman1.png", 14, 4, 16, 16);
	animation->AddClip("Right", 0, 3, 0.3f);
	animation->Play("Right", true);

	
	//BackGround->AddComponent<Animation>()->InitAnimation("assets/sprite/pacman9.png", 1, 18,18);

}