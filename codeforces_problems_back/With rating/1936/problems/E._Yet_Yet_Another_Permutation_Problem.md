<h1 style='text-align: center;'> E. Yet Yet Another Permutation Problem</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given a permutation $p$ of length $n$.

Please count the number of permutations $q$ of length $n$ which satisfy the following:

* for each $1 \le i < n$, $\max(q_1,\ldots,q_i) \neq \max(p_1,\ldots,p_i)$.

Since the answer may be large, output the answer modulo $998\,244\,353$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$). It is guaranteed that $p$ is a permutation.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print a single integer — the answer modulo $998\,244\,353$.

## Example

## Input


```

622 131 2 333 1 242 4 1 353 5 1 4 2156 13 2 8 7 11 1 3 9 15 4 5 12 10 14
```
## Output


```

1
3
2
4
18
424488915

```
## Note

In the first test case, $p = [2, 1]$. The only suitable $q$ is $[1, 2]$. Indeed, we need to satisfy the inequality $q_1 \neq p_1$. It only holds for $q = [1, 2]$.

In the second test case, $p = [1, 2, 3]$. So $q$ has to satisfy two inequalities: $q_1 \neq p_1$ and $\max(q_1, q_2) \neq \max(1, 2) = 2$. One can prove that this only holds for the following $3$ permutations:

* $q = [2, 3, 1]$: in this case $q_1 = 2 \neq 1$ and $\max(q_1, q_2) = 3 \neq 2$;
* $q = [3, 1, 2]$: in this case $q_1 = 3 \neq 1$ and $\max(q_1, q_2) = 3 \neq 2$;
* $q = [3, 2, 1]$: in this case $q_1 = 3 \neq 1$ and $\max(q_1, q_2) = 3 \neq 2$.


#### tags 

#3400 #divide_and_conquer #fft #math 