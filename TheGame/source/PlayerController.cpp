#include "PlayerController.h"
using namespace homer;

PlayerController::PlayerController(Entity* entity)
	:Component(entity)
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(float dt)
{
	x = m_Entity->GetX();
	y = m_Entity->GetY();
	Atlas* atlas = m_Entity->GetComponent<Atlas>();
	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_D)) {
		x += 100 * dt;
		atlas->SetFrame("1");
	}

	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_A)) {
		x -= 100 * dt;
		atlas->SetFrame("2");
	}

	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_W)) {
		y -= 100 * dt;
		atlas->SetFrame("3");
	}

	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_S)) {
		y += 100 * dt;
		atlas->SetFrame("4");
	}

	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_SPACE)) {
		if (spawn == false)
		{
			Entity* ghost = Engin::Get()->World().Create("ghost");
			ghost->AddComponent<SpriteRenderer>()->Init("assets/sprite/pacman3.png", 50, 50);
			spawn = true;
		}
	}

	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_BACKSPACE)) {
		Engin::Get()->World().Remove(Engin::Get()->World().Find("ghost"));
		spawn = false;
	}
	m_Entity->SetPosition(x, y);
}

void PlayerController::Start()
{
}

void PlayerController::Destroy()
{
}
