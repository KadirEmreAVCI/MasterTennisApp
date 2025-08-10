#pragma once
#include <QWidget>
#include "ui_SetScoreWidget.h"
#include "Set.h"
class SetScoreWidget : public QWidget
{
	Q_OBJECT

public:
	SetScoreWidget(unsigned uiSetIdx, const Set& set, QWidget *parent = nullptr);
	~SetScoreWidget();
	void SetEnabled(bool blEnabled);
	void SetSet(const Set& set);
	Set GetSet()const;
private:
	void EnableTiebreak(bool blTiebreak);
	void SetMajorScore(const Score& MajorScore);
	void SetTBScore(const Score& TiebreakScore);
	Ui::SetScoreWidgetClass ui;
private slots:
	void on_ClearButton_clicked();
	void on_checkBox_Tiebreak_checkStateChanged(Qt::CheckState state);
};
