// 96. Unique Binary Search Trees
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

int numTrees(int n)
{
    if (n <= 2)
    {
        return n;
    }
    vector<int> a(n + 1, 0);
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            a[i] += a[j] * a[i - j - 1];
        }
    }
    return a[n];
}

int main()
{
    cout << numTrees(3);
    return 0;
}
