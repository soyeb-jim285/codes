<h1 style='text-align: center;'> D. Long Way to be Non-decreasing</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Little R is a magician who likes non-decreasing arrays. She has an array of length $n$, initially as $a_1, \ldots, a_n$, in which each element is an integer between $[1, m]$. She wants it to be non-decreasing, i.e., $a_1 \leq a_2 \leq \ldots \leq a_n$.

To do this, she can perform several magic tricks. Little R has a fixed array $b_1\ldots b_m$ of length $m$. Formally, let's define a trick as a procedure that does the following things in order:

* Choose a set $S \subseteq \{1, 2, \ldots, n\}$.
* For each $u \in S$, assign $a_u$ with $b_{a_u}$.

Little R wonders how many tricks are needed at least to make the initial array non-decreasing. If it is not possible with any amount of tricks, print $-1$ instead.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\le t\le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1\leq n \leq 10^6$, $1 \leq m \leq 10^6$) — the length of the initial array and the range of the elements in the array.

The second line of each test case contains $n$ integers $a_1, \ldots, a_n$ ($1 \leq a_i \leq m$) — the initial array.

The third line of each test case contains $m$ integers $b_1, \ldots, b_m$ ($1 \leq b_i \leq m$) — the fixed magic array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$ and the sum of $m$ over all test cases does not exceed $10^6$.

### Output

For each test case, output a single integer: the minimum number of tricks needed, or $-1$ if it is impossible to make $a_1, \ldots, a_n$ non-decreasing.

## Example

### Input


```text
35 81 6 3 7 12 3 5 8 7 1 5 63 31 3 22 1 310 102 8 5 4 8 4 1 5 10 106 7 2 6 3 4 1 1 3 5
```
### Output

```text

3
-1
3

```
## Note

In the first case, the initial array $a_1, \ldots, a_n$ is $[1, 6, 3, 7, 1]$. You can choose $S$ as follows: 

* first trick: $S = [2, 4, 5]$, $a = [1, 1, 3, 5, 2]$;
* second trick: $S = [5]$, $a = [1, 1, 3, 5, 3]$;
* third trick: $S = [5]$, $a = [1, 1, 3, 5, 5]$.

 So it is possible to make $a_1, \ldots, a_n$ non-decreasing using $3$ tricks. It can be shown that this is the minimum possible amount of tricks.In the second case, it is impossible to make $a_1, \ldots, a_n$ non-decreasing.



#### Tags 

#2800 #NOT OK #binary_search #dfs_and_similar #graphs #implementation #shortest_paths #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_942_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
