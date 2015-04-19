#include <iostream>
#include <vector>
#include "../include/euler.h"

using namespace std;
using namespace euler;

bool testSieve()
{
    bool passed = true;

    Sieve s(100000);

    if (!s.isPrime(7)) {
        passed = false;
    }

    if (s.isPrime(988)) {
        passed = false;
    }

    if (!s.isPrime(10009)) {
        passed = false;
    }

    Sieve s2(100000, SIEVE_ERATOSTEN);

    if (!s2.isPrime(7)) {
        passed = false;
    }

    if (s2.isPrime(988)) {
        passed = false;
    }

    if (!s2.isPrime(10009)) {
        passed = false;
    }

    return passed;
}

bool testCommon()
{
    bool passed = true;

    // Mod inv
    long long a = 2, b = 5;

    if (modinv(a, b) != 3) {
        passed = false;
    }

    // Binomial check
    if (binomial(18, 9) != 48620) {
        passed = false;
    }

    if (binomial((unsigned long long)70, (unsigned long long)20) != 161884603662657876) {
        cout << "Fail" << endl;
    }

    if (binomial((unsigned long long)60, (unsigned long long)25) != 51915437974328292) {
        passed = false;
    }

    // GCD/LCM check
    if (gcd(300, 100) != 100) {
         passed = false;
    }
    if (gcd(1000, 625) != 125) {
         passed = false;
    }
    if (lcm(1000, 625) != 5000) {
         passed = false;
    }

    // Pandigital check
    /*
    if (!isPandigital(1342576)) {
        passed = false;
    }
    if (isPandigital(18423576)) {
        passed = false;
    }
    */
    return passed;
}

bool testComb()
{
    bool passed = true;

    Comb c;
    vector<int> test;

    // Make test array
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    vector<vector<int>> sol = c.make(test, 2);

    // Check if size fits
    if (sol.size() != 3) {
        passed = false;
    }

    // Check if array are as expected
    int expected[] = {1,2,1,3,2,3}, i = 0;

    vector<vector<int>>::iterator it = sol.begin();
    for (;it!=sol.end(); ++it) {
        vector<int>::iterator iit = (*it).begin();
        for (;iit!=(*it).end();++iit) {
            if ((*iit) != expected[i++]) {
                passed = false;
            }
        }
    }

    return passed;
}

bool testPerm()
{
    bool passed = true;

    Perm p;
    vector<int> test;

    // Make test array
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    // Check if array are as expected
    int expected[6][3] = {1,2,3,1,3,2,2,1,3,2,3,1,3,1,2,3,2,1}, k = 0, j = 0;

    do {
        j = 0;
        for (int i = 0; i < test.size(); i++) {
            if (test[i] != expected[k][j]) {
                passed = false;
            }
            ++j;
        }
        ++k;
    } while (p.next(test.begin(), test.end()));

    return passed;
}

int main2()
{
    cout << "RUNNING TESTS..." << endl;
    if (testSieve()) {
        cout << "Sieve test passed." << endl;
    } else {
        cout << "Sieve test failed!" << endl;
    }

    if (testCommon()) {
        cout << "Common test passed." << endl;
    } else {
        cout << "Common test failed!" << endl;
    }

    if (testComb()) {
        cout << "Comb test passed." << endl;
    } else {
        cout << "Comb test failed!" << endl;
    }

    if (testPerm()) {
        cout << "Perm test passed." << endl;
    } else {
        cout << "Perm test failed!" << endl;
    }

    cout << "TESTS DONE" << endl;
    return 0;
}
