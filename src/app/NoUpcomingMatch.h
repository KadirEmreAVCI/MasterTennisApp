#ifndef NOUPCOMINGMATCH_H
#define NOUPCOMINGMATCH_H

#include <QWidget>
#include "ui_NoUpcomingMatch.h"

class NoUpcomingMatch : public QWidget
{
	Q_OBJECT

public:
	explicit NoUpcomingMatch(QWidget *parent = nullptr);
	~NoUpcomingMatch();

private:
	Ui::NoUpcomingMatchClass ui;
};

#endif