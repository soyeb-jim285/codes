<h1 style='text-align: center;'> C. Tree Compass</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree with $n$ vertices numbered $1, 2, \ldots, n$. Initially, all vertices are colored white.

You can perform the following two-step operation: 

1. Choose a vertex $v$ ($1 \leq v \leq n$) and a distance $d$ ($0 \leq d \leq n-1$).
2. For all vertices $u$ ($1 \leq u \leq n$) such that $\text{dist}^\dagger(u,v)=d$, color $u$ black.

Construct a sequence of operations to color all the nodes in the tree black using the minimum possible number of operations. It can be proven that it is always possible to do so using at most $n$ operations.

$^\dagger$ $\text{dist}(x, y)$ denotes the number of edges on the (unique) simple path between vertices $x$ and $y$ on the tree.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 200$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^3$) — the number of vertices of the tree.

The following $n - 1$ lines of each test case describe the edges of the tree. The $i$-th of these lines contains two integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$, $u_i \neq v_i$), the indices of the vertices connected by the $i$-th edge.

It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^3$.

## Output

For each test case, first output a single integer $op$ $(1 \le op \le n)$, the minimum number of operations needed to color all vertices of the tree black.

Then, output $op$ lines, each containing $2$ integers. The $i$-th line should contain the values of $v$ and $d$ chosen for the $i$-th operation ($1 \le v \le n$, $0 \le d \le n - 1$)

You must guarantee that at the end of $op$ operations, all vertices are colored black.

If there are multiple solutions, you may output any one of them.

## Example

## Input


```

4121 241 21 31 472 73 26 45 71 66 7
```
## Output


```

1
1 0
2
1 1
2 1
2
1 1
2 1
3
6 1
7 1
2 1
```
## Note

In the first test case, there is only one possible operation, and performing it gives us a valid answer.

In the second test case, the first operation colors vertex $2$ black, and the second operation colors vertex $1$ black. It can be shown that it is impossible to color both vertices black in one operation, so the minimum number of operations needed is $2$. Another possible solution is to use the $2$ operations: $(u, r) = (1, 0)$ and $(u, r) = (2, 0)$.

In the third test case, the first operation colors vertices $2$, $3$ and $4$ black, and the second operation colors vertex $1$ black. Again, it can be shown that it is impossible to color all vertices black in $1$ operation, so the minimum number of operations needed is $2$.

In the fourth test case, the first operation colors vertices $4$, $1$ and $7$ black, the second operation colors vertices $2$, $5$ and $6$ black while the third operation colors vertices $3$ and $7$ black. Notice that it is allowed to color vertex $7$ black twice.

Thus, each node was marked at least once, with node $7$ marked twice. It can be shown that it is impossible to color all vertices black in fewer than $3$ moves.



#### tags 

#2300 #constructive_algorithms #dfs_and_similar #greedy #trees 