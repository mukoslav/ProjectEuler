#ifndef COMMON_H
#define COMMON_H

#include <cmath>

namespace euler {

    /**
     * Calculates the binomial coefficient, choose{n, k}, i.e., the number of
     * distinct sets of k elements that can be sampled with replacement from a
     * population of n elements.
     * (T -> unsigned long long, long long, int)
     *
     * @param T n
     * @param T k
     * @return T
     */
    template<typename T>
    T binomial(T x, T result);

    /**
     * Check if number is pandigital.
     * Pandigital number is an integer that in a given base has among
     * it's significant digits each digit used in the base at least once.
     *
     * @param unsigned long long n
     * @return bool
     */
    bool isPandigital(unsigned long long n);

    /**
     * Find the greatest common divisor of two integers
     *
     * @param long long a
     * @param long long b
     * @return long long
     */
    long long gcd(long long a, long long b);

    /**
     * Find of the greatest common divisor of two integers
     *
     * @param long long a
     * @param long long b
     * @return long long
     */
    long long lcm(long long a, long long b);

    /**
     * Recursive function to find x!.
     * (T -> unsigned long long, long long, int)
     *
     * @param T x
     * @param T
     * @return T
     */
    template<typename T>
    T factorial(T n, T k = 1) ;

    /**
     * As function name says.
     *
     * @todo slow, make better one.
     * @param int
     * @return int
     */
    int countDistinctFactors(int n);

    /**
     * Check if numbers are permutation of one another.
     *
     * @param int
     * @param int
     * @return bool
     */
    bool isPermutation(int m, int n);

    /**
     * Mod pow
     * (T -> unsigned long long, long long, int)
     *
     * @param T
     * @param T
     * @param T
     * @return T
     */
    template <typename T>
    T modpow(T base, T exp, T mod);

    /**
     * Count digits in number
     *
     * @param unsigned long
     * @return int
     */
    int numberOfDigits(unsigned long i);

    /**
     * Mod inv
     *
     * @param T
     * @param T
     * @return T
     */
    template <typename T>
    T modinv(T a, T b);
}
#endif
