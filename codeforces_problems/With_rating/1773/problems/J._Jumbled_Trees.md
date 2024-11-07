<h1 style='text-align: center;'> J. Jumbled Trees</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an undirected connected graph with $n$ vertices and $m$ edges. Each edge has an associated counter, initially equal to $0$. In one operation, you can choose an arbitrary spanning tree and add any value $v$ to all edges of this spanning tree. 

Determine if it's possible to make every counter equal to its target value $x_i$ modulo prime $p$, and provide a sequence of operations that achieves it.

##### Input

The first line contains three integers $n$, $m$, and $p$ — the number of vertices, the number of edges, and the prime modulus ($1 \le n \le 500$; $1 \le m \le 1000$; $2 \le p \le 10^9$, $p$ is prime).

Next $m$ lines contain three integers $u_i$, $v_i$, $x_i$ each — the two endpoints of the $i$-th edge and the target value of that edge's counter ($1 \le u_i, v_i \le n$; $0 \le x_i < p$; $u_i \neq v_i$). 

The graph is connected. There are no loops, but there may be multiple edges between the same two vertices.

##### Output

If the target values on counters cannot be achieved, print -1. 

Otherwise, print $t$ — the number of operations, followed by $t$ lines, describing the sequence of operations. Each line starts with integer $v$ ($0 \le v < p$) — the counter increment for this operation. Then, in the same line, followed by $n - 1$ integers $e_1$, $e_2$, ... $e_{n - 1}$ ($1 \le e_i \le m$) — the edges of the spanning tree.

The number of operations $t$ should not exceed $2m$. You don't need to minimize $t$. Any correct answer within the $2m$ bound is accepted. You are allowed to repeat spanning trees.

## Examples

##### Input


```text
3 3 101
1 2 30
2 3 40
3 1 50
```
##### Output


```text
3
10 1 2
20 1 3
30 2 3
```
##### Input

```text

2 2 37
1 2 8
1 2 15

```
##### Output


```text
2
8 1
15 2
```
##### Input

```text

5 4 5
1 3 1
2 3 2
2 5 3
4 1 4

```
##### Output


```text
-1
```


#### Tags 

#2900 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../2022-2023_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
