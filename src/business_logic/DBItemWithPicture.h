#ifndef DBITEMWITHPICTURE_H
#define DBITEMWITHPICTURE_H

// Project Headers
#include "DBItem.h"

// Standard Headers
#include <string>

class DBItemWithPicture : public DBItem{
public:
    std::string GetPictureRootPath()const;
    std::string GetFullPicturePath()const;
    std::string GetPictureFileName()const;
    bool SaveImage(const std::string& sSourcePictureFullPath)const;
protected: 
    DBItemWithPicture(unsigned uiID, const std::string& sDBTable, const std::string& m_sDBColumns, const std::string& sPictureRootPath, const std::string& sPictureFileName);
    ~DBItemWithPicture() = default;
    virtual bool DeleteFromDB()const override;
    void LoadPictureFileName();
    void DeletePreviousPicture()const;
private:
    std::string m_sPictureFileName{};
    std::string m_sPictureRootPath{};
};

#endif // DBITEMWITHPICTURE_H