#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <stdexcept>
#include <QString>

class QLabel;
class QPushButton;
class QComboBox;
class QTableWidget;
class QWidget;
class QListWidget;

namespace utility{
    // Helper functions for QLabel
    QLabel* CreateLabelWithPicture(const std::string& sPicAddress, float fScale = 1.0f);
    void InitLabelWithPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale = 1.0f);
    
    // Helper functions for QPushButton
    QPushButton* CreateButtonWithPicture(const std::string& sPicAddress, float fScale = 1.0f);
    void InitButtonWithPicture(QPushButton* pButton, const std::string& sPicAddress, float fScale = 1.0f);
    
    // Helper functions for QComboBox
    void InitComboBox(QComboBox* pComboBox, const QString& sVal = "");
    void SetComboBoxAlternatives(QComboBox* pComboBox, const std::vector<std::string>& vecAlternatives, bool blStartWithEmptyAlternative = true);
    void DisableFirstItemOfComboBox(QComboBox* pComboBox);

    // Helper functions for QTableWidget
    void PlaceValue2TableCell(QTableWidget* table, QString sVal, unsigned uiRowIdx, unsigned uiColumnIdx);
    QLabel* PlaceLabel2TableCellWithImage(QTableWidget* pTableWidget, const std::string& sPicAddr, float fScale, unsigned uiRowIdx, unsigned uiColumnIdx);
    QPushButton* PlaceButton2TableCell(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sButtonText);
    QPushButton* PlaceButton2TableCellWithImage(QTableWidget* pTableWidget, unsigned uiRowIdx, unsigned uiColumnIdx, const std::string& sImageAddr, float fScale, bool blEnabled);
    unsigned FindIndexOfSignalingItem(QTableWidget*, QObject*);
    template<typename T>
    const T& GetSignalingItem(const std::vector<T>& vecItems, QTableWidget* pTableWidget, QObject* pSender)
    {
        unsigned uiIdx = FindIndexOfSignalingItem(pTableWidget, pSender);
        if (uiIdx < vecItems.size())
        {
            return vecItems[uiIdx];
        }
        throw std::out_of_range("Index out of range in GetSignalingItem");
    }

    // Helper functions for QListWidget
    QWidget* InsertItem2ListWidget(QListWidget*, QWidget*, float fScale = 1.0f);
    void DeleteItemFromListWidget(QListWidget*, unsigned uiItemIdx);
    void ClearListWidget(QListWidget*);

    // Common helper functions
    std::string Serialize(const std::vector<std::string>& vecDeserialized);
    std::vector<std::string> Deserialize(const std::string& sSerialized);
};

#endif