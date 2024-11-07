<h1 style='text-align: center;'> A. Twin Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation$^\dagger$ $a$ of length $n$.

Find any permutation $b$ of length $n$ such that $a_1+b_1 \le a_2+b_2 \le a_3+b_3 \le \ldots \le a_n+b_n$.

It can be proven that a permutation $b$ that satisfies the condition above always exists.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 2000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the length of permutations $a$ and $b$.

The second line of each test case contains $n$ distinct integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le n$) — the elements of permutation $a$. All elements of $a$ are distinct.

## Note

 that there is no bound on the sum of $n$ over all test cases.

## Output

For each test case, output any permutation $b$ which satisfies the constraints mentioned in the statement. It can be proven that a permutation $b$ that satisfies the condition above always exists.

## Example

## Input


```

551 2 4 5 321 21133 2 141 4 3 2
```
## Output


```

1 2 4 3 5
2 1
1
1 2 3
1 2 3 4
```
## Note

In the first test case $a=[1, 2, 4, 5, 3]$. Then the permutation $b=[1, 2, 4, 3, 5]$ satisfies the condition because $1 + 1 \le 2 + 2 \le 4 + 4 \le 5 + 3 \le 3 + 5$.



#### tags 

#800 #constructive_algorithms 