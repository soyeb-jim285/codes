<h1 style='text-align: center;'> B. Permutation Printing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$.

Find a permutation$^\dagger$ $p$ of length $n$ such that there do not exist two distinct indices $i$ and $j$ ($1 \leq i, j < n$; $i \neq j$) such that $p_i$ divides $p_j$ and $p_{i+1}$ divides $p_{j+1}$.

Refer to the ## Note

s section for some examples.

Under the constraints of this problem, it can be proven that at least one $p$ exists.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \leq n \leq 10^5$) — the length of the permutation $p$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output $p_1, p_2, \ldots, p_n$.

If there are multiple solutions, you may output any one of them.

## Example

## Input


```

243
```
## Output


```

4 1 2 3
1 2 3

```
## Note

In the first test case, $p=[4,1,2,3]$ is a valid permutation. However, the permutation $p=[1,2,3,4]$ is not a valid permutation as we can choose $i=1$ and $j=3$. Then $p_1=1$ divides $p_3=3$ and $p_2=2$ divides $p_4=4$. ## Note

 that the permutation $p=[3, 4, 2, 1]$ is also not a valid permutation as we can choose $i=3$ and $j=2$. Then $p_3=2$ divides $p_2=4$ and $p_4=1$ divides $p_3=2$.

In the second test case, $p=[1,2,3]$ is a valid permutation. In fact, all $6$ permutations of length $3$ are valid.



#### tags 

#1000 #brute_force #constructive_algorithms #math 