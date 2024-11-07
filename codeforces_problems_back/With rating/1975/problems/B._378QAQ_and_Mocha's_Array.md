<h1 style='text-align: center;'> B. 378QAQ and Mocha's Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mocha likes arrays, so before her departure, 378QAQ gave her an array $a$ consisting of $n$ positive integers as a gift.

Mocha thinks that $a$ is beautiful if there exist two numbers $i$ and $j$ ($1\leq i,j\leq n$, $i\neq j$) such that for all $k$ ($1 \leq k \leq n$), $a_k$ is divisible$^\dagger$ by either $a_i$ or $a_j$.

Determine whether $a$ is beautiful.

$^\dagger$ $x$ is divisible by $y$ if there exists an integer $z$ such that $x = y \cdot z$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\leq t\leq 500$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3\leq n\leq 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\leq a_i \leq 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output "Yes" if array $a$ is beautiful, and output "No" otherwise.

You can output "Yes" and "No" in any case (for example, strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive response).

## Example

## Input


```

437 3 857 1 9 3 554 12 2 6 357 49 9 3 1000000000
```
## Output


```

No
Yes
Yes
No

```
## Note

In the first test case, any two numbers in the array are coprime, so the answer is "No".

In the second test case, we can pick $i=2$ and $j=1$. Since every number in the array is divisible by $a_i = 1$, the answer is "Yes".

In the third test case, we can pick $i=3$ and $j=5$. $2$ and $4$ is divisible by $a_i = 2$ while $3$, $6$ and $12$ is divisible by $a_j = 3$, so the answer is "Yes".



#### tags 

#1000 #brute_force #greedy #math #sortings 