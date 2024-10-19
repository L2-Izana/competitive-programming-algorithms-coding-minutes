// 136. Single Number
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

int singleNumber(vector<int> &nums)
{
    // The idea is using a ^ a = 0 and 0 ^ b = b, hence we have a funny formula: a ^ b ^ a = b
    int a = 0;
    for (int num : nums)
    {
        a = a ^ num;
    }
    return a;
}
int main()
{
    return 0;
}
