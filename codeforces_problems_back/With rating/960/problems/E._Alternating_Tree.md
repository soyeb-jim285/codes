<h1 style='text-align: center;'> E. Alternating Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a tree with $n$ nodes numbered from $1$ to $n$. Each node $i$ has an associated value $V_i$.

If the simple path from $u_1$ to $u_m$ consists of $m$ nodes namely $u_1 \rightarrow u_2 \rightarrow u_3 \rightarrow \dots u_{m-1} \rightarrow u_{m}$, then its alternating function $A(u_{1},u_{m})$ is defined as $A(u_{1},u_{m}) = \sum\limits_{i=1}^{m} (-1)^{i+1} \cdot V_{u_{i}}$. A path can also have $0$ edges, i.e. $u_{1}=u_{m}$.

Compute the sum of alternating functions of all unique simple paths. ## Note

 that the paths are directed: two paths are considered different if the starting vertices differ or the ending vertices differ. The answer may be large so compute it modulo $10^{9}+7$. 

## Input

The first line contains an integer $n$ $(2 \leq n \leq 2\cdot10^{5} )$ — the number of vertices in the tree.

The second line contains $n$ space-separated integers $V_1, V_2, \ldots, V_n$ ($-10^9\leq V_i \leq 10^9$) — values of the nodes.

The next $n-1$ lines each contain two space-separated integers $u$ and $v$ $(1\leq u, v\leq n, u \neq v)$ denoting an edge between vertices $u$ and $v$. It is guaranteed that the given graph is a tree.

## Output

Print the total sum of alternating functions of all unique simple paths modulo $10^{9}+7$. 

## Examples

## Input


```
4  
-4 1 5 -2  
1 2  
1 3  
1 4  

```
## Output


```
40  

```
## Input


```
8  
-2 6 -4 -4 -9 -3 -7 23  
8 2  
2 3  
1 4  
6 5  
7 6  
4 7  
5 8  

```
## Output


```
4  

```
## Note

Consider the first example.

A simple path from node $1$ to node $2$: $1 \rightarrow 2$ has alternating function equal to $A(1,2) = 1 \cdot (-4)+(-1) \cdot 1 = -5$.

A simple path from node $1$ to node $3$: $1 \rightarrow 3$ has alternating function equal to $A(1,3) = 1 \cdot (-4)+(-1) \cdot 5 = -9$.

A simple path from node $2$ to node $4$: $2 \rightarrow 1 \rightarrow 4$ has alternating function $A(2,4) = 1 \cdot (1)+(-1) \cdot (-4)+1 \cdot (-2) = 3$.

A simple path from node $1$ to node $1$ has a single node $1$, so $A(1,1) = 1 \cdot (-4) = -4$.

Similarly, $A(2, 1) = 5$, $A(3, 1) = 9$, $A(4, 2) = 3$, $A(1, 4) = -2$, $A(4, 1) = 2$, $A(2, 2) = 1$, $A(3, 3) = 5$, $A(4, 4) = -2$, $A(3, 4) = 7$, $A(4, 3) = 7$, $A(2, 3) = 10$, $A(3, 2) = 10$. So the answer is $(-5) + (-9) + 3 + (-4) + 5 + 9 + 3 + (-2) + 2 + 1 + 5 + (-2) + 7 + 7 + 10 + 10 = 40$.

Similarly $A(1,4)=-2, A(2,2)=1, A(2,1)=5, A(2,3)=10, A(3,3)=5, A(3,1)=9, A(3,2)=10, A(3,4)=7, A(4,4)=-2, A(4,1)=2, A(4,2)=3 , A(4,3)=7$ which sums upto 40. 



#### tags 

#2300 #combinatorics #dfs_and_similar #divide_and_conquer #dp #probabilities #trees 