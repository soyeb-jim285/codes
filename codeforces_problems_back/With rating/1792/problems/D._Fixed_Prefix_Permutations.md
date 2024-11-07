<h1 style='text-align: center;'> D. Fixed Prefix Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ permutations $a_1, a_2, \dots, a_n$, each of length $m$. Recall that a permutation of length $m$ is a sequence of $m$ distinct integers from $1$ to $m$.

Let the beauty of a permutation $p_1, p_2, \dots, p_m$ be the largest $k$ such that $p_1 = 1, p_2 = 2, \dots, p_k = k$. If $p_1 \neq 1$, then the beauty is $0$.

The product of two permutations $p \cdot q$ is a permutation $r$ such that $r_j = q_{p_j}$.

For each $i$ from $1$ to $n$, print the largest beauty of a permutation $a_i \cdot a_j$ over all $j$ from $1$ to $n$ (possibly, $i = j$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains two integers $n$ and $m$ ($1 \le n \le 5 \cdot 10^4$; $1 \le m \le 10$) — the number of permutations and the length of each permutation.

The $i$-th of the next $n$ lines contains a permutation $a_i$ — $m$ distinct integers from $1$ to $m$.

The sum of $n$ doesn't exceed $5 \cdot 10^4$ over all testcases.

## Output

For each testcase, print $n$ integers. The $i$-th value should be equal to the largest beauty of a permutation $a_i \cdot a_j$ over all $j$ ($1 \le j \le n$).

## Example

## Input


```

33 42 4 1 31 2 4 32 1 3 42 21 22 18 103 4 9 6 10 2 7 8 1 53 9 1 8 5 7 4 10 2 63 10 1 7 5 9 6 4 2 81 2 3 4 8 6 10 7 9 51 2 3 4 10 6 8 5 7 99 6 1 2 10 4 7 8 3 57 9 3 2 5 6 4 8 1 109 4 3 7 5 6 1 10 8 2
```
## Output


```

1 4 4 
2 2 
10 8 1 6 8 10 1 7 

```


#### tags 

#1700 #binary_search #bitmasks #data_structures #hashing #math #sortings 