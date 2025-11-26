# Write a recursive and dynamic programming solution for the Subset Sum problem, compare their time complexities, and explain why the problem is NP-Complete.

def subset_sum_rec(arr, n, sum_val):
    if sum_val == 0:
        return True
    if n == 0:
        return False

    if arr[n-1] > sum_val:
        return subset_sum_rec(arr, n-1, sum_val)
    
    return subset_sum_rec(arr, n-1, sum_val) or subset_sum_rec(arr, n-1, sum_val - arr[n-1])

# Input
n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))
sum_val = int(input("Enter target sum: "))

if subset_sum_rec(arr, n, sum_val):
    print(f"Subset with sum {sum_val} exists.")
else:
    print(f"Subset with sum {sum_val} does not exist.")

"""
Time Complexity (TC): O(2^n)
Space Complexity (SC): O(n) for recursion stack
"""

def subset_sum_dp(arr, sum_val):
    n = len(arr)
    dp = [[False]*(sum_val+1) for _ in range(n+1)]

    for i in range(n+1):
        dp[i][0] = True  # sum 0 is always possible

    for i in range(1, n+1):
        for j in range(1, sum_val+1):
            if arr[i-1] <= j:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][sum_val]

# Input
n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))
sum_val = int(input("Enter target sum: "))

if subset_sum_dp(arr, sum_val):
    print(f"Subset with sum {sum_val} exists.")
else:
    print(f"Subset with sum {sum_val} does not exist.")

"""
Time Complexity (TC): O(n*sum)
Space Complexity (SC): O(n*sum)
"""
