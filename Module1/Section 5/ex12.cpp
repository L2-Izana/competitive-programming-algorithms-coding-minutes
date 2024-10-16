// 1356. Sort Integers by The Number of 1 Bits
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

int coutBits(int n)
{
    int c = 0;
    while (n > 0)
    {
        n = (n & (n - 1));
        c++;
    }
    return c;
}
vector<int> sortByBits(vector<int> &arr)
{
    std::sort(arr.begin(), arr.end(), [](int a, int b)
              { int m = coutBits(a); int n = coutBits(b); if (m != n) {
                return m < n;
              }

              else {return a < b;} });
    return arr;
}

int main()
{
    vector<int> arr = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    for (int i : sortByBits(arr))
    {
        cout << i << " ";
    }
    return 0;
}