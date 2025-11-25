#Explain with examples the difference between P, NP, NP-Complete, and NP-Hard problems.
#Write a small program to verify whether a problem’s brute-force solution belongs to P or NP class (based on time).

import time

def subset_sum(nums, target, index=0):
    # Base cases
    if target == 0:
        return True
    if index >= len(nums) or target < 0:
        return False
    # Recursive: include or exclude
    return subset_sum(nums, target - nums[index], index + 1) or subset_sum(nums, target, index + 1)

nums = [2, 3, 7, 8, 10]
target = 11

start = time.time()
result = subset_sum(nums, target)
end = time.time()

print(f"Subset with target {target} {'exists' if result else 'does not exist'}")
print(f"Execution time: {(end - start) * 1000:.4f} ms")

"""
🔹 Time Complexity: O(2^n)  (exponential recursion)
🔹 Space Complexity: O(n)   (recursion depth)
"""
