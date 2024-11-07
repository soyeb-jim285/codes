<h1 style='text-align: center;'> B. Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recall that a permutation of length $n$ is an array where each element from $1$ to $n$ occurs exactly once.

For a fixed positive integer $d$, let's define the cost of the permutation $p$ of length $n$ as the number of indices $i$ $(1 \le i < n)$ such that $p_i \cdot d = p_{i + 1}$.

For example, if $d = 3$ and $p = [5, 2, 6, 7, 1, 3, 4]$, then the cost of such a permutation is $2$, because $p_2 \cdot 3 = p_3$ and $p_5 \cdot 3 = p_6$.

Your task is the following one: for a given value $n$, find the permutation of length $n$ and the value $d$ with maximum possible cost (over all ways to choose the permutation and $d$). If there are multiple answers, then print any of them.

### Input

The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases.

The single line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print the value $d$ in the first line, and $n$ integers in the second line — the permutation itself. If there are multiple answers, then print any of them.

## Example

### Input


```text
223
```
### Output

```text

2
1 2
3
2 1 3

```


#### Tags 

#800 #OK #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_131_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
