#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

enum class DialogMode {
	eAddDialog,
	eEditDialog
};
template <typename T>
class AddEditDialog {
public:
	void PrepareDialog(DialogMode mode, const T& item = T{});
protected:
	AddEditDialog() = default;
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
	DialogMode m_DialogMode{DialogMode::eAddDialog};
	QString m_sFullDestDir{};
	QString m_sFullSourceDir{};
	QString m_sImageFileName{};
	T m_EditedItem{};
};

#endif