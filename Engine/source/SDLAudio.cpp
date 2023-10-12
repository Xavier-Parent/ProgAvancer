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
	Mix_Music* music;
	music = Mix_LoadMUS("assets/Victory.mp3");
	return size_t();
}

size_t SDLAudio::LoadSound(const std::string& filename)
{
	Mix_Chunk* sample;
	sample = Mix_LoadWAV("assets/Error.mp3");
	return size_t();
}

void SDLAudio::PlayMusic(size_t id)
{
}

void SDLAudio::PlayMusic(size_t id, int loop)
{
}

void SDLAudio::PlaySFX(size_t id)
{
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
