#include "Animation.h"

using namespace homer;
Animation::Animation(Entity* entity) : SpriteRenderer(entity)
{
	id = 0;
	frame = RectF();
	currentClip = Clip();
	delay = 0;
	index = 0;
	columns = 0;
	rows = 0;
	loop = false;
	timer = 0;
}

Animation::~Animation()
{
}

void Animation::InitAnimation(const std::string& filename, int frameInRows, int frameInColumns, int frameWidth, int frameHeight)
{
	id = Engin::Get()->Graphics().LoadTexture(filename);
	rows = frameInColumns;
	columns = frameInRows;
	frame.w = static_cast<float>(frameWidth);
	frame.h = static_cast<float>(frameHeight);
}

void Animation::AddClip(const std::string& name, int start, int count, float delay)
{
	Clip clip{ start , count };
	clipMap[name] = clip;
	this->delay = delay;
}

void Animation::Update(float dt)
{

	timer += dt;
	if (timer > delay)
	{
		timer = 0;
		index++;
		if (index >= currentClip._start + currentClip._count)
		{
			index = currentClip._start;
			if (!loop) {
				Stop();
			}
		}

		frame.x = (index % columns) * frame.w;
		frame.y = (index / columns) * frame.h;

	}
}

void Animation::Draw()
{
	RectF square = RectF();
	square.x = m_Entity->GetX();
	square.y = m_Entity->GetY();
	square.h = frame.h * 10;
	square.w = frame.w * 10;
	Engin::Get()->Graphics().DrawTexture(id, frame, square, 0, Flip(), Color::Red);
}

void Animation::Stop()
{
}

void Animation::Play(const std::string& name, bool loop)
{
	if (clipMap[name]._start == currentClip._start)
	{
		return;
	}
	if (clipMap.count(name) > 0)
	{

		currentClip = clipMap[name];
		index = currentClip._start;
		frame.x = (index % columns) * frame.w;
		frame.y = (index / columns) * frame.h;
		this->loop = loop;

	}
}
