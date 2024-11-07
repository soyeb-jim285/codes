<h1 style='text-align: center;'> F. Yet Another Problem About Pairs Satisfying an Inequality</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \dots a_n$. Count the number of pairs of indices $1 \leq i, j \leq n$ such that $a_i < i < a_j < j$.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains an integer $n$ ($2 \leq n \leq 2 \cdot 10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \leq a_i \leq 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ across all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the number of pairs of indices satisfying the condition in the statement.

Please note, that the answer for some test cases won't fit into 32-bit integer type, so you should use at least 64-bit integer type in your programming language (like long long for C++).

## Example

### Input


```text
581 1 2 3 8 2 1 421 2100 2 1 6 3 4 1 2 8 321 100000000030 1000000000 2
```
### Output

```text

3
0
10
0
1

```
## Note

For the first test cases the pairs are $(i, j)$ = $\{(2, 4), (2, 8), (3, 8)\}$. 

* The pair $(2, 4)$ is true because $a_2 = 1$, $a_4 = 3$ and $1 < 2 < 3 < 4$.
* The pair $(2, 8)$ is true because $a_2 = 1$, $a_8 = 4$ and $1 < 2 < 4 < 8$.
* The pair $(3, 8)$ is true because $a_3 = 2$, $a_8 = 4$ and $2 < 3 < 4 < 8$.


#### Tags 

#1300 #OK #binary_search #data_structures #dp #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_806_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
