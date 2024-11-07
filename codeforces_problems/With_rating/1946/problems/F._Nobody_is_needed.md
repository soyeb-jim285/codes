<h1 style='text-align: center;'> F. Nobody is needed</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Oleg received a permutation $a$ of length $n$ as a birthday present.

Oleg's friend Nechipor asks Oleg $q$ questions, each question is characterized by two numbers $l$ and $r$, in response to the question Oleg must say the number of sets of indices $(t_1, t_2, \ldots, t_k)$ of any length $k \ge 1$ such that: 

* $l \le t_i \le r$ for each $i$ from $1$ to $k$.
* $t_i < t_{i+1}$ for each $i$ from $1$ to $k-1$.
* $a_{t_{i+1}}$ is divisible by $a_{t_i}$ for each $i$ from $1$ to $k-1$.

Help Oleg and answer all of Nechipor's questions.

### Input

Each test consists of several sets of input data. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of sets of input data. The description of the sets of input data follows.

The first line of each set of input data contains two integers $n$ and $q$ ($1 \le n, q \le 10^6$) — the length of the permutation and the number of Nechipor's questions.

The second line of each set of input data contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — the permutation $a$ itself.

In each of the next $q$ lines of each set of input data, there are two integers $l$ and $r$ ($1 \le l \le r \le n$) — the next question of Nechipor.

It is guaranteed that the sum of the values of $n$ and the sum of the values of $q$ over all test cases does not exceed $10^6$.

### Output

For each set of input data, output the answers to all of Nechipor's questions.

## Example

### Input


```text
48 82 1 6 3 5 4 8 71 82 81 71 61 35 84 42 31 111 13 33 2 11 21 32 38 11 2 3 4 5 6 7 81 8
```
### Output

```text

20 15 18 12 5 5 1 3
1
2 3 2
27

```
## Note

All suitable arrays in the first set of input data: ($1$), ($2$), ($3$), ($4$), ($5$), ($6$), ($7$), ($8$), ($1, 3$), ($1, 6$), ($1, 7$), ($1, 6, 7$), ($2, 3$), ($2, 4$), ($2, 5$), ($2, 6$), ($2, 7$), ($2, 8$), ($2, 6, 7$), ($6, 7$).

All suitable arrays in the fourth set of input data: ($1$), ($2$), ($3$), ($4$), ($5$), ($6$), ($7$), ($8$), ($1, 2$), ($1, 3$), ($1, 4$), ($1, 5$), ($1, 6$), ($1, 7$), ($1, 8$), ($1, 2, 4$), ($1, 2, 6$), ($1, 2, 8$), ($1, 2, 4, 8$), ($1, 3, 6$), ($1, 4, 8$), ($2, 4$), ($2, 6$), ($2, 8$), ($2, 4, 8$), ($3, 6$), ($4, 8$).



#### Tags 

#2500 #NOT OK #2-sat #data_structures #dfs_and_similar #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_936_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
