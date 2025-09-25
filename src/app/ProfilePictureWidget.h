#ifndef PROFILEPICTUREWIDGET_H
#define PROFILEPICTUREWIDGET_H

#include <QWidget>
#include "ui_ProfilePictureWidget.h"
class ProfilePictureWidget : public QWidget, public Ui::ProfilePictureWidgetClass
{
	Q_OBJECT

public:
	ProfilePictureWidget(QWidget *parent = nullptr);
	~ProfilePictureWidget();
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