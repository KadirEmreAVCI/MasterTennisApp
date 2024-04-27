#include <string>
#include "Countdown.h"
QString Countdown::ms_sFormat;
void Countdown::setDateFormat(std::string sFormat)
{
	ms_sFormat = QString::fromStdString(sFormat);
}
void Countdown::setMatchDate(std::string sMatchDate)
{
	m_MatchDate = QDateTime::fromString(QString::fromStdString(sMatchDate), ms_sFormat);
}
QString Countdown::secondsToString(int seconds) const
{
	const int DAY = 86400;
	int days = seconds / DAY;
	QTime t = QTime(0, 0).addSecs(seconds % DAY);
	return QString("%1  %2:%3:%4")
		.arg(days, 3).arg(t.hour(), 2, 10, QChar('0')).arg(t.minute(), 2, 10, QChar('0')).arg(t.second(), 2, 10, QChar('0'));
}
QString Countdown::GetCountdown() const
{
	return secondsToString(QDateTime::currentDateTime().secsTo(m_MatchDate));
}