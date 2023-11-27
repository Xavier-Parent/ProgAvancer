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
	animation->AddClip("Right", 0, 4, 0.1f);
	animation->AddClip("Left", 14, 4, 0.1f);
	animation->AddClip("Up", 28, 4, 0.1f);
	animation->AddClip("Down", 42, 4, 0.1f);
	animation->AddClip("Dead", 4, 10, 0.2f);

	Entity* ghost = Engin::Get()->World().Create("ghost");
	Animation* animationGhost;
	animationGhost = ghost->AddComponent<Animation>();
	Enemy* E = ghost->AddComponent<Enemy>();
	ghost->AddComponent<BoxCollider>()->AddToLayer("EnemyLayer",ghost);
	animationGhost->InitAnimation("assets/sprite/ghostred.png", 8, 1, 16,16);
	animationGhost->AddClip("ghostRight", 0,2,0.1f);
	animationGhost->AddClip("ghostLeft", 2, 2, 0.1f);
	animationGhost->AddClip("ghostUp", 4, 2, 0.1f);
	animationGhost->AddClip("ghostDown", 6, 2, 0.1f);
	//vais devoir faire une sprite sheet pour le ghost mort
	//animationGhost->InitAnimation("assets/sprite/ghostdead.png", 4, 1, 16, 16);
	// 
	//animationGhost->AddClip("ghostdead", 0, 2, 0.1f);
	//animationGhost->AddClip("allin", 0, 6, 0.2f);
	P->OnStateChanged.AddListener(E);

	Entity* gameManager = Engin::Get()->World().Create("gameManager");
	GameManager* M = gameManager->AddComponent<GameManager>();
	P->OnEatDot.AddListener(M);
}