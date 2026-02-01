#ifndef MATCH_H
#define MATCH_H

#include <vector>
#include <string>
#include <QDate>
#include <QTime>
#include "Set.h"
#include "Score.h"
#include "DBItem.h"
class Match : public DBItem {
public:
	explicit Match(unsigned uiID = 0, unsigned uiTournamentID = 0, const std::string& sStatu = "", const std::string& sStage = "", const std::string& sOpponent1 = "", const std::optional<std::string>& soptOpponent2 = "", const QDate& rDate = QDate{}, const QTime& rTime = {}, const std::vector<Set>& vecSet = {});
	unsigned GetID()const;
	unsigned GetTournamentID()const;
	const std::string& GetStatu()const;
	const std::string& GetStage()const;
	const std::string& GetOpponent1()const;
	std::string GetOpponent2()const;
	QDate GetDate()const;
	QTime GetTime()const;
	Score GetScore()const;
	const std::vector<Set>& GetSets()const;
	common::Outcome GetOutcome()const;
	std::string GetOutcomePic()const;
	std::string SetsToString()const;
	static std::vector<Set> SetsFromString(const std::string& sSets);
	bool IsUpcomingMatch()const;
	bool IsValid()const;
	bool IsEarlier(const Match& other)const;
	bool IsTiebreakPlayed()const;
	bool operator<(const Match& other)const;
	bool operator>(const Match& other)const;
	bool operator<=(const Match& other)const;
	bool operator>=(const Match& other)const;
	friend bool operator==(const Match& lhs, const Match& rhs)
	{
		return	lhs.m_uiID == rhs.m_uiID &&
				lhs.m_uiTournamentID == rhs.m_uiTournamentID &&
				lhs.m_sStatu == rhs.m_sStatu &&
				lhs.m_sStage == rhs.m_sStage &&
				lhs.m_sOpponent1 == rhs.m_sOpponent1 &&
				lhs.m_soptOpponent2 == rhs.m_soptOpponent2 &&
				lhs.m_Date == rhs.m_Date &&
				lhs.m_Time == rhs.m_Time &&
				lhs.m_vecSet == rhs.m_vecSet;
	}
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
	virtual bool InsertToDB()const override;
	virtual bool EditInDB()const override;
	virtual void LoadFromDB(unsigned ID)override;
private:
	void SetSets(const std::vector<Set>&);
	void SetScore();
	unsigned m_uiTournamentID{};
	std::string m_sStatu{};
	std::string m_sStage{};
	std::string m_sOpponent1{};
	std::optional<std::string> m_soptOpponent2{};
	QDate m_Date{};
	QTime m_Time{};
	Score m_Score{};
	std::vector<Set> m_vecSet{};
};

#endif