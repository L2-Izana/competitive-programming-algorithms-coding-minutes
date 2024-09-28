#include <bits/stdc++.h>
using namespace std;

/**
 * One Integer
 * You are given a list of integers nums. You can reduce the length of nums by taking any two integers, removing them, and appending their sum to the end. The cost of doing this is the sum of the two integers you removed.
 * Return the minimum total cost of reducing nums to one integer.
 */
int solve(vector<int> nums)
{
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const int n : nums)
    {
        pq.push(n);
    }
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << solve(nums);
    return 0;
}
