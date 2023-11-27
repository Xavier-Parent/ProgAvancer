#include "Enemy.h"
#include "BoxCollider.h"
using namespace homer;
Enemy::Enemy(Entity* entity)
	:Component(entity)
{
	x = 44;
	y = 40;
	enemySpeed = 125;
	animation = m_Entity->GetComponent<Animation>();
	tileMap = Engin::Get()->World().Find("background")->GetComponent<Tilemap>();
	goUp = false;
	goDown = false;
	goRight = false;
	goLeft = false;
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	m_Entity->SetPosition(x, y);
	currentMovementState = MovementState::MOVE_DOWN;
	CreateColliders();
}

void Enemy::Update(float dt)
{
	x = m_Entity->GetX();
	y = m_Entity->GetY();
	int colIndex;
	int colX;
	int colY;
	CheckCollision();

	MovementState newMovementState = currentMovementState;
	EDirections collisionDirection = tileMap->IsColliding("Wall", m_Entity, &colIndex, &colX, &colY);

	if (collisionDirection != EDirections::NONE) {
		ChooseRandomDirection();
		newMovementState = MovementState::IDLE;
	}

	else {
		if (rand() % 100 < 10) {
			ChooseRandomDirection();
			newMovementState = currentMovementState; 
		}
	}

	switch (currentMovementState) {
	case MovementState::MOVE_RIGHT:
		x += enemySpeed * dt;
		animation->Play("ghostRight", true);
		if (x > 712) {
			x = -36;
		}
		break;
	case MovementState::MOVE_LEFT:
		x -= enemySpeed * dt;
		animation->Play("ghostLeft", true);
		if (x < -36) {
			x = 712;
		}
		break;
	case MovementState::MOVE_UP:
		y -= enemySpeed * dt;

		animation->Play("ghostUp", true);
		break;
	case MovementState::MOVE_DOWN:
		y += enemySpeed * dt;
		animation->Play("ghostDown", true);
		break;
	case MovementState::IDLE:
		ChooseRandomDirection();
		newMovementState = currentMovementState;
		break;
	default:
		break;
	}

	currentMovementState = newMovementState;

	m_Entity->SetPosition(x, y);
	upCollider->SetPosition(m_Entity->GetX(), m_Entity->GetY() - 16);
	downCollider->SetPosition(m_Entity->GetX(), m_Entity->GetY() + 16);
	rightCollider->SetPosition(m_Entity->GetX() + 16, m_Entity->GetY());
	leftCollider->SetPosition(m_Entity->GetX() - 16, m_Entity->GetY());
}

void Enemy::ChooseRandomDirection()
{
	std::vector<MovementState> possibleDirections;

	if (currentMovementState != MovementState::MOVE_UP && currentMovementState != MovementState::MOVE_DOWN && goUp) possibleDirections.push_back(MovementState::MOVE_UP);
	if (currentMovementState != MovementState::MOVE_DOWN && currentMovementState != MovementState::MOVE_UP && goDown) possibleDirections.push_back(MovementState::MOVE_DOWN);
	if (currentMovementState != MovementState::MOVE_LEFT && currentMovementState != MovementState::MOVE_RIGHT && goLeft) possibleDirections.push_back(MovementState::MOVE_LEFT);
	if (currentMovementState != MovementState::MOVE_RIGHT && currentMovementState != MovementState::MOVE_LEFT && goRight) possibleDirections.push_back(MovementState::MOVE_RIGHT);

	if (!possibleDirections.empty()) {
		int randomIndex = rand() % possibleDirections.size();
		currentMovementState = possibleDirections[randomIndex];
	}
}

void Enemy::Destroy()
{
}

void Enemy::CheckCollision()
{
	std::cout << goRight;
	if (tileMap->IsColliding("Wall", upCollider, &colIndex, &colX, &colY))
	{
		goUp = false;
	}
	else
	{
		goUp = true;
	}
	if (tileMap->IsColliding("Wall", downCollider, &colIndex, &colX, &colY))
	{
		goDown = false;
	}
	else
	{
		goDown = true;
	}
	if (tileMap->IsColliding("Wall", rightCollider, &colIndex, &colX, &colY))
	{
		goRight = false;
	}
	else
	{
		goRight = true;
	}
	if (tileMap->IsColliding("Wall", leftCollider, &colIndex, &colX, &colY))
	{
		goLeft = false;
	}
	else
	{
		goLeft = true;
	}

	EDirections dir = tileMap->IsColliding("Wall", m_Entity, &colIndex, &colX, &colY);

	if (dir == RIGHT)
	{
		x = colX + 18;
		//ChooseRandomDirection();
	}
	if (dir == LEFT)
	{
		x = colX - 26;
		//ChooseRandomDirection();
	}
	if (dir == DOWN)
	{
		y = colY + 18;
		//ChooseRandomDirection();
	}
	if (dir == UP)
	{
		y = colY - 26;
		//ChooseRandomDirection();
	}

}

Entity* Enemy::CreateAndSetupCollider(const std::string& name, int xOffset, int yOffset)
{
	Entity* collider = Engin::Get()->World().Create(name);
	collider->AddComponent<BoxCollider>();
	collider->SetPosition(m_Entity->GetX() + xOffset, m_Entity->GetY() + yOffset);
	return collider;
}

void Enemy::CreateColliders()
{
	const int offset = 16;
	upCollider = CreateAndSetupCollider("upCollider", 0, -offset);
	downCollider = CreateAndSetupCollider("downCollider", 0, offset);
	rightCollider = CreateAndSetupCollider("rightCollider", offset, 0);
	leftCollider = CreateAndSetupCollider("leftCollider", -offset, 0);
}
