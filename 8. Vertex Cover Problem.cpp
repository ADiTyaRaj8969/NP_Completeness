// Implement a brute-force solution for the Minimum Vertex Cover problem and discuss why it belongs
// to NP-Complete.

#include <bits/stdc++.h>
using namespace std;

// Check if given vertex set is a vertex cover
bool isVertexCover(const vector<vector<int>>& adj, const vector<int>& cover)
{
    int n = adj.size();
    vector<bool> inCover(n, false);
    for (int v : cover) inCover[v] = true;

    for (int u = 0; u < n; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            if (adj[u][v] == 1)
            {
                if (!inCover[u] && !inCover[v])
                    return false;  // edge not covered
            }
        }
    }
    return true;
}

// Brute-force: try all subsets
vector<int> minimumVertexCover(const vector<vector<int>>& adj, int n)
{
    vector<int> vertices(n);
    iota(vertices.begin(), vertices.end(), 0);

    for (int size = 1; size <= n; size++)
    {
        vector<int> comb(size);
        function<bool(int, int)> dfs = [&](int start, int index)
        {
            if (index == size)
            {
                if (isVertexCover(adj, comb))
                    return true;
                return false;
            }
            for (int i = start; i < n; i++)
            {
                comb[index] = vertices[i];
                if (dfs(i + 1, index + 1))
                    return true;
            }
            return false;
        };
        if (dfs(0, 0))
            return comb;
    }
    return {};  // no cover (should not happen)
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> adj[i][j];

    vector<int> mvc = minimumVertexCover(adj, n);
    cout << "Minimum Vertex Cover size: " << mvc.size() << "\nVertices: ";
    for (int v : mvc) cout << v << " ";
    cout << endl;

    return 0;
}

/*
Time Complexity (TC):
- There are 2^n subsets of vertices.
- Checking a subset for vertex cover: O(n^2)
=> Overall: O(2^n * n^2)

Space Complexity (SC):
- Adjacency matrix: O(n^2)
- Combination array & recursion stack: O(n)
=> Overall: O(n^2 + n)
*/
