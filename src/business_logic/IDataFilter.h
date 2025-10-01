#ifndef IDATAFILTER_H
#define IDATAFILTER_H

//Standard Headers
#include <vector>
#include <string>

template <typename T>
class IDataFilter {
public:
    virtual ~IDataFilter() = default;
    virtual std::vector<T> ApplyFilter(const std::vector<T>&, const std::string& sFilteringWord) = 0;
};

#endif