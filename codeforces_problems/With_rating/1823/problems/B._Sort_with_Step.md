<h1 style='text-align: center;'> B. Sort with Step</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's define a permutation of length $n$ as an array $p$ of length $n$, which contains every number from $1$ to $n$ exactly once.

You are given a permutation $p_1, p_2, \dots, p_n$ and a number $k$. You need to sort this permutation in the ascending order. In order to do it, you can repeat the following operation any number of times (possibly, zero): 

* pick two elements of the permutation $p_i$ and $p_j$ such that $|i - j| = k$, and swap them.

Unfortunately, some permutations can't be sorted with some fixed numbers $k$. For example, it's impossible to sort $[2, 4, 3, 1]$ with $k = 2$.

That's why, before starting the sorting, you can make at most one preliminary exchange: 

* choose any pair $p_i$ and $p_j$ and swap them.

Your task is to: 

1. check whether is it possible to sort the permutation without any preliminary exchanges,
2. if it's not, check, whether is it possible to sort the permutation using exactly one preliminary exchange.

For example, if $k = 2$ and permutation is $[2, 4, 3, 1]$, then you can make a preliminary exchange of $p_1$ and $p_4$, which will produce permutation $[1, 4, 3, 2]$, which is possible to sort with given $k$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2 \le n \le 2 \cdot 10^5$; $1 \le k \le n - 1$) — length of the permutation, and a distance between elements that can be swapped.

The second line of each test case contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \le p_i \le n$) — elements of the permutation $p$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10 ^ 5$.

### Output

For each test case print 

* 0, if it is possible to sort the permutation without preliminary exchange;
* 1, if it is possible to sort the permutation with one preliminary exchange, but not possible without preliminary exchange;
* -1, if it is not possible to sort the permutation with at most one preliminary exchange.
## Example

### Input


```text
64 13 1 2 44 23 4 1 24 23 1 4 210 34 5 9 1 8 6 10 2 3 710 34 6 9 1 8 5 10 2 3 710 34 6 9 1 8 5 10 3 2 7
```
### Output

```text

0
0
1
0
1
-1

```
## Note

In the first test case, there is no need in preliminary exchange, as it is possible to swap $(p_1, p_2)$ and then $(p_2, p_3)$.

In the second test case, there is no need in preliminary exchange, as it is possible to swap $(p_1, p_3)$ and then $(p_2, p_4)$.

In the third test case, you need to apply preliminary exchange to $(p_2, p_3)$. After that the permutation becomes $[3, 4, 1, 2]$ and can be sorted with $k = 2$.



#### Tags 

#900 #OK #brute_force #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_868_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
