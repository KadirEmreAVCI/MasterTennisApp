#include "OrgParticipation.h"
#include "Organization.h"
#include "Utility.h"

OrgParticipation::OrgParticipation(QWidget* parent, const std::string& sOrgImageFile, const std::string& sOrgName, unsigned uiParticipationCount) 
    :
    m_sOrgImageFile{ (Organization::GetOrgImageRootDestDir() + "/").toStdString() + sOrgImageFile}, m_sOrgName{sOrgName}, m_uiParticipationCount{uiParticipationCount}
{
    setupUi(this);
    utility::InitLabelWithPicture(labelOrgIcon, m_sOrgImageFile, 1.90f);
    labelOrgName->setText(QString::fromStdString(m_sOrgName));
    labelParticipationCount->setText(QString::fromStdString(" x" + std::to_string(m_uiParticipationCount)));
}