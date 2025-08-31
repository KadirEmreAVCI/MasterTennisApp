#ifndef ADDEDITMATCHDIALOG_H
#define ADDEDITMATCHDIALOG_H

#include <QDialog>
#include "ui_AddEditMatchDialog.h"
#include "AddEditDialog.h"
#include "Tournament.h"
#include "Match.h"
#include "Set.h"
class Calendar;
class AddEditMatchDialog : public QDialog, public AddEditDialog
{
	Q_OBJECT

public:
	AddEditMatchDialog(QWidget *parent = nullptr);
	~AddEditMatchDialog();
	void PrepareDialog(DialogMode, const Tournament& t, const Match& m = Match{});
private:
	virtual void InitDialog()override;
	virtual void FillDialog()override;
	virtual void ClearDialog()override;
	virtual bool IsMandatoryFieldsFilled()const override;
	virtual bool IsThereAnyUnsavedInfo()const override;
	void FillSets();
	void InitSetList(Set s, bool blEnabled = true);
	void InsertSet(size_t idx, Set set);
	void RemoveSet(size_t idx);
	void SetEnableOpponent(bool);
	std::vector<Set> GetSets()const;
	void SetEnableSetList(bool blEnabled);
	Ui::AddEditMatchDialogClass ui;
	std::unique_ptr<Calendar> m_upCalendar{ nullptr };
	std::vector<std::string> m_vecStatuAlternatives = {"U", "WO", "BYE"};
	QString m_sWL{};
	unsigned m_uiMinSet{}, m_uiMaxSet{};
	Tournament m_RootTournament;
	Match m_EditedMatch{};
	QDate m_MatchDate{};
private slots:
	void on_AddSetButton_clicked();
	void on_RemoveSetButton_clicked();
	void on_DateButton_clicked();
	void on_SaveButton_clicked();
	void on_ClearButton_clicked();
	void on_radioButton_Win_clicked();
	void on_radioButton_Lose_clicked();
	void on_comboBox_Statu_currentTextChanged(const QString& statu);
public slots:
	void SetMatchDate(const QDate& date);
};

#endif