<h1 style='text-align: center;'> B. Array Recovery</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For an array of non-negative integers $a$ of size $n$, we construct another array $d$ as follows: $d_1 = a_1$, $d_i = |a_i - a_{i - 1}|$ for $2 \le i \le n$.

Your task is to restore the array $a$ from a given array $d$, or to report that there are multiple possible arrays. 

## Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains one integer $n$ ($1 \le n \le 100$) — the size of the arrays $a$ and $d$.

The second line contains $n$ integers $d_1, d_2, \dots, d_n$ ($0 \le d_i \le 100$) — the elements of the array $d$.

It can be shown that there always exists at least one suitable array $a$ under these constraints.

## Output

For each test case, print the elements of the array $a$, if there is only one possible array $a$. Otherwise, print $-1$.

## Example

## Input


```

341 0 2 532 6 350 0 0 0 0
```
## Output


```

1 1 3 8
-1
0 0 0 0 0

```
## Note

In the second example, there are two suitable arrays: $[2, 8, 5]$ and $[2, 8, 11]$.



#### tags 

#1100 #constructive_algorithms #greedy #math 