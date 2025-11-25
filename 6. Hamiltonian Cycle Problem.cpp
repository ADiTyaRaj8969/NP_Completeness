// Write a backtracking program to determine if a given graph contains a Hamiltonian Cycle.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos)
{
    // Check if current vertex is adjacent to the previous one
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex already exists in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos)
{
    int n = graph.size();

    // Base case: all vertices included
    if (pos == n)
    {
        return graph[path[pos - 1]][path[0]] == 1;  // last connects to first
    }

    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;  // backtrack
        }
    }
    return false;
}

bool hamCycle(vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> path(n, -1);
    path[0] = 0;  // start vertex

    if (!hamCycleUtil(graph, path, 1))
    {
        cout << "No Hamiltonian Cycle exists ❌" << endl;
        return false;
    }

    cout << "Hamiltonian Cycle exists ✅ : ";
    for (int v : path) cout << v << " ";
    cout << path[0] << endl;  // complete cycle
    return true;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0}, {1, 0, 1, 1, 1}, {0, 1, 0, 0, 1}, {1, 1, 0, 0, 1}, {0, 1, 1, 1, 0}};

    hamCycle(graph);
    return 0;
}

/*
Time Complexity: O(N!)
    - For each vertex, we explore all remaining possibilities.
Space Complexity: O(N)
    - Recursion stack and path array of size N.
*/
