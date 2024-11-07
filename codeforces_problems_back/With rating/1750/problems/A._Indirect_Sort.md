<h1 style='text-align: center;'> A. Indirect Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $a_1, a_2, \ldots, a_n$ of size $n$, where each integer from $1$ to $n$ appears exactly once.

You can do the following operation any number of times (possibly, zero):

* Choose any three indices $i, j, k$ ($1 \le i < j < k \le n$).
* If $a_i > a_k$, replace $a_i$ with $a_i + a_j$. Otherwise, swap $a_j$ and $a_k$.

Determine whether you can make the array $a$ sorted in non-descending order.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 5000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($3 \le n \le 10$) — the length of the array $a$.

The second line contains $n$ integers $a_1,a_2,\dots,a_n$ ($1 \le a_i \le n$, $a_i \neq a_j$ if $i \neq j$) — the elements of the array $a$.

## Output

For each test case, output "Yes" (without quotes) if the array can be sorted in non-descending order, and "No" (without quotes) otherwise.

You can output "Yes" and "No" in any case (for example, strings "YES", "yEs" and "yes" will be recognized as a positive response).

## Example

## Input


```

731 2 331 3 275 3 4 7 6 2 177 6 5 4 3 2 152 1 4 5 352 1 3 4 571 2 6 7 4 3 5
```
## Output


```

Yes
Yes
No
No
No
No
Yes

```
## Note

In the first test case, $[1,2,3]$ is already sorted in non-descending order.

In the second test case, we can choose $i = 1,j = 2,k = 3$. Since $a_1 \le a_3$, swap $a_2$ and $a_3$, the array then becomes $[1,2,3]$, which is sorted in non-descending order.

In the seventh test case, we can do the following operations successively:

* Choose $i = 5,j = 6,k = 7$. Since $a_5 \le a_7$, swap $a_6$ and $a_7$, the array then becomes $[1,2,6,7,4,5,3]$.
* Choose $i = 5,j = 6,k = 7$. Since $a_5 > a_7$, replace $a_5$ with $a_5+a_6=9$, the array then becomes $[1,2,6,7,9,5,3]$.
* Choose $i = 2,j = 5,k = 7$. Since $a_2 \le a_7$, swap $a_5$ and $a_7$, the array then becomes $[1,2,6,7,3,5,9]$.
* Choose $i = 2,j = 4,k = 6$. Since $a_2 \le a_6$, swap $a_4$ and $a_6$, the array then becomes $[1,2,6,5,3,7,9]$.
* Choose $i = 1,j = 3,k = 5$. Since $a_1 \le a_5$, swap $a_3$ and $a_5$, the array then becomes $[1,2,3,5,6,7,9]$, which is sorted in non-descending order.

In the third, the fourth, the fifth and the sixth test cases, it can be shown that the array cannot be sorted in non-descending order.



#### tags 

#800 #constructive_algorithms #implementation #math 