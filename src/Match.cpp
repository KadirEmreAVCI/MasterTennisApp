#include <algorithm>
#include "Match.h"
Match::Match(unsigned uiID,
	unsigned uiTournamentID,
	const std::string& sStatu,
	const std::string& sStage,
	const std::string& sOpponent1,
	const std::string& sOpponent2,
	const QDate& rDate,
	const QTime& rTime,
	const std::vector<Set>& vecSet)
	:
	m_uiTournamentID{ uiTournamentID },
	m_sStatu{ sStatu },
	m_sStage{ sStage },
	m_sOpponent1{ sOpponent1 },
	m_soptOpponent2{ sOpponent2 },
	m_Date{ rDate },
	m_Time{ rTime },
	DBItem("Match", "TournamentID,Statu,Stage,Opponent1,Opponent2,Date,Time,Score,Sets")
{
	SetID(uiID);
	SetSets(vecSet);
}
unsigned Match::GetID()const
{
	return m_uiID;
}
void Match::SetID(unsigned uiID)
{
	m_uiID = uiID;
}
unsigned Match::GetTournamentID()const
{
	return m_uiTournamentID;
}
void Match::SetTournamentID(unsigned uiTournamentID)
{
	m_uiTournamentID = uiTournamentID;
}
std::string Match::GetStatu()const
{
	return m_sStatu;
}
void Match::SetStatu(const std::string& sStatu)
{
	m_sStatu = sStatu;
}
Outcome Match::GetOutcome()const
{
	return GetScore().GetOutcome();
}
std::string Match::GetStage()const
{
	return m_sStage;
}
void Match::SetStage(const std::string& sStage)
{
	m_sStage = sStage;
}
std::string Match::GetOpponent1()const
{
	return m_sOpponent1;
}
std::string Match::GetOpponent2()const
{
	return m_soptOpponent2.value_or("-");
}
void Match::SetOpponent1(const std::string& sOpponent1)
{
	m_sOpponent1 = sOpponent1;
}
void Match::SetOpponent2(std::optional<std::string> soptOpponent2)
{
	m_soptOpponent2 = soptOpponent2;
}
QDate Match::GetDate()const
{
	return m_Date;
}
void Match::SetDate(const QDate& date)
{
	m_Date = date;
}
QTime Match::GetTime()const
{
	return m_Time;
}
void Match::SetTime(const QTime& time)
{
	m_Time = time;
}
Score Match::GetScore()const
{
	return m_Score;
}
void Match::SetScore()
{
	m_Score.SetScore(std::make_pair<unsigned, unsigned>(std::count_if(m_vecSet.cbegin(), m_vecSet.cend(), [](const Set& s) {return s.GetOutcome() == Outcome::HomeWin; }), 
														std::count_if(m_vecSet.cbegin(), m_vecSet.cend(), [](const Set& s) {return s.GetOutcome() == Outcome::AwayWin; })));
}
std::vector<Set> Match::GetSets()const
{
	return m_vecSet;
}
void Match::SetSets(std::vector<Set> vecSet)
{
	m_vecSet = vecSet;
	SetScore();
}
std::string Match::SetsToString()const
{
	std::ostringstream oss;
	std::copy(m_vecSet.cbegin(), m_vecSet.cend(), std::ostream_iterator<Set>(oss, "\n"));
	std::string sSets = oss.str();
	if (!sSets.empty())
	{
		sSets.erase(sSets.size() - 1);
	}
	return sSets;
}
std::vector<Set> Match::SetsFromString(const std::string& sSets)
{
	std::vector<Set> vecSet;
	std::stringstream ss{sSets};
	std::string sSet;
	while (std::getline(ss, sSet, '\n'))
	{
		vecSet.emplace_back(Set::FromString(sSet));
	}
	return vecSet;
}
bool Match::IsUpcomingMatch()const
{
	return m_Date > QDate::currentDate() || (m_Date == QDate::currentDate() && m_Time > QTime::currentTime());
}
bool Match::IsMatchValid()const
{
	const bool blUpcomingMatchValid = IsUpcomingMatch() && GetScore() == Score(0, 0) && (m_vecSet.empty() || std::all_of(m_vecSet.cbegin(), m_vecSet.cend(), [](const Set& s) {
		return s == Set{ Score(0, 0), Score(0, 0) }; }));
	const bool blCompletedMatchValid = !IsUpcomingMatch() && (GetOutcome() != Outcome::Tied) && std::all_of(m_vecSet.cbegin(), m_vecSet.cend(), [](const Set& s) {
		return s.GetOutcome() != Outcome::Tied; });
	return blUpcomingMatchValid || blCompletedMatchValid;
}
bool Match::IsEarlier(const Match& other)const
{
	return (m_Date < other.m_Date) || ((m_Date == other.m_Date) && (m_Time < other.m_Time));
}
bool Match::InsertToDB()const
{
	std::cout << "Match::InsertToDB t = " << *this << "\n";
	std::string sDBValues{ "'" + std::to_string(GetTournamentID()) +
							"','" + GetStatu() +
							"','" + GetStage() +
							"','" + GetOpponent1() +
							"','" + GetOpponent2() +
							"','" + GetDate().toString().toStdString() +
							"','" + GetTime().toString().toStdString() +
							"','" + GetScore().ToString() +
							"','" + SetsToString() +
							"'" };
	return SQLiteDB::instance().InsertItem2Table(m_sDBTable, m_sDBColumns, sDBValues);
}
bool Match::EditInDB()const
{
	std::cout << "Match::EditInDB t = " << *this << "\n";
	QMap<QString, QVariant> columnValues;
	columnValues["TournamentID"] = QString::fromStdString(std::to_string(m_uiTournamentID));
	columnValues["Statu"] = QString::fromStdString(m_sStatu);
	columnValues["Stage"] = QString::fromStdString(m_sStage);
	columnValues["Opponent1"] = QString::fromStdString(m_sOpponent1);
	columnValues["Opponent2"] = QString::fromStdString(GetOpponent2());
	columnValues["Date"] = m_Date.toString();
	columnValues["Time"] = m_Time.toString();
	columnValues["Score"] = QString::fromStdString(m_Score.ToString());
	columnValues["Sets"] = QString::fromStdString(SetsToString());
	return SQLiteDB::instance().EditItemInTable(m_sDBTable, columnValues, m_uiID);
}
void Match::LoadFromDB(unsigned ID)
{
	const SQLiteDB& db = SQLiteDB::instance();
	SetID(stoi(db.GetValue(m_sDBTable, "ID", ID)));
	SetTournamentID(stoi(db.GetValueWithCond(m_sDBTable, "TournamentID", "ID", std::to_string(m_uiID))));
	SetStatu(db.GetValueWithCond(m_sDBTable, "Statu", "ID", std::to_string(m_uiID)));
	SetStage(db.GetValueWithCond(m_sDBTable, "Stage", "ID", std::to_string(m_uiID)));
	SetOpponent1(db.GetValueWithCond(m_sDBTable, "Opponent1", "ID", std::to_string(m_uiID)));
	SetOpponent2(db.GetValueWithCond(m_sDBTable, "Opponent2", "ID", std::to_string(m_uiID)));
	SetDate(QDate::fromString(QString::fromStdString(db.GetValueWithCond(m_sDBTable, "Date", "ID", std::to_string(m_uiID)))));
	SetTime(QTime::fromString(QString::fromStdString(db.GetValueWithCond(m_sDBTable, "Time", "ID", std::to_string(m_uiID)))));
	SetSets(SetsFromString(db.GetValueWithCond(m_sDBTable, "Sets", "ID", std::to_string(m_uiID))));
}