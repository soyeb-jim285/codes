<h1 style='text-align: center;'> D. Explorer Space</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are wandering in the explorer space of the 2050 Conference.

The explorer space can be viewed as an undirected weighted grid graph with size $n\times m$. The set of vertices is $\{(i, j)|1\le i\le n, 1\le j\le m\}$. Two vertices $(i_1,j_1)$ and $(i_2, j_2)$ are connected by an edge if and only if $|i_1-i_2|+|j_1-j_2|=1$.

At each step, you can walk to any vertex connected by an edge with your current vertex. On each edge, there are some number of exhibits. Since you already know all the exhibits, whenever you go through an edge containing $x$ exhibits, your boredness increases by $x$.

For each starting vertex $(i, j)$, please answer the following question: What is the minimum possible boredness if you walk from $(i, j)$ and go back to it after exactly $k$ steps?

You can use any edge for multiple times but the boredness on those edges are also counted for multiple times. At each step, you cannot stay on your current vertex. You also cannot change direction while going through an edge. Before going back to your starting vertex $(i, j)$ after $k$ steps, you can visit $(i, j)$ (or not) freely.

##### Input

The first line contains three integers $n$, $m$ and $k$ ($2\leq n, m\leq 500, 1\leq k\leq 20$).

The $j$-th number ($1\le j \le m - 1$) in the $i$-th line of the following $n$ lines is the number of exibits on the edge between vertex $(i, j)$ and vertex $(i, j+1)$. 

The $j$-th number ($1\le j\le m$) in the $i$-th line of the following $n-1$ lines is the number of exibits on the edge between vertex $(i, j)$ and vertex $(i+1, j)$. 

The number of exhibits on each edge is an integer between $1$ and $10^6$.

##### Output

##### Output

 $n$ lines with $m$ numbers each. The $j$-th number in the $i$-th line, $answer_{ij}$, should be the minimum possible boredness if you walk from $(i, j)$ and go back to it after exactly $k$ steps.

If you cannot go back to vertex $(i, j)$ after exactly $k$ steps, $answer_{ij}$ should be $-1$. 

## Examples

##### Input


```text
3 3 10
1 1
1 1
1 1
1 1 1
1 1 1
```
##### Output


```text
10 10 10
10 10 10
10 10 10
```
##### Input


```text
2 2 4
1
3
4 2
```
##### Output


```text
4 4
10 6
```
##### Input


```text
2 2 3
1
2
3 4
```
##### Output


```text
-1 -1
-1 -1
```
## Note

In the first example, the answer is always $10$ no matter how you walk.

In the second example, $answer_{21} = 10$, the path is $(2,1) \to (1,1) \to (1,2) \to (2,2) \to (2,1)$, the boredness is $4 + 1 + 2 + 3 = 10$.



#### Tags 

#1800 #NOT OK #dp #graphs #shortest_paths 

## Blogs
- [All Contest Problems](../Contest_2050_and_Codeforces_Round_718_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
