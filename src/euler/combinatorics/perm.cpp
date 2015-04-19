#include "Perm.h"

namespace euler {
    Perm::Perm(){}

    template<typename T>
    std::vector<T> make(T arr)
    {
        std::vector<T> sols;
        return sols;
    }
    template std::vector<std::vector<int>> make(std::vector<int> arr);
    template std::vector<std::string> make(std::string arr);


    template<typename It>
    bool Perm::next(It begin, It end)
    {
        if (begin == end) {
            return false;
        }

        It i = begin;
        ++i;
        if (i == end) {
            return false;
        }

        i = end;
        --i;

        while (true) {
            It j = i;
            --i;

            if (*i < *j) {
                It k = end;
                while (!(*i < *--k));

                std::iter_swap(i, k);
                std::reverse(j, end);
                return true;
            }

            if (i == begin) {
                std::reverse(begin, end);
                return false;
            }
        }
    }
    template bool Perm::next(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    template bool Perm::next(std::string::iterator begin, std::string::iterator end);

}
