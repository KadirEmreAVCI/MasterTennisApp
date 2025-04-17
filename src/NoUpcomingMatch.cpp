#include "NoUpcomingMatch.h"
#include "Config.h"

NoUpcomingMatch::NoUpcomingMatch(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setFixedSize(g_uiUpcomingMatchWidth, g_uiUpcomingMatchHeight);
}

NoUpcomingMatch::~NoUpcomingMatch()
{}
