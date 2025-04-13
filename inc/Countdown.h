#pragma once
#include <string>
#include <QObject>
#include <QDateTime>
class Countdown : public QObject {
	Q_OBJECT
public:
	static void setDateFormat(std::string);
	void setMatchDate(const QDate& date, const QTime& time);
	QString GetCountdown();
private:
	QString secondsToString(int seconds) const;
	static QString ms_sFormat;
	QDateTime m_MatchDate;
signals:
	// Signal functions are just declared, not defined by programmers!
	void TimeIsUp();
};

