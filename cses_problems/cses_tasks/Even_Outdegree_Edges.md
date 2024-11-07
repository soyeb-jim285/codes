![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Even Outdegree Edges

  * Task
  * Statistics

CSES - Even Outdegree Edges

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given an undirected graph, your task is to choose a direction for each edge so
that in the resulting directed graph each node has an even outdegree. The
outdegree of a node is the number of edges coming out of that node.

# Input

The first input line has two integers $n$ and $m$: the number of nodes and
edges. The nodes are numbered $1,2,\dots,n$.

After this, there are $m$ lines describing the edges. Each line has two
integers $a$ and $b$: there is an edge between nodes $a$ and $b$.

You may assume that the graph is simple, i.e., there is at most one edge
between any two nodes and every edge connects two distinct nodes.

# Output

Print $m$ lines describing the directions of the edges. Each line has two
integers $a$ and $b$: there is an edge from node $a$ to node $b$. You can
print any valid solution.

If there are no solutions, only print "IMPOSSIBLE".

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 4 4 1 2 2 3 3 4 1 4 ```

Output:

``` 1 2 3 2 3 4 1 4 ```

#### Additional Problems

... Prüfer CodeAcyclic Graph EdgesStrongly Connected EdgesEven Outdegree
EdgesMultiplication TableAdvertisementSpecial SubstringsPermutation
Inversions...

* * *

