#include "GameManager.h"
#include <iostream>
#include "engin.h"

using namespace homer;

GameManager::GameManager()
{
	score = 0;
	currentIndex = 0;
}

GameManager::GameManager(Entity* parent)
{
}

void GameManager::OnNotify(const int& value)
{
	score = value;
}
size_t id;
void GameManager::Draw()
{
}
bool first = false;
bool second = false;
bool third = false;

float timere = 0;
void GameManager::Update(float dt)
{
	timere += dt;
	std::cout << timere << std::endl;
	if (timere >= 7 && first == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex++;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		first = true;
	}
	if (timere >= 15 && second == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex++;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		second = true;
	}
	if (timere >= 30 && third == false)
	{
		Engin::Get()->Audio().StopMusic();
		currentIndex++;
		Engin::Get()->Audio().PlayMusic(musicIds[currentIndex]);
		third = true;
	}
	//Engin::Get()->Graphics().DrawString("allo", id, 300, 200, Color::Blue);
	//std::cout << score;
}

void GameManager::Start()
{
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/game_start.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/retreating.wav"));
	musicIds.push_back(Engin::Get()->Audio().LoadMusic("assets/audio/siren_1.wav"));
	currentIndex = 0;
	Engin::Get()->Audio().PlayMusic(musicIds[currentIndex],0);
}

void GameManager::Destroy()
{

}
