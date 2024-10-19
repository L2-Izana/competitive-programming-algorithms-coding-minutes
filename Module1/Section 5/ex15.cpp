// 137. Single Number II
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

// Approach 2: Try bitmasking, or finding the key hidden in each set bit in every number
// Most of the set bit is divided by 3, except the one that makes the column (the sum of all the bit at position i is not divided by 3 or 3k+1)
// => Check through the position i of every num and see which one stirs it up

// My solution (too safe -> too slow)
bool isBitSet(int n, int i)
{
    return (n & (1 << i)) != 0;
}
int singleNumber(vector<int> &nums)
{
    vector<vector<bool>> a(nums.size(), vector<bool>(32, false));
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 31; j >= 0; j--)
        {
            a[i][j] = isBitSet(nums[i], 31 - j);
        }
    }
    vector<bool> singleNumberBitSet(32, false);
    for (int j = 31; j >= 0; j--)
    {
        int sum_col = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum_col += a[i][j];
        }
        if (sum_col % 3 != 0)
        {
            singleNumberBitSet[31 - j] = true;
        }
    }
    for (int num : nums)
    {
        bool isValid = true;
        for (int i = 0; i < 32; i++)
        {
            if (isBitSet(num, i) != singleNumberBitSet[i])
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            return num;
        }
    }
    return 0;
}

// Best solution, same shit of my solution but remember the collected form from all the positions i that are stirred up will form the answer
int singleNumberBestSol(vector<int> &nums)
{
    int ans = 0;

    for (int i = 0; i < 32; i++)
    {
        int idx = (1 << i); // the bit at index i
        int cnt = 0;

        for (int &x : nums)
        {
            if ((x & idx) != 0) // the bit at index i of the num x is 1
                cnt++;
        }

        if (cnt % 3 != 0)
        {
            ans |= idx;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums);
    return 0;
}
