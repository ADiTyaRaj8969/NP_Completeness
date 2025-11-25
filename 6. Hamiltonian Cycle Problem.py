# Write a backtracking program to determine if a given graph contains a Hamiltonian Cycle.

def is_safe(v, graph, path, pos):
    # Check adjacency
    if graph[path[pos - 1]][v] == 0:
        return False
    # Check if vertex already in path
    if v in path:
        return False
    return True

def ham_cycle_util(graph, path, pos):
    n = len(graph)
    # Base case: all vertices included
    if pos == n:
        return graph[path[pos - 1]][path[0]] == 1  # last connects to first

    for v in range(1, n):
        if is_safe(v, graph, path, pos):
            path[pos] = v
            if ham_cycle_util(graph, path, pos + 1):
                return True
            path[pos] = -1  # backtrack
    return False

def ham_cycle(graph):
    n = len(graph)
    path = [-1] * n
    path[0] = 0  # start vertex

    if not ham_cycle_util(graph, path, 1):
        print("No Hamiltonian Cycle exists ❌")
        return False

    print("Hamiltonian Cycle exists ✅:", *path, path[0])
    return True


graph = [
    [0, 1, 0, 1, 0],
    [1, 0, 1, 1, 1],
    [0, 1, 0, 0, 1],
    [1, 1, 0, 0, 1],
    [0, 1, 1, 1, 0]
]

ham_cycle(graph)

"""
Time Complexity: O(N!)
    - Each vertex can lead to (N-1)! permutations.
Space Complexity: O(N)
    - Recursion stack + path list.
"""
