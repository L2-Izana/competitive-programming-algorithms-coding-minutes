#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

int minJumps(vector<int> &nums, vector<int> &dp, int i)
{
    // Base case: if we have reached the last element, no more jumps are needed
    if (i == nums.size() - 1)
    {
        return 0;
    }

    // If we go beyond the array bounds, return a high value to indicate invalid path
    if (i >= nums.size())
    {
        return INT_MAX;
    }

    // If we've already computed the minimum jumps from this position, return it
    if (dp[i] != 0)
    {
        return dp[i];
    }

    int maxSteps = nums[i]; // Maximum steps we can take from current position
    int steps = INT_MAX;    // Variable to store minimum steps from this position

    // Try all possible jumps from current position up to maxSteps
    for (int j = 1; j <= maxSteps; j++)
    {
        int next_cell = i + j; // Calculate the next cell we would jump to

        // Recursive call to find min jumps needed from the next cell
        int min_jumps_next = minJumps(nums, dp, next_cell);

        // If next cell can be reached (for the base case 2: i >= n), update steps to keep the minimum jumps count
        if (min_jumps_next != INT_MAX)
        {
            steps = min(steps, min_jumps_next + 1); // + 1 to move from i to i + j. We can plus 1 later, does not matter
        }
    }

    // Store the result in dp array to avoid redundant calculations and return
    return dp[i] = steps;
}

int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0); // dp array to memoize minimum steps to reach the end from each position
    return minJumps(nums, dp, 0);   // Start calculating from position 0
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums);
    return 0;
}