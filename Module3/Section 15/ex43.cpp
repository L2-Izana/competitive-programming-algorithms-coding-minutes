// The World is a Theatre

#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;
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
long long solve(int n, int m, int t)
{
    int a = 4;
    long long b = 0;
    while (t - a >= 1 && a <= n)
    {
        b += combination(n, a) * combination(m, t - a);
        a++;
    }
    return b;
}
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    cout << solve(n, m, t);
    return 0;
}