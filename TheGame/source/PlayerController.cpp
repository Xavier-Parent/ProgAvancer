#include "PlayerController.h"
using namespace homer;

PlayerController::PlayerController(Entity* entity)
	:Component(entity)
{
    x = 0;
    y = 0;
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(float dt)
{
	x = m_Entity->GetX();
	y = m_Entity->GetY();
	//Atlas* atlas = m_Entity->GetComponent<Atlas>();
	Animation* animation = m_Entity->GetComponent<Animation>();

    if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_D)) {
        x += 100 * dt;
        // atlas->SetFrame("1");
        animation->Play("Right", true);
    }

    if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_A)) {
        x -= 100 * dt;
        // atlas->SetFrame("2");
        animation->Play("Left", true);
    }

    if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_W)) {
        y -= 100 * dt;
        // atlas->SetFrame("3");
        animation->Play("Up", true);
    }

    if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_S)) {
        y += 100 * dt;
        // atlas->SetFrame("4");
        animation->Play("Down", true);
    }

	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_SPACE)) {
		animation->Play("Dead", true);
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
