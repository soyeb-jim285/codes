<h1 style='text-align: center;'> G. The Awesomest Vertex</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a rooted tree on $n$ vertices. The vertices are numbered from $1$ to $n$; the root is the vertex number $1$.

Each vertex has two integers associated with it: $a_i$ and $b_i$. We denote the set of all ancestors of $v$ (including $v$ itself) by $R(v)$. The awesomeness of a vertex $v$ is defined as 

$$\left| \sum_{w \in R(v)} a_w\right| \cdot \left|\sum_{w \in R(v)} b_w\right|,$$

where $|x|$ denotes the absolute value of $x$. 

Process $q$ queries of one of the following forms: 

* 1 v x — increase $a_v$ by a positive integer $x$.
* 2 v — report the maximum awesomeness in the subtree of vertex $v$.
## Input

The first line contains two integers $n$ and $q$ ($1 \leq n \leq 2\cdot 10^5, 1 \leq q \leq 10^5$) — the number of vertices in the tree and the number of queries, respectively.

The second line contains $n - 1$ integers $p_2, p_3, \dots, p_n$ ($1 \leq p_i < i$), where $p_i$ means that there is an edge between vertices $i$ and $p_i$.

The third line contains $n$ integers $a_1, a_2, \dots, a_n$ ($-5000 \leq a_i \leq 5000$), the initial values of $a_i$ for each vertex.

The fourth line contains $n$ integers $b_1, b_2, \dots, b_n$ ($-5000 \leq b_i \leq 5000$), the values of $b_i$ for each vertex.

Each of the next $q$ lines describes a query. It has one of the following forms: 

* 1 v x  ($1 \leq v \leq n$, $1\leq x \leq 5000$).
* 2 v  ($1 \leq v \leq n$).
## Output

For each query of the second type, print a single line with the maximum awesomeness in the respective subtree.

## Example

## Input


```
5 6  
1 1 2 2  
10 -3 -7 -3 -10  
10 3 9 3 6  
2 1  
2 2  
1 2 6  
2 1  
1 2 5  
2 1  

```
## Output


```
100  
91  
169  
240  

```
## Note

The initial awesomeness of the vertices is $[100, 91, 57, 64, 57]$. The most awesome vertex in the subtree of vertex $1$ (the first query) is $1$, and the most awesome vertex in the subtree of vertex $2$ (the second query) is $2$. 

After the first update (the third query), the awesomeness changes to $[100, 169, 57, 160, 57]$ and thus the most awesome vertex in the whole tree (the fourth query) is now $2$.

After the second update (the fifth query), the awesomeness becomes $[100, 234, 57, 240, 152]$, hence the most awesome vertex (the sixth query) is now $4$. 



#### tags 

#3000 #data_structures #dfs_and_similar 