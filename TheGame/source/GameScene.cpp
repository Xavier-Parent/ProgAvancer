#include "GameScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "Enemy.h"
#include "SpriteRenderer.h"
#include "Animation.h"
#include "TileMap.h"
#include "TextRenderer.h"
#include "GameManager.h"
using namespace homer;
void GameScene::Load()
{
	Entity* background = Engin::Get()->World().Create("background");
	Tilemap* map;	
	map = background->AddComponent<Tilemap>();
	map->Load("assets/sprite/pacman9.png",240 , 248, 8, 8);
	map->AddLayerFromCSV("Background", "assets/sprite/final_Background.csv");
	map->AddLayerFromCSV("Collectable", "assets/sprite/final_Collectable.csv");
	map->AddLayerFromCSV("PowerUp", "assets/sprite/final_PowerUp.csv");
	map->AddLayerFromCSV("Wall","assets/sprite/final_Wall.csv");
	map->AddLayerFromCSV("Door", "assets/sprite/final_Door.csv");

	Entity* pacMan = Engin::Get()->World().Create("pacMan");
	Animation* animation;
	animation = pacMan->AddComponent<Animation>();
	Engin::Get()->Collider().AddToLayer("PlayerLayer", pacMan);
	PlayerController* P =  pacMan->AddComponent<PlayerController>();
	animation->InitAnimation("assets/sprite/pacManClean.png", 14, 4, 16, 16);

	Entity* Blinky = Engin::Get()->World().Create("Blinky");
	Blinky->SetPosition(310, 280);
	Animation* animationBlinky = Blinky->AddComponent<Animation>();
	Enemy* E = Blinky->AddComponent<Enemy>();
	//Engin::Get()->Collider().AddToLayer("EnemyLayer", Blinky);
	animationBlinky->InitAnimation("assets/sprite/blinky.png", 16, 1, 16,16);

	Entity* inky = Engin::Get()->World().Create("inky");
	inky->SetPosition(310, 310);
	Animation* animationInky = inky->AddComponent<Animation>();
	Enemy* E2 = inky->AddComponent<Enemy>();
	//Engin::Get()->Collider().AddToLayer("EnemyLayer", inky);
	animationInky->InitAnimation("assets/sprite/inky.png", 16, 1, 16,16);

	Entity* pinky = Engin::Get()->World().Create("pinky");
	pinky->SetPosition(310, 310);
	Animation* animationPinky = pinky->AddComponent<Animation>();
	Enemy* E3 = pinky->AddComponent<Enemy>();
	//Engin::Get()->Collider().AddToLayer("EnemyLayer", pinky);
	animationPinky->InitAnimation("assets/sprite/pinky.png", 16, 1, 16, 16);

	Entity* clyde = Engin::Get()->World().Create("clyde");
	clyde->SetPosition(310, 310);
	Animation* animationClyde = clyde->AddComponent<Animation>();
	Enemy* E4 = clyde->AddComponent<Enemy>();
	//Engin::Get()->Collider().AddToLayer("EnemyLayer", clyde);
	animationClyde->InitAnimation("assets/sprite/clyde.png", 16, 1, 16, 16);

	P->playerAction.AddListener(E);
	P->playerAction.AddListener(E2);
	P->playerAction.AddListener(E3);
	P->playerAction.AddListener(E4);

	Entity* gameManager = Engin::Get()->World().Create("gameManager");	
	GameManager* M = gameManager->AddComponent<GameManager>();
	P->gameState.AddListener(M);
}