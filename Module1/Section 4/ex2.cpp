#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the index of the Kth Largest Element
 *
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 *
 * @param s the input string to be analyzed.
 * @param k k^{th} largest
 * @return int its index, or -1 if none exists.
 */

// My solution: using max heap
int findKthLargest(vector<int> nums, int k)
{
    priority_queue<int> h;
    for (int n : nums)
    {
        h.push(n);
    }
    while (!h.empty() && k > 1)
    {
        h.pop();
        k--;
    }
    return h.top();
}

// Best solution: using min heap
int findKthLargest(vector<int> nums, int k)
{
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        int ele = nums[i];
        pq.push(ele);
    }

    for (int i = k; i < n; i++)
    {
        int ele = nums[i];
        if (ele > pq.top())
        {
            pq.pop();
            pq.push(ele);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << findKthLargest(nums, k);
    return 0;
}