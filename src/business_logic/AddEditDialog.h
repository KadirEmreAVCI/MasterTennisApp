#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

enum class DialogMode {
	eAddDialog,
	eEditDialog
};
class AddEditDialog {
protected:
	AddEditDialog();
	virtual ~AddEditDialog() = default;
	void SetDialogMode(DialogMode);
	virtual void InitDialog() = 0;
	virtual void FillDialog() = 0;
	virtual void ClearDialog() = 0;
	virtual bool IsMandatoryFieldsFilled()const = 0;
	virtual bool IsThereAnyUnsavedInfo()const = 0;
	bool SaveImage()const;
	void ClearImage();
	void OnBrowseButtonClicked(const QString& sSourceDir, const QString& sRootDestDir);
	DialogMode m_DialogMode;
	QString m_sFullDestDir{};
	QString m_sFullSourceDir{};
	QString m_sImageFileName{};
};

#endif