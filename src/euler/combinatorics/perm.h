#ifndef PERM_H
#define PERM_H

#include <vector>
#include <algorithm>

namespace euler {
    class Perm
    {
        public:
            Perm();
            template<typename T>
            std::vector<T> make(T arr);
            template<typename It>
            bool next(It begin, It end);
    };
}
#endif // COMB_H
