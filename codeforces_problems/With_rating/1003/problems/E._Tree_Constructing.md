<h1 style='text-align: center;'> E. Tree Constructing</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $n$, $d$ and $k$.

Your task is to construct an undirected tree on $n$ vertices with diameter $d$ and degree of each vertex at most $k$, or say that it is impossible.

An undirected tree is a connected undirected graph with $n - 1$ edges.

Diameter of a tree is the maximum length of a simple path (a path in which each vertex appears at most once) between all pairs of vertices of this tree.

Degree of a vertex is the number of edges incident to this vertex (i.e. for a vertex $u$ it is the number of edges $(u, v)$ that belong to the tree, where $v$ is any other vertex of a tree).

###### Input

The first line of the input contains three integers $n$, $d$ and $k$ ($1 \le n, d, k \le 4 \cdot 10^5$).

###### Output

If there is no tree satisfying the conditions above, print only one word "NO" (without quotes).

Otherwise in the first line print "YES" (without quotes), and then print $n - 1$ lines describing edges of a tree satisfying the conditions above. Vertices of the tree must be numbered from $1$ to $n$. You can print edges and vertices connected by an edge in any order. If there are multiple answers, print any of them.1

## Examples

###### Input


```text
6 3 3  

```
###### Output


```text
YES  
3 1  
4 1  
1 2  
5 2  
2 6  

```
###### Input


```text
6 2 3  

```
###### Output


```text
NO  

```
###### Input


```text
10 4 3  

```
###### Output


```text
YES  
2 9  
2 10  
10 3  
3 1  
6 10  
8 2  
4 3  
5 6  
6 7  

```
###### Input


```text
8 5 3  

```
###### Output


```text
YES  
2 5  
7 2  
3 7  
3 1  
1 6  
8 7  
4 3  

```


#### Tags 

#2100 #NOT OK #constructive_algorithms #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_494_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
