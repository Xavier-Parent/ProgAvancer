#include "Animation.h"

using namespace homer;
Animation::Animation(Entity* entity)
{
}

Animation::~Animation()
{
}

void Animation::InitAnimation(const std::string& filename, int frameInRows, int frameWidth, int frameHeight)
{
	id = Engin::Get()->Graphics().LoadTexture(filename);
}

void Animation::AddClip(const std::string& name, int start, int count, float delay)
{

}

void Animation::Update(float dt)
{

}

void Animation::Stop()
{

}

void Animation::Play(const std::string& name, bool loop)
{

}
