"""
Implement TSP using:

(a) Brute Force

(b) Dynamic Programming (Held–Karp Algorithm)
Compare both in terms of time complexity.

"""
from itertools import permutations

# ---------- (a) Brute Force TSP ----------
def tsp_brute_force(dist, start):
    n = len(dist)
    cities = [i for i in range(n) if i != start]
    min_cost = float('inf')

    for perm in permutations(cities):
        cost = 0
        k = start
        for city in perm:
            cost += dist[k][city]
            k = city
        cost += dist[k][start]
        min_cost = min(min_cost, cost)

    return min_cost

# ---------- (b) Held–Karp Dynamic Programming ----------
def tsp_dp(dist, start):
    n = len(dist)
    VISITED_ALL = (1 << n) - 1
    dp = [[float('inf')] * n for _ in range(1 << n)]
    dp[1 << start][start] = 0

    for mask in range(1 << n):
        for u in range(n):
            if not (mask & (1 << u)):
                continue
            for v in range(n):
                if mask & (1 << v):
                    continue
                next_mask = mask | (1 << v)
                dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + dist[u][v])

    ans = float('inf')
    for i in range(n):
        if i != start:
            ans = min(ans, dp[VISITED_ALL][i] + dist[i][start])

    return ans


dist = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]
start = 0

print("TSP Brute Force Cost:", tsp_brute_force(dist, start))
print("TSP Dynamic Programming Cost:", tsp_dp(dist, start))

"""
Time Complexity:
(a) Brute Force: O(n!)  # factorial growth
(b) Held–Karp DP: O(n^2 * 2^n)

Space Complexity:
(a) Brute Force: O(n)
(b) Held–Karp DP: O(n * 2^n)
"""
