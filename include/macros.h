#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

// Determine whether the given signed or unsigned integer is odd.
#define isOdd(num) ((num) & 1)

// Determine whether the given signed or unsigned integer is even.
#define isEven(num) (!isOdd((num)))

// Useful container manipulation / traversal macros
#define foreach(it,t) for (auto it=t.begin(); it!=t.end(); ++it) // traverse an STL data structure
#define isIn(a,b) ((b).find(a) != (b).end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair

// Bit manipulation
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lBit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest

// PI and Infinite
#define INF 1001001001
#define PI 3.1415926535897932384626

#endif // MACROS_H_INCLUDED
