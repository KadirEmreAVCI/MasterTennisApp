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
}
AddEditMatchDialog::~AddEditMatchDialog()
{}
void AddEditMatchDialog::InitCustomComponents()
{
	m_upCalendar = std::make_unique<Calendar>(this);
	QObject::connect(&*m_upCalendar, &Calendar::MatchDateSet, this, &AddEditMatchDialog::SetMatchDate);
}
void AddEditMatchDialog::SetDialogMode(DialogMode mode, const Tournament& t)
{
	InitDialog(t);
	using enum DialogMode;
	m_DialogMode = mode;
	switch (m_DialogMode)
	{
	case eAddDialog:
	{
		setWindowTitle("Add Match");
		break;
	}
	case eEditDialog:
	{
		setWindowTitle("Edit Match");
		//InitDialog(t,m);
		break;
	}
	default:
		std::cout << "AddEditMatchDialog::SetDialogMode Unknown DialogMode!\n";
	}
}
void AddEditMatchDialog::InitDialog(const Tournament& t)
{
	InitButtonWithPicture(ui.DateButton, ":images/images/calendar.png", 0.04f);
	InitButtonWithPicture(ui.AddSetButton, ":images/images/plus.png", 0.04f);
	InitButtonWithPicture(ui.RemoveSetButton, ":images/images/minus.png", 0.04f);
	m_RootTournament = t;
	m_uiMinSet = (m_RootTournament.GetSetsBestOf() + 1) / 2;
	m_uiMaxSet = m_RootTournament.GetSetsBestOf();
	SetComboBoxAlternatives(ui.comboBox_Stage, m_RootTournament.GetStages());
	ui.lineEdit__Opponent1->setEnabled(true);
	if (m_RootTournament.GetType() == "Double")
		ui.lineEdit__Opponent2->setEnabled(true);
	else
		ui.lineEdit__Opponent2->setEnabled(false);
	InitSetList(Set(false, Score(0,0)));
	ClearDialog();
}
void AddEditMatchDialog::InitSetList(Set s, bool blEnabled)
{
	ui.listWidget->clear();
	m_uiAddedSet = 0;
	const unsigned int uiMinSet = (m_RootTournament.GetSetsBestOf() + 1) / 2;
	for (auto uiAddedSet = 0; uiAddedSet < uiMinSet; ++uiAddedSet)
	{
		InsertSet(s);
	}
	SetEnableSetList(blEnabled);
}
void AddEditMatchDialog::ClearDialog()
{
	InitComboBox(ui.comboBox_Statu);
	InitComboBox(ui.comboBox_Stage);
	ui.radioButton_Win->setChecked(false);
	ui.radioButton_Win->setEnabled(false);
	ui.radioButton_Lose->setChecked(false);
	ui.radioButton_Lose->setEnabled(false);
	SetEnableOpponent(true);

}
void AddEditMatchDialog::InsertSet(Set set)
{
	if (m_uiAddedSet < m_uiMaxSet)
	{
		++m_uiAddedSet;
		if (m_uiAddedSet == m_uiMaxSet)
			set.SetSuperTB(true);
		auto item = new QListWidgetItem(ui.listWidget);
		auto ssw = new SetScoreWidget(m_uiAddedSet, set, this);
		item->setSizeHint(QSize(ssw->width(), ssw->height()));
		ui.listWidget->addItem(item);
		ui.listWidget->setItemWidget(item, ssw);
	}
}
void AddEditMatchDialog::SetEnableOpponent(bool blEnabled)
{
	ui.lineEdit__Opponent1->setText("");
	ui.lineEdit__Opponent1->setEnabled(blEnabled);
	if (m_RootTournament.GetType() == "Double")
	{
		ui.lineEdit__Opponent2->setText("");
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
Score AddEditMatchDialog::GetMatchScore()const
{
	unsigned uiHomeScore{}, uiAwayScore{};
	std::vector<Set> vecSet = GetSets();
	if (!vecSet.empty())
	{
		uiHomeScore = std::count_if(vecSet.cbegin(), vecSet.cend(), [](const auto& set) {
			return set.GetWinner() == Winner::Home;
			});
		uiAwayScore = vecSet.size() - uiHomeScore;
	}
	std::cout << "AddEditMatchDialog::GetMatchScore Match Score = " << Score(uiHomeScore, uiAwayScore) << '\n';
	return Score(uiHomeScore, uiAwayScore);
}
bool AddEditMatchDialog::MandatoryFieldsFilled()const
{
	return m_sStatu != ""
		&& m_sStage != ""
		&& ui.lineEdit__Opponent1->text() != ""
		&& (m_RootTournament.GetType() == "Single" || (m_RootTournament.GetType() == "Double" && ui.lineEdit__Opponent2->text() != ""))
		&& m_MatchDate.isValid()
		&& ui.timeEdit->time().isValid()
		&& AreSetsValid() && (m_uiAddedSet >= m_uiMinSet) && (m_uiAddedSet <= m_uiMaxSet);
}
bool AddEditMatchDialog::AreSetsValid()const
{
	std::vector<Set> vecSet = GetSets();
	const auto blSetsInvalid = std::any_of(vecSet.cbegin(), vecSet.cend(), [](const auto& s) {
		return !s.IsValid();
		});
	return !blSetsInvalid;
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
	if (m_uiAddedSet < m_uiMaxSet)
	{
		InsertSet();
	}
	else
	{
		std::string sMessage = "You can not exceed maximum number of sets(" + std::to_string(m_RootTournament.GetSetsBestOf()) + ") in the tournament";
		QMessageBox::warning(this, "Warning", QString::fromStdString(sMessage));
	}
}

void AddEditMatchDialog::on_RemoveSetButton_clicked()
{
	if (m_uiAddedSet > m_uiMinSet)
	{
		QListWidgetItem* lastItem = ui.listWidget->item(--m_uiAddedSet);
		ui.listWidget->removeItemWidget(lastItem);
		delete lastItem;
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
	if (MandatoryFieldsFilled())
	{
		Match m;
		m.SetTournamentID(m_RootTournament.GetID());
		m.SetStatu(m_sStatu.toStdString());
		m.SetStage(m_sStage.toStdString());
		m.SetOpponent1(ui.lineEdit__Opponent1->text().toStdString());
		if(ui.lineEdit__Opponent2->isEnabled() && ui.lineEdit__Opponent2->text() != "")
			m.SetOpponent2(ui.lineEdit__Opponent2->text().toStdString());
		m.SetDate(m_MatchDate);
		m.SetTime(ui.timeEdit->time());
		m.SetScore(GetMatchScore());
		std::cout << "AddEditMatchDialog::on_SaveButton_clicked Match Score = " << m.GetScore().ToString() << "\n";
		m.SetSets(GetSets());
		const bool blNewMatchAdded = AppController::instance().AddNewMatch(m);
		if (blNewMatchAdded)
			QMessageBox::information(this, "Information", "New match is added successfully");
	}
	else
	{
		QMessageBox::critical(this, "Error", "Please fill all the mandatory fields.");
	}
}

void AddEditMatchDialog::on_radioButton_Win_clicked()
{
	ui.listWidget->clear();
	m_sWL = "W";
	if (m_sStatu == "WO")
	{
		InitSetList(Set(false, Score(6, 0)), false);
	}
}

void AddEditMatchDialog::on_radioButton_Lose_clicked()
{
	ui.listWidget->clear();
	m_sWL = "L";
	if (m_sStatu == "WO")
	{
		InitSetList(Set(false, Score(0, 6)), false);
	}
}

void AddEditMatchDialog::on_comboBox_Statu_currentTextChanged(const QString& statu)
{
	m_sStatu = statu;
	if (m_sStatu == "BYE" || m_sStatu == "WO")
	{
		ui.AddSetButton->setEnabled(false);
		ui.RemoveSetButton->setEnabled(false);
		if (m_sStatu == "BYE")
		{
			ui.radioButton_Win->setEnabled(false);
			ui.radioButton_Lose->setEnabled(false);
			ui.DateButton->setEnabled(false);
			ui.timeEdit->setEnabled(false);
			SetEnableOpponent(false);
			InitSetList(Set(false, Score(6, 0)), false);
		}
		else
		{
			ui.radioButton_Win->setEnabled(true);
			ui.radioButton_Lose->setEnabled(true);
			ui.DateButton->setEnabled(true);
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
		InitSetList(Set(false, Score(0, 0)));
		ui.radioButton_Win->setEnabled(false);
		ui.radioButton_Lose->setEnabled(false);
		ui.AddSetButton->setEnabled(true);
		ui.RemoveSetButton->setEnabled(true);
		ui.DateButton->setEnabled(true);
		ui.timeEdit->setEnabled(true);
		SetEnableOpponent(true);
	}
}

void AddEditMatchDialog::on_comboBox_Stage_currentTextChanged(const QString& stage)
{
	m_sStage = stage;
}