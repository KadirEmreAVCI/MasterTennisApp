#ifndef ORGPARTICIPATION_H
#define ORGPARTICIPATION_H

// Project Headers
#include "Organization.h"

#include <string>
#include <memory>
#include <QWidget>
#include "ui_OrgParticipation.h"

class OrgParticipation : public QWidget, public Ui::OrgParticipationClass
{
	Q_OBJECT

public:
	OrgParticipation(const Organization& org, unsigned uiParticipationCount, QWidget* parent = nullptr);
	~OrgParticipation() = default;
};

#endif