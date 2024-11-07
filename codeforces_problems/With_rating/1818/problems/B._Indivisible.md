<h1 style='text-align: center;'> B. Indivisible</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're given a positive integer $n$.

Find a permutation $a_1, a_2, \dots, a_n$ such that for any $1 \leq l < r \leq n$, the sum $a_l + a_{l+1} + \dots + a_r$ is not divisible by $r-l+1$.

A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contain a single integer $n$ ($1 \leq n \leq 100$) — the size of the desired permutation.

### Output

For each test case, if there is no such permutation print $-1$.

Otherwise, print $n$ distinct integers $p_1, p_{2}, \dots, p_n$ ($1 \leq p_i \leq n$) — a permutation satisfying the condition described in the statement.

If there are multiple solutions, print any.

## Example

### Input


```text
3
1
2
3
```
### Output


```text
1
1 2
-1
```
## Note

In the first example, there are no valid pairs of $l < r$, meaning that the condition is true for all such pairs.

In the second example, the only valid pair is $l=1$ and $r=2$, for which $a_1 + a_2 = 1+2=3$ is not divisible by $r-l+1=2$.

in the third example, for $l=1$ and $r=3$ the sum $a_1+a_2+a_3$ is always $6$, which is divisible by $3$.



#### Tags 

#900 #OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_869_(Div._2).md)
- [Codeforces Round #869 (en)](../blogs/Codeforces_Round_869_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
