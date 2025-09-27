// Project Headers
#include "DBItemWithPicture.h"

// Qt Headers
#include <QFile>
#include <QString>

DBItemWithPicture::DBItemWithPicture(unsigned uiID, const std::string& sDBTable, const std::string& m_sDBColumns, const std::string& sPictureRootPath, const std::string& sPictureFileName) 
	: 
	DBItem(uiID, sDBTable, m_sDBColumns), 
	m_sPictureRootPath{sPictureRootPath},
	m_sPictureFileName{sPictureFileName}
{

}
std::string DBItemWithPicture::GetPictureFileName()const
{
	return m_sPictureFileName;
}
bool DBItemWithPicture::DeleteFromDB()const
{
	DeleteCurrentPicture();
	return DBItem::DeleteFromDB();
}
void DBItemWithPicture::LoadPictureFileName()
{
	m_sPictureFileName = m_spIDatabase->RetrieveValue(m_sDBTable, "PictureFileName", "ID", std::to_string(m_uiID));
}
std::string DBItemWithPicture::GetPictureRootPath()const
{
	return m_sPictureRootPath;
}
std::string DBItemWithPicture::GetFullPicturePath()const
{
	const std::string sPictureFileName = (m_sPictureFileName == "") ? "default.png" : m_sPictureFileName;
	return m_sPictureRootPath + m_sPictureFileName;
}
void DBItemWithPicture::DeleteCurrentPicture()const
{
	const std::string sCurrentPictureFileName = m_spIDatabase->RetrieveValue(m_sDBTable, "PictureFileName", "ID", std::to_string(m_uiID));
	if (sCurrentPictureFileName != m_sPictureFileName)
	{
		const QString sFullCurrentPicturePath = QString::fromStdString(GetFullPicturePath());
		if (QFile::exists(sFullCurrentPicturePath))
		{
			QFile::remove(sFullCurrentPicturePath);
		}
	}
}