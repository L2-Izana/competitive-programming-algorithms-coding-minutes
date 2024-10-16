#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

bool isPowerOfFour(int n)
{
    if (n > 0 && (n & (n - 1)) == 0)
    { // n is power of 2
        // Check if it is also a power of four
        // A power of four has exactly one bit set in an even position
        return (n & 0xAAAAAAAA) == 0; // Check if no bits are set in the odd positions
    } // A is the hexadecimal repretation of 1010
    return false;
}

int main()
{
    cout << isPowerOfFour(4);
    return 0;
}