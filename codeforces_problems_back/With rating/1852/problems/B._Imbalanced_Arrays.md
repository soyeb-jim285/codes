<h1 style='text-align: center;'> B. Imbalanced Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ntarsis has come up with an array $a$ of $n$ non-negative integers.

Call an array $b$ of $n$ integers imbalanced if it satisfies the following: 

* $-n\le b_i\le n$, $b_i \ne 0$,
* there are no two indices $(i, j)$ ($1 \le i, j \le n$) such that $b_i + b_j = 0$,
* for each $1 \leq i \leq n$, there are exactly $a_i$ indices $j$ ($1 \le j \le n$) such that $b_i+b_j>0$, where $i$ and $j$ are not necessarily distinct.

Given the array $a$, Ntarsis wants you to construct some imbalanced array. Help him solve this task, or determine it is impossible.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). The description of the test cases follows.

The first line of each test case has a single integer $n$ ($1 \leq n \leq 10^5$).

The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq n$).

It is guaranteed that the sum of $n$ across all test cases does not exceed $10^5$.

## Output

For each test case, output "NO" if there exists no imbalanced array. 

Otherwise, output "YES". Then, on the next line, output $n$ integers $b_1, b_2, \ldots, b_n$ where $b_i \neq 0$ for all $1 \leq i \leq n$ — an imbalanced array.

## Example

## Input


```

51141 4 3 430 1 044 3 2 131 3 1
```
## Output


```

YES
1 
NO
YES
-3 1 -2 
YES
4 2 -1 -3 
YES
-1 3 -1
```
## Note

For the first test case, $b = [1]$ is an imbalanced array. This is because for $i = 1$, there is exactly one $j$ ($j = 1$) where $b_1 + b_j > 0$.

For the second test case, it can be shown that there exists no imbalanced array.

For the third test case, $a = [0, 1, 0]$. The array $b = [-3, 1, -2]$ is an imbalanced array. 

* For $i = 1$ and $i = 3$, there exists no index $j$ such that $b_i + b_j > 0$.
* For $i = 2$, there is only one index $j = 2$ such that $b_i + b_j > 0$ ($b_2 + b_2 = 1 + 1 = 2$).

 Another possible output for the third test case could be $b = [-2, 1, -3]$.

#### tags 

#1800 #constructive_algorithms #graphs #greedy #math #sortings #two_pointers 