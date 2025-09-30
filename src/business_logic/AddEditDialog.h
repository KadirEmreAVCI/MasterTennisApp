#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

class QDialog;

enum class DialogMode {
	eAddDialog,
	eEditDialog
};
template <typename T>
class AddEditDialog {
public:
	void OpenAddDialog();
	void OpenEditDialog(const T&);
protected:
	explicit AddEditDialog(QDialog* parent);
	virtual ~AddEditDialog() = default;
	void PrepareDialog(DialogMode mode, const T& item = T{});
	void SetDialogMode(DialogMode);
	virtual void InitDialog() = 0;
	virtual void FillDialog() = 0;
	virtual void ClearDialog() = 0;
	virtual bool IsMandatoryFieldsFilled()const = 0;
	virtual bool IsThereAnyUnsavedInfo()const = 0;
	DialogMode m_DialogMode{DialogMode::eAddDialog};
	T m_EditedItem{};
	QDialog* m_pParent{nullptr};
};

#endif