# Implement a backtracking solution to color a graph using m colors so that no two adjacent vertices share the same color.
# This is another NP-Complete example.

def is_safe(vertex, adj, colors, color):
    n = len(adj)
    for i in range(n):
        if adj[vertex][i] == 1 and colors[i] == color:
            return False
    return True

def graph_coloring_util(adj, m, colors, vertex):
    n = len(adj)
    if vertex == n:
        return True  # all vertices colored

    for c in range(1, m+1):
        if is_safe(vertex, adj, colors, c):
            colors[vertex] = c
            if graph_coloring_util(adj, m, colors, vertex+1):
                return True
            colors[vertex] = 0  # backtrack
    return False

def graph_coloring(adj, m):
    n = len(adj)
    colors = [0]*n
    if graph_coloring_util(adj, m, colors, 0):
        return colors
    else:
        return None

# Input
n = int(input("Enter number of vertices: "))
m = int(input("Enter number of colors (m): "))
print("Enter adjacency matrix row by row:")
adj = [list(map(int, input().split())) for _ in range(n)]

colors = graph_coloring(adj, m)
if colors:
    print(f"Graph can be colored with {m} colors.")
    print("Coloring:", colors)
else:
    print(f"Graph cannot be colored with {m} colors.")

"""
Time Complexity (TC):
- Worst case: try all m^n colorings → O(m^n)

Space Complexity (SC):
- Colors array: O(n)
- Recursion stack depth: O(n)
=> Overall SC: O(n)
"""
