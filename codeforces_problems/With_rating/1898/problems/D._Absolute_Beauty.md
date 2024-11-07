<h1 style='text-align: center;'> D. Absolute Beauty</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kirill has two integer arrays $a_1,a_2,\ldots,a_n$ and $b_1,b_2,\ldots,b_n$ of length $n$. He defines the absolute beauty of the array $b$ as $$\sum_{i=1}^{n} |a_i - b_i|.$$ Here, $|x|$ denotes the absolute value of $x$.

Kirill can perform the following operation at most once: 

* select two indices $i$ and $j$ ($1 \leq i < j \leq n$) and swap the values of $b_i$ and $b_j$.

Help him find the maximum possible absolute beauty of the array $b$ after performing at most one swap.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10\,000$). The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2\leq n\leq 2\cdot 10^5$) — the length of the arrays $a$ and $b$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1\leq a_i\leq 10^9$) — the array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1\leq b_i\leq 10^9$) — the array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, output one integer — the maximum possible absolute beauty of the array $b$ after no more than one swap.

## Example

### Input


```text
631 3 53 3 321 21 221 22 141 2 3 45 6 7 8101 8 2 5 3 5 3 1 1 32 9 2 4 8 2 3 5 3 1347326 6958 3586533587 35863 59474
```
### Output

```text

4
2
2
16
31
419045

```
## Note

In the first test case, each of the possible swaps does not change the array $b$.

In the second test case, the absolute beauty of the array $b$ without performing the swap is $|1-1| + |2-2| = 0$. After swapping the first and the second element in the array $b$, the absolute beauty becomes $|1-2| + |2-1| = 2$. These are all the possible outcomes, hence the answer is $2$.

In the third test case, it is optimal for Kirill to not perform the swap. Similarly to the previous test case, the answer is $2$.

In the fourth test case, no matter what Kirill does, the absolute beauty of $b$ remains equal to $16$.



#### Tags 

#1900 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_910_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
