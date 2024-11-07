<h1 style='text-align: center;'> A. Perfect Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$.

The weight of a permutation $p_1, p_2, \ldots, p_n$ is the number of indices $1\le i\le n$ such that $i$ divides $p_i$. Find a permutation $p_1,p_2,\dots, p_n$ with the minimum possible weight (among all permutations of length $n$).

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 10^4$). The description of the test cases follows.

The only line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$) — the length of permutation.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print a line containing $n$ integers $p_1, p_2,\dots, p_n$ so that the permutation $p$ has the minimum possible weight.

If there are several possible answers, you can print any of them.

## Example

### Input


```text
214
```
### Output

```text

1
2 1 4 3

```
## Note

In the first test case, the only valid permutation is $p=[1]$. Its weight is $1$.

In the second test case, one possible answer is the permutation $p=[2,1,4,3]$. One can check that $1$ divides $p_1$ and $i$ does not divide $p_i$ for $i=2,3,4$, so the weight of this permutation is $1$. It is impossible to find a permutation of length $4$ with a strictly smaller weight.



#### Tags 

#800 #OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_810_(Div._2).md)
- [Codeforces Round #810 (en)](../blogs/Codeforces_Round_810_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
