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
	animationBlinky->InitAnimation("assets/sprite/blinky.png", 8, 1, 16,16);

	Entity* inky = Engin::Get()->World().Create("inky");
	inky->SetPosition(40, 500);
	Animation* animationInky = inky->AddComponent<Animation>();
	Enemy* E2 = inky->AddComponent<Enemy>();
	inky->AddComponent<BoxCollider>();
	animationInky->InitAnimation("assets/sprite/inky.png", 8, 1, 16,16);

	Entity* pinky = Engin::Get()->World().Create("pinky");
	pinky->SetPosition(500, 44);
	Animation* animationPinky = pinky->AddComponent<Animation>();
	Enemy* E3 = pinky->AddComponent<Enemy>();
	pinky->AddComponent<BoxCollider>();
	animationPinky->InitAnimation("assets/sprite/pinky.png", 8, 1, 16, 16);

	Entity* clyde = Engin::Get()->World().Create("clyde");
	clyde->SetPosition(500, 500);
	Animation* animationClyde = clyde->AddComponent<Animation>();
	Enemy* E4 = clyde->AddComponent<Enemy>();
	clyde->AddComponent<BoxCollider>();
	animationClyde->InitAnimation("assets/sprite/clyde.png", 8, 1, 16, 16);
	/*
	Entity* ghost3 = Engin::Get()->World().Create("ghost3");
	ghost2->SetPosition(400, 430);
	Animation* animationGhost2 = ghost2->AddComponent<Animation>();
	Enemy* E2 = ghost2->AddComponent<Enemy>();
	ghost2->AddComponent<BoxCollider>();
	animationGhost2->InitAnimation("assets/sprite/pacman2.png", 8, 1, 16, 16);

	Entity* ghost4 = Engin::Get()->World().Create("ghost4");
	ghost2->SetPosition(400, 430);
	Animation* animationGhost2 = ghost2->AddComponent<Animation>();
	Enemy* E2 = ghost2->AddComponent<Enemy>();
	ghost2->AddComponent<BoxCollider>();
	animationGhost2->InitAnimation("assets/sprite/pacman2.png", 8, 1, 16, 16);
	*/


	//vais devoir faire une sprite sheet pour le ghost mort
	//animationGhost->InitAnimation("assets/sprite/ghostdead.png", 4, 1, 16, 16);
	// 
	//animationGhost->AddClip("ghostdead", 0, 2, 0.1f);
	//animationGhost->AddClip("allin", 0, 6, 0.2f);
	P->OnStateChanged.AddListener(E);
	P->OnStateChanged.AddListener(E2);
	P->OnStateChanged.AddListener(E3);
	P->OnStateChanged.AddListener(E4);

	Entity* gameManager = Engin::Get()->World().Create("gameManager");
	GameManager* M = gameManager->AddComponent<GameManager>();
	P->OnEatDot.AddListener(M);
}