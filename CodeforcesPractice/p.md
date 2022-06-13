Given a DAG (Directed Acyclic Graph) where each node of DAG has a character value (a - z).
Find a path from node 1 to node n such that string formed from concatenation of all character values of node coming in the path (taken in same
order as path from node 1 to n) is lexicographically smallest one.

# Input:

Number of nodes (n), number of edges (m).
N characters a_0, a_1,..... ,a_n where a_i represents character value of node i.
Following m lines contains two integers a, b each which means there is a directed edge from node number a to b.

# Output:

Lexicographically smallest string found.

# Constraints:

1 <= n <= 1e6
n - 1 <= m <= 1e6
'a' <= a_i <= 'z'

# Sample Test Case1:

## Input:

5 6
b a c z e
1 2
1 3
2 4
3 5
3 4
4 5

## Output:

baze

## Explanation:

Path from [ 1->2->4->5 ]
