// Project Headers
#include "DBItemWithPicture.h"

// Qt Headers
#include <QFile>
#include <QString>
#include <QFileInfo>

DBItemWithPicture::DBItemWithPicture(unsigned uiID, const std::string& sDBTable, const std::string& m_sDBColumns, const std::string& sPictureRootPath, const std::string& sPictureFileName) 
	: 
	DBItem(uiID, sDBTable, m_sDBColumns), 
	m_sPictureFileName{sPictureFileName},
	m_sPictureRootPath{sPictureRootPath}
{

}
const std::string& DBItemWithPicture::GetPictureFileName()const
{
	return m_sPictureFileName;
}
bool DBItemWithPicture::DeleteFromDB()const
{
	DeletePreviousPicture();
	return DBItem::DeleteFromDB();
}
void DBItemWithPicture::LoadPictureFileName()
{
	m_sPictureFileName = m_spIDatabase->RetrieveValue(m_sDBTable, "PictureFileName", "ID", std::to_string(m_uiID));
}
std::string DBItemWithPicture::GetFullPicturePath()const
{
	const std::string sPictureFileName = (m_sPictureFileName == "") ? "default.png" : m_sPictureFileName;
	return m_sPictureRootPath + sPictureFileName;
}
void DBItemWithPicture::DeletePreviousPicture()const
{
	const std::string sPreviousPictureFileName = m_spIDatabase->RetrieveValue(m_sDBTable, "PictureFileName", "ID", std::to_string(m_uiID));
	const QString sPreviousPictureFullPath = QString::fromStdString(m_sPictureRootPath + sPreviousPictureFileName);
	if (QFile::exists(sPreviousPictureFullPath))
	{
		QFile::remove(sPreviousPictureFullPath);
	}
}
bool DBItemWithPicture::IsPictureChanged() const
{
	return m_sPictureFileName != m_spIDatabase->RetrieveValue(m_sDBTable, "PictureFileName", "ID", std::to_string(m_uiID));
}
bool DBItemWithPicture::SaveImage(const std::string& sSourcePictureFullPath)const
{
	QString sPictureFileName = QFileInfo(QString::fromStdString(sSourcePictureFullPath)).fileName();
	QString sDestPictureFullPath = QString::fromStdString(m_sPictureRootPath) + sPictureFileName;
	if (QFile::exists(sDestPictureFullPath))
	{
		QFile::remove(sDestPictureFullPath);
	}
	return QFile::copy(QString::fromStdString(sSourcePictureFullPath), sDestPictureFullPath);
} 