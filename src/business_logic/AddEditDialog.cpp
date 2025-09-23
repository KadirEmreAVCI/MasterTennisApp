#include <QFileDialog>
#include <iostream>
#include "AddEditDialog.h"
#include "Organization.h"
#include "Profile.h"
#include "Tournament.h"
#include "Match.h"
template <typename T>
void AddEditDialog<T>::PrepareDialog(DialogMode mode, const T& item)
{
	m_EditedItem = item;
	SetDialogMode(mode);
	InitDialog();
	if(m_DialogMode == DialogMode::eEditDialog)
	{
		FillDialog();
	}
}
template <typename T>
void AddEditDialog<T>::SetDialogMode(DialogMode mode)
{
	m_DialogMode = mode;
}
template <typename T>
bool AddEditDialog<T>::SaveImage()const
{
	if (QFile::exists(m_sFullDestDir))
	{
		QFile::remove(m_sFullDestDir);
	}
	return QFile::copy(m_sFullSourceDir, m_sFullDestDir);
} 
template <typename T>
void AddEditDialog<T>::ClearImage()
{
	m_sFullSourceDir = "";
	m_sFullDestDir = "";
	m_sImageFileName = "";
}
template <typename T>
void AddEditDialog<T>::OnBrowseButtonClicked(const QString& sFullSourceDir, const QString& sRootDestDir)
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
template class AddEditDialog<Organization>;
template class AddEditDialog<Profile>;
template class AddEditDialog<Tournament>;
template class AddEditDialog<Match>;