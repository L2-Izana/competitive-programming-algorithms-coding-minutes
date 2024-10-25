// Skyline

#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

unsigned long long factorial(int n)
{
    unsigned long long a = 1;
    for (int i = 1; i <= n; i++)
    {
        a *= i;
    }
    return a;
}
unsigned long long combination(int n, int r)
{
    unsigned long long result = 1;
    for (int i = 1; i <= r; ++i)
    {
        result *= (n - r + i);
        result /= i;
    }
    return result;
}

int solve(int n)
{
    int a = 0;
    // with duplication
    int c = combination(n, 3);
    int c2 = factorial(n - 3);
    // Now we want to partition these c2 numbers into 3 locations < j, > j and < k, and > k, let their numbers are u, v, c2-u-v.
    // Therefore, we have c2Cu, c2Cv, c2C(c2-u-v)
    // Runing u,v from u = 0, v= 0 -> u+v <= n-3
    int c = combination(n, 3) * factorial(n - 3);
    return c;
}
/**
 * 1234 1243 1423 4123
 * 3124 1324
 * 2134 1342
 * 2314 2341
 */
int main()
{
    cout << solve(4);
    return 0;
}
// Given an array(n). Label the indices 0 -> n-1 so that there would not be any increasing triplets i, j, k so that i < j < k
// 2134 -> [1, 0, 2, 3]

// 12345 123 345
// with 1 triplet (i,j,k), we have (i-1)!*(k-j-1)!*(n-k-1)!