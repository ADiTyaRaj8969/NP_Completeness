/*
Implement TSP using:

(a) Brute Force

(b) Dynamic Programming (Held–Karp Algorithm)
Compare both in terms of time complexity.

*/

#include <bits/stdc++.h>
using namespace std;

// ---------- (a) Brute Force TSP ----------
int tspBruteForce(vector<vector<int>>& dist, int start)
{
    int n = dist.size();
    vector<int> cities;
    for (int i = 0; i < n; i++)
        if (i != start)
            cities.push_back(i);

    int minCost = INT_MAX;

    do
    {
        int cost = 0, k = start;
        for (int city : cities)
        {
            cost += dist[k][city];
            k = city;
        }
        cost += dist[k][start];  // return to start
        minCost = min(minCost, cost);
    } while (next_permutation(cities.begin(), cities.end()));

    return minCost;
}

// ---------- (b) Held–Karp Dynamic Programming ----------
int tspDP(vector<vector<int>>& dist, int start)
{
    int n = dist.size();
    int VISITED_ALL = (1 << n) - 1;

    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    dp[1 << start][start] = 0;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int u = 0; u < n; u++)
        {
            if (!(mask & (1 << u)))
                continue;
            for (int v = 0; v < n; v++)
            {
                if (mask & (1 << v))
                    continue;
                int nextMask = mask | (1 << v);
                dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        if (i != start)
            ans = min(ans, dp[VISITED_ALL][i] + dist[i][start]);

    return ans;
}

int main()
{
    vector<vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int start = 0;

    cout << "TSP Brute Force Cost: " << tspBruteForce(dist, start) << endl;
    cout << "TSP Dynamic Programming Cost: " << tspDP(dist, start) << endl;

    return 0;
}

/*
Time Complexity:
(a) Brute Force: O(n!) → tries every permutation
(b) Held–Karp DP: O(n^2 * 2^n)

Space Complexity:
(a) Brute Force: O(n)
(b) Held–Karp DP: O(n * 2^n)
*/
