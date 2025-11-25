# Write a program using backtracking to solve the CNF-SAT problem (general Boolean satisfiability).
# This is the first proven NP-Complete problem.

from itertools import product

def evaluate_cnf(clauses, assignment):
    for clause in clauses:
        clause_value = False
        for literal in clause:
            var = abs(literal) - 1
            value = assignment[var]
            if literal < 0:
                value = not value
            clause_value |= value
        if not clause_value:
            return False
    return True

def solve_sat(n, clauses):
    for bits in product([False, True], repeat=n):
        if evaluate_cnf(clauses, bits):
            return True
    return False

# Example: (A ∨ ¬B) ∧ (B ∨ C)
clauses = [
    [1, -2],  # A ∨ ¬B
    [2, 3]    # B ∨ C
]
n = 3  # Variables: A, B, C

if solve_sat(n, clauses):
    print("Satisfiable ✅")
else:
    print("Unsatisfiable ❌")

"""
Time Complexity: O(2^n * m * k)
    - 2^n possible truth assignments
    - Each clause (m) has k literals to check

Space Complexity: O(n + m*k)
    - Store variable assignments and CNF structure
"""

