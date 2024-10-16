// Hamming Distance
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

int hammingDistance(int x, int y)
{
    int z = x ^ y;
    int c = 0;
    while (z > 0)
    {
        z = z & (z - 1);
        c++;
    }
    return c;
}
int main()
{

    return 0;
}