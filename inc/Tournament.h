#pragma once
#include <string>
#include <vector>
#include "Match.h"
#include "Period.h"
enum class Type {
	eSingle = 0,
	eDouble = 1
};
class Tournament{
public:
	Tournament(std::string sName, Type type, unsigned uiTotalCategory, std::string sCategory, Period per, unsigned uiParticipant, std::string sMaxStage, bool blCompleted, std::string sMaxStageAchieved);
	void AddMatch(const Match&);
	Match GetMatch()const;
	std::string GetName()const;
	void SetName(std::string);
	Type GetType()const;
	void SetType(Type);
	unsigned GetTotalCategory()const;
	void SetTotalCategory(unsigned);
	std::string GetCategory()const;
	void SetCategory(std::string);
	Period GetPeriod()const;
	void SetPeriod(Period);
	unsigned GetParticipant()const;
	void SetParticipant(unsigned);
	bool GetCompleted()const;
	void SetCompleted(bool);
	std::string GetMaxStageAchieved()const;
	void SetMaxStageAchieved(std::string);
private:
	std::string m_sName;
	Type m_Type;
	unsigned m_uiTotalCategory;
	std::string m_sCategory;
	Period m_Period;
	unsigned m_uiParticipant;
	bool m_blCompleted{ false };
	std::string m_sMaxStageAchieved;
	std::vector<Match> m_vecMatch;
};

