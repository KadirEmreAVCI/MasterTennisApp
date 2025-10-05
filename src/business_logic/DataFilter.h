#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <QTableWidget>
#include "IDataFilter.h"

template <typename T, typename FilterFunc>
class DataFilter : public IDataFilter<T>{
public:
    explicit DataFilter(bool blSearchForExactMatch) : m_blSearchForExactMatch{blSearchForExactMatch}{}
    std::vector<T> ApplyFilter(const std::vector<T>& vecUnfilteredItems, const std::string& sFilteringWord)
    {
        std::vector<T> vecFilteredItems;
        if(sFilteringWord != "")
        {
            const auto sFilteringWordLower = ToLowerCase(sFilteringWord);
            std::copy_if(vecUnfilteredItems.cbegin(), vecUnfilteredItems.cend(), std::back_inserter(vecFilteredItems), [this, &sFilteringWordLower](const T& item){
                const auto sFilteredDataLower = ToLowerCase(GetFilteredData(item));
                if(sFilteredDataLower.find(sFilteringWordLower) != std::string::npos)
                {
                    if(m_blSearchForExactMatch)
                    {
                        return sFilteredDataLower == sFilteringWordLower;
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    return false;
                }
            });
        }
        else
        {
            vecFilteredItems = vecUnfilteredItems;
        }
        return vecFilteredItems;
    }
private:  
    std::string GetFilteredData(const T& item)const
    {
        return m_FilterFunc(item);
    }
    FilterFunc m_FilterFunc;
    bool m_blSearchForExactMatch = false;
protected:
    static std::string ToLowerCase(const std::string& sWord)
    {
        std::string sResult = sWord;
        std::transform(sResult.begin(), sResult.end(), sResult.begin(), [](unsigned char c){
            return std::tolower(c);
        });
        return sResult;
    }
};

#endif  // DATAFILTER_H