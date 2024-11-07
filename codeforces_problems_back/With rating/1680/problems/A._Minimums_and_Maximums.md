<h1 style='text-align: center;'> A. Minimums and Maximums</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

An array is beautiful if both of the following two conditions meet:

* there are at least $l_1$ and at most $r_1$ elements in the array equal to its minimum;
* there are at least $l_2$ and at most $r_2$ elements in the array equal to its maximum.

For example, the array $[2, 3, 2, 4, 4, 3, 2]$ has $3$ elements equal to its minimum ($1$-st, $3$-rd and $7$-th) and $2$ elements equal to its maximum ($4$-th and $5$-th).

Another example: the array $[42, 42, 42]$ has $3$ elements equal to its minimum and $3$ elements equal to its maximum.

Your task is to calculate the minimum possible number of elements in a beautiful array.

## Input

The first line contains one integer $t$ ($1 \le t \le 5000$) — the number of test cases.

Each test case consists of one line containing four integers $l_1$, $r_1$, $l_2$ and $r_2$ ($1 \le l_1 \le r_1 \le 50$; $1 \le l_2 \le r_2 \le 50$).

## Output

For each test case, print one integer — the minimum possible number of elements in a beautiful array.

## Example

## Input


```

73 5 4 65 8 5 53 3 10 121 5 3 31 1 2 22 2 1 16 6 6 6
```
## Output


```

4
5
13
3
3
3
6

```
## Note

Optimal arrays in the test cases of the example:

1. $[1, 1, 1, 1]$, it has $4$ minimums and $4$ maximums;
2. $[4, 4, 4, 4, 4]$, it has $5$ minimums and $5$ maximums;
3. $[1, 2, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2]$, it has $3$ minimums and $10$ maximums;
4. $[8, 8, 8]$, it has $3$ minimums and $3$ maximums;
5. $[4, 6, 6]$, it has $1$ minimum and $2$ maximums;
6. $[3, 4, 3]$, it has $2$ minimums and $1$ maximum;
7. $[5, 5, 5, 5, 5, 5]$, it has $6$ minimums and $6$ maximums.


#### tags 

#800 #brute_force #math 