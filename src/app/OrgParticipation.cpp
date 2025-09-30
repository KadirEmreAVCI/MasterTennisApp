#include "OrgParticipation.h"
#include "Organization.h"
#include "Utility.h"

OrgParticipation::OrgParticipation(const Organization& org, unsigned uiParticipationCount, QWidget* parent) 
{
    setupUi(this);
    utility::InitLabelWithPicture(labelOrgIcon, org.GetFullPicturePath(), 1.90f);
    labelOrgName->setText(QString::fromStdString(org.GetName()));
    labelParticipationCount->setText(QString::fromStdString(" x" + std::to_string(uiParticipationCount)));
}