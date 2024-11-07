<h1 style='text-align: center;'> F. Juju and Binary String</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The cuteness of a binary string is the number of $\texttt{1}$s divided by the length of the string. For example, the cuteness of $\texttt{01101}$ is $\frac{3}{5}$.

Juju has a binary string $s$ of length $n$. She wants to choose some non-intersecting subsegments of $s$ such that their concatenation has length $m$ and it has the same cuteness as the string $s$. 

More specifically, she wants to find two arrays $l$ and $r$ of equal length $k$ such that $1 \leq l_1 \leq r_1 < l_2 \leq r_2 < \ldots < l_k \leq r_k \leq n$, and also:

* $\sum\limits_{i=1}^k (r_i - l_i + 1) = m$;
* The cuteness of $s[l_1,r_1]+s[l_2,r_2]+\ldots+s[l_k,r_k]$ is equal to the cuteness of $s$, where $s[x, y]$ denotes the subsegment $s_x s_{x+1} \ldots s_y$, and $+$ denotes string concatenation.

Juju does not like splitting the string into many parts, so she also wants to minimize the value of $k$. Find the minimum value of $k$ such that there exist $l$ and $r$ that satisfy the constraints above or determine that it is impossible to find such $l$ and $r$ for any $k$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq m \leq n \leq 2 \cdot 10^5$).

The second line of each test case contains a binary string $s$ of length $n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, if there is no valid pair of $l$ and $r$, print $-1$. 

Otherwise, print $k + 1$ lines.

In the first line, print a number $k$ ($1 \leq k \leq m$) — the minimum number of subsegments required.

Then print $k$ lines, the $i$-th should contain $l_i$ and $r_i$ ($1 \leq l_i \leq r_i \leq n$) — the range of the $i$-th subsegment. ## Note

 that you should output the subsegments such that the inequality $l_1 \leq r_1 < l_2 \leq r_2 < \ldots < l_k \leq r_k$ is true.

## Example

## Input


```

44 200118 6110000114 301015 511111
```
## Output


```

1
2 3
2
2 3
5 8
-1
1
1 5

```
## Note

In the first example, the cuteness of $\texttt{0011}$ is the same as the cuteness of $\texttt{01}$.

In the second example, the cuteness of $\texttt{11000011}$ is $\frac{1}{2}$ and there is no subsegment of size $6$ with the same cuteness. So we must use $2$ disjoint subsegments $\texttt{10}$ and $\texttt{0011}$.

In the third example, there are $8$ ways to split the string such that $\sum\limits_{i=1}^k (r_i - l_i + 1) = 3$ but none of them has the same cuteness as $\texttt{0101}$.

In the last example, we don't have to split the string.



#### tags 

#2700 #brute_force #constructive_algorithms #greedy #math 