#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>
#include <QString>

class QLabel;
class QPushButton;
class QComboBox;

namespace utility{
    void InitPicture(QLabel* pPicLabel, std::string sPicAddress, float fScale = 1.0f);
    void InitButtonWithPicture(QPushButton* pButton, std::string sPicAddress, float fScale = 1.0f);
    void InitComboBox(QComboBox* pComboBox, const QString& sVal = "");
    void SetComboBoxAlternatives(QComboBox* pComboBox, const std::vector<std::string>& vecAlternatives, bool blStartWithEmptyAlternative = true);
};

#endif