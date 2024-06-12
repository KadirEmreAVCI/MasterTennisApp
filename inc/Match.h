#pragma once
#include <vector>
#include <string>
#include <QDate>
#include <QTime>
#include "Set.h"
#include "Score.h"
class Match{
public:
	unsigned GetID()const;
	void SetID(unsigned uiID);
	unsigned GetTournamentID()const;
	void SetTournamentID(unsigned uiTournamentID);
	std::string GetStatu()const;
	void SetStatu(const std::string& sStatu);
	std::string GetStage()const;
	void SetStage(const std::string& sStage);
	std::string GetOpponent1()const;
	std::string GetOpponent2()const;
	void SetOpponent1(const std::string&);
	void SetOpponent2(std::optional<std::string> = std::nullopt);
	QDate GetDate()const;
	void SetDate(const QDate& date);
	QTime GetTime()const;
	void SetTime(const QTime& time);
	Score GetScore()const;
	void SetScore(const Score& s);
	std::vector<Set> GetSets()const;
	void SetSets(std::vector<Set>);
	std::string SetsToString()const;
	friend std::ostream& operator<<(std::ostream& os, const Match& m)
	{
		os << "\tID: " << m.m_uiID <<
			", TOURNAMENT ID: " << m.m_uiTournamentID <<
			", STATU: " << m.m_sStatu <<
			", STAGE: " << m.m_sStage <<
			", OPPONENT 1: " << m.m_sOpponent1 <<
			", OPPONENT 2: " << m.m_soptOpponent2.value_or("NA") <<
			", DATE: " << m.m_Date.toString().toStdString() <<
			", TIME: " << m.m_Time.toString().toStdString() <<
			", SCORE: " << m.m_Score.ToString() <<
			", SETS: " << m.SetsToString();
		return os;
	}
private:
	unsigned m_uiID;
	unsigned m_uiTournamentID;
	std::string m_sStatu{};
	std::string m_sStage{};
	std::string m_sOpponent1{};
	std::optional<std::string> m_soptOpponent2{};
	QDate m_Date{};
	QTime m_Time{};
	Score m_Score{};
	std::vector<Set> m_vecSet{};
};

