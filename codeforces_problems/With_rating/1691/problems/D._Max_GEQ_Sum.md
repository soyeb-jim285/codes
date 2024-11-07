<h1 style='text-align: center;'> D. Max GEQ Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers. You are asked to find out if the inequality $$\max(a_i, a_{i + 1}, \ldots, a_{j - 1}, a_{j}) \geq a_i + a_{i + 1} + \dots + a_{j - 1} + a_{j}$$ holds for all pairs of indices $(i, j)$, where $1 \leq i \leq j \leq n$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$)  — the size of the array.

The next line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, on a new line output "YES" if the condition is satisfied for the given array, and "NO" otherwise. You can print each letter in any case (upper or lower).

## Example

### Input


```text
34-1 1 -1 25-1 2 -3 2 -132 3 -1
```
### Output

```text

YES
YES
NO

```
## Note

In test cases $1$ and $2$, the given condition is satisfied for all $(i, j)$ pairs. 

In test case $3$, the condition isn't satisfied for the pair $(1, 2)$ as $\max(2, 3) < 2 + 3$.



#### Tags 

#1800 #NOT OK #binary_search #constructive_algorithms #data_structures #divide_and_conquer #implementation #two_pointers 

## Blogs
- [All Contest Problems](../CodeCraft-22_and_Codeforces_Round_795_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
