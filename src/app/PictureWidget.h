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
    void FillWidget(DBItemWithPicture* pDBItemWithPicture);
    QString GetSourcePictureFullPath()const;
private:
	QString m_sSourcePictureFullPath{};
    DBItemWithPicture* m_pDBItemWithPicture{nullptr};
private slots:
	void on_BrowseButton_clicked();
	void on_DefaultPPButton_clicked();
};

#endif