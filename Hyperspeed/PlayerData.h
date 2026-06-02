#pragma once

#include <string>
#include <fstream>

using namespace std;

class PlayerData
{
public:
	PlayerData(const string& saveFilePath = "playerdata.dat");
	~PlayerData();

	void AddCoins(int amount);
	void IncrementDeaths();
	void SubmitScore(int score);

	int GetCoins() const { return m_Coins; }
	int GetDeaths() const { return m_Deaths; }
	int GetHighScore() const { return m_HighScore; }

	void ResetSessionData();

	void Save();
	void Load();

private:
	int m_Coins;
	int m_Deaths;
	int m_HighScore;

	string m_SaveFilePath;
};
