<h1 style='text-align: center;'> C. To Become Max</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers $a$ of length $n$.

In one operation you: 

* Choose an index $i$ such that $1 \le i \le n - 1$ and $a_i \le a_{i + 1}$.
* Increase $a_i$ by $1$.

Find the maximum possible value of $\max(a_1, a_2, \ldots a_n)$ that you can get after performing this operation at most $k$ times.

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2 \le n \le 1000$, $1 \le k \le 10^{8}$) — the length of the array $a$ and the maximum number of operations that can be performed.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le 10^{8}$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

### Output

For each test case output a single integer — the maximum possible maximum of the array after performing at most $k$ operations.

## Example

### Input


```text
63 41 3 35 61 3 4 5 14 131 1 3 1795 34 3 2 2 25 66 5 4 1 52 173 5
```
### Output

```text

4
7
179
5
7
6

```
## Note

In the first test case, one possible optimal sequence of operations is: $[\color{red}{1}, 3, 3] \rightarrow [2, \color{red}{3}, 3] \rightarrow [\color{red}{2}, 4, 3] \rightarrow [\color{red}{3}, 4, 3] \rightarrow [4, 4, 3]$.

In the second test case, one possible optimal sequence of operations is: $[1, \color{red}{3}, 4, 5, 1] \rightarrow [1, \color{red}{4}, 4, 5, 1] \rightarrow [1, 5, \color{red}{4}, 5, 1] \rightarrow [1, 5, \color{red}{5}, 5, 1] \rightarrow [1, \color{red}{5}, 6, 5, 1] \rightarrow [1, \color{red}{6}, 6, 5, 1] \rightarrow [1, 7, 6, 5, 1]$.



#### Tags 

#1600 #NOT OK #binary_search #brute_force #data_structures #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_890_(Div._2)_supported_by_Constructor_Institute.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
