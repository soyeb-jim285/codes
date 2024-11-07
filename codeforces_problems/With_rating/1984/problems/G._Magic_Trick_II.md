<h1 style='text-align: center;'> G. Magic Trick II</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The secret behind Oscar's first magic trick has been revealed! Because he still wants to impress Lura, he comes up with a new idea: he still wants to sort a permutation $p_1, p_2, \ldots, p_n$ of $[1, 2, \ldots, n]$.

This time, he chooses an integer $k$. He wants to sort the permutation in non-decreasing order using the following operation several times: 

1. Pick a continuous subarray of length $k$ and remove it from $p$.
2. Insert the continuous subarray back into $p$ at any position (perhaps, in the very front or the very back).

To be as impressive as possible, Oscar would like to choose the maximal value of $k$ such that he can sort his permutation. Please help him find the maximal $k$ as well as a sequence of operations that will sort the permutation. You don't need to minimize the number of operations, but you are allowed to use at most $5n^2$ operations.

We have a proof that, for the maximal $k$ such that you can sort the permutation in any number of operations, you can also sort it in at most $5n^2$ operations.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($5 \leq n \leq 10^3$) — the length of the permutation.

The second line of each test case contains a permutation $p_1, p_2, \ldots, p_n$ of $[1, 2, \ldots, n]$.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^3$.

### Output

For each test case, first output the chosen value of $k$ on a new line ($1 \leq k \leq n$).

Then, output a single integer $m$ — the number of operations used ($0 \leq m \leq 5n^2$).

Then, on each of the next $m$ lines, output the operations denoted by two integers $i$ and $j$ ($1 \leq i, j \leq n - k + 1$), representing an operation where you remove the subarray starting from index $i$ and replace it back into $p$ at index $j$.

## Example

### Input


```text
355 1 2 3 452 3 5 4 161 2 3 4 5 6
```
### Output

```text

4
1
2 1
3
2
1 3
2 1
6
0

```
## Note

In the first test case, it is enough to move the last four numbers to the front.

In the second test case, it can be shown that we cannot have $k = 4$ or $k = 5$. With $k = 3$, we can move the first three numbers to the end, and then the middle three to the front to sort the permutation.

In the third test case, the permutation is already sorted. We can have $k = 6$ and use no operations.



#### Tags 

#3200 #NOT OK #constructive_algorithms #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_26.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
