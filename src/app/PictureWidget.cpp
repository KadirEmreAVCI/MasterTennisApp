#include "PictureWidget.h"
#include "utility.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <iostream>

PictureWidget::PictureWidget(QWidget *parent): QWidget(parent)
{
	setupUi(this);
    utility::InitButtonWithPicture(DefaultPPButton, ":images/CrossButton.png", 0.35f);
}
PictureWidget::~PictureWidget()
{

}
void PictureWidget::InitWidget(const QString& sImageRootDestDir)
{
    ClearWidget();
    m_sImageRootDestDir = sImageRootDestDir;
}
void PictureWidget::ClearWidget()
{
    lineEdit_ImageFileName->setText("");
    m_sFullDestDir = "";
    m_sFullSourceDir = "";
}
void PictureWidget::FillWidget(const QString& sImageFileName)
{
    lineEdit_ImageFileName->setText(sImageFileName);
}
QString PictureWidget::GetImageFileName()const
{
    return QFileInfo(m_sFullDestDir).fileName();
}
void PictureWidget::on_BrowseButton_clicked()
{
	const QString sFullSourceDir = QFileDialog::getOpenFileName(this, "Select the image.", "Images(.png, .jpg, .jpeg)");
	if (QFileInfo(sFullSourceDir).fileName() != "")
	{
		m_sFullSourceDir = sFullSourceDir;
        FindFullDestDir(m_sImageRootDestDir);
		lineEdit_ImageFileName->setText(m_sFullSourceDir);
	}
}
void PictureWidget::on_DefaultPPButton_clicked()
{
	if (lineEdit_ImageFileName->text() != "")
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Cancellation", "Are you sure you want to remove the organization picture?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			ClearWidget();
			lineEdit_ImageFileName->setText("");
		}
	}
}
bool PictureWidget::SaveImage()const
{
	if (QFile::exists(m_sFullDestDir))
	{
		QFile::remove(m_sFullDestDir);
	}
	return QFile::copy(m_sFullSourceDir, m_sFullDestDir);
} 
void PictureWidget::FindFullDestDir(const QString& sRootDestDir)
{
    lineEdit_ImageFileName->setText(QFileInfo(m_sFullSourceDir).fileName());
	if (lineEdit_ImageFileName->text() != "")
	{
		QDir destDir(sRootDestDir);
		if (!destDir.exists())
		{
			destDir.mkpath(sRootDestDir);
		}
		m_sFullDestDir = destDir.filePath(lineEdit_ImageFileName->text());
	}
}