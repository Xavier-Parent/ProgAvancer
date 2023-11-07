#include "PlayerController.h"
#include "engin.h"

using namespace homer;
PlayerController::PlayerController()
	:x(0), y(0)
{
	x = 0;
	y = 0;
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(float dt)
{

	if (Engin::Get()->Input().IsKeyDown(7)) {
		x += 100 * dt;
	}
	if (Engin::Get()->Input().IsKeyDown(4)) {
		x -= 100 * dt;
	}
	if (Engin::Get()->Input().IsKeyDown(26)) {
		y -= 100 * dt;
	}
	if (Engin::Get()->Input().IsKeyDown(22)) {
		y += 100 * dt;
	}
	if (Engin::Get()->Input().IsKeyDown(44)) {
		Engin::Get()->World().Create("Pas ghost");
	}

	if (Engin::Get()->Input().IsKeyDown(42)) {
		Engin::Get()->World().Remove(m_Entity);
	}
}
