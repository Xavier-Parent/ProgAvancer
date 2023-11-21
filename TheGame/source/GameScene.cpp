#include "GameScene.h"
#include "engin.h"
//#include "PlayerController.h"
//#include "SpriteRenderer.h"
//#include "Animation.h"
#include "TileMap.h"
using namespace homer;
void GameScene::Load()
{
	Entity* map = Engin::Get()->World().Create("background");
	map->AddComponent<Tilemap>()->Load("assets/sprite/map.tmx", 200, 200, 16, 16);
	map->Draw();

	//Entity* pacMan = Engin::Get()->World().Create("pacMan");
	//map->Draw();


	/*
	Animation* animation;
	animation = pacMan->AddComponent<Animation>();
	pacMan->AddComponent<PlayerController>();
	animation->InitAnimation("assets/sprite/pacManClean.png", 14, 4, 16, 16);
	animation->AddClip("Right", 0, 4, 0.1f);
	animation->AddClip("Left", 14, 4, 0.1f);
	animation->AddClip("Up", 28, 4, 0.1f);
	animation->AddClip("Down", 42, 4, 0.1f);
	animation->AddClip("Dead", 4, 10, 0.2f);
	animation->Play("Dead", true);
	*/
}