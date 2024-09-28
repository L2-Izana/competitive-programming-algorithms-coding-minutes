#include <bits/stdc++.h>
using namespace std;

// My solution: brutal (2 sorts)
vector<int> findClosestElements(vector<int> arr, int k, int x)
{
    vector<pair<int, int>> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m.push_back({arr[i], abs(arr[i] - x)});
    }

    std::sort(m.begin(), m.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
              { return a.second < b.second; });

    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(m[i].first);
    }
    std::sort(ans.begin(), ans.end());

    return ans;
}

// Best solution: 2 pointers
vector<int> findClosestElements2(vector<int> arr, int k, int x)
{
    int n = arr.size(), R = lower_bound(begin(arr), end(arr), x) - begin(arr), L = R - 1; // Search for the index of the smallest element >= x

    /**
     * Then expand the window, remember:
     * The further the index is to R, the more the distance is
     * The array given is sorted and the final result is required to be sorted
     */
    while (k--)
        if (R >= n || L >= 0 && x - arr[L] <= arr[R] - x)
            L--;
        else
            R++;
    return vector<int>(begin(arr) + L + 1, begin(arr) + R);
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 4, 5};
    findClosestElements2(arr, 4, -1);
    return 1;
}