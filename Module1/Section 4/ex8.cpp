#include <bits/stdc++.h>
using namespace std;

/**
 * Smallest Range Covering Elements from K Lists
 * You have k lists of integers . Find the smallest range that includes at least one number from each of the k lists.
 *
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
 */

vector<int> smallestRange(vector<vector<int>> nums)
{
}

int main()
{
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    smallestRange(nums);
    return 1;
}