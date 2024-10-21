// 260. Single Number III
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    int result = 0;

    // XOR all numbers together, this will give us the XOR of the two unique numbers
    for (int num : nums)
    {
        result ^= num;
    }

    // Find the first bit position where the two numbers differ
    int pos = 0;
    while ((result & (1 << pos)) == 0)
    {
        pos++;
    }

    // Divide numbers into two sets based on the differing bit
    int setA = 0;
    int setB = 0;
    for (int num : nums)
    {
        if (num & (1 << pos))
        {
            setA ^= num; // Numbers where the bit is set
        }
        else
        {
            setB ^= num; // Numbers where the bit is not set
        }
    }

    // Return the two unique numbers
    return {setA, setB};
}

int main()
{
    // vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> nums = {2, 1, 2, 3, 4, 1};
    // cout << (-1 ^ 0);
    singleNumber(nums);
    return 0;
}

// Compute the XOR product, using the formula from ex14, we have left a^b -> there will be some bit being set
// -> those positions will sum up 2k + 1 in column
// Loop through the number that has the bit being set in these positions -> Using cp14 again -> Their xor product is indeed the unique number