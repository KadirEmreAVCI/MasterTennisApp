#ifndef ORGPARTICIPATION_H
#define ORGPARTICIPATION_H

#include <string>
#include <memory>
#include <QWidget>
#include "ui_OrgParticipation.h"
#include "IQTComponent.h"
class OrgParticipation : public QWidget, public Ui::OrgParticipationClass, public IQTComponent
{
	Q_OBJECT

public:
	OrgParticipation(QWidget* parent = nullptr, const std::string& sOrgImageFile = "", const std::string& sOrgName = "", unsigned uiParticipationCount = 0);
	~OrgParticipation() = default;
private:
	void InitCustomComponents() override final;
    std::string m_sOrgImageFile;
    std::string m_sOrgName;
    unsigned m_uiParticipationCount;
};

#endif