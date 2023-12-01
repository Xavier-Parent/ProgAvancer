#include "TitleScene.h"
#include "engin.h"
#include "PlayerController.h"
#include "Atlas.h"
#include "TextRenderer.h"

using namespace homer;
void TitleScene::Load()
{
	
	Entity* Text = Engin::Get()->World().Create("text");
	Text->AddComponent<TextRenderer>()->InitText("assets/arcade.ttf", "Press  Start", 50, 250,300);
	
	RectF square = RectF();
	square.x = 100;
	square.y = 100;
	square.h = 50;
	square.w = 50;
	
}