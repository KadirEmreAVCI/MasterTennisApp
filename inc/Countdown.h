#pragma once
#include <string>
#include <QDateTime>
class Countdown{
public:
	static void setDateFormat(std::string);
	void setMatchDate(std::string);
	QString GetCountdown() const;
private:
	QString secondsToString(int seconds) const;
	static QString ms_sFormat;
	QDateTime m_MatchDate;

};

