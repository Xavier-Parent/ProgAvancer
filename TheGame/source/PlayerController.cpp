#include "PlayerController.h"
using namespace homer;

PlayerController::PlayerController(Entity* entity)
	:Component(entity)
{
	x = m_Entity->GetX();
	y = m_Entity->GetY();
	tileMap = Engin::Get()->World().Find("background")->GetComponent<Tilemap>();
	animation = m_Entity->GetComponent<Animation>();
	speedx = 100;
	speedy = 100;
	
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(float dt)
{

	int penis;
	float oldx = x;
	//Atlas* atlas = m_Entity->GetComponent<Atlas>();

	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_D)) {
		x += speedx * dt;
		animation->Play("Right", true);
		if (tileMap->IsColliding("Wall", m_Entity, &penis))
		{
			x = oldx - 1;
			
		}
	}
	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_A)) {
		x -= speedx * dt;
		animation->Play("Left", true);
		if (tileMap->IsColliding("Wall", m_Entity, &penis))
		{
			x = oldx + 1;
		}
	}
	float oldy = y;
	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_W)) {
		y -= speedy * dt;
		animation->Play("Up", true);
		if (tileMap->IsColliding("Wall", m_Entity, &penis))
		{
			y = oldy + 1;
		}
	}
	if (Engin::Get()->Input().IsKeyDown(EKey::EKEY_S) && hit == false) {
		y += speedy * dt;
		animation->Play("Down", true);
		if (tileMap->IsColliding("Wall", m_Entity, &penis))
		{
			y = oldy - 1;
			hit = true;
		}
	}
	m_Entity->SetPosition(x, y);

	tileMap->IsColliding("Collectable", m_Entity, &penis);
	//tileMap->IsColliding("Wall", m_Entity, &penis);



}

void PlayerController::Start()
{

}

void PlayerController::Destroy()
{
}
