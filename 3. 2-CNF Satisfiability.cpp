// Implement an algorithm to determine if a 2-CNF Boolean expression is satisfiable.
//(Example: (A ∨ B) ∧ (¬A ∨ C) → True if A=F, B=T, C=T)

#include <bits/stdc++.h>
using namespace std;

// Function to evaluate the 2-CNF formula (A ∨ B) ∧ (¬A ∨ C)
bool evaluateFormula(bool A, bool B, bool C)
{
    bool clause1 = (A || B);
    bool clause2 = ((!A) || C);
    return clause1 && clause2;
}

int main()
{
    bool found = false;

    // Try all combinations of A, B, C (2^3 = 8 combinations)
    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            for (int c = 0; c <= 1; c++)
            {
                if (evaluateFormula(a, b, c))
                {
                    cout << "Satisfying assignment found: "
                         << "A=" << a << " B=" << b << " C=" << c << endl;
                    found = true;
                }
            }
        }
    }

    if (!found)
        cout << "No satisfying assignment exists.\n";

    return 0;
}

/*
🔹 Time Complexity: O(2^n)  (n = number of variables)
🔹 Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct TwoSAT
{
    int n;
    vector<vector<int>> g, rg;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSAT(int vars) : n(vars), g(2 * vars), rg(2 * vars), assignment(vars) {}

    void addClause(int i, bool f, int j, bool g_)
    {
        int a = 2 * i ^ (f ? 0 : 1);
        int b = 2 * j ^ (g_ ? 0 : 1);
        g[a ^ 1].push_back(b);
        rg[b].push_back(a ^ 1);
        g[b ^ 1].push_back(a);
        rg[a].push_back(b ^ 1);
    }

    void dfs1(int v, vector<bool>& vis)
    {
        vis[v] = true;
        for (int u : g[v])
            if (!vis[u])
                dfs1(u, vis);
        order.push_back(v);
    }

    void dfs2(int v, int c, vector<bool>& vis)
    {
        vis[v] = true;
        comp[v] = c;
        for (int u : rg[v])
            if (!vis[u])
                dfs2(u, c, vis);
    }

    bool satisfiable()
    {
        vector<bool> vis(2 * n);
        for (int i = 0; i < 2 * n; ++i)
            if (!vis[i])
                dfs1(i, vis);

        fill(vis.begin(), vis.end(), false);
        comp.assign(2 * n, -1);
        int j = 0;
        for (int i = 2 * n - 1; i >= 0; --i)
            if (!vis[order[i]])
                dfs2(order[i], j++, vis);

        for (int i = 0; i < n; ++i)
        {
            if (comp[2 * i] == comp[2 * i + 1])
                return false;
            assignment[i] = comp[2 * i] > comp[2 * i + 1];
        }
        return true;
    }
};

int main()
{
    TwoSAT sat(3);                     // Variables: A, B, C (indices 0,1,2)
    sat.addClause(0, true, 1, true);   // (A ∨ B)
    sat.addClause(0, false, 2, true);  // (¬A ∨ C)

    cout << (sat.satisfiable() ? "Satisfiable ✅" : "Unsatisfiable ❌") << endl;
    return 0;
}

/*
🔹 Time Complexity: O(V + E)
🔹 Space Complexity: O(V + E)
*/
