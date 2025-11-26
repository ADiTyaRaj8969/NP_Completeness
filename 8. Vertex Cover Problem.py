# Implement a brute-force solution for the Minimum Vertex Cover problem and discuss why it belongs to NP-Complete.

from itertools import combinations

def is_vertex_cover(adj, cover):
    n = len(adj)
    in_cover = [False]*n
    for v in cover:
        in_cover[v] = True

    for u in range(n):
        for v in range(u+1, n):
            if adj[u][v] == 1 and not (in_cover[u] or in_cover[v]):
                return False
    return True

def minimum_vertex_cover(adj):
    n = len(adj)
    vertices = list(range(n))
    for size in range(1, n+1):
        for comb in combinations(vertices, size):
            if is_vertex_cover(adj, comb):
                return comb
    return []

# Input
n = int(input("Enter number of vertices: "))
print("Enter adjacency matrix row by row:")
adj = [list(map(int, input().split())) for _ in range(n)]

mvc = minimum_vertex_cover(adj)
print(f"Minimum Vertex Cover size: {len(mvc)}")
print("Vertices:", mvc)

"""
Time Complexity (TC):
- There are 2^n subsets of vertices.
- Checking a subset for vertex cover: O(n^2)
=> Overall: O(2^n * n^2)

Space Complexity (SC):
- Adjacency matrix: O(n^2)
- Combination list: O(n)
=> Overall: O(n^2 + n)
"""
