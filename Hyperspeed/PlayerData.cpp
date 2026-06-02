#include "PlayerData.h"

PlayerData::PlayerData(const string& saveFilePath)
	: m_Coins(0), m_Deaths(0), m_HighScore(0), m_SaveFilePath(saveFilePath)
{
	Load();
}

PlayerData::~PlayerData()
{
	Save();
}

void PlayerData::AddCoins(int amount)
{
	m_Coins += amount;
}

void PlayerData::IncrementDeaths()
{
	m_Deaths++;
}

void PlayerData::SubmitScore(int score)
{
	if (score > m_HighScore)
		m_HighScore = score;
}

void PlayerData::ResetSessionData()
{
	m_Coins = 0;
}

void PlayerData::Save()
{
	ofstream file(m_SaveFilePath, ios::binary);
	if (!file.is_open()) return;

	file.write(reinterpret_cast<const char*>(&m_Coins), sizeof(m_Coins));
	file.write(reinterpret_cast<const char*>(&m_Deaths), sizeof(m_Deaths));
	file.write(reinterpret_cast<const char*>(&m_HighScore), sizeof(m_HighScore));
}

void PlayerData::Load()
{
	ifstream file(m_SaveFilePath, ios::binary);
	if (!file.is_open()) return;

	file.read(reinterpret_cast<char*>(&m_Coins), sizeof(m_Coins));
	file.read(reinterpret_cast<char*>(&m_Deaths), sizeof(m_Deaths));
	file.read(reinterpret_cast<char*>(&m_HighScore), sizeof(m_HighScore));
}
