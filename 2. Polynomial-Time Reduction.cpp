// Write a program (in C++ or Python) to reduce the Subset Sum problem to the Partition problem,
// demonstrating polynomial-time reduction.

#include <bits/stdc++.h>
using namespace std;

// Recursive subset sum function
bool subsetSum(vector<int>& nums, int target, int i = 0)
{
    if (target == 0)
        return true;
    if (i >= nums.size() || target < 0)
        return false;
    return subsetSum(nums, target - nums[i], i + 1) || subsetSum(nums, target, i + 1);
}

// Partition Problem using reduction to Subset Sum
bool canPartition(vector<int>& nums)
{
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0)
        return false;  // Odd total can't be partitioned equally
    return subsetSum(nums, total / 2);
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartition(nums) ? "Can be partitioned" : "Cannot be partitioned") << endl;
    return 0;
}

/*
🔹 Time Complexity: O(2^n)  — Exponential recursion
🔹 Space Complexity: O(n)   — Recursion depth
*/

#include <bits/stdc++.h>
using namespace std;

bool canPartitionDP(vector<int>& nums)
{
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0)
        return false;
    int target = total / 2;

    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= nums.size(); i++) dp[i][0] = true;  // sum=0 always true

    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[nums.size()][target];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << (canPartitionDP(nums) ? "Can be partitioned" : "Cannot be partitioned") << endl;
    return 0;
}

/*
🔹 Time Complexity: O(n * target)
🔹 Space Complexity: O(n * target)
*/
