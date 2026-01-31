#include "PictureWidget.h"
#include "utility.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <iostream>

PictureWidget::PictureWidget(QWidget *parent): QWidget(parent)
{
	setupUi(this);
    utility::InitButtonWithPicture(DefaultPictureButton, ":images/CrossButton.png", 0.35f);
}
PictureWidget::~PictureWidget()
{

}
void PictureWidget::InitWidget()
{
    ClearWidget();
}
void PictureWidget::ClearWidget()
{
    lineEdit_PictureFileName->setText("");
}
void PictureWidget::FillWidget(const DBItemWithPicture* pDBItemWithPicture)
{
    m_bIsPictureChanged = false;
	lineEdit_PictureFileName->setText(QString::fromStdString(pDBItemWithPicture->GetFullPicturePath()));
}
QString PictureWidget::GetSourcePictureFullPath()const
{
    return lineEdit_PictureFileName->text();
}
bool PictureWidget::IsPictureChanged() const
{
	return m_bIsPictureChanged;
}
void PictureWidget::on_BrowseButton_clicked()
{
	const QString sSourcePictureFullPath = QFileDialog::getOpenFileName(this, "Select the image.", "Images(.png, .jpg, .jpeg)");
	if (QFileInfo(sSourcePictureFullPath).fileName() != "")
	{
		lineEdit_PictureFileName->setText(QFileInfo(sSourcePictureFullPath).filePath());
		m_bIsPictureChanged = true;
	}
}
void PictureWidget::on_DefaultPictureButton_clicked()
{
	if (lineEdit_PictureFileName->text() != "")
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Cancellation", "Are you sure you want to remove the organization picture?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			ClearWidget();
			m_bIsPictureChanged = true;
		}
	}
}