#include <Sort.h>
#include <string>
#include <algorithm>

struct less_than_str
{
    inline bool operator() (IString& struct1, IString& struct2)
    {
        return (std::tolower(struct1.GetStr()[0]) > std::tolower(struct2.GetStr()[0]));
    }
};

void ReverseCaseInsensitiveSort(std::vector<IString>& vec) {
    std::sort(vec.begin(), vec.end(), less_than_str());
}