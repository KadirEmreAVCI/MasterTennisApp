#include <iostream>
#include <string>
#include "Countdown.h"
QString Countdown::ms_sFormat;
void Countdown::setDateFormat(std::string sFormat)
{
	ms_sFormat = QString::fromStdString(sFormat);
}
void Countdown::setMatchDate(const QDate& date, const QTime& time)
{
	m_MatchDate = QDateTime::fromString(date.toString("yyyy-MM-dd") + " " + time.toString(), ms_sFormat);
}
QString Countdown::secondsToString(int seconds) const
{
	const int DAY = 86400;
	int days = seconds / DAY;
	QTime t = QTime(0, 0).addSecs(seconds % DAY);
	return QString("%1 Days %2:%3:%4")
		.arg(days, 3).arg(t.hour(), 2, 10, QChar('0')).arg(t.minute(), 2, 10, QChar('0')).arg(t.second(), 2, 10, QChar('0'));
}
QString Countdown::GetCountdown()
{
	if (const std::string& sCountdown = secondsToString(QDateTime::currentDateTime().secsTo(m_MatchDate)).toStdString(); sCountdown == "  0 Days 00:00:00")
	{
		std::cout << "Countdown::GetCountdown emit TimeIsUp()\n";
		emit TimeIsUp();
	}
	return secondsToString(QDateTime::currentDateTime().secsTo(m_MatchDate));
}