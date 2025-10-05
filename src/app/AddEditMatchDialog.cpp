#include <map>
#include <QMessageBox>
#include "AddEditMatchDialog.h"
#include "SetScoreWidget.h"
#include "Calendar.h"
#include "Match.h"
#include "AppController.h"
#include "DatabaseController.h"
#include "Utility.h"

AddEditMatchDialog::AddEditMatchDialog(QWidget *parent)
	: QDialog(parent),AddEditDialog<Match>(this)
{
	ui.setupUi(this);
	m_upCalendar = std::make_unique<Calendar>(this);
	const unsigned int uiFixedWidth = 120;
	ui.comboBox_Statu->setFixedWidth(uiFixedWidth);
	ui.comboBox_Stage->setFixedWidth(uiFixedWidth);
	ui.lineEdit_Date->setFixedWidth(uiFixedWidth);
	ui.timeEdit->setFixedWidth(uiFixedWidth);
	ui.DateButton->setFixedWidth(30);
	QObject::connect(&*m_upCalendar, &Calendar::MatchDateSet, this, &AddEditMatchDialog::SetMatchDate);
}
AddEditMatchDialog::~AddEditMatchDialog()
{}
void AddEditMatchDialog::SetRootTournament(const Tournament& t)
{
	m_RootTournament = t;
}
void AddEditMatchDialog::InitDialog()
{
	using namespace utility;
	m_uiMinSet = (m_RootTournament.GetSetsBestOf() + 1) / 2;
	m_uiMaxSet = m_RootTournament.GetSetsBestOf();
	ClearDialog();
	InitButtonWithPicture(ui.DateButton, ":images/calendar.png", 0.8f);
	InitButtonWithPicture(ui.AddSetButton, ":images/plus.png", 0.8f);
	InitButtonWithPicture(ui.RemoveSetButton, ":images/minus.png", 0.8f);
	SetComboBoxItems(ui.comboBox_Statu, m_vecStatuItems);
	SetComboBoxItems(ui.comboBox_Stage, m_RootTournament.GetPossibleStages());
	ui.lineEdit__Opponent1->setEnabled(true);
	ui.lineEdit__Opponent2->setEnabled(m_RootTournament.IsDoubleTournament());
	SetMatchDate(QDate::currentDate());
	ui.timeEdit->setTime(QTime(0, 0));
	InitSetList(Set(Score(0, 0)));
}
void AddEditMatchDialog::FillDialog()
{
	utility::InitComboBox(ui.comboBox_Statu, QString::fromStdString(m_EditedItem.GetStatu()));
	if (m_EditedItem.GetStatu() == "WO")
	{
		if (m_EditedItem.GetOutcome() == common::Outcome::HomeWin)
		{
			ui.radioButton_Win->setChecked(true);
		}
		else if (m_EditedItem.GetOutcome() == common::Outcome::AwayWin)
		{
			ui.radioButton_Lose->setChecked(true);
		}
	}
	utility::InitComboBox(ui.comboBox_Stage, QString::fromStdString(m_EditedItem.GetStage()));
	ui.lineEdit__Opponent1->setText(QString::fromStdString(m_EditedItem.GetOpponent1()));
	if (m_RootTournament.IsDoubleTournament())
	{
		ui.lineEdit__Opponent2->setText(QString::fromStdString(m_EditedItem.GetOpponent2()));
	}
	SetMatchDate(m_EditedItem.GetDate());
	ui.timeEdit->setTime(m_EditedItem.GetTime());
	FillSets();
}
void AddEditMatchDialog::FillSets()
{
	size_t szSetIdx{ 0 };
	ui.listWidget->clear();
	for (const auto& s : m_EditedItem.GetSets())
	{
		InsertSet(szSetIdx, s);
	}
	if (ui.comboBox_Statu->currentText() == "BYE")
	{
		SetEnableSetList(false);
	}
}
void AddEditMatchDialog::InitSetList(Set s, bool blEnabled)
{
	ui.listWidget->clear();
	for (auto szSetIdx = 0; szSetIdx < m_uiMinSet; ++szSetIdx)
	{
		InsertSet(szSetIdx, s);
	}
	SetEnableSetList(blEnabled);
}
void AddEditMatchDialog::ClearDialog()
{
	utility::InitComboBox(ui.comboBox_Statu);
	utility::InitComboBox(ui.comboBox_Stage);
	ui.radioButton_Win->setAutoExclusive(false);
	ui.radioButton_Lose->setAutoExclusive(false);
	ui.radioButton_Win->setChecked(false);
	ui.radioButton_Lose->setChecked(false);
	ui.radioButton_Win->setAutoExclusive(true);
	ui.radioButton_Lose->setAutoExclusive(true);
	ui.radioButton_Win->setVisible(false);
	ui.radioButton_Lose->setVisible(false);
	ui.lineEdit__Opponent1->setText("");
	ui.lineEdit__Opponent2->setText("");
	SetEnableOpponent(true);
	ui.listWidget->clear();
}
bool AddEditMatchDialog::InsertSet(size_t idx, Set set)
{
	if (ui.listWidget->count() < m_uiMaxSet)
	{
		utility::InsertItem2ListWidget(ui.listWidget, new SetScoreWidget(idx, set, this));
		return true;
	}
	return false;
}
bool AddEditMatchDialog::RemoveSet()
{
	if (ui.listWidget->count() > m_uiMinSet)
	{
		utility::DeleteItemFromListWidget(ui.listWidget, ui.listWidget->count() - 1);
		return true;
	}
	return false;
}
void AddEditMatchDialog::SetEnableOpponent(bool blEnabled)
{
	ui.lineEdit__Opponent1->setEnabled(blEnabled);
	if (m_RootTournament.IsDoubleTournament())
	{
		ui.lineEdit__Opponent2->setEnabled(blEnabled);
	}
}
std::vector<Set> AddEditMatchDialog::GetSets()const
{
	std::vector<Set> vecSet;
	for (size_t idx{}; idx < ui.listWidget->count(); ++idx)
	{
		QWidget* widget = ui.listWidget->itemWidget(ui.listWidget->item(idx));
		SetScoreWidget* ssw = qobject_cast<SetScoreWidget*>(widget);
		if (ssw)
		{
			vecSet.push_back(ssw->GetSet());
		}
	}
	return vecSet;
}
bool AddEditMatchDialog::IsMandatoryFieldsFilled()const
{
	const bool blWOValid = (ui.comboBox_Statu->currentText() == "WO" && ui.comboBox_Stage->currentText() != "" && ui.lineEdit__Opponent1->text() != "" && (!m_RootTournament.IsDoubleTournament() || (m_RootTournament.IsDoubleTournament() && ui.lineEdit__Opponent2->text() != "")) && m_MatchDate.isValid() && ui.timeEdit->time().isValid());
	const bool blUsualValid = (ui.comboBox_Statu->currentText() == "U" && ui.comboBox_Stage->currentText() != "" && ui.lineEdit__Opponent1->text() != "" && (!m_RootTournament.IsDoubleTournament() || (m_RootTournament.IsDoubleTournament() && ui.lineEdit__Opponent2->text() != "")) && m_MatchDate.isValid() && ui.timeEdit->time().isValid());
	const bool blBYEValid = (ui.comboBox_Statu->currentText() == "BYE" && ui.comboBox_Stage->currentText() != "");
	return blWOValid || blUsualValid || blBYEValid;
}
bool AddEditMatchDialog::IsThereAnyUnsavedInfo()const
{
	return (ui.comboBox_Statu->currentText() != "") || (ui.comboBox_Stage->currentText() != "") || (ui.lineEdit__Opponent1->text() != "") || (m_RootTournament.IsDoubleTournament() && ui.lineEdit__Opponent2->text() != "") || (m_MatchDate != QDate::currentDate()) || (ui.timeEdit->time() != QTime(0,0));
}
void AddEditMatchDialog::SetEnableSetList(bool blEnabled)
{
	size_t szSet = ui.listWidget->count();
	for (size_t idx{}; idx < szSet; ++idx)
	{
		QWidget* widget = ui.listWidget->itemWidget(ui.listWidget->item(idx));
		SetScoreWidget* ssw = qobject_cast<SetScoreWidget*>(widget);
		if (ssw)
		{
			ssw->SetEnabled(blEnabled);
		}
	}
}
void AddEditMatchDialog::SetMatchDate(const QDate& date)
{
	m_MatchDate = date;
	ui.lineEdit_Date->setText(date.toString());
}
void AddEditMatchDialog::on_AddSetButton_clicked()
{
	if (!InsertSet(ui.listWidget->count(), Set{}))
	{
		std::string sMessage = "You can not exceed maximum number of sets(" + std::to_string(m_RootTournament.GetSetsBestOf()) + ") in the tournament";
		QMessageBox::warning(this, "Warning", QString::fromStdString(sMessage));
	}
}
void AddEditMatchDialog::on_RemoveSetButton_clicked()
{
	if (!RemoveSet())
	{
		QMessageBox::warning(this, "Warning", "Minimum number of sets already reached!");
	}
}
void AddEditMatchDialog::on_DateButton_clicked()
{
	m_upCalendar->setModal(true);
	m_upCalendar->exec();
}
void AddEditMatchDialog::on_SaveButton_clicked()
{
	if (IsMandatoryFieldsFilled())
	{
		Match m{
			m_EditedItem.GetID(),
			m_RootTournament.GetID(),
			ui.comboBox_Statu->currentText().toStdString(),
			ui.comboBox_Stage->currentText().toStdString(),
			ui.lineEdit__Opponent1->text().toStdString(),
			m_RootTournament.IsDoubleTournament() ? std::optional<std::string>(ui.lineEdit__Opponent2->text().toStdString()) : std::nullopt,
			m_MatchDate,
			ui.timeEdit->time(),
			GetSets()
		};
		if (!m.IsValid())
		{
			QMessageBox::critical(this, "Error", "Invalid match.");
		}
		else
		{
			close();
			switch (m_DialogMode)
			{
			case DialogMode::eAddDialog:
			{
				if (AppController::instance().AddNewItem(m))
					QMessageBox::information(this, "Information", "New match is added successfully");
				break;
			}
			case DialogMode::eEditDialog:
			{
				if (m == m_EditedItem)
				{
					QMessageBox::warning(this, "Warning", "No change detected in the match.");
				}
				else
				{
					if (m_RootTournament.IsMatchValidForTournament(m))
					{
						if (AppController::instance().EditItem(m))
							QMessageBox::information(this, "Information", "The match is edited successfully");
					}
					else
					{
						QMessageBox::warning(this, "Warning", "Edited match is not compatible with the tournament.");
					}
				}
				break;
			}
			default:
				std::cerr << "AddEditMatchDialog::on_SaveButton_clicked Unknown DialogMode!\n";
			}
		}
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please fill all the mandatory fields.");
	}
}
void AddEditMatchDialog::on_ClearButton_clicked()
{
	if (IsThereAnyUnsavedInfo() && m_DialogMode != DialogMode::eEditDialog)
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Clear Request", "Are you sure you want to clear the dialog? All unsaved information will be lost.", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			InitDialog();
		}
	}
	else
	{
		InitDialog();
	}
}
void AddEditMatchDialog::on_radioButton_Win_clicked()
{
	ui.listWidget->clear();
	m_sWL = "W";
	if (ui.comboBox_Statu->currentText() == "WO")
	{
		InitSetList(Set(Score(6, 0)), false);
	}
}
void AddEditMatchDialog::on_radioButton_Lose_clicked()
{
	ui.listWidget->clear();
	m_sWL = "L";
	if (ui.comboBox_Statu->currentText() == "WO")
	{
		InitSetList(Set(Score(0, 6)), false);
	}
}
void AddEditMatchDialog::on_comboBox_Statu_currentTextChanged(const QString& statu)
{
	if (ui.comboBox_Statu->currentText() == "BYE" || ui.comboBox_Statu->currentText() == "WO")
	{
		ui.AddSetButton->setEnabled(false);
		ui.RemoveSetButton->setEnabled(false);
		if (ui.comboBox_Statu->currentText() == "BYE")
		{
			ui.radioButton_Win->setVisible(false);
			ui.radioButton_Lose->setVisible(false);
			ui.timeEdit->setEnabled(false);
			ui.lineEdit__Opponent1->setText("");
			ui.lineEdit__Opponent2->setText("");
			SetEnableOpponent(false);
			InitSetList(Set(Score(6, 0)), false);
		}
		else
		{
			ui.radioButton_Win->setVisible(true);
			ui.radioButton_Lose->setVisible(true);
			ui.timeEdit->setEnabled(true);
			SetEnableOpponent(true);
			if (m_sWL == "W")
			{
				on_radioButton_Win_clicked();
			}
			else if (m_sWL == "L")
			{
				on_radioButton_Lose_clicked();
			}
		}
	}
	else
	{
		InitSetList(Set(Score(0, 0)));
		ui.radioButton_Win->setVisible(false);
		ui.radioButton_Lose->setVisible(false);
		ui.AddSetButton->setEnabled(true);
		ui.RemoveSetButton->setEnabled(true);
		ui.timeEdit->setEnabled(true);
		SetEnableOpponent(true);
	}
}