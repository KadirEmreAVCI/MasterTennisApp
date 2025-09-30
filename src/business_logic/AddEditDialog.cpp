#include <QFileDialog>
#include <iostream>
#include "AddEditDialog.h"
#include "Organization.h"
#include "Profile.h"
#include "Tournament.h"
#include "Match.h"
template <typename T>
AddEditDialog<T>::AddEditDialog(QDialog* parent) : m_pParent{parent}
{

}
template <typename T>
void AddEditDialog<T>::OpenAddDialog()
{
	m_pParent->setModal(true);
	PrepareDialog(DialogMode::eAddDialog);
	m_pParent->exec();
}
template <typename T>
void AddEditDialog<T>::OpenEditDialog(const T& item)
{
	m_pParent->setModal(true);
	PrepareDialog(DialogMode::eEditDialog, item);
	m_pParent->exec();
}
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
template class AddEditDialog<Organization>;
template class AddEditDialog<Profile>;
template class AddEditDialog<Tournament>;
template class AddEditDialog<Match>;