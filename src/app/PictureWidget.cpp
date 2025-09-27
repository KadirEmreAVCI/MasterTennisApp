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
    m_sSourcePictureFullPath = "";
}
void PictureWidget::FillWidget(DBItemWithPicture* pDBItemWithPicture)
{
	m_pDBItemWithPicture = pDBItemWithPicture;
    lineEdit_PictureFileName->setText(QString::fromStdString(m_pDBItemWithPicture->GetPictureFileName()));
}
QString PictureWidget::GetSourcePictureFullPath()const
{
    return m_sSourcePictureFullPath;
}
void PictureWidget::on_BrowseButton_clicked()
{
	const QString sSourcePictureFullPath = QFileDialog::getOpenFileName(this, "Select the image.", "Images(.png, .jpg, .jpeg)");
	if (QFileInfo(sSourcePictureFullPath).fileName() != "")
	{
		m_sSourcePictureFullPath = sSourcePictureFullPath;
		lineEdit_PictureFileName->setText(QFileInfo(m_sSourcePictureFullPath).fileName());
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
		}
	}
}