<h1 style='text-align: center;'> D. Paths on the Tree</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a rooted tree consisting of $n$ vertices. The vertices are numbered from $1$ to $n$, and the root is the vertex $1$. You are also given a score array $s_1, s_2, \ldots, s_n$.

A multiset of $k$ simple paths is called valid if the following two conditions are both true. 

* Each path starts from $1$.
* Let $c_i$ be the number of paths covering vertex $i$. For each pair of vertices $(u,v)$ ($2\le u,v\le n$) that have the same parent, $|c_u-c_v|\le 1$ holds.

 The value of the path multiset is defined as $\sum\limits_{i=1}^n c_i s_i$.It can be shown that it is always possible to find at least one valid multiset. Find the maximum value among all valid multisets.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two space-separated integers $n$ ($2 \le n \le 2 \cdot 10^5$) and $k$ ($1 \le k \le 10^9$) — the size of the tree and the required number of paths.

The second line contains $n - 1$ space-separated integers $p_2,p_3,\ldots,p_n$ ($1\le p_i\le n$), where $p_i$ is the parent of the $i$-th vertex. It is guaranteed that this value describe a valid tree with root $1$.

The third line contains $n$ space-separated integers $s_1,s_2,\ldots,s_n$ ($0 \le s_i \le 10^4$) — the scores of the vertices.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10 ^ 5$.

## Output

For each test case, print a single integer — the maximum value of a path multiset.

## Example

## Input


```

25 41 2 1 36 2 1 5 75 31 2 1 36 6 1 4 10
```
## Output


```

54
56

```
## Note

In the first test case, one of optimal solutions is four paths $1 \to 2 \to 3 \to 5$, $1 \to 2 \to 3 \to 5$, $1 \to 4$, $1 \to 4$, here $c=[4,2,2,2,2]$. The value equals to $4\cdot 6+ 2\cdot 2+2\cdot 1+2\cdot 5+2\cdot 7=54$.

In the second test case, one of optimal solution is three paths $1 \to 2 \to 3 \to 5$, $1 \to 2 \to 3 \to 5$, $1 \to 4$, here $c=[3,2,2,1,2]$. The value equals to $3\cdot 6+ 2\cdot 6+2\cdot 1+1\cdot 4+2\cdot 10=56$.



#### tags 

#1900 #dfs_and_similar #dp #greedy #sortings #trees 