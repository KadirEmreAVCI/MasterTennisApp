#include "SetScoreWidget.h"

SetScoreWidget::SetScoreWidget(unsigned uiSetIdx, const Set& set, QWidget *parent): QWidget(parent)
{
	ui.setupUi(this);
	ui.label_Set->clear();
	QString sSetIdx = QString::fromStdString(std::to_string(uiSetIdx + 1));
	ui.label_Set->setText("SET " + sSetIdx);
	SetSet(set);
	EnableTiebreak(false);
}
SetScoreWidget::~SetScoreWidget()
{

}
void SetScoreWidget::SetEnabled(bool blEnabled)
{
	ui.spinBox_HomeScore->setEnabled(blEnabled);
	ui.spinBox_AwayScore->setEnabled(blEnabled);
	ui.spinBox_HomeTiebreakScore->setEnabled(false);
	ui.spinBox_AwayTiebreakScore->setEnabled(false);
	ui.ClearButton->setEnabled(blEnabled);
	ui.checkBox_Tiebreak->setEnabled(blEnabled);
}
void SetScoreWidget::SetSet(const Set& set)
{
	SetMajorScore(set.GetMajorScore());
	SetTBScore(set.GetTBScore());
}
Set SetScoreWidget::GetSet()const
{
	return Set(Score(ui.spinBox_HomeScore->value(), ui.spinBox_AwayScore->value()), Score(ui.spinBox_HomeTiebreakScore->value(), ui.spinBox_AwayTiebreakScore->value()));
}
void SetScoreWidget::EnableTiebreak(bool blTiebreak)
{
	if (false == blTiebreak)
	{
		SetTBScore(Score(0,0));
	}
	ui.spinBox_AwayTiebreakScore->setEnabled(blTiebreak);
	ui.spinBox_HomeTiebreakScore->setEnabled(blTiebreak);
}
void SetScoreWidget::SetMajorScore(const Score& score)
{
	ui.spinBox_HomeScore->setValue(score.GetHomeScore());
	ui.spinBox_AwayScore->setValue(score.GetAwayScore());
}
void SetScoreWidget::SetTBScore(const Score& score)
{
	ui.spinBox_HomeTiebreakScore->setValue(score.GetHomeScore());
	ui.spinBox_AwayTiebreakScore->setValue(score.GetAwayScore());
}
void SetScoreWidget::on_ClearButton_clicked()
{
	ui.checkBox_Tiebreak->setChecked(false);
	SetSet(Set(Score(0,0), Score(0,0)));
}
void SetScoreWidget::on_checkBox_Tiebreak_checkStateChanged(Qt::CheckState state)
{
	if (state == Qt::Checked)
	{
		EnableTiebreak(true);
	}
	else
	{
		EnableTiebreak(false);
	}
}
