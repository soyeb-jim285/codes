<h1 style='text-align: center;'> F. Madoka and The First Session</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Oh no, on the first exam Madoka got this hard problem:

Given integer $n$ and $m$ pairs of integers ($v_i, u_i$). Also there is an array $b_1, b_2, \ldots, b_n$, initially filled with zeros.

Then for each index $i$, where $1 \leq i \leq m$, perform either $b_{v_i} := b_{v_i} - 1$ and $b_{u_i} := b_{u_i} + 1$, or $b_{v_i} := b_{v_i} + 1$ and $b_{u_i} := b_{u_i} - 1$. 
## Note

 that exactly one of these operations should be performed for every $i$.

Also there is an array $s$ of length $n$ consisting of $0$ and $1$. And there is an array $a_1, a_2, \ldots, a_n$, where it is guaranteed, that if $s_i = 0$ holds, then $a_i = 0$.

Help Madoka and determine whenever it is possible to perform operations in such way that for every $i$, where $s_i = 1$ it holds that $a_i = b_i$. If it possible you should also provide Madoka with a way to perform operations.

##### Input

The first line contains two integers $n$ and $m$ ($2 \leq n \leq 10000, 1 \leq m \leq 10000$) — the length of the array $a$ and the number of pair of integers.

The second line contains $n$ integers $s_1, s_2, \ldots s_n$ ($0 \le s_i \le 1$) — the elements of the array $s$.

The third line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \leq m$) — the elements of the array $a$. It is guaranteed that if $s_i = 0$ holds, then $a_i = 0$.

$i$-th of the following $m$ lines contains two integers $v_i$ and $u_i$ ($1 \leq v_i, u_i \leq n, v_i \ne u_i$) — the indexes of the elements of the array $b$ to which the operation is performed. It is also guaranteed that there are no two indices $i$ and $j$, where $1 \le i < j \le m$, such that $(v_i, u_i) = (v_j, u_j)$ or $(v_i, u_i) = (u_j, v_j)$.

##### Output

In the first line print "YES" if it is possible to perform operations in the required way, and "NO" otherwise.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

In case you printed "YES", print $m$ pairs of integers. If for pair $(v_i, u_i)$ we should perform $b_{v_i} := b_{v_i} - 1$ and $b_{u_i} := b_{u_i} + 1$, print $(v_i, u_i)$. Otherwise print $(u_i, v_i)$. If there are multiple ways to get the correct answer, you can print any of them.

You can print pairs in any order.

## Examples

##### Input


```text
5 5
1 1 1 1 1
-2 0 2 1 -1
1 5
1 4
3 5
3 4
4 5
```
##### Output


```text
YES
1 5
1 4
5 3
4 3
5 4
```
##### Input


```text
5 5
0 1 0 1 0
0 1 0 0 0
1 3
2 3
3 5
3 4
4 5
```
##### Output


```text
YES
3 1
3 2
5 3
3 4
4 5
```
##### Input


```text
4 4
1 1 1 1
0 2 -2 2
1 3
1 4
2 3
2 4
```
##### Output


```text
NO
```
## Note

In the first example, the array $b$ will change as follows: $[0,0,0,0,0] \rightarrow [-1,0,0,1,0] \rightarrow [-2,0,0,1,1] \rightarrow [-2,0,1,0,1] \rightarrow [-2,0,2,0,0] \rightarrow [-2,0,2,1,-1]$. $a_i = b_i$ for all indices $i$ from $1$ to $5$.

In the second example, it is enough for us that $b_2 = 1$ at the end, since only $s_2 = 1$.

In the third example, the operations cannot be performed as required.



#### Tags 

#2500 #NOT OK #constructive_algorithms #flows #graph_matchings #graphs #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_818_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
