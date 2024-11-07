<h1 style='text-align: center;'> C. Set Construction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary matrix $b$ (all elements of the matrix are $0$ or $1$) of $n$ rows and $n$ columns.

You need to construct a $n$ sets $A_1, A_2, \ldots, A_n$, for which the following conditions are satisfied:

* Each set is nonempty and consists of distinct integers between $1$ and $n$ inclusive.
* All sets are distinct.
* For all pairs $(i,j)$ satisfying $1\leq i, j\leq n$, $b_{i,j}=1$ if and only if $A_i\subsetneq A_j$. In other words, $b_{i, j}$ is $1$ if $A_i$ is a proper subset of $A_j$ and $0$ otherwise.

Set $X$ is a proper subset of set $Y$, if $X$ is a nonempty subset of $Y$, and $X \neq Y$.

It's guaranteed that for all test cases in this problem, such $n$ sets exist. 
## Note

 that it doesn't mean that such $n$ sets exist for all possible inputs.

If there are multiple solutions, you can output any of them.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1\le t\le 1000$) — the number of test cases. The description of test cases follows.

The first line contains a single integer $n$ ($1\le n\le 100$).

The following $n$ lines contain a binary matrix $b$, the $j$-th character of $i$-th line denotes $b_{i,j}$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

It's guaranteed that for all test cases in this problem, such $n$ sets exist. 

### Output

For each test case, output $n$ lines.

For the $i$-th line, first output $s_i$ $(1 \le s_i \le n)$  — the size of the set $A_i$. Then, output $s_i$ distinct integers from $1$ to $n$  — the elements of the set $A_i$.

If there are multiple solutions, you can output any of them.

It's guaranteed that for all test cases in this problem, such $n$ sets exist. 

## Example

### Input


```text
2
4
0001
1001
0001
0000
3
011
001
000
```
### Output


```text
3 1 2 3
2 1 3
2 2 4
4 1 2 3 4
1 1
2 1 2
3 1 2 3
```
## Note

In the first test case, we have $A_1 = \{1, 2, 3\}, A_2 = \{1, 3\}, A_3 = \{2, 4\}, A_4 = \{1, 2, 3, 4\}$. Sets $A_1, A_2, A_3$ are proper subsets of $A_4$, and also set $A_2$ is a proper subset of $A_1$. No other set is a proper subset of any other set.

In the second test case, we have $A_1 = \{1\}, A_2 = \{1, 2\}, A_3 = \{1, 2, 3\}$. $A_1$ is a proper subset of $A_2$ and $A_3$, and $A_2$ is a proper subset of $A_3$.



#### Tags 

#1400 #NOT OK #constructive_algorithms #dfs_and_similar #graphs #greedy 

## Blogs
- [All Contest Problems](../Pinely_Round_1_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
