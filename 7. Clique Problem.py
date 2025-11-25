# Given an undirected graph, implement a program to check whether there exists a clique of size k.
# (Use combinations of vertices and adjacency matrix check.)

from itertools import combinations

# Function to check if a set of vertices form a clique
def is_clique(adj, vertices):
    for i in range(len(vertices)):
        for j in range(i + 1, len(vertices)):
            if adj[vertices[i]][vertices[j]] == 0:
                return False
    return True

# Function to find clique of size k
def find_clique(adj, n, k):
    for comb in combinations(range(n), k):
        if is_clique(adj, comb):
            return True
    return False

# Input
n = int(input("Enter number of vertices: "))
k = int(input("Enter size of clique (k): "))
print("Enter adjacency matrix row by row:")
adj = [list(map(int, input().split())) for _ in range(n)]

if find_clique(adj, n, k):
    print(f"Clique of size {k} exists.")
else:
    print(f"Clique of size {k} does not exist.")

"""
Time Complexity (TC):
- Generate all combinations of k vertices: C(n, k) ≈ n! / (k! * (n-k)!)
- Check if combination is a clique: O(k^2)
=> Overall: O(C(n, k) * k^2) → exponential, suitable for small n.

Space Complexity (SC):
- Adjacency matrix: O(n^2)
- Combination list: O(k)
=> Overall SC: O(n^2 + k)
"""
