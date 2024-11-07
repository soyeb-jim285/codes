<h1 style='text-align: center;'> F. Maximize the Difference</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For an array $b$ of $m$ non-negative integers, define $f(b)$ as the maximum value of $\max\limits_{i = 1}^{m} (b_i | x) - \min\limits_{i = 1}^{m} (b_i | x)$ over all possible non-negative integers $x$, where $|$ is [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

You are given integers $n$ and $q$. You start with an empty array $a$. Process the following $q$ queries:

* $v$: append $v$ to the back of $a$ and then output $f(a)$. It is guaranteed that $0 \leq v < n$.

The queries are given in a modified way.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2 \cdot 10^5$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($1 \leq n \leq 2^{22}$, $1 \leq q \leq 10^6$) — the number of queries.

The second line of each test case contains $q$ space-separated integers $e_1,e_2,\ldots,e_q$ ($0 \leq e_i < n$) — the encrypted values of $v$.

Let $\mathrm{last}_i$ equal the output of the $(i-1)$-th query for $i\geq 2$ and $\mathrm{last}_i=0$ for $i=1$. Then the value of $v$ for the $i$-th query is ($e_i + \mathrm{last}_i$) modulo $n$. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $2^{22}$ and the sum of $q$ over all test cases does not exceed $10^6$.

### Output

For each test case, print $q$ integers. The $i$-th integer is the output of the $i$-th query.

## Example

### Input


```text
25 21 27 43 1 5 2
```
### Output

```text

0 2
0 2 3 5

```
## Note

In the first test case, the final $a=[1,2]$. For $i=1$, the answer is always $0$, irrespective of $x$. For $i=2$, we can select $x=5$.

In the second test case, the final $a=[3,1,0,5]$.



#### Tags 

#2700 #NOT OK #bitmasks #brute_force #dfs_and_similar 

## Blogs
- [All Contest Problems](../think-cell_Round_1.md)
- [think-cell Round 1 (en)](../blogs/think-cell_Round_1_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Discussion (en)](../blogs/Discussion_(en).md)
