<h1 style='text-align: center;'> G. Rudolf and Subway</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Building bridges did not help Bernard, and he continued to be late everywhere. Then Rudolf decided to teach him how to use the subway.

Rudolf depicted the subway map as an undirected connected graph, without self-loops, where the vertices represent stations. There is at most one edge between any pair of vertices.

Two vertices are connected by an edge if it is possible to travel directly between the corresponding stations, bypassing other stations. The subway in the city where Rudolf and Bernard live has a color notation. This means that any edge between stations has a specific color. Edges of a specific color together form a subway line. A subway line cannot contain unconnected edges and forms a connected subgraph of the given subway graph.

An example of the subway map is shown in the figure.

 ![](images/31e30f806576f7b01bfd85b0add099f0d5011898.png) Rudolf claims that the route will be optimal if it passes through the minimum number of subway lines.

Help Bernard determine this minimum number for the given departure and destination stations.

#### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

This is followed by descriptions of the test cases.

The first line of each test case contains two integers $n$ and $m$ ($2 \le n \le 2 \cdot 10^5, 1 \le m \le 2 \cdot 10^5$) — the number of subway stations and the number of direct routes between stations (i.e., graph edges).

This is followed by $m$ lines — the description of the edges. Each line of the description contains three integers $u$, $v$, and $c$ ($1 \le u, v \le n, u \ne v, 1 \le c \le 2 \cdot 10^5$) — the numbers of the vertices between which there is an edge, and the color of this edge. It is guaranteed that edges of the same color form a connected subgraph of the given subway graph. There is at most one edge between a pair of any two vertices.

This is followed by two integers $b$ and $e$ ($1 \le b, e \le n$) — the departure and destination stations.

The sum of all $n$ over all test cases does not exceed $2 \cdot 10^5$. The sum of all $m$ over all test cases does not exceed $2 \cdot 10^5$.

#### Output

For each testcase, output a single integer — the minimum number of subway lines through which the route from station $b$ to station $e$ can pass.

## Examples

#### Input


```text
56 61 2 12 3 15 2 22 4 24 6 23 6 31 36 61 2 12 3 15 2 22 4 24 6 23 6 31 66 61 2 12 3 15 2 22 4 24 6 23 6 36 64 31 2 11 3 14 1 12 36 71 2 431 3 344 6 436 3 432 3 435 3 434 5 431 6
```
#### Output

```text

1
2
0
1
1

```
#### Input


```text
37 92 4 13 6 12 3 51 7 14 7 12 5 45 4 43 4 13 7 15 36 56 5 836914 1 836915 4 836913 2 836914 3 836915 16 76 1 836916 2 836912 5 836915 6 836912 3 836915 4 835743 5 836911 4
```
#### Output

```text

2
1
2

```
## Note

The subway graph for the first example is shown in the figure in the problem statement.

In the first test case, from vertex $1$ to vertex $3$, you can travel along the path $1 \rightarrow 2 \rightarrow 3$, using only the green line.

In the second test case, from vertex $1$ to vertex $6$, you can travel along the path $1 \rightarrow 2 \rightarrow 3 \rightarrow 6$, using the green and blue lines.

In the third test case, there is no need to travel from vertex $6$ to the same vertex, so the number of lines is $0$.

In the fourth test case, all edges of the graph belong to one line, so the answer is $1$.



#### Tags 

#2000 #NOT OK #constructive_algorithms #dfs_and_similar #graphs #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_933_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
- [../blogs/https:_codeforces.com_blog_entry_126654.md](../blogs/https:_codeforces.com_blog_entry_126654.md)
