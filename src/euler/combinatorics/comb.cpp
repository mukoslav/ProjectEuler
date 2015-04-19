#include "comb.h"

namespace euler {
    Comb::Comb(){}

    std::vector<std::vector<int>> Comb::make(std::vector<int> arr, int k)
    {
        this->elements = arr;
        this->n = arr.size();
        this->k = k;

        for (int i = 0; i<this->n; ++i) {
            std::vector<int> c;
            make_recursion(c, i, 0);
        }

        return solutions;
    }

    void Comb::make_recursion(std::vector<int> c, int i, int d)
    {
        c.push_back(elements[i]);

        if (d == (this->k - 1)) {
            solutions.push_back(c);
            return;
        }

        ++d;
        for(int j = i + 1; j<this->n; ++j) {
            make_recursion(c, j, d);
        }
    }
}
