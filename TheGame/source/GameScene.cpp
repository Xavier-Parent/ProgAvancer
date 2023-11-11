#include "GameScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "SpriteRenderer.h"
#include "Animation.h"
using namespace homer;
void GameScene::Load()
{
	Entity* pacMan = Engin::Get()->World().Create("pacMan");
	Animation* animation;
	animation = pacMan->AddComponent<Animation>();
	pacMan->AddComponent<PlayerController>();
	animation->InitAnimation("assets/sprite/pacman.png", 14, 4, 16, 16);
	animation->AddClip("Right", 0, 3, 0.3f);
	animation->AddClip("Left", 14, 3, 0.3f);
	animation->AddClip("Up", 28, 3, 0.3f);
	animation->AddClip("Down", 42, 3, 0.3f);
	animation->AddClip("Dead", 4, 10, 0.2f);
	animation->Play("Dead", true);	
}