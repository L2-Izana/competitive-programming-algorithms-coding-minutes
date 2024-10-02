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
    vector<pair<int, int>> a;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int n : nums[i])
        {
            a.push_back({n, i});
        }
    }

    sort(a.begin(), a.end());

    int smallest_r = INT_MAX;
    vector<int> ans(2, 0);

    int l = 0;
    int r = 0;
    vector<int> count(nums.size(), 0);

    int unique_count = 0;

    while (r < a.size())
    {

        int right_list = a[r].second;
        count[right_list]++;
        if (count[right_list] == 1)
        {
            unique_count++;
        }

        while (unique_count == nums.size())
        {
            int left_val = a[l].first;
            int right_val = a[r].first;

            if (right_val - left_val < smallest_r)
            {
                smallest_r = right_val - left_val;
                ans = {left_val, right_val};
            }

            int left_list = a[l].second;
            count[left_list]--;
            if (count[left_list] == 0)
            {
                unique_count--;
            }
            l++;
        }
        r++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> ans = smallestRange(nums);
    cout << ans[0] << " " << ans[1];
    return 1;
}