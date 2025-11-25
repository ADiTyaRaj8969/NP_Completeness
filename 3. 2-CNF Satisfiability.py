#Implement an algorithm to determine if a 2-CNF Boolean expression is satisfiable.
#(Example: (A ∨ B) ∧ (¬A ∨ C) → True if A=F, B=T, C=T)

def evaluate_formula(A, B, C):
    clause1 = (A or B)
    clause2 = ((not A) or C)
    return clause1 and clause2

found = False

for A in [False, True]:
    for B in [False, True]:
        for C in [False, True]:
            if evaluate_formula(A, B, C):
                print(f"Satisfying assignment found: A={A}, B={B}, C={C}")
                found = True

if not found:
    print("No satisfying assignment exists.")

"""
🔹 Time Complexity: O(2^n)
🔹 Space Complexity: O(1)
"""

import networkx as nx

def add_clause(G, x, not_x, y, not_y):
    G.add_edge(not_x, y)
    G.add_edge(not_y, x)

def is_satisfiable():
    G = nx.DiGraph()
    vars = ['A', 'B', 'C']
    nodes = vars + [f'¬{v}' for v in vars]
    G.add_nodes_from(nodes)

    add_clause(G, 'A', '¬A', 'B', '¬B')  # (A ∨ B)
    add_clause(G, 'C', '¬C', '¬A', 'A')  # (¬A ∨ C)

    scc = list(nx.strongly_connected_components(G))
    for v in vars:
        for comp in scc:
            if v in comp and f'¬{v}' in comp:
                return False
    return True

print("Satisfiable ✅" if is_satisfiable() else "Unsatisfiable ❌")

"""
🔹 Time Complexity: O(V + E)
🔹 Space Complexity: O(V + E)
"""
