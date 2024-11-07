<h1 style='text-align: center;'> C. Almost All Multiples</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given two integers $n$ and $x$, a permutation$^{\dagger}$ $p$ of length $n$ is called funny if $p_i$ is a multiple of $i$ for all $1 \leq i \leq n - 1$, $p_n = 1$, and $p_1 = x$.

Find the lexicographically minimal$^{\ddagger}$ funny permutation, or report that no such permutation exists.

$^{\dagger}$ A permutation of length $n$ is an array consisting of each of the integers from $1$ to $n$ exactly once.

$^{\ddagger}$ Let $a$ and $b$ be permutations of length $n$. Then $a$ is lexicographically smaller than $b$ if in the first position $i$ where $a$ and $b$ differ, $a_i < b_i$. A permutation is lexicographically minimal if it is lexicographically smaller than all other permutations.

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $n$ and $x$ ($2 \leq n \leq 2 \cdot 10^5$; $1 < x \leq n$).

The sum of $n$ across all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, if the answer exists, output $n$ distinct integers $p_1, p_2, \dots, p_n$ ($1 \leq p_i \leq n$) — the lexicographically minimal funny permutation $p$. Otherwise, output $-1$.

## Example

## Input


```

33 34 25 4
```
## Output


```

3 2 1 
2 4 3 1 
-1

```
## Note

In the first test case, the permutation $[3,2,1]$ satisfies all the conditions: $p_1=3$, $p_3=1$, and: 

* $p_1=3$ is a multiple of $1$.
* $p_2=2$ is a multiple of $2$.

In the second test case, the permutation $[2,4,3,1]$ satisfies all the conditions: $p_1=2$, $p_4=1$, and: 

* $p_1=2$ is a multiple of $1$.
* $p_2=4$ is a multiple of $2$.
* $p_3=3$ is a multiple of $3$.

We can show that these permutations are lexicographically minimal.

No such permutations exist in the third test case.



#### tags 

#1400 #greedy #number_theory 