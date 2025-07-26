#pragma once

#include "SDL_mixer.h"
#include <string>
#include <iostream>

using namespace std;

class Audio
{
private:

	Mix_Chunk* m_MixChunk = nullptr;
	int m_Channel = 0;

	bool LoadFromFile(const string& path, int channel);

public:

	Audio(string audioPath, int channel);
	~Audio();
	void Play(int looping);
	void Pause();
	void SetVolume(int volume);

protected:


};

