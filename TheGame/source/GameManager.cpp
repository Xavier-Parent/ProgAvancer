#include "GameManager.h"
#include <iostream>
#include "engin.h"

using namespace homer;
GameManager::GameManager(Entity* parent)
	:Component(parent)
{
	score = 0;
	currentIndex = 0;
	gameFinish = false;
	textRenderer = Engin::Get()->World().Create("Text1")->AddComponent<TextRenderer>();
	textRenderer2 = Engin::Get()->World().Create("Text2")->AddComponent<TextRenderer>();
	textRenderer3 = Engin::Get()->World().Create("Text3")->AddComponent<TextRenderer>();
	textRenderer4 = Engin::Get()->World().Create("Text4")->AddComponent<TextRenderer>();
	textRenderer5 = Engin::Get()->World().Create("Text5")->AddComponent<TextRenderer>();

	textRenderer->InitText("assets/arcade.ttf", std::to_string(score), 50, 360, 768);
	textRenderer2->InitText("assets/arcade.ttf", "score ", 50, 150, 768);
}

void GameManager::OnNotify(const Game_State& value)
{
	if (value.HasLose == true)
	{
		textRenderer3->InitText("assets/arcade.ttf", "You lose ", 100, 275, 325);
		textRenderer5->InitText("assets/arcade.ttf", "Press   Space   to   continue ", 50, 50, 725);
		gameFinish = true;
	}
	if (value.hasWon == true)
	{
		textRenderer4->InitText("assets/arcade.ttf", "YOU WON! ", 100, 275, 325);
		textRenderer5->InitText("assets/arcade.ttf", "Press   Space   to   continue ", 50, 50, 725);
		gameFinish = true;
	}
	score = value._collectable;
	textRenderer->InitText("assets/arcade.ttf", std::to_string(score), 50, 360, 768);
}

void GameManager::Draw()
{
}
float _time = 0;
void GameManager::Update(float dt)
{
	if (gameFinish == false)
	{
		_time += dt;
		if (_time >= 4)
		{
			if (score < 500 && currentIndex < 1)
			{
				Engin::Get()->Audio().StopMusic();
				currentIndex = 1;
				Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
			}
			else if (score < 1000 && score >= 500 && currentIndex < 2)
			{
				Engin::Get()->Audio().StopMusic();
				currentIndex = 2;
				Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
			}
			else if (score < 1500 && score >= 1000 && currentIndex < 3)
			{
				Engin::Get()->Audio().StopMusic();
				currentIndex = 3;
				Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
			}
			else if (score < 2000 && score >= 1500 && currentIndex < 4)
			{
				Engin::Get()->Audio().StopMusic();
				currentIndex = 4;
				Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
			}
			if (score > 2500 && currentIndex < 5)
			{
				Engin::Get()->Audio().StopMusic();
				currentIndex = 5;
				Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
			}
		}
	}
	else
	{
		if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_SPACE))
		{
			Engin::Get()->World().Unload();
			Engin::Get()->World().Load("Title Scene");
		}
	}
}


void GameManager::Start()
{
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/game_start.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_1.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_2.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_3.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_4.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_5.wav"));
	currentIndex = 0;
	Engin::Get()->Audio().PlayMusic(musicIds[currentIndex], 0);
}

void GameManager::Destroy()
{

}
