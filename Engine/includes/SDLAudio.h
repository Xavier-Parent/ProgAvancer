#pragma once
#include <iostream>
#include "IAudio.h"
#include "SDL_mixer.h"
#include <map>

class SDLAudio : public IAudio
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	SDLAudio();
	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~SDLAudio();
	/// <summary>
	/// Function to Load a music
	/// </summary>
	/// <param name="filename">The path of the position of the file for the Music </param>
	/// <returns></returns>
	virtual size_t LoadMusic(const std::string& filename) override;
	/// <summary>
	/// Function to Load a sound in the game
	/// </summary>
	/// <param name="filename">The path to find the file for the sound</param>
	/// <returns></returns>
	virtual size_t LoadSound(const std::string& filename) override;

	virtual void PlayMusic(size_t id) override;
	/// <summary>
	/// Function to play the corect music using an ID
	/// </summary>
	/// <param name="id">The Id of the music</param>
	virtual void PlayMusic(size_t id, int loop) override;
	/// <summary>
	/// Function to ply a music with an ID and decide if it can loop
	/// </summary>
	/// <param name="id">The ID of the correct music</param>
	/// <param name="loop">The music can loop</param>
	virtual void PlaySFX(size_t id) override;
	/// <summary>
	/// Function to play a sound
	/// </summary>
	/// <param name="id">The ID of the sound</param>
	virtual void PlaySFX(size_t id, int loop) override;
	/// <summary>
	/// Function to play a sound and decide if it can loop
	/// </summary>
	/// <param name="id">The Id of the sound</param>
	/// <param name="loop">The Sound can loop</param>
	virtual void PauseMusic() override;
	/// <summary>
	/// Function to pause a music or a sound
	/// </summary>
	virtual void StopMusic() override;
	/// <summary>
	/// Function to stop a music or a sound
	/// </summary>
	virtual void ResumeMusic() override;
	/// <summary>
	/// Function to set the Volume of the game
	/// </summary>
	/// <param name="volume">The value of the volume</param>
	virtual void SetVolume(int volume) override;
	/// <summary>
	/// Function to set the volume of a particular music or sound
	/// </summary>
	/// <param name="soundId">The ID of the music or sound that need to be change</param>
	/// <param name="volume">The value of the volume</param>
	virtual void SetVolume(size_t soundId, int volume) override;

private:
	std::map<size_t, Mix_Music*> m_MusicMap;
	std::map<size_t, Mix_Chunk*> m_SoundMap;

};