#include <map>
#include <QMessageBox>
#include "AddEditMatchDialog.h"
#include "SetScoreWidget.h"
#include "Calendar.h"
#include "Match.h"
#include "AppController.h"

AddEditMatchDialog::AddEditMatchDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitCustomComponents();
	QObject::connect(&*m_upCalendar, &Calendar::MatchDateSet, this, &AddEditMatchDialog::SetMatchDate);
}
AddEditMatchDialog::~AddEditMatchDialog()
{}
void AddEditMatchDialog::InitCustomComponents()
{
	m_upCalendar = std::make_unique<Calendar>(this);
	const unsigned int uiFixedWidth = 120;
	ui.comboBox_Statu->setFixedWidth(uiFixedWidth);
	ui.comboBox_Stage->setFixedWidth(uiFixedWidth);
	ui.lineEdit_Date->setFixedWidth(uiFixedWidth);
	ui.timeEdit->setFixedWidth(uiFixedWidth);
	ui.DateButton->setFixedWidth(30);
}
void AddEditMatchDialog::PrepareDialog(DialogMode mode, const Tournament& t, const Match& m)
{
	std::cout << "AddEditMatchDialog::PrepareDialog\n";
	SetDialogMode(mode);
	m_RootTournament = t;
	m_uiMinSet = (m_RootTournament.GetSetsBestOf() + 1) / 2;
	m_uiMaxSet = m_RootTournament.GetSetsBestOf();
	InitDialog();
	switch (m_DialogMode)
	{
	case DialogMode::eAddDialog:
	{
		setWindowTitle("Add Match");
		InitSetList(Set(Score(0, 0)));
		break;
	}
	case DialogMode::eEditDialog:
	{
		setWindowTitle("Edit Match");
		m_EditedMatch = m;
		FillDialog();
		break;
	}
	default:
		std::cout << "AddEditMatchDialog::SetDialogMode Unknown DialogMode!\n";
	}
}
void AddEditMatchDialog::InitDialog()
{
	ClearDialog();
	InitButtonWithPicture(ui.DateButton, ":images/images/calendar.png", 0.04f);
	InitButtonWithPicture(ui.AddSetButton, ":images/images/plus.png", 0.04f);
	InitButtonWithPicture(ui.RemoveSetButton, ":images/images/minus.png", 0.04f);
	SetComboBoxAlternatives(ui.comboBox_Statu, m_vecStatuAlternatives);
	SetComboBoxAlternatives(ui.comboBox_Stage, m_RootTournament.GetStages());
	ui.lineEdit__Opponent1->setEnabled(true);
	if (m_RootTournament.IsDoubleTournament())
		ui.lineEdit__Opponent2->setEnabled(true);
	else
		ui.lineEdit__Opponent2->setEnabled(false);
	SetMatchDate(QDate::currentDate());
	ui.timeEdit->setTime(QTime(0, 0));
	InitSetList(Set{}, true);
}
void AddEditMatchDialog::FillDialog()
{
	ui.comboBox_Statu->setCurrentIndex(1 + std::distance(m_vecStatuAlternatives.cbegin(), std::find(m_vecStatuAlternatives.cbegin(), m_vecStatuAlternatives.cend(), m_EditedMatch.GetStatu())));
	if (m_EditedMatch.GetStatu() == "WO")
	{
		if (m_EditedMatch.GetOutcome() == Outcome::HomeWin)
		{
			ui.radioButton_Win->setChecked(true);
		}
		else if (m_EditedMatch.GetOutcome() == Outcome::AwayWin)
		{
			ui.radioButton_Lose->setChecked(true);
		}
	}
	const auto& vecStage = m_RootTournament.GetStages();
	ui.comboBox_Stage->setCurrentIndex(1 + std::distance(vecStage.cbegin(), std::find(vecStage.cbegin(), vecStage.cend(), m_EditedMatch.GetStage())));
	ui.lineEdit__Opponent1->setText(QString::fromStdString(m_EditedMatch.GetOpponent1()));
	if (m_RootTournament.IsDoubleTournament())
	{
		ui.lineEdit__Opponent2->setText(QString::fromStdString(m_EditedMatch.GetOpponent2()));
	}
	SetMatchDate(m_EditedMatch.GetDate());
	ui.timeEdit->setTime(m_EditedMatch.GetTime());
	FillSets();
}
void AddEditMatchDialog::FillSets()
{
	size_t szSetIdx{ 0 };
	ui.listWidget->clear();
	for (const auto& s : m_EditedMatch.GetSets())
	{
		std::cout << "AddEditMatchDialog::InitDialogWithMatch set = " << s << "\n";
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
	const unsigned int uiMinSet = (m_RootTournament.GetSetsBestOf() + 1) / 2;
	for (auto szSetIdx = 0; szSetIdx < uiMinSet; ++szSetIdx)
	{
		InsertSet(szSetIdx, s);
	}
	SetEnableSetList(blEnabled);
}
void AddEditMatchDialog::ClearDialog()
{
	InitComboBox(ui.comboBox_Statu);
	InitComboBox(ui.comboBox_Stage);
	ui.radioButton_Win->setAutoExclusive(false);
	ui.radioButton_Lose->setAutoExclusive(false);
	ui.radioButton_Win->setChecked(false);
	ui.radioButton_Lose->setChecked(false);
	ui.radioButton_Win->setAutoExclusive(true);
	ui.radioButton_Lose->setAutoExclusive(true);
	ui.radioButton_Win->setVisible(false);
	ui.radioButton_Lose->setVisible(false);
	SetEnableOpponent(true);
	ui.listWidget->clear();
}
void AddEditMatchDialog::InsertSet(size_t idx, Set set)
{
	if (ui.listWidget->count() < m_uiMaxSet)
	{
		auto item = new QListWidgetItem(ui.listWidget);
		auto ssw = new SetScoreWidget(idx, set, this);
		item->setSizeHint(QSize(ssw->width(), ssw->height()));
		ui.listWidget->addItem(item);
		ui.listWidget->setItemWidget(item, ssw);
	}
}
void AddEditMatchDialog::RemoveSet(size_t idx)
{
	if (ui.listWidget->count() > 0)
	{
		QListWidgetItem* lastItem = ui.listWidget->item(idx);
		ui.listWidget->removeItemWidget(lastItem);
		delete lastItem;
	}
}
void AddEditMatchDialog::SetEnableOpponent(bool blEnabled)
{
	ui.lineEdit__Opponent1->setText("");
	ui.lineEdit__Opponent2->setText("");
	ui.lineEdit__Opponent1->setEnabled(blEnabled);
	if (m_RootTournament.IsDoubleTournament())
	{
		ui.lineEdit__Opponent2->setEnabled(blEnabled);
	}
}
std::vector<Set> AddEditMatchDialog::GetSets()const
{
	std::vector<Set> vecSet;
	size_t szSet = ui.listWidget->count();
	for (size_t idx{}; idx < szSet; ++idx)
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
Score AddEditMatchDialog::CollectMatchScore()const
{
	unsigned uiHomeScore{}, uiAwayScore{};
	std::vector<Set> vecSet = GetSets();
	if (!vecSet.empty())
	{
		uiHomeScore = std::count_if(vecSet.cbegin(), vecSet.cend(), [](const auto& set) {
			return set.GetOutcome() == Outcome::HomeWin;
			});
		uiAwayScore = std::count_if(vecSet.cbegin(), vecSet.cend(), [](const auto& set) {
			return set.GetOutcome() == Outcome::AwayWin;
			});
	}
	return Score(uiHomeScore, uiAwayScore);
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
	if (ui.listWidget->count() < m_uiMaxSet)
	{
		InsertSet(ui.listWidget->count(), Set{});
	}
	else
	{
		std::string sMessage = "You can not exceed maximum number of sets(" + std::to_string(m_RootTournament.GetSetsBestOf()) + ") in the tournament";
		QMessageBox::warning(this, "Warning", QString::fromStdString(sMessage));
	}
}

void AddEditMatchDialog::on_RemoveSetButton_clicked()
{
	if (ui.listWidget->count() > m_uiMinSet)
	{
		RemoveSet(ui.listWidget->count() - 1);
	}
	else
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
		Match m;
		m.SetDate(m_MatchDate);
		m.SetTime(ui.timeEdit->time());
		m.SetTournamentID(m_RootTournament.GetID());
		m.SetStatu(ui.comboBox_Statu->currentText().toStdString());
		m.SetStage(ui.comboBox_Stage->currentText().toStdString());
		m.SetOpponent1(ui.lineEdit__Opponent1->text().toStdString());
		if (m_RootTournament.IsDoubleTournament())
			m.SetOpponent2(ui.lineEdit__Opponent2->text().toStdString());
		m.SetScore(CollectMatchScore());
		m.SetSets(GetSets());
		if (!m.IsMatchValid())
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
				if (AppController::instance().AddNewMatch(m))
					QMessageBox::information(this, "Information", "New match is added successfully");
				break;
			}
			case DialogMode::eEditDialog:
			{
				m.SetID(m_EditedMatch.GetID());
				if (m == m_EditedMatch)
				{
					QMessageBox::warning(this, "Warning", "No change detected in the match.");
				}
				else
				{
					if (AppController::instance().EditMatch(m))
						QMessageBox::information(this, "Information", "The match is edited successfully");
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