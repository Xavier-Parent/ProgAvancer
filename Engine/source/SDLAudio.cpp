#include "SDLAudio.h"


SDLAudio::SDLAudio()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

SDLAudio::~SDLAudio()
{
	Mix_CloseAudio();
}

size_t SDLAudio::LoadMusic(const std::string& filename)
{
	const size_t id = std::hash<std::string>()(filename);

	if (m_MusicMap.count(id) > 0)
	{
		return id;
	}
	Mix_Music* _music = Mix_LoadMUS(filename.c_str());
	if (_music != NULL)
	{
		m_MusicMap[id] = _music;
	}

	return id;
}

size_t SDLAudio::LoadSound(const std::string& filename)
{

	const size_t id = std::hash<std::string>()(filename);

	if (m_SoundMap.count(id) > 0)
	{
		return id;
	}
	Mix_Chunk* _sound = Mix_LoadWAV(filename.c_str());
	
	if (_sound != NULL)
	{
		m_SoundMap[id] = _sound;
	}

	return id;
}

void SDLAudio::PlayMusic(size_t id)
{
	if (m_MusicMap.count(id) > 0)
	{
		Mix_HaltMusic();
		Mix_PlayMusic(m_MusicMap[id],0);
	}
}

void SDLAudio::PlayMusic(size_t id, int loop)
{
}

void SDLAudio::PlaySFX(size_t id)
{
	if (m_SoundMap.count(id) > 0)
	{
		Mix_PlayChannel(-1, m_SoundMap[id], 0);
	}
}

void SDLAudio::PlaySFX(size_t id, int loop)
{
}

void SDLAudio::PauseMusic()
{
}

void SDLAudio::StopMusic()
{
}

void SDLAudio::ResumeMusic()
{
}

void SDLAudio::SetVolume(int volume)
{
}

void SDLAudio::SetVolume(size_t soundId, int volume)
{
}
