<h1 style='text-align: center;'> A. Too Min Too Max</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a$ of $n$ elements, find the maximum value of the expression:

$$|a_i - a_j| + |a_j - a_k| + |a_k - a_l| + |a_l - a_i|$$

where $i$, $j$, $k$, and $l$ are four distinct indices of the array $a$, with $1 \le i, j, k, l \le n$.

Here $|x|$ denotes the absolute value of $x$.

## Input

The first line contains one integer $t$ ($1 \le t \le 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($4 \le n \le 100$) — the length of the given array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^6 \le a_i \le 10^6$).

## Output

For each test case, print a single integer — the maximum value.

## Example

## Input


```

541 1 1 151 1 2 2 385 1 3 2 -3 -1 10 343 3 1 141 2 2 -1
```
## Output


```

0
6
38
8
8

```
## Note

In the first test case, for any selection of $i$, $j$, $k$, $l$, the answer will be $0$. For example, $|a_1 - a_2| + |a_2 - a_3| + |a_3 - a_4| + |a_4 - a_1| = |1 - 1| + |1 - 1| + |1 - 1| + |1 - 1| = 0 + 0 + 0 + 0 = 0$.

In the second test case, for $i = 1$, $j = 3$, $k = 2$, and $l = 5$, the answer will be $6$. $|a_1 - a_3| + |a_3 - a_2| + |a_2 - a_5| + |a_5 - a_1| = |1 - 2| + |2 - 1| + |1 - 3| + |3 - 1| = 1 + 1 + 2 + 2 = 6$.



#### tags 

#800 #greedy #math 