#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

// Project Headers
#include "DBItemWithPicture.h"

#include <QWidget>
#include "ui_PictureWidget.h"
class PictureWidget : public QWidget, public Ui::PictureWidgetClass
{
	Q_OBJECT

public:
	PictureWidget(QWidget *parent = nullptr);
	~PictureWidget();
    void InitWidget();
    void ClearWidget();
    void FillWidget(const DBItemWithPicture* pDBItemWithPicture);
    QString GetSourcePictureFullPath()const;
	bool IsPictureChanged() const;
private:
	bool m_bIsPictureChanged{ false };
private slots:
	void on_BrowseButton_clicked();
	void on_DefaultPictureButton_clicked();
};

#endif