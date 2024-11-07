<h1 style='text-align: center;'> E. Half-sum</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're given a multiset of non-negative integers $\{a_1, a_2, \dots, a_n\}$.

In one step you take two elements $x$ and $y$ of the multiset, remove them and insert their mean value $\frac{x + y}{2}$ back into the multiset.

You repeat the step described above until you are left with only two numbers $A$ and $B$. What is the maximum possible value of their absolute difference $|A-B|$?

Since the answer is not an integer number, output it modulo $10^9+7$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^6$) — the size of the multiset.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the elements of the multiset.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

## Output

For each test case, output a single integer, the answer to the problem modulo $10^9+7$.

Formally, let $M = 10^9+7$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. ## Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output an integer $x$ such that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

## Example

## Input


```

527 341 2 10 1131 2 3664 32 64 16 64 041 1 1 1
```
## Output


```

4
9
500000005
59
0

```
## Note

In the first case, you can't do any operations, so the answer is $|7-3|=4$.

In the second case, one of the optimal sequence of operations: 

1. Substitute $1$ and $2$ with $1.5$;
2. Substitute $10$ and $11$ with $10.5$;
3. The difference between $1.5$ and $10.5$ is $9$.

In the third case, the exact answer is $\frac{3}{2}$, and $500\,000\,005 \cdot 2 \equiv 3 \pmod{10^9+7}$.



#### tags 

#3400 #brute_force #divide_and_conquer #greedy 