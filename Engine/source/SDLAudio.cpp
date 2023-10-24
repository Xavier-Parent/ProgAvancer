#include "SDLAudio.h"
#include "engin.h"


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
	const size_t _musId = std::hash<std::string>()(filename);
	if (m_MusicMap.count(_musId) > 0)
	{
		return _musId;
	}

	Mix_Music* _mus = Mix_LoadMUS(filename.c_str());
	if (_mus)
	{
		
		m_MusicMap.emplace(_musId, _mus);
		return _musId;
	}
	else {
		homer::Engin::Get()->Logger().LogError(std::string(SDL_GetError()));
	}

	return 0;
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
	/*
	if (m_MusicMap.count(id) > 0)
	{
		Mix_PlayMusic(m_MusicMap[id],0);
		//Mix_HaltMusic();
	}
	*/
	PlayMusic(id, -1);
}

void SDLAudio::PlayMusic(size_t id, int loop)
{
	Mix_PlayMusic(m_MusicMap[id], loop);
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
	if (m_SoundMap.count(id) > 0)
	{
		Mix_PlayChannel(-1,m_SoundMap[id], loop);
	}
}

void SDLAudio::PauseMusic()
{
	Mix_PauseMusic();
}

void SDLAudio::StopMusic()
{
	Mix_HaltMusic();
}

void SDLAudio::ResumeMusic()
{
	Mix_ResumeMusic();
}

void SDLAudio::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

void SDLAudio::SetVolume(size_t soundId, int volume)
{
	Mix_VolumeChunk(m_SoundMap[soundId], volume);
}
