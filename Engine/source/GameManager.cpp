#include "GameManager.h"
#include <iostream>
#include "engin.h"

using namespace homer;
GameManager::GameManager(Entity* parent)
	:Component(parent)
{
	score = 0;
	currentIndex = 0;
	//Text->AddComponent<TextRenderer>()->InitText("assets/arcade.ttf", "J'aime les fruits", 50);
}

void GameManager::OnNotify(const int& value)
{
	score = value;
	textRenderer->InitText("assets/arcade.ttf", std::to_string(score), 50, 360, 768);
}
size_t id;
void GameManager::Draw()
{
}
bool first = false;
bool second = false;
bool third = false;
bool fourth = false;
bool five = false;

float timere = 0;
void GameManager::Update(float dt)
{
	timere += dt;
	//std::cout << timere << std::endl;
	if (timere >= 3 && first == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex = 1;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		first = true;
	}
	if (timere >= 12 && second == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex = 2;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		second = true;
	}
	if (timere >= 24 && third == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex = 3;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		third = true;
	}
	if (timere >= 36 && fourth == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex = 4;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		fourth = true;
	}
	if (timere >= 48 && five == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex = 5;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		five = true;
	}
}

void GameManager::Start()
{
	
	textRenderer = m_Entity->AddComponent<TextRenderer>();
	textRenderer->InitText("assets/arcade.ttf",std::to_string(score), 50, 360,768);
	textRenderer2 = m_Entity->AddComponent<TextRenderer>();
	textRenderer2->InitText("assets/arcade.ttf", "score ", 50, 150, 768);
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/game_start.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_1.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_2.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_3.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_4.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_5.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/retreating.wav"));
	currentIndex = 0;
	Engin::Get()->Audio().PlayMusic(musicIds[currentIndex],0);


}

void GameManager::Destroy()
{

}
