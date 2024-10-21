#include <bits/stdc++.h>
using namespace std;

// Function to calculate nCr directly to avoid large factorials
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

unsigned long long solve(int n)
{
    unsigned long long a = combination(n, 5); // nC5
    unsigned long long b = combination(n, 6); // nC6
    unsigned long long c = combination(n, 7); // nC7

    return a + b + c;
}

int main()
{
    int n;
    cin >> n;         // Input the number
    cout << solve(n); // Output the result
    return 0;
}
