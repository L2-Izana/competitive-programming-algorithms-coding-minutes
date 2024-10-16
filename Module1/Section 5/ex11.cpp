// 338. Counting Bits

#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

// My way: O(nlogn) as it needs to iterate every single bit
vector<int> countBits(int n)
{
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        int c = 0;
        int b = i;
        while (b > 0)
        {
            c += (b & 1); // Add 1 if last bit is 1 else 0
            b = b >> 1;
        }
        a[i] = c;
    }
    return a;
}

// Faster way: nearly O(n), it only perform operations on right most set bit (1), else eliminates others (0)
vector<int> countBits(int n)
{
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        int c = 0;
        int b = i;
        while (b > 0)
        {
            b = b & (b - 1); // Eliminate the rightmost set bit to 2nd rightmost, e.g. 1010001 -> 101 or 1010010 -> 101
            c++;
        }
        a[i] = c;
    }
    return a;
}

int main()
{
    return 0;
}
