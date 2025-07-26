#include "Audio.h"

bool Audio::LoadFromFile(const string& path, int channel)
{
	m_MixChunk = Mix_LoadWAV(path.c_str());

	if (m_MixChunk != NULL)
	{
		return true;
	}

	return false;
}

void Audio::Play(int looping)
{
	Mix_PlayChannel(m_Channel, m_MixChunk, looping);
}

void Audio::Pause()
{
	Mix_Pause(m_Channel);
}

void Audio::SetVolume(int volume)
{
	Mix_Volume(m_Channel, volume);
}

Audio::Audio(string audioPath, int channel)
{
	if (!LoadFromFile(audioPath, channel))
	{
		cout << "Error, could not load Audio from File " << audioPath << endl;
	}

	m_Channel = channel;
}

Audio::~Audio()
{
	delete m_MixChunk;
	m_MixChunk = nullptr;
}
