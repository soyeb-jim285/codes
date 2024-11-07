<h1 style='text-align: center;'> D. Same Count One</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

ChthollyNotaSeniorious received a special gift from AquaMoon: $n$ binary arrays of length $m$. AquaMoon tells him that in one operation, he can choose any two arrays and any position $pos$ from $1$ to $m$, and swap the elements at positions $pos$ in these arrays.

He is fascinated with this game, and he wants to find the minimum number of operations needed to make the numbers of $1$s in all arrays the same. He has invited you to participate in this interesting game, so please try to find it!

If it is possible, please output specific exchange steps in the format described in the output section. Otherwise, please output $-1$.

## Input

The first line of the input contains a single integer $t$ ($1 \leq t \leq 2\cdot 10^4$)  — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($2 \leq n \leq 10^5$, $2 \leq m \leq 10^5$).

The $i$-th of the following $n$ lines contains $m$ integers $a_{i, 1}, a_{i, 2}, \ldots, a_{i, m}$ $(0 \le a_{i, j} \le 1)$  — the elements of the $i$-th array.

 It is guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $10^6$.

## Output

For each test case, if the objective is not achievable, output $-1$. 

Otherwise, in the first line output $k$ $(0 \le k \le mn)$  — the minimum number of operations required.

The $i$-th of the following $k$ lines should contain $3$ integers, $x_i, y_i, z_i$ $(1 \le x_i, y_i \le n, 1 \le z_i \le m)$, which describe an operation that swap $a_{x_i, z_i}, a_{y_i, z_i}$: swap the $z_i$-th number of the $x_i$-th and $y_i$-th arrays.

## Example

## Input


```

33 41 1 1 00 0 1 01 0 0 14 31 0 00 1 10 0 10 0 02 20 00 1
```
## Output


```

1
2 1 1
1
4 2 2
-1

```
## Note

In the first test case, it's enough to do a single operation: to swap the first element in the second and the first rows. The arrays will become $[0, 1, 1, 0], [1, 0, 1, 0], [1, 0, 0, 1]$, each of them contains exactly two $1$s.



#### tags 

#1600 #brute_force #constructive_algorithms #greedy #implementation #two_pointers 