<h1 style='text-align: center;'> D. Super-Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A permutation is a sequence $n$ integers, where each integer from $1$ to $n$ appears exactly once. For example, $[1]$, $[3,5,2,1,4]$, $[1,3,2]$ are permutations, while $[2,3,2]$, $[4,3,1]$, $[0]$ are not.

Given a permutation $a$, we construct an array $b$, where $b_i = (a_1 + a_2 +~\dots~+ a_i) \bmod n$.

A permutation of numbers $[a_1, a_2, \dots, a_n]$ is called a super-permutation if $[b_1 + 1, b_2 + 1, \dots, b_n + 1]$ is also a permutation of length $n$.

Grisha became interested whether a super-permutation of length $n$ exists. Help him solve this non-trivial problem. ## Output

 any super-permutation of length $n$, if it exists. Otherwise, output $-1$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

Each test case consists of a single line containing one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the desired permutation.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output in a separate line:

* $n$ integers — a super-permutation of length $n$, if it exists.
* $-1$, otherwise.

If there are several suitable permutations, output any of them.

## Example

## Input


```

41236
```
## Output


```

1
2 1
-1
6 5 2 3 4 1
```


#### tags 

#1200 #constructive_algorithms #math 