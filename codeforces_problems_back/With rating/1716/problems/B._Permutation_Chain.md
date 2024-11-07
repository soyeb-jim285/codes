<h1 style='text-align: center;'> B. Permutation Chain</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A permutation of length $n$ is a sequence of integers from $1$ to $n$ such that each integer appears in it exactly once.

Let the fixedness of a permutation $p$ be the number of fixed points in it — the number of positions $j$ such that $p_j = j$, where $p_j$ is the $j$-th element of the permutation $p$.

You are asked to build a sequence of permutations $a_1, a_2, \dots$, starting from the identity permutation (permutation $a_1 = [1, 2, \dots, n]$). Let's call it a permutation chain. Thus, $a_i$ is the $i$-th permutation of length $n$.

For every $i$ from $2$ onwards, the permutation $a_i$ should be obtained from the permutation $a_{i-1}$ by swapping any two elements in it (not necessarily neighboring). The fixedness of the permutation $a_i$ should be strictly lower than the fixedness of the permutation $a_{i-1}$.

Consider some chains for $n = 3$:

* $a_1 = [1, 2, 3]$, $a_2 = [1, 3, 2]$ — that is a valid chain of length $2$. From $a_1$ to $a_2$, the elements on positions $2$ and $3$ get swapped, the fixedness decrease from $3$ to $1$.
* $a_1 = [2, 1, 3]$, $a_2 = [3, 1, 2]$ — that is not a valid chain. The first permutation should always be $[1, 2, 3]$ for $n = 3$.
* $a_1 = [1, 2, 3]$, $a_2 = [1, 3, 2]$, $a_3 = [1, 2, 3]$ — that is not a valid chain. From $a_2$ to $a_3$, the elements on positions $2$ and $3$ get swapped but the fixedness increase from $1$ to $3$.
* $a_1 = [1, 2, 3]$, $a_2 = [3, 2, 1]$, $a_3 = [3, 1, 2]$ — that is a valid chain of length $3$. From $a_1$ to $a_2$, the elements on positions $1$ and $3$ get swapped, the fixedness decrease from $3$ to $1$. From $a_2$ to $a_3$, the elements on positions $2$ and $3$ get swapped, the fixedness decrease from $1$ to $0$.

Find the longest permutation chain. If there are multiple longest answers, print any of them.

## Input

The first line contains a single integer $t$ ($1 \le t \le 99$) — the number of testcases.

The only line of each testcase contains a single integer $n$ ($2 \le n \le 100$) — the required length of permutations in the chain.

## Output

For each testcase, first, print the length of a permutation chain $k$.

Then print $k$ permutations $a_1, a_2, \dots, a_k$. $a_1$ should be an identity permutation of length $n$ ($[1, 2, \dots, n]$). For each $i$ from $2$ to $k$, $a_i$ should be obtained by swapping two elements in $a_{i-1}$. It should also have a strictly lower fixedness than $a_{i-1}$.

## Example

## Input


```

223
```
## Output


```

2
1 2
2 1
3
1 2 3
3 2 1
3 1 2

```


#### tags 

#800 #constructive_algorithms #math 