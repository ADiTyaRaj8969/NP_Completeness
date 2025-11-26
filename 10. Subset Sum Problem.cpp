// Write a recursive and dynamic programming solution for the Subset Sum problem, compare their time
// complexities, and explain why the problem is NP-Complete.

#include <bits/stdc++.h>
using namespace std;

// Recursive function to check subset sum
bool subsetSumRec(vector<int>& arr, int n, int sum)
{
    if (sum == 0)
        return true;  // empty subset makes sum 0
    if (n == 0)
        return false;  // no elements left

    if (arr[n - 1] > sum)  // skip if element > sum
        return subsetSumRec(arr, n - 1, sum);

    // Include or exclude current element
    return subsetSumRec(arr, n - 1, sum) || subsetSumRec(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target sum: ";
    cin >> sum;

    if (subsetSumRec(arr, n, sum))
        cout << "Subset with sum " << sum << " exists.\n";
    else
        cout << "Subset with sum " << sum << " does not exist.\n";

    return 0;
}

/*
Time Complexity (TC): O(2^n) -> check all subsets
Space Complexity (SC): O(n) -> recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

bool subsetSumDP(vector<int>& arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Sum 0 is always possible (empty subset)
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target sum: ";
    cin >> sum;

    if (subsetSumDP(arr, sum))
        cout << "Subset with sum " << sum << " exists.\n";
    else
        cout << "Subset with sum " << sum << " does not exist.\n";

    return 0;
}

/*
Time Complexity (TC): O(n*sum)
Space Complexity (SC): O(n*sum) for DP table
*/
