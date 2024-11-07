<h1 style='text-align: center;'> F. Graph Without Long Directed Paths</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a connected undirected graph consisting of $n$ vertices and $m$ edges. There are no self-loops or multiple edges in the given graph.

You have to direct its edges in such a way that the obtained directed graph does not contain any paths of length two or greater (where the length of path is denoted as the number of traversed edges).

### Input

The first line contains two integer numbers $n$ and $m$ ($2 \le n \le 2 \cdot 10^5$, $n - 1 \le m \le 2 \cdot 10^5$) — the number of vertices and edges, respectively.

The following $m$ lines contain edges: edge $i$ is given as a pair of vertices $u_i$, $v_i$ ($1 \le u_i, v_i \le n$, $u_i \ne v_i$). There are no multiple edges in the given graph, i. e. for each pair ($u_i, v_i$) there are no other pairs ($u_i, v_i$) and ($v_i, u_i$) in the list of edges. It is also guaranteed that the given graph is connected (there is a path between any pair of vertex in the given graph).

### Output

If it is impossible to direct edges of the given graph in such a way that the obtained directed graph does not contain paths of length at least two, print "NO" in the first line.

Otherwise print "YES" in the first line, and then print any suitable orientation of edges: a binary string (the string consisting only of '0' and '1') of length $m$. The $i$-th element of this string should be '0' if the $i$-th edge of the graph should be directed from $u_i$ to $v_i$, and '1' otherwise. Edges are numbered in the order they are given in the input.

## Example

### Input


```text
6 5
1 5
2 1
1 4
3 1
6 1
```
### Output


```text
YES
10100
```
## Note

The picture corresponding to the first example: ![](images/d38084716d7214e4107c06dac7fa126636937855.png)

And one of possible answers: ![](images/6134e1d8526f4a574a8a2456fd040e1de8f892b8.png)



#### Tags 

#1700 #NOT OK #dfs_and_similar #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_550_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
