<h1 style='text-align: center;'> C. Cat, Fox and Double Maximum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fox loves permutations! She came up with the following problem and asked Cat to solve it:

You are given an even positive integer $n$ and a permutation$^\dagger$ $p$ of length $n$. 

The score of another permutation $q$ of length $n$ is the number of local maximums in the array $a$ of length $n$, where $a_i = p_i + q_i$ for all $i$ ($1 \le i \le n$). In other words, the score of $q$ is the number of $i$ such that $1 < i < n$ (note the strict inequalities), $a_{i-1} < a_i$, and $a_i > a_{i+1}$ (once again, note the strict inequalities). 

Find the permutation $q$ that achieves the maximum score for given $n$ and $p$. If there exist multiple such permutations, you can pick any of them.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## Input

The first line of input contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases in the input you will have to solve.

The first line of each test case contains one even integer $n$ ($4 \leq n \leq 10^5$, $n$ is even) — the length of the permutation $p$.

The second line of each test case contains the $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \leq p_i \leq n$). It is guaranteed that $p$ is a permutation of length $n$.

It is guaranteed that the sum of $n$ across all test cases doesn't exceed $10^5$.

## Output

For each test case, output one line containing any permutation of length $n$ (the array $q$), such that $q$ maximizes the score under the given constraints.

## Example

## Input


```

441 2 3 444 3 1 266 5 1 4 2 381 2 4 5 7 6 8 3
```
## Output


```

2 4 1 3
3 1 4 2
2 5 1 4 3 6
5 4 8 2 7 1 6 3

```
## Note

In the first example, $a = [3, 6, 4, 7]$. The array has just one local maximum (on the second position), so the score of the chosen permutation $q$ is $1$. It can be proven that this score is optimal under the constraints.

In the last example, the resulting array $a = [6, 6, 12, 7, 14, 7, 14, 6]$ has $3$ local maximums — on the third, fifth and seventh positions. 



#### tags 

#1700 #constructive_algorithms #greedy #implementation #math #sortings 