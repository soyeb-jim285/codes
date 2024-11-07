<h1 style='text-align: center;'> C. Partitioning the Array</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Allen has an array $a_1, a_2,\ldots,a_n$. For every positive integer $k$ that is a divisor of $n$, Allen does the following:

* He partitions the array into $\frac{n}{k}$ disjoint subarrays of length $k$. In other words, he partitions the array into the following subarrays: $$[a_1,a_2,\ldots,a_k],[a_{k+1}, a_{k+2},\ldots,a_{2k}],\ldots,[a_{n-k+1},a_{n-k+2},\ldots,a_{n}]$$
* Allen earns one point if there exists some positive integer $m$ ($m \geq 2$) such that if he replaces every element in the array with its remainder when divided by $m$, then all subarrays will be identical.

Help Allen find the number of points he will earn.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2\cdot10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2,\ldots, a_n$ ($1 \leq a_i \leq n$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. 

## Output

For each test case, output a single integer — the number of points Allen will earn.

## Example

## Input


```

841 2 1 431 2 351 1 1 1 161 3 1 1 3 166 2 6 2 2 262 6 3 6 6 6101 7 5 1 4 3 1 3 1 411
```
## Output


```

2
1
2
4
4
1
2
1

```
## Note

In the first test case, $k=2$ earns a point since Allen can pick $m = 2$ and both subarrays will be equal to $[1, 0]$. $k=4$ also earns a point, since no matter what $m$ Allen chooses, there will be only one subarray and thus all subarrays are equal.

In the second test case, Allen earns $1$ point for $k=3$, where his choice for $m$ does not matter.



#### tags 

#1600 #brute_force #math #number_theory 