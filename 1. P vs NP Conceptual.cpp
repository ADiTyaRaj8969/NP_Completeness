// Explain with examples the difference between P, NP, NP-Complete, and NP-Hard problems.
// Write a small program to verify whether a problem’s brute-force solution belongs to P or NP class
// (based on time).
#include <bits/stdc++.h>
using namespace std;

// Function to check if a subset with given sum exists
bool subsetSum(vector<int>& nums, int target, int index = 0)
{
    // Base cases
    if (target == 0)
        return true;
    if (index >= nums.size() || target < 0)
        return false;

    // Recursive: include or exclude current element
    return subsetSum(nums, target - nums[index], index + 1) || subsetSum(nums, target, index + 1);
}

int main()
{
    vector<int> nums = {2, 3, 7, 8, 10};
    int target = 11;

    auto start = chrono::high_resolution_clock::now();
    bool result = subsetSum(nums, target);
    auto end = chrono::high_resolution_clock::now();

    cout << "Subset with target " << target << (result ? " exists" : " does not exist") << endl;
    cout << "Execution time: " << chrono::duration<double, milli>(end - start).count() << " ms"
         << endl;

    return 0;
}

/*
🔹 Time Complexity: O(2^n)  (exponential recursion)
🔹 Space Complexity: O(n)   (recursion stack)
*/
