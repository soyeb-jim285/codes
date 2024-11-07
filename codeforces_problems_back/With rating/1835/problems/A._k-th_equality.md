<h1 style='text-align: center;'> A. k-th equality</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider all equalities of form $a + b = c$, where $a$ has $A$ digits, $b$ has $B$ digits, and $c$ has $C$ digits. All the numbers are positive integers and are written without leading zeroes. Find the $k$-th lexicographically smallest equality when written as a string like above or determine that it does not exist.

For example, the first three equalities satisfying $A = 1$, $B = 1$, $C = 2$ are 

* $1 + 9 = 10$,
* $2 + 8 = 10$,
* $2 + 9 = 11$.

An equality $s$ is lexicographically smaller than an equality $t$ with the same lengths of the numbers if and only if the following holds: 

* in the first position where $s$ and $t$ differ, the equality $s$ has a smaller digit than the corresponding digit in $t$.
## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. The description of test cases follows.

The first line of each test case contains integers $A$, $B$, $C$, $k$ ($1 \leq A, B, C \leq 6$, $1 \leq k \leq 10^{12}$).

Each input file has at most $5$ test cases which do not satisfy $A, B, C \leq 3$.

## Output

For each test case, if there are strictly less than $k$ valid equalities, output $-1$.

Otherwise, output the $k$-th equality as a string of form $a + b = c$.

## Example

## Input


```

71 1 1 92 2 3 12 2 1 11 5 6 421 6 6 100000005 5 6 30315688156 6 6 1000000000000
```
## Output


```

2 + 1 = 3
10 + 90 = 100
-1
9 + 99996 = 100005
-1
78506 + 28543 = 107049
-1

```
## Note

In the first test case, the first $9$ solutions are: $\langle 1, 1, 2 \rangle, \langle 1, 2, 3 \rangle, \langle 1, 3, 4 \rangle, \langle 1, 4, 5 \rangle, \langle 1, 5, 6 \rangle, \langle 1, 6, 7 \rangle, \langle 1, 7, 8 \rangle, \langle 1, 8, 9 \rangle, \langle 2, 1, 3 \rangle$.

Int the third test case, there are no solutions as the smallest possible values for $a$ and $b$ are larger than the maximal possible value of $c$ — $10 + 10 = 20 > 9$.

Please note that whitespaces in the output matter.



#### tags 

#1700 #brute_force #implementation #math 