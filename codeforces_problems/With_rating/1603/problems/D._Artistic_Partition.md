<h1 style='text-align: center;'> D. Artistic Partition</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

For two positive integers $l$ and $r$ ($l \le r$) let $c(l, r)$ denote the number of integer pairs $(i, j)$ such that $l \le i \le j \le r$ and $\operatorname{gcd}(i, j) \ge l$. Here, $\operatorname{gcd}(i, j)$ is the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $i$ and $j$.

YouKn0wWho has two integers $n$ and $k$ where $1 \le k \le n$. Let $f(n, k)$ denote the minimum of $\sum\limits_{i=1}^{k}{c(x_i+1,x_{i+1})}$ over all integer sequences $0=x_1 \lt x_2 \lt \ldots \lt x_{k} \lt x_{k+1}=n$.

Help YouKn0wWho find $f(n, k)$. 

### Input

The first line contains a single integer $t$ ($1 \le t \le 3 \cdot 10^5$) — the number of test cases.

The first and only line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 10^5$). 

### Output

For each test case, print a single integer — $f(n, k)$.

## Example

### Input


```text
4
6 2
4 4
3 1
10 3
```
### Output


```text
8
4
6
11
```
## Note

In the first test case, YouKn0wWho can select the sequence $[0, 2, 6]$. So $f(6, 2) = c(1, 2) + c(3, 6) = 3 + 5 = 8$ which is the minimum possible.



#### Tags 

#3000 #NOT OK #divide_and_conquer #dp #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_752_(Div._1).md)
- [Codeforces Round #752 (en)](../blogs/Codeforces_Round_752_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
