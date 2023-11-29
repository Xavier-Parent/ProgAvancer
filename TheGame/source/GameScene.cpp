#include "GameScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "Enemy.h"
#include "SpriteRenderer.h"
#include "Animation.h"
#include "TileMap.h"
#include "BoxCollider.h"
#include "GameManager.h"
using namespace homer;
void GameScene::Load()
{
	Entity* background = Engin::Get()->World().Create("background");
	Tilemap* map;	
	map = background->AddComponent<Tilemap>();
	map->Load("assets/sprite/pacman9.png",240 , 248, 8, 8);
	map->AddLayerFromCSV("Background", "assets/sprite/new_Background.csv");
	map->AddLayerFromCSV("Collectable", "assets/sprite/new_Collectable.csv");
	map->AddLayerFromCSV("PowerUp", "assets/sprite/new_PowerUp.csv");
	map->AddLayerFromCSV("Wall","assets/sprite/new_Wall.csv");

	Entity* pacMan = Engin::Get()->World().Create("pacMan");
	Animation* animation;
	animation = pacMan->AddComponent<Animation>();
	PlayerController* P =  pacMan->AddComponent<PlayerController>();
	pacMan->AddComponent<BoxCollider>()->AddToLayer("EnemyLayer", pacMan);
	animation->InitAnimation("assets/sprite/pacManClean.png", 14, 4, 16, 16);

	Entity* Blinky = Engin::Get()->World().Create("ghost");
	Blinky->SetPosition(40, 44);
	Animation* animationBlinky = Blinky->AddComponent<Animation>();
	Enemy* E = Blinky->AddComponent<Enemy>();
	Blinky->AddComponent<BoxCollider>();
	animationBlinky->InitAnimation("assets/sprite/blinky.png", 16, 1, 16,16);
	


	Entity* inky = Engin::Get()->World().Create("inky");
	inky->SetPosition(40, 500);
	Animation* animationInky = inky->AddComponent<Animation>();
	Enemy* E2 = inky->AddComponent<Enemy>();
	inky->AddComponent<BoxCollider>();
	animationInky->InitAnimation("assets/sprite/inky.png", 16, 1, 16,16);

	Entity* pinky = Engin::Get()->World().Create("pinky");
	pinky->SetPosition(500, 44);
	Animation* animationPinky = pinky->AddComponent<Animation>();
	Enemy* E3 = pinky->AddComponent<Enemy>();
	pinky->AddComponent<BoxCollider>();
	animationPinky->InitAnimation("assets/sprite/pinky.png", 16, 1, 16, 16);


	Entity* clyde = Engin::Get()->World().Create("clyde");
	clyde->SetPosition(500, 500);
	Animation* animationClyde = clyde->AddComponent<Animation>();
	Enemy* E4 = clyde->AddComponent<Enemy>();
	clyde->AddComponent<BoxCollider>();
	animationClyde->InitAnimation("assets/sprite/clyde.png", 16, 1, 16, 16);

	P->OnStateChanged.AddListener(E);
	P->OnStateChanged.AddListener(E2);
	P->OnStateChanged.AddListener(E3);
	P->OnStateChanged.AddListener(E4);

	Entity* gameManager = Engin::Get()->World().Create("gameManager");
	GameManager* M = gameManager->AddComponent<GameManager>();
	P->OnEatDot.AddListener(M);
}