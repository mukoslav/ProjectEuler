#ifndef COMB_H
#define COMB_H

#include <vector>

namespace euler {
    class Comb
    {
        public:
            Comb();
            std::vector<std::vector<int>> make(std::vector<int> arr, int k);
        protected:
            int n, k;
            std::vector<int> elements;
            std::vector<std::vector<int>> solutions;
            void make_recursion(std::vector<int> comb, int i, int d);
        private:
    };
}
#endif // COMB_H
