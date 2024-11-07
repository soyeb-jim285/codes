<h1 style='text-align: center;'> B. Anti-Fibonacci Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a permutation $p$ of length $n$ anti-Fibonacci if the condition $p_{i-2} + p_{i-1} \ne p_i$ holds for all $i$ ($3 \le i \le n$). Recall that the permutation is the array of length $n$ which contains each integer from $1$ to $n$ exactly once.

Your task is for a given number $n$ print $n$ distinct anti-Fibonacci permutations of length $n$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 48$) — the number of test cases. 

The single line of each test case contains a single integer $n$ ($3 \le n \le 50$).

### Output

For each test case, print $n$ lines. Each line should contain an anti-Fibonacci permutation of length $n$. In each test case, you cannot print any permutation more than once.

If there are multiple answers, print any of them. It can be shown that it is always possible to find $n$ different anti-Fibonacci permutations of size $n$ under the constraints of the problem.

## Example

### Input


```text
243
```
### Output

```text

4 1 3 2
1 2 4 3
3 4 1 2
2 4 1 3
3 2 1
1 3 2
3 1 2

```


#### Tags 

#800 #NOT OK #brute_force #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_123_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
