<h1 style='text-align: center;'> C. Trees of Tranquillity</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Soroush and Keshi each have a labeled and rooted tree on $n$ vertices. Both of their trees are rooted from vertex $1$.

Soroush and Keshi used to be at war. After endless decades of fighting, they finally became allies to prepare a Codeforces round. To celebrate this fortunate event, they decided to make a memorial graph on $n$ vertices.

They add an edge between vertices $u$ and $v$ in the memorial graph if both of the following conditions hold: 

* One of $u$ or $v$ is the ancestor of the other in Soroush's tree.
* Neither of $u$ or $v$ is the ancestor of the other in Keshi's tree.

Here vertex $u$ is considered ancestor of vertex $v$, if $u$ lies on the path from $1$ (the root) to the $v$.

Popping out of nowhere, Mashtali tried to find the maximum clique in the memorial graph for no reason. He failed because the graph was too big. 

Help Mashtali by finding the size of the maximum clique in the memorial graph.

As a reminder, clique is a subset of vertices of the graph, each two of which are connected by an edge.

## Input

The first line contains an integer $t$ $(1\le t\le 3 \cdot 10^5)$ — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ $(2\le n\le 3 \cdot 10^5)$.

The second line of each test case contains $n-1$ integers $a_2, \ldots, a_n$ $(1 \le a_i < i)$, $a_i$ being the parent of the vertex $i$ in Soroush's tree.

The third line of each test case contains $n-1$ integers $b_2, \ldots, b_n$ $(1 \le b_i < i)$, $b_i$ being the parent of the vertex $i$ in Keshi's tree.

It is guaranteed that the given graphs are trees.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

## Output

For each test case print a single integer — the size of the maximum clique in the memorial graph.

## Example

## Input


```

4
4
1 2 3
1 2 3
5
1 2 3 4
1 1 1 1
6
1 1 1 1 2
1 2 1 2 2
7
1 1 3 4 4 5
1 2 1 4 2 5

```
## Output


```

1
4
1
3

```
## Note

In the first and third test cases, you can pick any vertex.

In the second test case, one of the maximum cliques is $\{2, 3, 4, 5\}$.

In the fourth test case, one of the maximum cliques is $\{3, 4, 6\}$.



#### tags 

#2300 #data_structures #dfs_and_similar #greedy #trees 