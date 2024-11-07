<h1 style='text-align: center;'> H. Minimize Inversions Number</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of length $n$.

You can choose any subsequence, remove it from the permutation, and insert it at the beginning of the permutation keeping the same order.

For every $k$ from $0$ to $n$, find the minimal possible number of inversions in the permutation after you choose a subsequence of length exactly $k$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 50\,000$) — the number of test cases.

The first line of each test case contains one integer $n$ ($1 \le n \le 5 \cdot 10^5$) — the length of the permutation.

The second line of each test case contains the permutation $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$).

It is guaranteed that the total sum of $n$ doesn't exceed $5 \cdot 10^5$.

### Output

For each test case output $n + 1$ integers. The $i$-th of them must be the answer for the subsequence length of $i - 1$.

## Example

### Input


```text
31144 2 1 355 1 3 2 4
```
### Output

```text

0 0
4 2 2 1 4
5 4 2 2 1 5

```
## Note

In the second test case: 

* For the length $0$: $[4, 2, 1, 3] \rightarrow [4, 2, 1, 3]$: $4$ inversions.
* For the length $1$: $[4, 2, \mathbf{1}, 3] \rightarrow [1, 4, 2, 3]$: $2$ inversions.
* For the length $2$: $[4, \mathbf{2}, \mathbf{1}, 3] \rightarrow [2, 1, 4, 3]$, or $[4, 2, \mathbf{1}, \textbf{3}] \rightarrow [1, 3, 4, 2]$: $2$ inversions.
* For the length $3$: $[4, \mathbf{2}, \mathbf{1}, \mathbf{3}] \rightarrow [2, 1, 3, 4]$: $1$ inversion.
* For the length $4$: $[\mathbf{4}, \mathbf{2}, \mathbf{1}, \mathbf{3}] \rightarrow [4, 2, 1, 3]$: $4$ inversions.


#### Tags 

#3500 #NOT OK #data_structures #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_19.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
