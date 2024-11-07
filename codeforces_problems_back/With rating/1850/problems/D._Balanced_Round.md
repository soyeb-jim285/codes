<h1 style='text-align: center;'> D. Balanced Round</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are the author of a Codeforces round and have prepared $n$ problems you are going to set, problem $i$ having difficulty $a_i$. You will do the following process: 

* remove some (possibly zero) problems from the list;
* rearrange the remaining problems in any order you wish.

A round is considered balanced if and only if the absolute difference between the difficulty of any two consecutive problems is at most $k$ (less or equal than $k$).

What is the minimum number of problems you have to remove so that an arrangement of problems is balanced?

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains two positive integers $n$ ($1 \leq n \leq 2 \cdot 10^5$) and $k$ ($1 \leq k \leq 10^9$) — the number of problems, and the maximum allowed absolute difference between consecutive problems.

The second line of each test case contains $n$ space-separated integers $a_i$ ($1 \leq a_i \leq 10^9$) — the difficulty of each problem.

## Note

 that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the minimum number of problems you have to remove so that an arrangement of problems is balanced.

## Example

## Input


```

75 11 2 4 5 61 2108 317 3 1 20 12 5 17 124 22 4 6 85 32 3 19 10 83 41 10 58 18 3 1 4 5 10 7 3
```
## Output


```

2
0
5
0
3
1
4

```
## Note

For the first test case, we can remove the first $2$ problems and construct a set using problems with the difficulties $[4, 5, 6]$, with difficulties between adjacent problems equal to $|5 - 4| = 1 \leq 1$ and $|6 - 5| = 1 \leq 1$.

For the second test case, we can take the single problem and compose a round using the problem with difficulty $10$.



#### tags 

#900 #brute_force #greedy #implementation #sortings 