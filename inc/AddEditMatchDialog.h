#pragma once
#include <QDialog>
#include "ui_AddEditMatchDialog.h"
#include "IQTComponent.h"
#include "Tournament.h"
#include "Set.h"
class Calendar;
class AddEditMatchDialog : public QDialog, public IQTComponent
{
	Q_OBJECT

public:
	AddEditMatchDialog(QWidget *parent = nullptr);
	~AddEditMatchDialog();
	void InitCustomComponents() override final;
	void SetDialogMode(DialogMode mode, const Tournament& t);
private:
	void InitDialog(const Tournament& t);
	void InitSetList(Set s, bool blEnabled = true);
	void ClearDialog();
	void InsertSet(Set set = Set(false, Score(0,0)));
	void SetEnableOpponent(bool);
	std::vector<Set> GetSets()const;
	Score GetMatchScore()const;
	bool MandatoryFieldsFilled()const;
	bool AreSetsValid()const;
	void SetEnableSetList(bool blEnabled);
	Ui::AddEditMatchDialogClass ui;
	std::unique_ptr<Calendar> m_upCalendar{ nullptr };
	DialogMode m_DialogMode;
	QString m_sStatu{ "" }, m_sStage{""};
	QString m_sWL{};
	unsigned m_uiAddedSet{}, m_uiMinSet{}, m_uiMaxSet{};
	Tournament m_RootTournament;
	QDate m_MatchDate{};
private slots:
	void on_AddSetButton_clicked();
	void on_RemoveSetButton_clicked();
	void on_DateButton_clicked();
	void on_SaveButton_clicked();
	void on_radioButton_Win_clicked();
	void on_radioButton_Lose_clicked();
	void on_comboBox_Statu_currentTextChanged(const QString& statu);
	void on_comboBox_Stage_currentTextChanged(const QString& stage);
public slots:
	void SetMatchDate(const QDate& date);
};
