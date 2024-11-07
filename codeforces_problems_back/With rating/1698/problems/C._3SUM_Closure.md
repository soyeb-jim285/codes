<h1 style='text-align: center;'> C. 3SUM Closure</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$. The array is called 3SUM-closed if for all distinct indices $i$, $j$, $k$, the sum $a_i + a_j + a_k$ is an element of the array. More formally, $a$ is 3SUM-closed if for all integers $1 \leq i < j < k \leq n$, there exists some integer $1 \leq l \leq n$ such that $a_i + a_j + a_k = a_l$.

Determine if $a$ is 3SUM-closed.

## Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains an integer $n$ ($3 \leq n \leq 2 \cdot 10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($-10^9 \leq a_i \leq 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ across all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output "YES" (without quotes) if $a$ is 3SUM-closed and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

## Input


```

43-1 0 151 -2 -2 1 -360 0 0 0 0 04-1 2 -3 4
```
## Output


```

YES
NO
YES
NO

```
## Note

In the first test case, there is only one triple where $i=1$, $j=2$, $k=3$. In this case, $a_1 + a_2 + a_3 = 0$, which is an element of the array ($a_2 = 0$), so the array is 3SUM-closed.

In the second test case, $a_1 + a_4 + a_5 = -1$, which is not an element of the array. Therefore, the array is not 3SUM-closed.

In the third test case, $a_i + a_j + a_k = 0$ for all distinct $i$, $j$, $k$, and $0$ is an element of the array, so the array is 3SUM-closed.



#### tags 

#1300 #brute_force #data_structures 