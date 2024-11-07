![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Eulerian Subgraphs

  * Task
  * Statistics

CSES - Eulerian Subgraphs

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an undirected graph that has $n$ nodes and $m$ edges.

We consider subgraphs that have all nodes of the original graph and some of
its edges. A subgraph is called _Eulerian_ if each node has even degree.

Your task is to count the number of Eulerian subgraphs modulo $10^9+7$.

# Input

The first input line has two integers $n$ and $m$: the number of nodes and
edges. The nodes are numbered $1,2,\dots,n$.

After this, there are $m$ lines that describe the edges. Each line has two
integers $a$ and $b$: there is an edge between nodes $a$ and $b$. There is at
most one edge between two nodes, and each edge connects two distinct nodes.

# Output

Print the number of Eulerian subgraphs modulo $10^9+7$.

# Constraints

  * $1 \le n \le 10^5$
  * $0 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 4 3 1 2 1 3 2 3 ```

Output:

``` 2 ```

Explanation: You can either keep or remove all edges, so there are two
possible Eulerian subgraphs.

#### Advanced Techniques

... Reversals and SumsNecessary RoadsNecessary CitiesEulerian SubgraphsMonster
Game IMonster Game IISubarray SquaresHouses and Schools...

* * *

