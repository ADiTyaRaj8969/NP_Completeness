// Implement a backtracking solution to color a graph using m colors so that no two adjacent
// vertices share the same color. This is another NP-Complete example.

#include <bits/stdc++.h>
using namespace std;

// Function to check if vertex can be colored with 'color'
bool isSafe(int vertex, const vector<vector<int>>& adj, vector<int>& colors, int color)
{
    int n = adj.size();
    for (int i = 0; i < n; i++)
    {
        if (adj[vertex][i] && colors[i] == color)
            return false;
    }
    return true;
}

// Backtracking function
bool graphColoringUtil(const vector<vector<int>>& adj, int m, vector<int>& colors, int vertex)
{
    int n = adj.size();
    if (vertex == n)
        return true;  // all vertices colored

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(vertex, adj, colors, c))
        {
            colors[vertex] = c;
            if (graphColoringUtil(adj, m, colors, vertex + 1))
                return true;
            colors[vertex] = 0;  // backtrack
        }
    }
    return false;
}

// Main function to solve graph coloring
bool graphColoring(const vector<vector<int>>& adj, int m, vector<int>& colors)
{
    return graphColoringUtil(adj, m, colors, 0);
}

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors (m): ";
    cin >> m;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> adj[i][j];

    vector<int> colors(n, 0);

    if (graphColoring(adj, m, colors))
    {
        cout << "Graph can be colored with " << m << " colors.\n";
        cout << "Coloring: ";
        for (int c : colors) cout << c << " ";
        cout << endl;
    }
    else
    {
        cout << "Graph cannot be colored with " << m << " colors.\n";
    }

    return 0;
}

/*
Time Complexity (TC):
- Worst case: Try all m^n colorings → O(m^n)
Space Complexity (SC):
- Color array: O(n)
- Recursion stack depth: O(n)
=> Overall SC: O(n)
*/
