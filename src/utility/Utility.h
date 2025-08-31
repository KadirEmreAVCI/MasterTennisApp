#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <QString>

class QLabel;
class QPushButton;
class QComboBox;
class QTableWidget;
class QWidget;

namespace utility{
    // Helper functions for QLabel
    void InitLabelWithPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale = 1.0f);
    
    // Helper functions for QPushButton
    QPushButton* CreateButtonWithPicture(const std::string& sPicAddress, float fScale = 1.0f);
    void InitButtonWithPicture(QPushButton* pButton, const std::string& sPicAddress, float fScale = 1.0f);
    
    // Helper functions for QComboBox
    void InitComboBox(QComboBox* pComboBox, const QString& sVal = "");
    void SetComboBoxAlternatives(QComboBox* pComboBox, const std::vector<std::string>& vecAlternatives, bool blStartWithEmptyAlternative = true);
    
    // Helper functions for QTableWidget
    void PlaceValue2TableCell(QTableWidget* table, QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx);
    QLabel* PlaceLabel2TableCellWithImage(QTableWidget* pTableWidget, const std::string& sPicAddr, float fScale, unsigned uiRowIdx, unsigned uiColumnIdx);
    QPushButton* PlaceButton2TableCell(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sButtonText);
    QPushButton* PlaceButton2TableCellWithImage(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sImageAddr, float fScale, bool blEnabled);
    unsigned FindIndexOfSignalingItem(QTableWidget*, QObject*);

    // Common helper functions
    std::string Serialize(const std::vector<std::string>& vecDeserialized);
    std::vector<std::string> Deserialize(const std::string& sSerialized);
};

#endif