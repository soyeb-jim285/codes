<h1 style='text-align: center;'> D. Array Differentiation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence of $n$ integers $a_1, \, a_2, \, \dots, \, a_n$.

Does there exist a sequence of $n$ integers $b_1, \, b_2, \, \dots, \, b_n$ such that the following property holds?

* For each $1 \le i \le n$, there exist two (not necessarily distinct) indices $j$ and $k$ ($1 \le j, \, k \le n$) such that $a_i = b_j - b_k$.
## Input

The first line contains a single integer $t$ ($1 \le t \le 20$) — the number of test cases. Then $t$ test cases follow.

The first line of each test case contains one integer $n$ ($1 \le n \le 10$).

The second line of each test case contains the $n$ integers $a_1, \, \dots, \, a_n$ ($-10^5 \le a_i \le 10^5$).

## Output

For each test case, output a line containing YES if a sequence $b_1, \, \dots, \, b_n$ satisfying the required property exists, and NO otherwise.

## Example

## Input


```

5
5
4 -7 -1 5 10
1
0
3
1 10 100
4
-3 2 10 2
9
25 -171 250 174 152 242 100 -205 -258

```
## Output


```

YES
YES
NO
YES
YES

```
## Note

In the first test case, the sequence $b = [-9, \, 2, \, 1, \, 3, \, -2]$ satisfies the property. Indeed, the following holds: 

* $a_1 = 4 = 2 - (-2) = b_2 - b_5$;
* $a_2 = -7 = -9 - (-2) = b_1 - b_5$;
* $a_3 = -1 = 1 - 2 = b_3 - b_2$;
* $a_4 = 5 = 3 - (-2) = b_4 - b_5$;
* $a_5 = 10 = 1 - (-9) = b_3 - b_1$.

In the second test case, it is sufficient to choose $b = [0]$, since $a_1 = 0 = 0 - 0 = b_1 - b_1$.

In the third test case, it is possible to show that no sequence $b$ of length $3$ satisfies the property.



#### tags 

#1800 #bitmasks #brute_force #constructive_algorithms #dfs_and_similar #dp #graphs #math 