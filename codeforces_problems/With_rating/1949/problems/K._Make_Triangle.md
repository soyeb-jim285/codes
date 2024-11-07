<h1 style='text-align: center;'> K. Make Triangle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ positive integers $x_1, x_2, \ldots, x_n$ and three positive integers $n_a, n_b, n_c$ satisfying $n_a+n_b+n_c = n$. 

You want to split the $n$ positive integers into three groups, so that:

* The first group contains $n_a$ numbers, the second group contains $n_b$ numbers, the third group contains $n_c$ numbers.
* Let $s_a$ be the sum of the numbers in the first group, $s_b$ be the sum in the second group, and $s_c$ be the sum in the third group. Then $s_a, s_b, s_c$ are the sides of a triangle with positive area.

Determine if this is possible. If this is possible, find one way to do so.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1\le t\le 100\,000$) — the number of test cases. The descriptions of the $t$ test cases follow.

The first line of each test case contains the integers $n, n_a, n_b, n_c$ ($3 \leq n \leq 200\,000, 1\leq n_a,n_b,n_c \leq n-2, n_a+n_b+n_c = n$) — the number of integers to split into three groups, and the desired sizes of the three groups.

The second line of each test case contains $n$ integers $x_1, x_2, \ldots, x_n$ ($1 \leq x_i \leq 10^{9}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $200\,000$.

### Output

For each test case, print $\texttt{YES}$ if it is possible to split the numbers into three groups satisfying all the conditions. Otherwise, print $\texttt{NO}$.

If such a split exists, then describe the three groups as follows.

On the next line, print $n_a$ integers $a_1, a_2, \ldots, a_{n_a}$ — the numbers in the first group.

On the next line, print $n_b$ integers $b_1, b_2, \ldots, b_{n_b}$ — the numbers in the second group.

On the next line, print $n_c$ integers $c_1, c_2, \ldots, c_{n_c}$ — the numbers in the third group.

These $n_a+n_b+n_c=n$ integers should be a permutation of $x_1, x_2, \ldots, x_n$, and they should satisfy the conditions from the statement.

If there are multiple solutions, print any of them.

## Example

### Input


```text
46 2 2 21 1 1 1 1 15 3 1 11 1 1 1 16 2 2 21 1 1 1 1 38 1 2 516 1 1 1 1 1 1 12
```
### Output

```text

YES
1 1 
1 1 
1 1 
NO
NO
YES
16 
12 1 
1 1 1 1 1 

```
## Note

In the first test case, we can put two $1$s into each group: the sum in each group would be $2$, and there exists a triangle with positive area and sides $2$, $2$, $2$.

In the second and third test cases, it can be shown that there is no such way to split numbers into groups.

In the fourth test case, we can put number $16$ into the first group, with sum $16$, numbers $12$ and $1$ into the second group, with sum $13$, and the remaining five $1$s into the third group, with sum $5$, as there exists a triangle with positive area and sides $16, 13, 5$.



#### Tags 

#2800 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../European_Championship_2024_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
