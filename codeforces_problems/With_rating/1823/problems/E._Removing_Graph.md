<h1 style='text-align: center;'> E. Removing Graph</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game on a graph. They have an undirected graph without self-loops and multiple edges. All vertices of the graph have degree equal to $2$. The graph may consist of several components. 
## Note

 that if such graph has $n$ vertices, it will have exactly $n$ edges.

Alice and Bob take turn. Alice goes first. In each turn, the player can choose $k$ ($l \le k \le r$; $l < r$) vertices that form a connected subgraph and erase these vertices from the graph, including all incident edges.

The player who can't make a step loses.

For example, suppose they are playing on the given graph with given $l = 2$ and $r = 3$:

 ![](images/f875bcaf87a1f81c770d9a24d25b0984d9b9f042.png) A valid vertex set for Alice to choose at the first move is one of the following: 

* $\{1, 2\}$
* $\{1, 3\}$
* $\{2, 3\}$
* $\{4, 5\}$
* $\{4, 6\}$
* $\{5, 6\}$
* $\{1, 2, 3\}$
* $\{4, 5, 6\}$

 Suppose, Alice chooses subgraph $\{4, 6\}$.Then a valid vertex set for Bob to choose at the first move is one of the following: 

* $\{1, 2\}$
* $\{1, 3\}$
* $\{2, 3\}$
* $\{1, 2, 3\}$

 Suppose, Bob chooses subgraph $\{1, 2, 3\}$.Alice can't make a move, so she loses.

You are given a graph of size $n$ and integers $l$ and $r$. Who will win if both Alice and Bob play optimally.

##### Input

The first line contains three integers $n$, $l$ and $r$ ($3 \le n \le 2 \cdot 10^5$; $1 \le l < r \le n$) — the number of vertices in the graph, and the constraints on the number of vertices Alice or Bob can choose in one move.

Next $n$ lines contains edges of the graph: one edge per line. The $i$-th line contains two integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$; $u_i \neq v_i$) — description of the $i$-th edge.

It's guaranteed that the degree of each vertex of the given graph is equal to $2$.

##### Output

Print Alice (case-insensitive) if Alice wins, or Bob otherwise.

## Examples

##### Input


```text
6 2 3
1 2
2 3
3 1
4 5
5 6
6 4
```
##### Output


```text
Bob
```
##### Input


```text
6 1 2
1 2
2 3
3 1
4 5
5 6
6 4
```
##### Output


```text
Bob
```
##### Input


```text
12 1 3
1 2
2 3
3 1
4 5
5 6
6 7
7 4
8 9
9 10
10 11
11 12
12 8
```
##### Output


```text
Alice
```
## Note

In the first test the same input as in legend is shown.

In the second test the same graph as in legend is shown, but with $l = 1$ and $r = 2$.



#### Tags 

#2500 #NOT OK #brute_force #dp #games #graphs #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_868_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
