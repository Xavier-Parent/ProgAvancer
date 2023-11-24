#include "GameScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "SpriteRenderer.h"
#include "Animation.h"
#include "TileMap.h"
#include "BoxCollider.h"
using namespace homer;
void GameScene::Load()
{
	Entity* background = Engin::Get()->World().Create("background");	
	Tilemap* map;
	map = background->AddComponent<Tilemap>();
	map->Load("assets/sprite/pacman9.png",224 , 272, 8, 8);
	map->AddLayerFromCSV("Background", "assets/sprite/Layer_Background.csv");
	map->AddLayerFromCSV("Collectable", "assets/sprite/Layer_Collectable.csv");
	map->AddLayerFromCSV("Wall","assets/sprite/Layer_Wall.csv");

	size_t musicID = Engin::Get()->Audio().LoadMusic("assets/audio/game_start.wav");
	Engin::Get()->Audio().PlayMusic(musicID, 0);

	Entity* pacMan = Engin::Get()->World().Create("pacMan");

	Animation* animation;
	animation = pacMan->AddComponent<Animation>();
	pacMan->AddComponent<PlayerController>();
	pacMan->AddComponent<BoxCollider>();
	animation->InitAnimation("assets/sprite/pacManClean.png", 14, 4, 16, 16);
	animation->AddClip("Right", 0, 4, 0.1f);
	animation->AddClip("Left", 14, 4, 0.1f);
	animation->AddClip("Up", 28, 4, 0.1f);
	animation->AddClip("Down", 42, 4, 0.1f);
	animation->AddClip("Dead", 4, 10, 0.2f);
	animation->Play("Dead", true);	
}