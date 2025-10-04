#include "NoUpcomingMatch.h"
#include "Common.h"

NoUpcomingMatch::NoUpcomingMatch(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setFixedSize(common::g_uiUpcomingMatchWidth, common::g_uiUpcomingMatchHeight);
}

NoUpcomingMatch::~NoUpcomingMatch()
{}
