#ifndef SIEVE_H
#define SIEVE_H

#include <cmath>

#define SIEVE_ATKINS 1
#define SIEVE_ERATOSTEN 2

namespace euler {
    class Sieve
    {
        public:
            Sieve(unsigned long long n, int type = 1);
            Sieve();
            virtual ~Sieve();
            bool isPrime(unsigned long long n);
        protected:
            void atkins(unsigned long long n);
            void eratosthenes(unsigned long long n);
            bool *primes;
    };
}
#endif // SIEVE_H
