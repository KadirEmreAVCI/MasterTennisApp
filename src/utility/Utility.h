#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <QString>

class QLabel;
class QPushButton;
class QComboBox;
class QTableWidget;
namespace utility{
    void InitPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale = 1.0f);
    QPushButton* CreateButtonWithPicture(const std::string& sPicAddress, float fScale = 1.0f);
    void InitButtonWithPicture(QPushButton* pButton, const std::string& sPicAddress, float fScale = 1.0f);
    void InitComboBox(QComboBox* pComboBox, const QString& sVal = "");
    void SetComboBoxAlternatives(QComboBox* pComboBox, const std::vector<std::string>& vecAlternatives, bool blStartWithEmptyAlternative = true);
    void InsertValue2TableCell(QTableWidget* table, QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx);
    QLabel* InsertPic2TableCell(QTableWidget* pTableWidget, const std::string& sPicAddr, float fScale, unsigned uiRowIdx, unsigned uiColumnIdx);
    QPushButton* PlaceButton2TableCell(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sButtonText);
    QPushButton* PlaceButton2TableCellWithImage(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sImageAddr, float fScale, bool blEnabled);
};

#endif