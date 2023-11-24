#include "TitleScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "Atlas.h"
#include "SpriteRenderer.h"

using namespace homer;
void TitleScene::Load()
{
	//size_t arcadeFont = homer::Engin::Get()->Graphics().LoadFont("assets/arcade.ttf", 1);
	//Engin::Get()->Graphics().DrawString("Allo", arcadeFont, 50, 50, Color::Red);
	//Entity* pacMan = Engin::Get()->World().Create("pacMan");
	//pacMan->AddComponent<SpriteRenderer>()->Init("assets/sprite/pacman1.png", 500, 500);
	Entity* Text = Engin::Get()->World().Create("text");
	Text->AddComponent<SpriteRenderer>()->InitText("assets/arcade.ttf", 100);
	
	//homer::Engin::Get()->Graphics().FillRect(100, 100, 10, 10, Color::Red);
	RectF square = RectF();
	square.x = 100;
	square.y = 100;
	square.h = 50;
	square.w = 50;
	//Engin::Get()->Graphics().DrawRect(square, Color::Red);

	//size_t id = Engin::Get()->Graphics().LoadTexture("assets/sprite/pacManClean.png");
	//Engin::Get()->Graphics().DrawTexture(id, square, Color::Red);
    //pacMan->AddComponent<PlayerController>();
	//Atlas* atlas = pacMan->AddComponent<Atlas>();
	//atlas->Init("assets/sprite/pacman1.png");
	//atlas->AddFrame("1", 0, 0, 16, 16);
	//atlas->AddFrame("2", 0, 16, 16, 16);
	//atlas->AddFrame("3", 0, 32, 16, 16);
}