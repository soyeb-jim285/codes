<h1 style='text-align: center;'> E. Best Pair</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$. Let $cnt_x$ be the number of elements from the array which are equal to $x$. Let's also define $f(x, y)$ as $(cnt_x + cnt_y) \cdot (x + y)$.

Also you are given $m$ bad pairs $(x_i, y_i)$. 
## Note

 that if $(x, y)$ is a bad pair, then $(y, x)$ is also bad.

Your task is to find the maximum value of $f(u, v)$ over all pairs $(u, v)$, such that $u \neq v$, that this pair is not bad, and also that $u$ and $v$ each occur in the array $a$. It is guaranteed that such a pair exists.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10\,000$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($2 \le n \le 3 \cdot 10^5$, $0 \le m \le 3 \cdot 10^5$) — the length of the array and the number of bad pairs.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — elements of the array.

The $i$-th of the next $m$ lines contains two integers $x_i$ and $y_i$ ($1 \le x_i < y_i \le 10^9$), which represent a bad pair. It is guaranteed that no bad pair occurs twice in the input. It is also guaranteed that $cnt_{x_i} > 0$ and $cnt_{y_i} > 0$.

It is guaranteed that for each test case there is a pair of integers $(u, v)$, $u \ne v$, that is not bad, and such that both of these numbers occur in $a$.

It is guaranteed that the total sum of $n$ and the total sum of $m$ don't exceed $3 \cdot 10^5$.

### Output

For each test case print a single integer — the answer to the problem.

## Example

### Input


```text
36 16 3 6 7 3 33 62 03 47 41 2 2 3 1 5 11 53 51 32 5
```
### Output

```text

40
14
15

```
## Note

In the first test case $3$, $6$, $7$ occur in the array. 

* $f(3, 6) = (cnt_3 + cnt_6) \cdot (3 + 6) = (3 + 2) \cdot (3 + 6) = 45$. But $(3, 6)$ is bad so we ignore it.
* $f(3, 7) = (cnt_3 + cnt_7) \cdot (3 + 7) = (3 + 1) \cdot (3 + 7) = 40$.
* $f(6, 7) = (cnt_6 + cnt_7) \cdot (6 + 7) = (2 + 1) \cdot (6 + 7) = 39$.

The answer to the problem is $\max(40, 39) = 40$.



#### Tags 

#2100 #NOT OK #binary_search #brute_force #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_19.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
