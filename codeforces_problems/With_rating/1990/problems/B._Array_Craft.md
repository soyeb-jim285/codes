<h1 style='text-align: center;'> B. Array Craft</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For an array $b$ of size $m$, we define:

* the maximum prefix position of $b$ is the smallest index $i$ that satisfies $b_1+\ldots+b_i=\max_{j=1}^{m}(b_1+\ldots+b_j)$;
* the maximum suffix position of $b$ is the largest index $i$ that satisfies $b_i+\ldots+b_m=\max_{j=1}^{m}(b_j+\ldots+b_m)$.

You are given three integers $n$, $x$, and $y$ ($x > y$). Construct an array $a$ of size $n$ satisfying:

* $a_i$ is either $1$ or $-1$ for all $1 \le i \le n$;
* the maximum prefix position of $a$ is $x$;
* the maximum suffix position of $a$ is $y$.

If there are multiple arrays that meet the conditions, print any. It can be proven that such an array always exists under the given conditions.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

For each test case: 

* The only line contains three integers $n$, $x$, and $y$ ($2 \leq n \leq 10^5, 1 \le y \lt x \le n)$.

It is guaranteed that the sum of $n$ over all test cases will not exceed $10^5$.

### Output

For each test case, output $n$ space-separated integers $a_1, a_2, \ldots, a_n$ in a new line.

## Example

### Input


```text
32 2 14 4 36 5 1
```
### Output

```text

1 1
1 -1 1 1
1 1 -1 1 1 -1
```
## Note

In the second test case, 

* $i=x=4$ is the smallest index that satisfies $a_1+\ldots +a_i=\max_{j=1}^{n}(a_1+\ldots+a_j)=2$;
* $i=y=3$ is the greatest index that satisfies $a_i+\ldots +a_n=\max_{j=1}^{n}(a_j+\ldots+a_n)=2$.

Thus, the array $a=[1,-1,1,1]$ is considered correct.



#### Tags 

#1200 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_960_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
