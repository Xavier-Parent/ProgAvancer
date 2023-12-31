#include "Enemy.h"
#include "PlayerController.h"
using namespace homer;
Enemy::Enemy(Entity* entity)
	:Component(entity)
{
	x = 0;
	y = 0;
	animation = m_Entity->GetComponent<Animation>();
	tileMap = Engin::Get()->World().Find("background")->GetComponent<Tilemap>();
	goUp = false;
	goDown = false;
	goRight = false;
	goLeft = false;
	powerUp = false;
	playerDead = false;
	isWeak = false;
	normalSpeed = 125;
	weakenSpeed = 50;
	enemySpeed = 125;
	colIndex = 0;
	colX = 0;
	colY = 0;
	currentSoundIndex = 0;
	currentMovementState = MovementState::IDLE;
	animation->AddClip("ghostRight", 0, 2, 0.1f);
	animation->AddClip("ghostLeft", 2, 2, 0.1f);
	animation->AddClip("ghostUp", 4, 2, 0.1f);
	animation->AddClip("ghostDown", 6, 2, 0.1f);
	animation->AddClip("ghostDead", 8, 2, 0.1f);
	musicId = 0;
	soundIds = 0;
}

Enemy::~Enemy()
{
}

void Enemy::CheckPlayerCollisions()
{
	Entity* Player;

	if (Engin::Get()->Collider().CollideWithLayer(m_Entity, "PlayerLayer", &Player))
	{
		if (powerUp == true)
		{
			m_Entity->SetPosition(310, 310);
			powerUp = false;
			enemySpeed = normalSpeed;
			Player->GetComponent<PlayerController>()->EnemyCollisions();
			Engin::Get()->Audio().PlaySFX(soundIds);
		}
		else
		{
			if (Player)
			{
				Player->GetComponent<PlayerController>()->PlayerDead();
				enemySpeed = 0;
			}
		}
	}
}

void Enemy::OnNotify(const Player_Action& value)
{
	if (value.hasPowerup == true)
	{
		powerUp = true;
		animation->Stop();
		enemySpeed = weakenSpeed;
		animation->Play("ghostDead", true);
	}
	else
	{
		powerUp = false;
		animation->Stop();
		enemySpeed = normalSpeed;
	}
	if (value.isDead == true)
	{
		playerDead = true;
	}
}

void Enemy::Start()
{
	soundIds = Engin::Get()->Audio().LoadSound("assets/audio/eat_ghost.wav");
	currentMovementState = MovementState::MOVE_RIGHT;
	CreateColliders();
}

void Enemy::Update(float dt)
{
	if (playerDead == false)
	{
		CheckPlayerCollisions();
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
			if (powerUp == false)
			{
				animation->Play("ghostRight", true);
			}
			if (x > 712) {
				x = -36;
			}
			break;
		case MovementState::MOVE_LEFT:
			x -= enemySpeed * dt;
			if (powerUp == false)
				animation->Play("ghostLeft", true);
			if (x < -36) {
				x = 712;
			}
			break;
		case MovementState::MOVE_UP:
			y -= enemySpeed * dt;
			if (powerUp == false)
				animation->Play("ghostUp", true);
			break;
		case MovementState::MOVE_DOWN:
			y += enemySpeed * dt;
			if (powerUp == false)
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
	if (tileMap->IsColliding("Wall", upCollider, &colIndex, &colX, &colY))
	{
		goUp = false;
	}
	else
	{
		goUp = true;
	}
	if (tileMap->IsColliding("Wall", downCollider, &colIndex, &colX, &colY) || tileMap->IsColliding("Door", downCollider, &colIndex, &colX, &colY))
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
		x = colX + 18.0f;
	}
	if (dir == LEFT)
	{
		x = colX - 26.0f;
	}
	if (dir == DOWN)
	{
		y = colY + 18.0f;
	}
	if (dir == UP)
	{
		y = colY - 26.0f;
	}

}

Entity* Enemy::CreateAndSetupCollider(const std::string& name, int xOffset, int yOffset)
{
	Entity* collider = Engin::Get()->World().Create(name);
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
