<h1 style='text-align: center;'> D. Edge Elimination</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a tree (connected, undirected, acyclic graph) with $n$ vertices. Two edges are adjacent if they share exactly one endpoint. In one move you can remove an arbitrary edge, if that edge is adjacent to an even number of remaining edges.

Remove all of the edges, or determine that it is impossible. If there are multiple solutions, print any.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of vertices in the tree.

Then $n-1$ lines follow. The $i$-th of them contains two integers $u_i$, $v_i$ ($1 \le u_i,v_i \le n$) the endpoints of the $i$-th edge. It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case print "NO" if it is impossible to remove all the edges.

Otherwise print "YES", and in the next $n-1$ lines print a possible order of the removed edges. For each edge, print its endpoints in any order.

## Example

## Input


```

5
2
1 2
3
1 2
2 3
4
1 2
2 3
3 4
5
1 2
2 3
3 4
3 5
7
1 2
1 3
2 4
2 5
3 6
3 7

```
## Output


```

YES
2 1
NO
YES
2 3
3 4
2 1
YES
3 5
2 3
2 1
4 3
NO
```
## Note

Test case $1$: it is possible to remove the edge, because it is not adjacent to any other edge.

Test case $2$: both edges are adjacent to exactly one edge, so it is impossible to remove any of them. So the answer is "NO".

Test case $3$: the edge $2-3$ is adjacent to two other edges. So it is possible to remove it. After that removal it is possible to remove the remaining edges too.



#### tags 

#2900 #constructive_algorithms #dfs_and_similar #dp #trees 