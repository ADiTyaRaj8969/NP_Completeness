# Write a program (in C++ or Python) to reduce the Subset Sum problem to the Partition problem, demonstrating polynomial-time reduction.
def subset_sum(nums, target, i=0):
    if target == 0:
        return True
    if i >= len(nums) or target < 0:
        return False
    return subset_sum(nums, target - nums[i], i + 1) or subset_sum(nums, target, i + 1)

def can_partition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    return subset_sum(nums, total // 2)

nums = [1, 5, 11, 5]
print("Can be partitioned" if can_partition(nums) else "Cannot be partitioned")

"""
🔹 Time Complexity: O(2^n)
🔹 Space Complexity: O(n)
"""

def can_partition_dp(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    n = len(nums)

    dp = [[False] * (target + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = True  # sum = 0 always possible

    for i in range(1, n + 1):
        for j in range(1, target + 1):
            if nums[i - 1] <= j:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]]
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[n][target]

nums = [1, 5, 11, 5]
print("Can be partitioned" if can_partition_dp(nums) else "Cannot be partitioned")

"""
🔹 Time Complexity: O(n * target)
🔹 Space Complexity: O(n * target)
"""
