<h1 style='text-align: center;'> B. K-Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers $a$ of length $n$. 

You can apply the following operation any number of times (maybe, zero): 

* First, choose an integer $k$ such that $1 \le k \le n$ and pay $k + 1$ coins.
* Then, choose exactly $k$ indices such that $1 \le i_1 < i_2 < \ldots < i_k \le n$.
* Then, for each $x$ from $1$ to $k$, increase $a_{i_x}$ by $1$.

Find the minimum number of coins needed to make $a$ non-decreasing. That is, $a_1 \le a_2 \le \ldots \le a_n$.

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output a single integer — the minimum number of coins needed to make $a$ non-decreasing.

## Example

### Input


```text
531 7 952 1 4 7 641 3 2 411799344 12 37 60 311 613 365 328 675
```
### Output

```text

0
3
2
0
1821

```
## Note

In the first test case, $a$ is already sorted, so you don't have to spend any coins.

In the second test case, the optimal sequence of operations is: 

* Choose $k = 2$ and the indices $2$ and $5$: $[ 2, \color{red}{1}, 4, 7, \color{red}{6} ] \rightarrow [2, 2, 4, 7, 7]$. This costs $3$ coins.

 It can be proven that it is not possible to make $a$ non-decreasing by spending less than $3$ coins.

#### Tags 

#1000 #OK #greedy 

## Blogs
- [All Contest Problems](../EPIC_Institute_of_Technology_Round_Summer_2024_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
