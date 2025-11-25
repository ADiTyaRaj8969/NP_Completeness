// Write a program using backtracking to solve the CNF-SAT problem (general Boolean satisfiability).
// This is the first proven NP-Complete problem.

#include <bits/stdc++.h>
using namespace std;

// Evaluate CNF clauses for a given variable assignment
bool evaluateCNF(const vector<vector<int>>& clauses, const vector<bool>& assignment)
{
    for (auto& clause : clauses)
    {
        bool clauseValue = false;
        for (int literal : clause)
        {
            int var = abs(literal) - 1;
            bool value = assignment[var];
            if (literal < 0)
                value = !value;  // handle negation
            clauseValue |= value;
        }
        if (!clauseValue)
            return false;  // any false clause => formula false
    }
    return true;
}

bool solveSAT(int n, const vector<vector<int>>& clauses)
{
    int total = 1 << n;  // 2^n combinations
    for (int mask = 0; mask < total; mask++)
    {
        vector<bool> assignment(n);
        for (int i = 0; i < n; i++) assignment[i] = (mask >> i) & 1;
        if (evaluateCNF(clauses, assignment))
            return true;
    }
    return false;
}

int main()
{
    // (A ∨ ¬B) ∧ (B ∨ C)
    vector<vector<int>> clauses = {
        {1, -2},  // A ∨ ¬B
        {2, 3}    // B ∨ C
    };

    int n = 3;  // Variables: A, B, C

    if (solveSAT(n, clauses))
        cout << "Satisfiable ✅" << endl;
    else
        cout << "Unsatisfiable ❌" << endl;

    return 0;
}

/*
Time Complexity: O(2^n * m * k)
    - 2^n assignments (n = number of variables)
    - m = number of clauses
    - k = average literals per clause

Space Complexity: O(n + m*k)
    - storing assignments and CNF clauses
*/
