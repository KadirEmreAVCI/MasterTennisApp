#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include "ui_PictureWidget.h"
class PictureWidget : public QWidget, public Ui::PictureWidgetClass
{
	Q_OBJECT

public:
	PictureWidget(QWidget *parent = nullptr);
	~PictureWidget();
    void InitWidget(const QString& sImageRootDestDir);
    void ClearWidget();
    void FillWidget(const QString& sImageFileName);
    QString GetImageFileName()const;
    bool SaveImage()const;
private:
    QString m_sImageRootDestDir;
    QString m_sFullDestDir{};
	QString m_sFullSourceDir{};
    void FindFullDestDir(const QString& sRootDestDir);
private slots:
	void on_BrowseButton_clicked();
	void on_DefaultPPButton_clicked();
};

#endif