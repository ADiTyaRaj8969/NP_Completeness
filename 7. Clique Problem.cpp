// Given an undirected graph, implement a program to check whether there exists a clique of size k.
// (Use combinations of vertices and adjacency matrix check.)
#include <bits/stdc++.h>
using namespace std;

// Function to check if a set of vertices form a clique
bool isClique(const vector<vector<int>>& adj, const vector<int>& vertices)
{
    int k = vertices.size();
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (adj[vertices[i]][vertices[j]] == 0)
                return false;
        }
    }
    return true;
}

// Function to generate all combinations of size k
bool findClique(const vector<vector<int>>& adj, int n, int k)
{
    vector<int> vertices(n);
    iota(vertices.begin(), vertices.end(), 0);

    vector<int> comb(k);
    function<bool(int, int)> combUtil = [&](int start, int index)
    {
        if (index == k)
        {
            if (isClique(adj, comb))
                return true;
            return false;
        }
        for (int i = start; i < n; i++)
        {
            comb[index] = vertices[i];
            if (combUtil(i + 1, index + 1))
                return true;
        }
        return false;
    };

    return combUtil(0, 0);
}

int main()
{
    int n, k;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter size of clique (k): ";
    cin >> k;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> adj[i][j];

    if (findClique(adj, n, k))
        cout << "Clique of size " << k << " exists.\n";
    else
        cout << "Clique of size " << k << " does not exist.\n";

    return 0;
}

/*
Time Complexity (TC):
- Generate all combinations of k vertices: C(n, k) ≈ n! / (k! * (n-k)!)
- Check if combination is a clique: O(k^2)
=> Overall: O(C(n, k) * k^2) → exponential, suitable for small n.

Space Complexity (SC):
- Adjacency matrix: O(n^2)
- Combination array: O(k)
- Recursion stack depth: O(k)
=> Overall SC: O(n^2 + k)
*/
