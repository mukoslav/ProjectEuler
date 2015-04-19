#include "common.h"

namespace euler {

    long long gcd(long long a, long long b)
    {
        long long t;

        if (a < 0) {
            a = -a;
        }

        if (!b) {
            return a;
        }

        if (b < 0) {
            b = -b;
        }

        if (!a) {
            return b;
        }
        t = 0;

        while (!((a | b) & 1)) {
            a >>= 1;
            b >>= 1;
            ++t;
        }

        while (!(a & 1)) {
            a >>= 1;
        }

        while (!( b & 1 )) {
            b >>= 1;
        }

        while (a != b) {
            if (a > b) {
                a -= b;
                do {
                    a >>= 1;
                } while (!(a & 1));
            } else {
                b -= a;
                do {
                    b >>= 1;
                } while (!(b & 1));
            }
        }
        return a << t;
    }

    long long lcm(long long a, long long b)
    {
        return (a*b)/gcd(a,b);
    }

    bool isPandigital(unsigned long long n)
    {
       unsigned long long digits = 0;
       unsigned long long cnt = 0;
       unsigned long long tmp;

        for (;n > 0; n /= 10, ++cnt) {
            tmp = digits;
            digits == (digits |= 1 << (n - ((n / 10) * 10) - 1));
            if (tmp == digits) {
                return false;
            }
        }

        return true;
    }

    template<typename T>
    T binomial(T n, T k)
    {
        T i;
        T b;
        if (0 == k || n == k) {
            return 1;
        }
        if (k > n) {
            return 0;
        }
        if (k > (n - k)) {
            k = n - k;
        }
        if (1 == k) {
            return n;
        }
        b = 1;
        for (i = 1; i <= k; ++i) {
            b *= (n - (k - i));
            if (b < 0) {
                return -1; /* Overflow */
            }

            b /= i;
        }
        return b;
    }
    template unsigned long long binomial(unsigned long long n, unsigned long long k);
    template long long binomial(long long n, long long k);
    template int binomial(int n, int k);

    template<typename T>
    T factorial(T x, T result)
    {
        if (x == 1) {
            return result;
        } else {
            return factorial(x - 1, x * result);
        }
    }
    template unsigned long long factorial(unsigned long long x, unsigned long long result);
    template long long factorial(long long x, long long result);
    template int factorial(int x, int result);

    int countDistinctFactors(int n)
    {   int c = 0;
        for (int p = 2; n!=1; ++p) {
            if (n % p == 0) {
                c++;
                while(n % p == 0) {
                    n /= p;
                }
            }
        }
        return c;
    }

    bool isPermutation(int m, int n)
    {
        int arr[10] = {};

        int temp = n;
        while (temp > 0) {
            arr[temp % 10]++;
            temp /= 10;
        }

        temp = m;
        while (temp > 0){
            arr[temp % 10]--;
            temp /= 10;
        }

        for (int i = 0; i< 10; ++i) {
            if(arr[i] != 0) {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    T modpow(T base, T exp, T mod)
    {
        base %= mod;
        T result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
                base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    template unsigned long long modpow(unsigned long long base, unsigned long long exp, unsigned long long mod);
    template long long modpow(long long base, long long exp, long long mod);
    template int modpow(int base, int exp, int mod);

    int numberOfDigits(unsigned long i)
    {
        return (int)std::log10((double) i) + 1;
    }

    template <typename T>
    T modinv(T a, T b)
    {
        T b0 = b, t, q;
        T x0 = 0, x1 = 1;
        if (b == 1) return 1;
        while (a > 1) {
            q = a / b;
            t = b, b = a % b, a = t;
            t = x0, x0 = x1 - q * x0, x1 = t;
        }
        if (x1 < 0) x1 += b0;
        return x1;
    }
    template int modinv(int a, int b);
    template long long modinv(long long a, long long b);
    template unsigned long long modinv(unsigned long long a, unsigned long long b);
}// End namespace euler
