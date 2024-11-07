<h1 style='text-align: center;'> I. Neighbour Ordering</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an undirected graph $G$, we say that a neighbour ordering is an ordered list of all the neighbours of a vertex for each of the vertices of $G$. Consider a given neighbour ordering of $G$ and three vertices $u$, $v$ and $w$, such that $v$ is a neighbor of $u$ and $w$. We write $u <_{v} w$ if $u$ comes after $w$ in $v$'s neighbor list.

A neighbour ordering is said to be good if, for each simple cycle $v_1, v_2, \ldots, v_c$ of the graph, one of the following is satisfied:

* $v_1 <_{v_2} v_3, v_2 <_{v_3} v_4, \ldots, v_{c-2} <_{v_{c-1}} v_c, v_{c-1} <_{v_c} v_1, v_c <_{v_1} v_2$.
* $v_1 >_{v_2} v_3, v_2 >_{v_3} v_4, \ldots, v_{c-2} >_{v_{c-1}} v_c, v_{c-1} >_{v_c} v_1, v_c >_{v_1} v_2$.

Given a graph $G$, determine whether there exists a good neighbour ordering for it and construct one if it does.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($2 \leq n \leq 3 \cdot 10^5$, $1 \leq m \leq 3 \cdot 10^5$), the number of vertices and the number of edges of the graph.

The next $m$ lines each contain two integers $u, v$ ($0 \leq u, v < n$), denoting that there is an edge connecting vertices $u$ and $v$. It is guaranteed that the graph is connected and there are no loops or multiple edges between the same vertices.

The sum of $n$ and the sum of $m$ for all test cases are at most $3 \cdot 10^5$.

## Output

For each test case, output one line with YES if there is a good neighbour ordering, otherwise output one line with NO. You can print each letter in any case (upper or lower).

If the answer is YES, additionally output $n$ lines describing a good neighbour ordering. In the $i$-th line, output the neighbours of vertex $i$ in order. 

If there are multiple good neigbour orderings, print any.

## Example

## Input


```

35 60 10 21 22 33 44 12 10 16 100 12 00 30 41 21 42 32 53 54 5
```
## Output


```

YES
1 2 
4 2 0 
0 1 3 
2 4 
3 1 
YES
1 
0 
NO

```


#### tags 

#3500 #constructive_algorithms #graphs 