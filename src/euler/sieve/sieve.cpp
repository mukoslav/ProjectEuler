#include "sieve.h"

namespace euler {

    Sieve::Sieve(unsigned long long n, int type)
    {
        switch (type) {
            case SIEVE_ATKINS:
                this->atkins(n);
                break;
            case SIEVE_ERATOSTEN:
            default:
                this->eratosthenes(n);
                break;
        }
    }

    Sieve::Sieve()
    {
        this->eratosthenes(1000000);
    }

    Sieve::~Sieve()
    {
        delete primes;
    }

    void Sieve::atkins(unsigned long long n)
    {
        primes = new bool[n+1];
        primes[2] = true;
        primes[3] = true;

        for (unsigned long long i = 5; i <= n; ++i) {
            primes[i] = false;
        }

        unsigned long long lim = ceil(sqrt(n));

        for (unsigned long long x = 1; x <= lim; ++x) {
            for (unsigned long long y = 1; y <= lim; ++y) {
                unsigned long long num = (4 * x * x + y * y);

                if (num <= n && (num % 12 == 1 || num % 12 == 5)) {
                    primes[num] = true;
                }

                num = (3 * x * x + y * y);

                if (num <= n && (num % 12 == 7)) {
                    primes[num] = true;
                }

                if (x > y) {
                    num = (3 * x * x - y * y);
                    if (num <= n && (num % 12 == 11)) {
                        primes[num] = true;
                    }
                }
            }
        }

        for (unsigned long long i = 5; i <= lim; ++i) {
            if (primes[i]) {
                for (unsigned long long j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

    }

    void Sieve::eratosthenes(unsigned long long n)
    {
        primes = new bool[n + 1];
        unsigned long long l;

        primes[0] = false;
        primes[1] = false;

        for (unsigned long long i = 2; i <= n; ++i) {
            primes[i] = true;
        }

        for (unsigned long long i = 2; i<=n/2; ++i) {
            if (primes[i]) {
                l = n/i;
                for (unsigned long long j = 2; j<=l; ++j) {
                    primes[i*j] = false;
                }
            }
        }
    }

    bool Sieve::isPrime(unsigned long long n)
    {
        return primes[n];
    }
}// End namespace euler
