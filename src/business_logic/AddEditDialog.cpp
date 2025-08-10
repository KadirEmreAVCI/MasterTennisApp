#include <QFileDialog>
#include "AddEditDialog.h"
AddEditDialog::AddEditDialog()
{

}
void AddEditDialog::SetDialogMode(DialogMode mode)
{
	m_DialogMode = mode;
}
bool AddEditDialog::SaveImage()const
{
	if (QFile::exists(m_sFullDestDir))
	{
		QFile::remove(m_sFullDestDir);
	}
	return QFile::copy(m_sFullSourceDir, m_sFullDestDir);
}
void AddEditDialog::ClearImage()
{
	m_sFullSourceDir = "";
	m_sFullDestDir = "";
	m_sImageFileName = "";
}
void AddEditDialog::OnBrowseButtonClicked(const QString& sFullSourceDir, const QString& sRootDestDir)
{
	m_sFullSourceDir = sFullSourceDir;
	if (m_sImageFileName = QFileInfo(m_sFullSourceDir).fileName(); m_sImageFileName != "")
	{
		QDir destDir(sRootDestDir);
		if (!destDir.exists())
		{
			destDir.mkpath(sRootDestDir);
		}
		m_sFullDestDir = destDir.filePath(m_sImageFileName);
	}
}